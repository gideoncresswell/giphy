<?php

/**
 * @file
 * Giphy module theme implementations.
 */

/**
 * Implements template_preprocess_HOOK().
 */
function template_preprocess_giphy(&$variables) {
  $variables['theme_hook_suggestions'][] = 'giphy__' . $variables['image'];

  $variables['classes_array'] = array('giphy');
  $variables['classes_array'][] = 'giphy-' . $variables['image'];
}

/**
 * Implements template_process_HOOK().
 */
function template_process_giphy(&$variables) {
  $variables['classes'] = implode(' ', $variables['classes_array']);
}

/**
 * Default theme implementation for "giphy".
 */
function theme_giphy(&$variables) {
  $giphy = $variables['giphy'];

  if ($giphy) {
    $image = $giphy->images->{$variables['image']};
    $params['path'] = $image->url;
    $params['height'] = $image->height;
    $params['width'] = $image->width;
    $params['alt'] = $params['title'] = 'Giphy ' . $giphy->id;
    $params['title'] = $image->url;
    $content = theme('image', $params);

    switch ($variables['link']) {
      case 'current':
        $options = array('html' => TRUE);
        $content = l($content, $giphy->url, $options);
        break;
      case 'new':
        $options = array('html' => TRUE);
        $options['attributes']['target'][] = '_blank';
        $content = l($content, $giphy->url, $options);
        break;
    }
    $content = '<div class="giphy-image">' . $content . '</div>';

    $params = array();
    $params['path'] = drupal_get_path('module', 'giphy') . '/img/giphy_logo.png';
    $params['height'] = 21;
    $params['width'] = 100;
    $params['alt'] = $params['title'] = t('Powered by Giphy');
    $options = array('html' => TRUE);
    $options['attributes']['target'][] = '_blank';
    $options['attributes']['class'][] = 'giphy-attribution';
    $powered_by = l(theme('image', $params), 'http://giphy.com/', $options);
    $content .= $powered_by;

  } else {
    $content = '<span class="giphy-error">' . t('Unable to load Giphy content.') . '</span>';
  }

  return '<div class="' . $variables['classes'] . '">' . $content . '</div>';
}
