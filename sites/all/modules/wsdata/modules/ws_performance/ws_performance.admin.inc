<?php

function ws_performance_config_form($form, &$form_state) {
  $form['ws_performance_store_method'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log the full method called by the WSConfig'),
    '#default_value' => variable_get('ws_performance_store_method', FALSE),
  );
  $form['ws_performance_store_data'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log all data included include with the WSConfig call'),
    '#default_value' => variable_get('ws_performance_store_data', FALSE),
  );

  $form['ws_performance_store_result'] = array(
    '#type' => 'checkbox',
    '#title' => t('Log all results data retrived by the WSConfig call'),
    '#default_value' => variable_get('ws_performance_store_result', FALSE),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

function ws_performance_config_form_submit($form, &$form_state) {
  if (isset($form_state['values']['ws_performance_store_method'])) {
    variable_set('ws_performance_store_method', $form_state['values']['ws_performance_store_method']);
  }

  if (isset($form_state['values']['ws_performance_store_data'])) {
    variable_set('ws_performance_store_data', $form_state['values']['ws_performance_store_data']);
  }

  if (isset($form_state['values']['ws_performance_store_result'])) {
    variable_set('ws_performance_store_result', $form_state['values']['ws_performance_store_result']);
  }
}

function ws_performance_overview() {
  $form = array();

  $header = array(
    array('data' => t('WSConfig'), 'field' => 'wsconfig_name'),
    array('data' => t('Total number of calls'), 'field' => 'total'),
    array('data' => t('Average result size (bytes)'), 'field' => 'size'),
    array('data' => t('Average response time (ms)'), 'field' => 'wait'),
    array('data' => t('Since'), 'field' => 'run'),
  );
  $results = db_query('SELECT wsconfig_name, COUNT(0) AS total, AVG(size) AS size, AVG(wait) AS wait, MIN(run) AS run FROM {ws_performance} GROUP BY wsconfig_name;');
  $rows = array();
  foreach ($results as $result) {
    $row = array();
    foreach ((array)$result as $key => $data) {
      $row[$key]['data'] = $data;
      $row[$key]['header'] = $key;

      switch ($key) {
        case 'run':
          $row[$key]['data'] = format_date($data);
          break;
        case 'wsconfig_name':
          $row[$key]['data'] = l($data,'admin/reports/ws_performance/' . $data);
          break;
      }
    }
    $rows[] = $row;
  }

  $form['wsconfig_list'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $form;
}

function ws_performance_report($wsconfig) {
  $form = array();
  dpm($wsconfig);
  return $form;
}

function ws_performance_specific_report($wsconfig, $event) {
  $form = array();

  return $form;
}
