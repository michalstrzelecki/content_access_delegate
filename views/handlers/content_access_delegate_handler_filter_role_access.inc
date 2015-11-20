<?php

/**
 * @file
 * Definition of content_access_delegate_handler_filter_role_access.
 */

/**
 * Filter by node_access records.
 *
 * @ingroup views_filter_handlers
 */
class content_access_delegate_handler_filter_role_access extends views_handler_filter_equality {
  
  /**
   * Provide a simple radio for equality.
   */
  function value_form(&$form, &$form_state) {
    $roles = user_roles(TRUE);
    unset($roles[DRUPAL_AUTHENTICATED_RID]);
    unset($roles[3]);
    
    $form['value'] = array(
      '#type' => 'radios',
      '#title' => t('Role'),
      '#options' => $roles,
      '#default_value' => $this->value,
      '#description' => t('Choose a role that has access to nodes.'),
    );

    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
    }
  }
}
