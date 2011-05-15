<?php
/**
 * @file
 * Link module integration.
 */

/**
 * Implements hook_field_formatter_info().
 */
function sexybookmarks_field_formatter_info() {
  return array(
    'sexybookmarks' => array(
      'label' => t('SexyBookmarks'),
      'field types' => array('link_field'),
      'settings' => array('sexybookmarks_profile' => ''),
    ),
  );
}

/**
 * Implements hook_field_formatter_view().
 */
function sexybookmarks_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  $element = array();

  foreach ($items as $delta => $item) {
    $element[$delta] = array(
      '#theme' => 'sexybookmarks',
      '#url' => $item['display_url'],
      '#title' => $item['title'],
      '#profile' => $display['settings']['sexybookmarks_profile'],
    );
  }

  return $element;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function sexybookmarks_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $element = array();

  $options = array();
  ctools_include('export');
  foreach (ctools_export_crud_load_all('sexybookmarks_profiles') as $profile) {
    if (empty($profile->disabled)) {
      $options[$profile->name] = $profile->name;
    }
  }
  $element['sexybookmarks_profile'] = array(
    '#type' => 'select',
    '#title' => t('SexyBookmarks profile'),
    '#empty_value' => '',
    '#options' => $options,
    '#default_value' => !empty($display['settings']['sexybookmarks_profile']) ? $display['settings']['sexybookmarks_profile'] : '',
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function sexybookmarks_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  return t('Profile: !profile', array('!profile' => !empty($display['settings']['sexybookmarks_profile']) ? $display['settings']['sexybookmarks_profile'] : t('None')));
}
