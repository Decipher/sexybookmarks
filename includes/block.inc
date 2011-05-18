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
      $form = array();

      $options = array();
      ctools_include('export');
      foreach (ctools_export_crud_load_all('sexybookmarks_profiles') as $profile) {
        if (empty($profile->disabled)) {
          $options[$profile->name] = $profile->name;
        }
      }
      $form['profile'] = array(
        '#type' => 'select',
        '#title' => t('SexyBookmarks profile'),
        '#empty_value' => '',
        '#options' => $options,
        '#default_value' => variable_get('sexybookmarks_block_profile', ''),
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
      return array(
        'subject' => t('SexyBookmarks'),
        'content' => theme('sexybookmarks', array(
          'profile' => variable_get('sexybookmarks_block_profile', ''),
        ))
      );
  }
}
