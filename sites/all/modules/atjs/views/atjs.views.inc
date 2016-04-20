<?php

/**
 * @file
 * Integrates At.js usage data with views.
 */

/**
 * Implements hook_views_data_alter().
 */
function atjs_views_data_alter(&$data) {
  $data['atjs_listener_usage'] = array(
    'table' => array(
      'base' => array(
        'field' => 'aluid',
        'title' => t('At.js listener usage'),
        'help' => t('Query the usage of At.js listeners.'),
      ),
      'group' => t('At.js'),
    ),
    'aluid' => array(
      'title' => t('Usage ID'),
      'help' => t('The unique ID of this usage record.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'listener' => array(
      'title' => t('Listener'),
      'help' => t('The machine name of the listener used.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'source_entity_type' => array(
      'title' => t('Source entity type'),
      'help' => t('The entity type of the entity which has the field, and is the source of the mention.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'source_bundle' => array(
      'title' => t('Source bundle'),
      'help' => t('The bundle of the field which is the source of the mention'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'source_field_name' => array(
      'title' => t('Source field name'),
      'help' => t('The name of the field which the listener is attached to, and the mention is in.'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'source_entity_id' => array(
      'title' => t('Source entity ID'),
      'help' => t('The unique ID of the object from where entity is being mentioned.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'mentioned_entity_type' => array(
      'title' => t('Mentioned entity type'),
      'help' => t('The entity type of the entity being mentioned'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'mentioned_entity_id' => array(
      'title' => t('Mentioned entity ID'),
      'help' => t('The unique ID of the object being mentioned.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    ),
    'uid' => array(
      'title' => t('User ID'),
      'help' => t('ID of the Drupal user who created the mention.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'allow empty' => TRUE,
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'relationship' => array(
        'title' => t('User'),
        'help' => t('Relate the user who created the mention.'),
        'handler' => 'views_handler_relationship',
        'base' => 'users',
        'field' => 'uid',
        'label' => t('User'),
      ),
    ),
    'language' => array(
      'title' => t('Language'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_string',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_string',
      ),
    ),
    'timestamp' => array(
      'title' => t('Timestamp'),
      'help' => t('Time the mention was created.'),
      'argument' => array(
        'handler' => 'views_handler_argument_date',
      ),
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'dismissed' => array(
      'title' => t('Dismissed'),
      'help' => t('A flag indicating whether this usage has been dismissed'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'label' => t('Dismissed'),
        'type' => 'yes-no',
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    )
  );

  foreach (entity_get_info() as $entity_type => $entity_info) {
    $label = $entity_type === t('node') ? t('Content') : check_plain($entity_info['label']);

    $data[$entity_info['base table']]['atjs_mentions_source_rel'] = array(
      'group' => t('At.js'),
      'title' => t('Usage: !label', array('!label' => $label)),
      'help' => t('Join to At.js usage for !types.', array('!type' => $label)),
      'relationship' => array(
        'handler' => 'AtjsViewsHandlerRelationship',
        'label' => t('At.js source'),
        'base' => 'atjs_listener_usage',
        'base field' => 'source_entity_id',
        'relationship field' => $entity_info['entity keys']['id'],
      ),
    );
    $data[$entity_info['base table']]['atjs_mentions_target_rel'] = array(
      'group' => t('At.js'),
      'title' => t('Target: !label', array('!label' => $label)),
      'help' => t('Join to At.js target for !types.', array('!type' => $label)),
      'relationship' => array(
        'handler' => 'AtjsViewsHandlerRelationship',
        'label' => t('At.js targets'),
        'base' => 'atjs_listener_usage',
        'base field' => 'mentioned_entity_id',
        'relationship field' => $entity_info['entity keys']['id'],
      ),
    );

    $data['atjs_listener_usage'][$entity_info['base table'] . '_source_rel'] = array(
      'group' => t('At.js'),
      'title' => t('Source entity: !label', array('!label' => $label)),
      'help' => t('!types that mention other entities.', array('!type' => $label)),
      'relationship' => array(
        'handler' => 'AtjsViewsHandlerRelationship',
        'label' => t('At.js mention source'),
        'base' => $entity_info['base table'],
        'base field' => $entity_info['entity keys']['id'],
        'relationship field' => 'source_entity_id',
      ),
    );

    $data['atjs_listener_usage'][$entity_info['base table'] . '_mentioned_rel'] = array(
      'group' => t('At.js'),
      'title' => t('Mentioned !label', array('!label' => $label)),
      'help' => t('!types mentioned by current record.', array('!type' => $label)),
      'relationship' => array(
        'handler' => 'AtjsViewsHandlerRelationship',
        'label' => t('At.js mentioned entities'),
        'base' => $entity_info['base table'],
        'base field' => $entity_info['entity keys']['id'],
        'relationship field' => 'mentioned_entity_id',
      ),
    );
  }

}
