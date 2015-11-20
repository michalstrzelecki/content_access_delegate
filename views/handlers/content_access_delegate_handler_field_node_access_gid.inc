<?php

/**
* @file
* Definition of content_access_delegate_handler_field_node_access_gid.
*/

/**
* Render a role names which can view node. Based on node_access table.
*
* @ingroup views_field_handlers
*/
class content_access_delegate_handler_field_node_access_gid extends views_handler_field_prerender_list {

  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = array('table' => 'node', 'field' => 'nid');
  }

  function query() {
    $this->add_additional_fields();
    $this->field_alias = $this->aliases['nid'];
  }

  function pre_render(&$values) {
    $nids = array();
    $this->items = array();

    foreach ($values as $result) {
      $nids[] = $this->get_value($result, NULL, TRUE);
    }

    if ($nids) {
      $query = db_select('node_access', 'na');
      $query->addField('na', 'gid');
      $query->addField('na', 'nid');
      $query->condition('na.nid', $nids);
      $query->condition('na.grant_view', 1);
      $result = $query->execute();

      foreach ($result as $value) {
        $role = (integer) $value->gid;
        $role = user_role_load($role);

        if (!empty($role->name)) {
          $this->items[$value->nid][$value->gid]['role'] = check_plain($role->name);
        }
      }
    }
  }

  function render_item($count, $item) {
    return $item['role'];
  }

  function document_self_tokens(&$tokens) {
    $tokens['[' . $this->options['id'] . '-role' . ']'] = t('The name of the role.');
  }

  function add_self_tokens(&$tokens, $item) {
    if (!empty($item['role'])) {
      $tokens['[' . $this->options['id'] . '-role' . ']'] = $item['role'];
    }
  }
}
