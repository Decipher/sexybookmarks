<?php
/**
 * @file
 * CTools Export UI plugin for SexyBookmarks profiles.
 */

$plugin = array(
  'schema' => 'sexybookmarks_profiles',
  'access' => 'administer sexybookmarks',
  'menu' => array(
    'menu prefix' => 'admin/config/content',
    'menu item' => 'sexybookmarks',
    'menu title' => 'SexyBookmarks',
    'menu description' => 'Administer SexyBookmarks profiles.',
  ),
  'title singular' => t('profile'),
  'title singular proper' => t('Profile'),
  'title plural' => t('profiles'),
  'title plural proper' => t('Profiles'),
  'form' => array(
    'settings' => 'sexybookmarks_profiles_export_ui_form',
  ),
);

/**
 * SexyBookmarks profiles settings form.
 */
function sexybookmarks_profiles_export_ui_form(&$form, &$form_state) {
  drupal_add_library('system', 'farbtastic');
  $config = $form_state['item']->config;

  $form['config'] = array(
    '#type' => 'container',
    '#tree' => TRUE,
  );

  $form['config']['service'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($config['service']) ? $config['service'] : '5,7,88,2,3,257,74,52,207,191,236,54',
    '#theme' => 'sexybookmarks_services',
  );

  // General settings.
  $form['config']['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['config']['settings']['mode'] = array(
    '#type' => 'select',
    '#title' => t('Mode'),
    '#options' => array(
      'inject' => t('Inject'),
      'iframe' => t('iFrame'),
    ),
    '#default_value' => isset($config['mode']) ? $config['mode'] : 'inject',
    '#parents' => array('config', 'mode'),
  );
  $form['config']['settings']['expand'] = array(
    '#type' => 'checkbox',
    '#title' => t('Should iFrame auto-expand?'),
    '#default_value' => isset($config['expand']) ? $config['expand'] : TRUE,
    '#states' => array(
      'visible' => array(
        'select[name="config[mode]"]' => array('value' => 'iframe'),
      ),
    ),
    '#parents' => array('config', 'expand'),
  );
  $form['config']['settings']['duration'] = array(
    '#type' => 'textfield',
    '#title' => t('Transition time for iframe expansion'),
    '#default_value' => isset($config['duration']) ? $config['duration'] : '400',
    '#field_suffix' => t('ms'),
    '#size' => 5,
    '#states' => array(
      'visible' => array(
        'select[name="config[mode]"]' => array('value' => 'iframe'),
      ),
    ),
    '#parents' => array('config', 'duration'),
  );
  $form['config']['settings']['shortener'] = array(
    '#type' => 'select',
    '#title' => t('URL Shortener'),
    '#empty_value' => 'none',
    '#options' => array(
      'bitly' => t('bit.ly'),
      'google' => t('goo.gl'),
      'jmp' => t('jmp.li'),
      'supr' => t('su.pr'),
      'tinyurl' => t('tinyurl.com'),
    ),
    '#default_value' => isset($config['shortener']) ? $config['shortener'] : 'google',
    '#parents' => array('config', 'shortener'),
  );

  // Appearance settings.
  $form['config']['appearance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Appearance settings'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['config']['appearance']['center'] = array(
    '#type' => 'checkbox',
    '#title' => t('Center the bookmarks?'),
    '#default_value' => isset($config['center']) ? $config['center'] : FALSE,
    '#states' => array(
      'disabled' => array(
        'input[name="config[spaced]"]' => array('checked' => TRUE),
      ),
    ),
    '#parents' => array('config', 'center'),
  );
  $form['config']['appearance']['spaced'] = array(
    '#type' => 'checkbox',
    '#title' => t('Space the bookmarks evenly?'),
    '#default_value' => isset($config['spaced']) ? $config['spaced'] : FALSE,
    '#states' => array(
      'disabled' => array(
        'input[name="config[center]"]' => array('checked' => TRUE),
      ),
    ),
    '#parents' => array('config', 'spaced'),
  );
  $form['config']['appearance']['designer_toolTips'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use Facebook style designer tooltips?'),
    '#default_value' => isset($config['designer_toolTips']) ? $config['designer_toolTips'] : FALSE,
    '#parents' => array('config', 'designer_toolTips'),
  );
  $form['config']['appearance']['tip_bg_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Tooltip background'),
    '#size' => 7,
    '#maxlength' => 7,
    '#default_value' => isset($config['tip_bg_color']) ? $config['tip_bg_color'] : '#000000',
    '#states' => array(
      'invisible' => array(
        'input[name="config[designer_toolTips]"]' => array('checked' => FALSE),
      ),
    ),
    '#parents' => array('config', 'tip_bg_color'),
  );
  $form['config']['appearance']['tip_text_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Tooltip text'),
    '#size' => 7,
    '#maxlength' => 7,
    '#default_value' => isset($config['tip_text_color']) ? $config['tip_text_color'] : '#FFFFFF',
    '#states' => array(
      'invisible' => array(
        'input[name="config[designer_toolTips]"]' => array('checked' => FALSE),
      ),
    ),
    '#parents' => array('config', 'tip_text_color'),
  );

  // Twitter specific settings.
  $form['config']['twitter'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter settings'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['config']['twitter']['twitter_template'] = array(
    '#type' => 'textfield',
    '#title' => t('Template'),
    '#default_value' => isset($config['twitter_template']) ? $config['twitter_template'] : '${title} - ${short_link} via @Shareaholic',
    '#description' => '
      <ul>
        <li><strong>${title}</strong> - title of the page</li>
        <li><strong>${link}</strong> - link to the page</li>
        <li><strong>${short_link}</strong> - short link that you pass to the Share API</li>
        <li><strong>${notes}</strong> - any text; usually a very short summary of the link or user selected text</li>
      </ul>',
    '#parents' => array('config', 'twitter_template'),
  );
  $form['config']['twitter']['twitter_overlay'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use overlay?'),
    '#default_value' => isset($config['twitter_overlay']) ? $config['twitter_overlay'] : TRUE,
    '#parents' => array('config', 'twitter_overlay'),
  );

  // Facebook specific settings.
  $form['config']['facebook'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook settings'),
    '#tree' => FALSE,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['config']['facebook']['fbLikeButton'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Facebook like button?'),
    '#default_value' => isset($config['fbLikeButton']) ? $config['fbLikeButton'] : FALSE,
    '#parents' => array('config', 'fbLikeButton'),
  );
  $form['config']['facebook']['fbButtonPos'] = array(
    '#type' => 'select',
    '#options' => array(
      'bottom-left' => t('Bottom Left'),
      'bottom-right' => t('Bottom Right'),
      'top-left' => t('Top Left'),
      'top-right' => t('Top Right'),
    ),
    '#default_value' => isset($config['fbButtonPos']) ? $config['fbButtonPos'] : 'bottom-right',
    '#states' => array(
      'invisible' => array(
        'input[name="config[fbLikeButton]"]' => array('checked' => FALSE),
      ),
    ),
    '#parents' => array('config', 'fbButtonPos'),
  );
}

