<?php

/**
 * @file
 * Export of views_default object needed by content_access_delegate module.
 */

/**
 * Implementation of hook_views_default_views()
 */
function content_access_delegate_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'content_access_delegate';
  $view->description = 'UI for delegating role node access.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Content Access Delegate';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content Access Delegate';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '1';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::content_access_delegate_grants_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  
  /* Field: Content access: View grant */
  $handler->display->display_options['fields']['grant_view']['id'] = 'grant_view';
  $handler->display->display_options['fields']['grant_view']['table'] = 'node_access';
  $handler->display->display_options['fields']['grant_view']['field'] = 'grant_view';
  $handler->display->display_options['fields']['grant_view']['not'] = 0;
  
  /* Field: Content access: Update grant */
  $handler->display->display_options['fields']['grant_update']['id'] = 'grant_update';
  $handler->display->display_options['fields']['grant_update']['table'] = 'node_access';
  $handler->display->display_options['fields']['grant_update']['field'] = 'grant_update';
  $handler->display->display_options['fields']['grant_update']['not'] = 0;
  
  /* Field: Content access: Delete grant */
  $handler->display->display_options['fields']['grant_delete']['id'] = 'grant_delete';
  $handler->display->display_options['fields']['grant_delete']['table'] = 'node_access';
  $handler->display->display_options['fields']['grant_delete']['field'] = 'grant_delete';
  $handler->display->display_options['fields']['grant_delete']['not'] = 0;
  
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  
  /* Filter criterion: Content access: Role */
  $handler->display->display_options['filters']['gid']['id'] = 'gid';
  $handler->display->display_options['filters']['gid']['table'] = 'node_access';
  $handler->display->display_options['filters']['gid']['field'] = 'gid';
  $handler->display->display_options['filters']['gid']['group'] = 1;
  $handler->display->display_options['filters']['gid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['gid']['expose']['operator_id'] = 'gid_op';
  $handler->display->display_options['filters']['gid']['expose']['operator'] = 'gid_op';
  $handler->display->display_options['filters']['gid']['expose']['identifier'] = 'gid';
  $handler->display->display_options['filters']['gid']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['gid']['group_info']['identifier'] = 'gid';
  $handler->display->display_options['filters']['gid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['gid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  
  /* Filter criterion: Content access: View grant */
  $handler->display->display_options['filters']['grant_view']['id'] = 'grant_view';
  $handler->display->display_options['filters']['grant_view']['table'] = 'node_access';
  $handler->display->display_options['filters']['grant_view']['field'] = 'grant_view';
  $handler->display->display_options['filters']['grant_view']['value'] = '1';
  $handler->display->display_options['filters']['grant_view']['group'] = 1;
  $handler->display->display_options['filters']['grant_view']['exposed'] = TRUE;
  $handler->display->display_options['filters']['grant_view']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['grant_view']['expose']['operator'] = 'grant_view_op';
  $handler->display->display_options['filters']['grant_view']['expose']['identifier'] = 'grant_view';
  $handler->display->display_options['filters']['grant_view']['expose']['required'] = TRUE;
  
  /* Filter criterion: Content access: Update grant */
  $handler->display->display_options['filters']['grant_update']['id'] = 'grant_update';
  $handler->display->display_options['filters']['grant_update']['table'] = 'node_access';
  $handler->display->display_options['filters']['grant_update']['field'] = 'grant_update';
  $handler->display->display_options['filters']['grant_update']['group'] = 1;
  $handler->display->display_options['filters']['grant_update']['exposed'] = TRUE;
  $handler->display->display_options['filters']['grant_update']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['grant_update']['expose']['operator'] = 'grant_update_op';
  $handler->display->display_options['filters']['grant_update']['expose']['identifier'] = 'grant_update';
  
  /* Filter criterion: Content access: Delete grant */
  $handler->display->display_options['filters']['grant_delete']['id'] = 'grant_delete';
  $handler->display->display_options['filters']['grant_delete']['table'] = 'node_access';
  $handler->display->display_options['filters']['grant_delete']['field'] = 'grant_delete';
  $handler->display->display_options['filters']['grant_delete']['value'] = 'All';
  $handler->display->display_options['filters']['grant_delete']['group'] = 1;
  $handler->display->display_options['filters']['grant_delete']['exposed'] = TRUE;
  $handler->display->display_options['filters']['grant_delete']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['grant_delete']['expose']['operator'] = 'grant_delete_op';
  $handler->display->display_options['filters']['grant_delete']['expose']['identifier'] = 'grant_delete';
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content-access-delegate';
  
  $views['content_access_delegate'] = $view;
  
  return $views;
}
