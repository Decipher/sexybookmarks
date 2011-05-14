<?php
/**
 * @file
 * Field module integration.
 */

/**
 * Implements hook_field_extra_fields().
 */
function sexybookmarks_field_extra_fields() {
  //$stored_settings = variable_get('field_bundle_settings', array());
  $extra = array();

  foreach (field_info_bundles() as $entity => $bundles) {
    //$entity_type_info = entity_get_info($entity);
    //$stored_settings[$entity] = isset($stored_settings[$entity]) ? $stored_settings[$entity] : array();

    foreach (array_keys($bundles) as $bundle) {
      $extra[$entity][$bundle] = array(
        'display' => array(
          'sexybookmarks' => array(
            'label' => t('SexyBookmarks'),
            'description' => t('SexyBookmarks'),
            'weight' => 100,
          ),
        ),
      );

      //$stored_settings[$entity][$bundle] = isset($stored_settings[$entity][$bundle]) ? $stored_settings[$entity][$bundle] : array();
      //$stored_settings[$entity][$bundle]['extra_fields'] = isset($stored_settings[$entity][$bundle]['extra_fields']) ? $stored_settings[$entity][$bundle]['extra_fields'] : array();
      //$stored_settings[$entity][$bundle]['extra_fields']['display'] = isset($stored_settings[$entity][$bundle]['extra_fields']['display']) ? $stored_settings[$entity][$bundle]['extra_fields']['display'] : array();
      //$stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'] = isset($stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks']) ? $stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'] : array();
      //foreach (array_keys($entity_type_info['view modes']) as $view_mode) {
      //  $stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'][$view_mode] = isset($stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'][$view_mode]) ? $stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'][$view_mode] : array();
      //  $stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'][$view_mode]['visible'] = isset($stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'][$view_mode]['visible']) ? $stored_settings[$entity][$bundle]['extra_fields']['display']['sexybookmarks'][$view_mode]['visible'] : FALSE;
      //}
    }
  }

  //variable_set('field_bundle_settings', $stored_settings);
  //field_info_cache_clear();

  return $extra;
}

/**
 * Implements hook_entity_view().
 */
function sexybookmarks_entity_view($entity, $type, $view_mode, $langcode) {
  $entity->content['sexybookmarks'] = array(
    '#markup' => theme('sexybookmarks', array(
      'url' => isset($entity->uri['path']) ? url($entity->uri['path'], array('absolute' => TRUE)) : '',
      'title' => isset($entity->title) ? $entity->title : '',
      'profile' => 'default'
    )),
    '#weight' => 100,
  );
}
