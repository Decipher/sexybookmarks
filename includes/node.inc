<?php
/**
 * @file
 * Node module integration.
 */

/**
 * Implements hook_sexybookmarks_form_alter_alter() on behalf of node.module.
 */
function node_sexybookmarks_form_alter_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'node_type_form') {
    $form['sexybookmarks'] = array(
      '#type' => 'fieldset',
      '#title' => t('SexyBookmarks settings'),
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#group' => 'additional_settings',
      '#attached' => array(
        'js' => array(drupal_get_path('module', 'sexybookmarks') . '/scripts/node.js'),
      ),
    );

    $options = array('' => '- None -');
    ctools_include('export');
    foreach (ctools_export_crud_load_all('sexybookmarks_profiles') as $profile) {
      if (empty($profile->disabled)) {
        $options[$profile->name] = $profile->name;
      }
    }
    $form['sexybookmarks']['node_sexybookmarks_profile'] = array(
      '#type' => 'select',
      '#title' => t('Profile'),
      '#options' => $options,
      '#default_value' => variable_get("node_sexybookmarks_profile_{$form['#node_type']->type}", 'default'),
    );
  }
}

/**
 * Implements hook_nodeapi().
 */
function sexybookmarks_nodeapi(&$node, $op, $a3 = NULL, $a4 = NULL) {
  switch ($op) {
    case 'view':
      $node->content['sexybookmarks'] = array(
        '#weight' => module_exists('content') ? content_extra_field_weight($node->type, 'sexybookmarks') : 100,
        '#value' => theme('sexybookmarks', array(
          'profile' => variable_get("node_sexybookmarks_profile_{$node->type}", 'default'),
          'url' => url("node/{$node->nid}", array('absolute' => TRUE)),
          'title' => $node->title,
        )),
      );
      break;
  }
}
