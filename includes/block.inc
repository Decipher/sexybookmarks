<?php
/**
 * @file
 * Block module integration.
 */

/**
 * Implements hook_block_info().
 */
function sexybookmarks_block_info() {
  $blocks = array();

  $blocks['sexybookmarks'] = array(
    'info' => t('SexyBookmarks'),
  );

  return $blocks;
}

/**
 * Implements hook_block_configure().
 */
function sexybookmarks_block_configure($delta) {
  switch ($delta) {
    case 'sexybookmarks':
      $options = array();
      ctools_include('export');
      foreach (ctools_export_crud_load_all('sexybookmarks_profiles') as $profile) {
        $options[$profile->name] = $profile->name;
      }

      $form = array();

      $form['profile'] = array(
        '#type' => 'select',
        '#title' => t('SexyBookmarks profile'),
        '#options' => $options,
        '#default_value' => variable_get('sexybookmarks_block_profile', 'default'),
      );

      return $form;
  }
}

/**
 * Implements hook_block_save().
 */
function sexybookmarks_block_save($delta = 0, $edit = array()) {
  switch ($delta) {
    case 'sexybookmarks':
      variable_set('sexybookmarks_block_profile', $edit['profile']);
      break;
  }
}

/**
 * Implements hook_block_view().
 */
function sexybookmarks_block_view($delta) {
  switch ($delta) {
    case 'sexybookmarks':
      if (arg(0) == 'node' && arg(1) != '' && arg(2) == '') {
        $node = node_load(arg(1));
        return array(
          'subject' => t('SexyBookmarks'),
          'content' => theme('sexybookmarks', array(
            'url' => url($node->uri['path'], array('absolute' => TRUE)),
            'title' => $node->title,
            'profile' => variable_get('sexybookmarks_block_profile', 'default'),
          ))
        );
      }
  }
}
