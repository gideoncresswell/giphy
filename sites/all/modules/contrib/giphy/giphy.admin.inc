<?php

/**
 * @file
 * Giphy module administrative page callbacks.
 */

/**
 * Administrative configuration form.
 */
function giphy_admin_config_form($form, &$form_state) {
  $form['giphy_api_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API key'),
    '#default_value' => variable_get('giphy_api_key', GIPHY_PUBLIC_KEY),
  );

  return system_settings_form($form);
}
