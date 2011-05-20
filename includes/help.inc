<?php
/**
 * Help module integration.
 */

/**
 * Implements hook_help().
 */
function sexybookmarks_help($path, $arg) {
  switch ($path) {
    case 'admin/help#sexybookmarks':
      return "<p>\n"
           . '  ' . t('The SexyBookmarks for Drupal module is a port of the WordPress plug-in by the same name.') . "\n"
           . "</p>\n"
           . "<p>\n"
           . ' ' . t('The sole aim was to stray away from the "in the box" thinking behind most social bookmarking plugins, and add a little flair that would entice your readers, rather than deterring them with microscopic icons that get lost in pages heavy laden with content.') . "\n"
           . '</p>'
           . "<p>&nbsp;</p>\n"
           . '<h3>' . t('Setting up profiles') . '</h3>'
           . "<p>\n"
           . '  ' . t('Profiles are sets of configuration, allowing you to have use different settings in different conditions (e.g., use different Social bookmarking services for different Content types).') . "\n"
           . "</p>\n"
           . "<p>\n"
           . '  ' . t('Profiles can be managed at') . ":<br />\n"
           . '  &nbsp;&nbsp;' . l('Aministration &raquo; Configuration &raquo; Content authoring &raquo SexyBookmarks', 'admin/config/content/sexybookmarks', array('html' => TRUE)) . "\n"
           . "</p>\n"
           . "<p>&nbsp;</p>\n";

  }
}