function theme_sexybookmarks_services($variables) {
  $output = '';
  $form_element = $variables['form_element'];

  // List of SexyBookmarks services.
  $services = array(
    2, 3, 4, 5, 6, 7, 10, 24, 38, 39, 40, 52, 54, 74, 88, 201, 219, 257,
    27, 33, 41, 43, 45, 46, 53, 78, 195, 196, 205, 207, 210, 236, 247, 264,
    44, 48, 61, 77, 80, 100, 105, 140, 191, 202, 218, 238, 240, 266, 269, 280, 289,
    1, 14, 21, 89, 98, 102, 106, 243, 267, 268, 277, 278, 283, 284, 285, 286, 288,
    20, 59, 92, 188, 190, 192, 204, 246, 263, 265, 279, 281, 282, 287, 290, 291, 292, 293, 294,
  );
  $directory = md5(implode(',', $services));

  // Attach Javascript and Styles.
  $api = 'http://www.shareaholic.com/api/sprite/?v=2&apikey=' . SB_APIKEY . '&service=' . implode(',', $services);
  drupal_add_css(sexybookmarks_get_file($api, "{$directory}/sprite.css"));
  drupal_add_css('
    li.shareaholic {
      background-image: url("' . file_create_url(sexybookmarks_get_file("{$api}&apitype=png", "{$directory}/sprite.png")) . '");
    }

    div.shr-bookmarks ul.shr-socials li {
      cursor: move !important;
    }
  ', 'inline');
  drupal_add_js(drupal_get_path('module', 'sexybookmarks') . '/scripts/sexybookmarks.admin.js');
  drupal_add_library('system', 'ui.sortable');

  // Active services list.
  $active = array();
  foreach (explode(',', $form_element['#default_value']) as $item) {
    $active[] = array('data' => '', 'id' => "shr-{$item}", 'class' => array("shr-{$item}", 'shareaholic'));
  }
  $output .= '<div class="shr-bookmarks clearfix">' . theme('item_list', array('title' => t('Active services'), 'items' => $active, 'attributes' => array('id' => 'sexybookmarks-active', 'class' => array('shr-socials')))) . '</div>';

  // Inactive services list.
  $inactive = array();
  foreach (array_diff($services, explode(',', $form_element['#default_value'])) as $item) {
    $inactive[] = array('data' => '', 'id' => "shr-{$item}", 'class' => array("shr-{$item}", 'shareaholic'));
  }
  $output .= '<div class="shr-bookmarks clearfix">' . theme('item_list', array('title' => t('Inactive services'), 'items' => $inactive, 'attributes' => array('id' => 'sexybookmarks-inactive', 'class' => array('shr-socials')))) . '</div>';

  // Hidden field.
  element_set_attributes($form_element, array('id', 'name', 'value', 'size', 'maxlength'));
  $output .= theme('hidden', array('element' => $form_element));

  return $output;
}
