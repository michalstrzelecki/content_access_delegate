<?php

/**
 * Implements hook_views_data_alter().
 */
function content_access_delegate_views_data() {
  
  $data = array();

  // ----------------------------------------------------------------------
  // Node access table
  
  // gid field
  $data['node_access']['gid'] = array(
    'title' => t('Roles'),
    'help' => t('Roles which can display nodes.'),
    'field' => array(
      'handler' => 'content_access_delegate_handler_field_node_access_gid',
    ),
    'filter' => array(
      'handler' => 'content_access_delegate_handler_filter_role_access',
      'help' => t('Filter content by role which has any access.'),
    ),
  );
  
  // grant_view, grant_update, grant_delete field
  $op_standard = array('view', 'update', 'delete');
  foreach ($op_standard as $op) {
    $op_uc = ucfirst($op);
    $data['node_access']['grant_'.$op] = array(
      'title' => t('@op grant', array('@op' => $op_uc)),
      'help' => t('Boolean idicates role can @op a node.', array('@op' => $op)),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
        'help' => t('Filter for content by @op ability.', array('@op' => $op)),
        'use equal' => TRUE,
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );
  }

  return $data;
}
