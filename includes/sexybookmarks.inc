<?php
/**
 * @file
 * SexyBookmarks module integration.
 */

/**
 * Implementation of hook_default_sexybookmarks_profile().
 */
function sexybookmarks_default_sexybookmarks_profile() {
  $export = array();

  $profile = new stdClass;
  $profile->disabled = FALSE; /* Edit this to true to make a default profile disabled initially */
  $profile->api_version = 2;
  $profile->name = 'default';
  $profile->config = array(
    'service' => '5,7,88,2,3,257,74,52,207,191,236,54',
    'mode' => 'inject',
    'expand' => 1,
    'duration' => '400',
    'shortener' => 'google',
    'center' => 0,
    'spaced' => 0,
    'designer_toolTips' => 0,
    'tip_bg_color' => '#000000',
    'tip_text_color' => '#FFFFFF',
    'twitter_template' => '${title} - ${short_link} via @Shareaholic',
    'twitter_overlay' => 1,
    'fbLikeButton' => 0,
    'fbButtonPos' => 'bottom-right',
  );
  $export['default'] = $profile;

  return $export;
}
