<?php
/**
 * @file
 * Listing bean plugin.
 */

class WsBean extends BeanPlugin {

  /**
   * Default values for the bean's settings
   */
  public function values() {
    $values = array(
      'settings' => array(
        'wsconfig_settings' => array(
          'wsconfig' => '',
          'replacements' => array(),
          'arguments' => '',
          'options' => '',
        ),
        'wsprocessor' => '',
        'themehook' => '',
      ),
    );

    return array_merge(parent::values(), $values);
  }

    /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('WsBean Settings'),
      '#description' => t('To render content into a wsbean, the data is retrived by the selected Web Service Configure, then if is parsed by the Web Service Processor, the result of that is then passed to the given theme hook to be rendered.'),
    );

    $form['settings']['wsconfig_settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('WsConfig Settings'),
    );

    $form['settings']['wsconfig_settings']['wsconfig'] = array(
      '#type' => 'select',
      '#title' => t('Web Service Config'),
      '#description' => t('The web service config to use to retrieve the data'),
      '#options' => wsconfig_get_list_by_name(),
      '#default_value' => isset($bean->settings['wsconfig_settings']['wsconfig']) ? $bean->settings['wsconfig_settings']['wsconfig'] : '',
    );

    foreach (wsconfig_get_list_by_name() as $machinename => $name) {
      $wsconfig = wsconfig_load_by_name($machinename);

      $items = array();
      foreach ($wsconfig->getOperations() as $opname) {
        $items[$opname] = $wsconfig->getMethodName($opname);
      }

      $form['settings']['wsconfig_settings']['wsconfig_method_' . $machinename] = array(
        '#type' => 'select',
        '#title' => t('Web Service Config Method'),
        '#description' => t('The web service method to use'),
        '#options' => $items,
        '#default_value' => isset($bean->settings['wsconfig_settings']['wsconfig_method_' . $machinename]) ? $bean->settings['wsconfig_settings']['wsconfig_method_' . $machinename] : '',
        '#states' => array(
          'visible' => array(
            ':input[name="settings[wsconfig_settings][wsconfig]"]' => array('value' => $machinename),
          ),
        ),
      );

      if (module_exists('bean_panels_context')) {
        ctools_include('context');
        $converters = ctools_context_get_all_converters();
      }

      foreach ($wsconfig->getOperations() as $opname) {
        foreach ($wsconfig->getReplacements($opname) as $arg) {

          if (module_exists('bean_panels_context')) {
            $form['settings']['wsconfig_settings']['replacements']['wsconfig_method_' . $machinename][$arg] = array(
              '#type' => 'select',
              '#title' => t('@arg from context', array('@arg' => $arg)),
              '#description' => t('Which type of context to use for this argument.'),
              '#default_value' => isset($bean->settings['wsconfig_settings']['replacements']['wsconfig_method_' . $machinename][$arg]) ?
                $bean->settings['wsconfig_settings']['replacements']['wsconfig_method_' . $machinename][$arg] : NULL,
              '#options' => $converters,
              '#states' => array(
                'visible' => array(
                  ':input[name="settings[wsconfig_settings][wsconfig]"]' => array('value' => $machinename),
                  ':input[name="settings[wsconfig_settings][wsconfig_method_' . $machinename . ']"]' => array('value' => $opname),
                ),
              ),
            );
          }

          $form['settings']['wsconfig_settings']['replacements']['wsconfig_method_' . $machinename][$arg . '_default'] = array(
            '#type' => 'textfield',
            '#title' => t('Default value for @arg', array('@arg' => $arg)),
            '#description' => t('Default value to use when context is not available.'),
            '#default_value' => isset($bean->settings['wsconfig_settings']['replacements']['wsconfig_method_' . $machinename][$arg . '_default']) ?
              $bean->settings['wsconfig_settings']['replacements']['wsconfig_method_' . $machinename][$arg . '_default'] : '',
            '#states' => array(
              'visible' => array(
                ':input[name="settings[wsconfig_settings][wsconfig]"]' => array('value' => $machinename),
                ':input[name="settings[wsconfig_settings][wsconfig_method_' . $machinename . ']"]' => array('value' => $opname),
              ),
            ),
          );
        }
      }
    }
     
    $form['settings']['wsconfig_settings']['arguments'] = array(
      '#type' => 'textfield',
      '#title' => t('Arguments'),
      '#description' => t('JSON encoded arguments to pass to the wsconfig'),
      '#default_value' => isset($bean->settings['arguments']) ? $bean->settings['arguments'] : '',
    );

    $form['settings']['wsconfig_settings']['options'] = array(
      '#type' => 'textfield',
      '#title' => t('Options'),
      '#description' => t('JSON encoded options'),
      '#default_value' => isset($bean->settings['options']) ? $bean->settings['options'] : '',
    );

    $form['settings']['wsprocessor'] = array(
      '#type' => 'select',
      '#title' => t('Web Service Processor'),
      '#description' => t('The web service processor to parse the data'),
      '#options' => wsconfig_get_form_processors(),
      '#default_value' => isset($bean->settings['wsprocessor']) ? $bean->settings['wsprocessor'] : '',
    );

    $form['settings']['themehook'] = array(
      '#type' => 'textfield',
      '#title' => t('Theme Hook'),
      '#description' => t('The name of the theme hook to render the data received from the processor with.'),
      '#default_value' => isset($bean->settings['themehook']) ? $bean->settings['themehook'] : '',
    );
    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $contexts = NULL;

    if (isset($bean->contexts)) {
      $contexts = $bean->contexts;
    }

    if (!empty($bean->settings['themehook'])) {
      $form = array('#theme' => $bean->settings['themehook']);
    }

    $wsconfig = wsconfig_load_by_name($bean->settings['wsconfig_settings']['wsconfig']);

    if (!$wsconfig) {
      $content['bean'][$bean->delta]['form']['#markup'] = t('Unable to load WSConfig @wsconfig', array('@wsconfig' => $bean->settings['wsconfig']));
      return $content;
    }

    $processor = $bean->settings['wsprocessor'];
    if (!class_exists($processor) or !is_subclass_of($processor, 'WsData')) {
      $content['bean'][$bean->delta]['form']['#markup'] = t('Unable to load wsprocessor @wsprocessor', array('@wsprocessor' => $bean->settings['wsprocessor']));
      return $content;
    }

    $method = 'wsconfig_method_' . $bean->settings['wsconfig_settings']['wsconfig'];

    // Fidn the replacements.
    $replacements = array();   
    foreach ($wsconfig->getReplacements($bean->settings['wsconfig_settings'][$method]) as $arg) {
      $replacements[$arg] = $bean->settings['wsconfig_settings']['replacements'][$method][$arg . '_default'];

      // If contexts are available, find the matching one and replace it.
      if (isset($contexts)) {
        $context_option = $bean->settings['wsconfig_settings']['replacements'][$method][$arg];
        list($type, $converter) = explode('.', $context_option);

        foreach($contexts[1] as $context) {
          if ($context->type == $type) {
            $replacements[$arg] = ctools_context_convert_context($context, $converter);
            break;
          }
        }
      }
    }

    $arguments = json_decode($bean->settings['wsconfig_settings']['arguments'], TRUE);
    $arguments = isset($arguments) ? $arguments : array();

    $options = json_decode($bean->settings['wsconfig_settings']['options'], TRUE);
    $options = isset($options) ? $options : array();

    try {
      $data = $wsconfig->call(
        $bean->settings['wsconfig_settings'][$method],
        $replacements,
        $arguments,
        $options
     );
    } catch (Exception $e) {
       $content['bean'][$bean->delta]['form']['#markup'] = t('An error occured while making the web service call.');
       return $content;
    }

    // Create a new processor
    $processor = new $processor($data, $bean);
    $content['bean'][$bean->delta]['form'] = $processor->getData();
    return $content;
  }
}
