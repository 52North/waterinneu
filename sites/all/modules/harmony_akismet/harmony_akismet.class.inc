<?php

/*
analysis request
report spam
report ham*/

class HarmonyAkismet {
  public $api_key = '';
  public $user_agent = '';
  public $logging_level = 0;
  public $timeout = 3;
  public $site_url;
  public $harmony_akismet_data_to_send = array();
  public $test_mode = FALSE;

  /**
   * Constructor.
   */
  function __construct($key = NULL) {
    global $base_url;
    if (!$key) {
      $key = variable_get('harmony_akismet_api_key', '');
    }

    $this->api_key = $key;
    $this->logging_level = variable_get('harmony_akismet_logging', 0);
    $this->timeout = variable_get('harmony_akismet_timeout', 3);
    $this->site_url = $base_url . base_path();
    $this->harmony_akismet_data_to_send = variable_get('harmony_akismet_data_to_send', array('email'));
    $this->test_mode = variable_get('harmony_akismet_test_mode', FALSE);
  }

  /**
   * Get the user agent string which will includes software versions.
   */
  public function get_user_agent() {
    if ($this->user_agent === '') {
      $module_info = system_get_info('module', 'harmony_akismet');
      $this->user_agent = 'Drupal/' . VERSION .' | harmony_akismet/' . $module_info['version'];
    }

    return $this->user_agent;
  }

  /**
   * Write to Drupal watchdog respect the logging level.
   */
  public function log($severity, $message, $variables, $response_type = '', $force = FALSE) {
    // Respect the logging level for various types of log entry.
    if (!$force) {
      if ($this->logging_level == 0 && ($response_type == 'ham' || $response_type == 'spam')) {
        return;
      }
      elseif ($this->logging_level == 1 && $response_type == 'ham') {
        return;
      }
    }

    watchdog('harmony_akismet', $message, $variables, $severity);
  }

  /**
   * Verify that our API key is working.
   */
  public function verify_key() {
    // Check for an API key first.
    if (!$this->api_key) {
      drupal_set_message(t("You've attempted to verify your API key with Akismet when you've not set one."), 'error');
      return FALSE;
    }

    // Prep the URL of the site.
    $url = $this->site_url;

    // Host & path.
    $host = 'rest.akismet.com';
    $path = '/1.1/verify-key';

    // Build the request.
    $request = array(
      'method' => 'POST',
      'data' => 'key='. $this->api_key .'&blog='. urlencode($url),
      'timeout' => $this->timeout,
      'headers' => array(
        'Content-Type' => 'application/x-www-form-urlencoded',
        'User-Agent' => $this->get_user_agent(),
      ),
    );

    // Do it!
    $response = drupal_http_request('http://' . $host . $path, $request);
    $response->code = (int) $response->code;

    // If successful bow out now.
    if ($response->code == 200 && $response->data == 'valid') {
      drupal_set_message(t('Your key API is valid, Akismet was contacted successfully.'));
      return TRUE;
    }

    // Check for timeout error.
    if ($response->code === 1 || $response->code == 408) {
      $message = 'There was an error contacting Akismet, the request exceeded the allowed time of @timeout seconds.';
      $variables = array('@timeout' => $this->timeout);

      $this->log(WATCHDOG_ERROR, $message, $variables, '', TRUE);

      drupal_set_message(t($message, $variables), 'error');
      return FALSE;
    }

    // For anything else just return what we've got as an error.
    $variables = array('@details' => $this->timeout, '%code' => $response->code);

    $this->log(WATCHDOG_ERROR, "There was an error contacting Akismet, here are the details.\n@details", $variables, '', TRUE);

    drupal_set_message(t('There was an error contacting Akismet, we got back the drupal_http_request code %code.', $variables), 'error');
    return FALSE;
  }

  public function text_check($content) {
    // Check for an API key first.
    if (!$this->api_key) {
      $this->log(WATCHDOG_ERROR, "Text check was requested but you're missing an API key.", array(), '', TRUE);
      return FALSE;
    }

    // Prep the URL of the site.
    $url = $this->site_url;

    // Host & path.
    $host = $this->api_key . '.rest.akismet.com';
    $path = '/1.1/comment-check';

    // Build the request.
    $request = array(
      'method' => 'POST',
      'data' => '',
      'timeout' => $this->timeout,
      'headers' => array(
        'Content-Type' => 'application/x-www-form-urlencoded',
        'User-Agent' => $this->get_user_agent(),
      ),
    );

    // Build up the data.
    $data = array(
      'blog' => $url,
      'user_ip' => ip_address(),
      //'permalink' => '',
      'comment_type' => 'forum-post',
      'comment_content' => $content['text'],
    );

    // Optional server data.
    if (!empty($_SERVER['HTTP_USER_AGENT'])) {
      $data['user_agent'] = $_SERVER['HTTP_USER_AGENT'];
    }
    if (!empty($_SERVER['HTTP_REFERER'])) {
      $data['referrer'] = $_SERVER['HTTP_REFERER'];
    }

    // Optional other data.
    if (in_array('username', $this->harmony_akismet_data_to_send) && !empty($content['username'])) {
      $data['comment_author'] = $content['username'];
    }
    if (in_array('email', $this->harmony_akismet_data_to_send) && !empty($content['email'])) {
      $data['comment_author_email'] = $content['email'];
    }

    // Consider test mode.
    if ($this->test_mode) {
      $data['is_test'] = '1';
      $lowercased = strtolower($content['text']);

      // Ham mode.
      if (strpos($lowercased, 'ham') !== FALSE) {
        $data['user_role'] = 'administrator';
      }
      // Spam mode.
      elseif (strpos($lowercased, 'spam') !== FALSE) {
        $data['comment_author'] = 'viagra-test-123';
      }
    }

    // URL Encode the lot and put together the request data.
    foreach ($data as $k => $v) {
      $request['data'] .= $k . '=' . urlencode($v) . '&';
    }
    $request['data'] = rtrim($request['data'], '&');

    // Do it!
    $response = drupal_http_request('http://' . $host . $path, $request);
    $response->code = (int) $response->code;

    // If we've got something back then remember it.
    if ($response->code == 200) {
      $status = '';

      // Spam.
      if ($response->data == 'true') {
        $status = 'spam';
      }
      // Ham.
      elseif ($response->data == 'false') {
        $status = 'ham';
      }

      // Build up the message variable.
      $variables = array(
        '%status' => $status,
        '@request' => print_r($response, TRUE),
      );

      // Log things depending on logging level.
      if ($status) {
        $this->log(WATCHDOG_INFO, "Akismet responded with the status %status for a text analysis check. Here's the request:\n@request", $variables, $status);
      }
      // Somethings going wrong.
      else {
        $this->log(WATCHDOG_ERROR, "Akismet has responded to a text analysis request with an API error, something's wrong with what we're sending. Here's the request:\n @request", $variables, $status, TRUE);
      }

      return $status;
    }

    // Something's gone wrong here, yaaay :/ Log it.
    $this->log(WATCHDOG_ERROR, "Akismet has failed to respond with a 200 HTTP code meaning the service couldn't be reached or other issues. Here's the request:\n @request", array('@request' => print_r($response, TRUE)), '', TRUE);
    return '';
  }
}
