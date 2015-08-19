<?php

/**
 * @file
 * API Documentation for wsfields
 *
 * @author David Pascoe-Deslauriers <dpascoed@coldfrontlabs.ca>
 * @author Mathew Winstone <mwinstone@coldfrontlabs.ca>
 */

/**
 * Allows modules to alter and format field data prior to it being added to
 * a field instance.
 *
 * @param array $instance
 *  Instance of a field
 * @return array
 *  Returns a formatted array for use in a field instance
 */
function hook_wsfields_FIELD_TYPE_data_alter($data, $instance) {
  
}

/**
 * Allows modules to log or otherwise deal with updates to entity expires information
 */
function hook_wsfields_entity_expires($entity_type, $entity_id, $expire) {

}
