<?php
/**
 * @file
 * Field UI module integration.
 */

/**
 * Implements hook_field_extra_fields().
 */
function sexybookmarks_field_extra_fields() {
  $extra = array();

  ctools_include('export');
  foreach (field_info_bundles() as $entity => $bundles) {
    foreach (array_keys($bundles) as $bundle) {
      $profile = ctools_export_crud_load('sexybookmarks_profiles', variable_get("{$entity}_sexybookmarks_profile_{$bundle}", ''));
      if (!empty($profile)) {
        $extra[$entity][$bundle] = array(
          'display' => array(
            'sexybookmarks' => array(
              'label' => t('SexyBookmarks'),
              'description' => t('SexyBookmarks'),
              'weight' => 100,
            ),
          ),
        );
      }
    }
  }

  return $extra;
}

/**
 * Implements hook_entity_view().
 */
function sexybookmarks_entity_view($entity, $type, $view_mode, $langcode) {
  ctools_include('export');
  $profile = ctools_export_crud_load('sexybookmarks_profiles', variable_get("{$type}_sexybookmarks_profile_{$entity->content['#bundle']}", ''));
  if (!empty($profile)) {
    $entity->content['sexybookmarks'] = array(
      '#markup' => theme('sexybookmarks', array(
        'url' => isset($entity->uri['path']) ? url($entity->uri['path'], array('absolute' => TRUE)) : '',
        'title' => isset($entity->title) ? $entity->title : '',
        'profile' => $profile->name,
      )),
      '#weight' => 100,
    );
  }
}
