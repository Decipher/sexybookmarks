<?php
/**
 * @file
 * Custom Formatters module integration.
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function sexybookmarks_custom_formatters_defaults() {
  $formatters = array();

  $formatter = new stdClass;
  $formatter->disabled = TRUE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'example_php_sexybookmarks';
  $formatter->label = 'Example: SexyBookmarks (PHP)';
  $formatter->description = 'A PHP example formatter; SexyBookmarks module.';
  $formatter->mode = 'php';
  $formatter->field_types = 'text';
  $formatter->code = '/**
 * This is an example Advanced Custom Formatter to demonstrate how to output various items as a SexyBookmarks.
 */
$profile = \'default\';

/**
 * If Devel module is present (recommended), display the contents of the $element variable to help with construction of the formatter.
 */
if (module_exists(\'devel\')) {
  dpm($variables);
}

/**
 * Render Node URL as a SexyBookmark.
 */
/* -- Delete this line if you want to use this code -- */
$node = $variables[\'#object\'];
$url = url("node/{$node->nid}", array(\'absolute\' => TRUE));
$title = $node->title;
return theme(\'sexybookmarks\', array(
  \'profile\' => $profile,
  \'url\' => $url,
  \'title\' => $title,
));
// */';
  $formatters['example_php_sexybookmarks'] = $formatter;

  return $formatters;
}
