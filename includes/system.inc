<?php
/**
 * @file
 * System module integration.
 */

/**
 * Implements hook_theme().
 */
function sexybookmarks_form_alter(&$form, &$form_state, $form_id) {
  drupal_alter('sexybookmarks_form_alter', $form, $form_state, $form_id);
}

/**
 * Implements hook_token_info_alter().
 */
function sexybookmarks_token_info_alter(&$data) {
  drupal_alter('sexybookmarks_token_info_alter', $data);
}

/**
 * Implements hook_tokens_alter().
 */
function sexybookmarks_tokens_alter(array &$replacements, array $context) {
  drupal_alter('sexybookmarks_tokens_alter', $replacements, $context);
}
