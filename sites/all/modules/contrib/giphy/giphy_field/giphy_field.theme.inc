<?php

/**
 * @file
 * Giphy Field theme functions.
 *
 */

/**
 * Default implementation of giphy_field_items_table theme function.
 */
function theme_giphy_field_items_table($variables) {
  $table = array();
  $table['#theme'] = 'table';
  $table['#rows'] = array();

  foreach ($variables['table'] as $key => $val) {
    if (is_numeric($key)) {
      $row = array();
      $row[] = drupal_render($val['preview']);
      $row[] = drupal_render($val['remove']);
      $row[] = drupal_render($val['value']);
      $table['#rows'][] = $row;
    }
  }

  return drupal_render($table);
}

/**
 * Default implementation of giphy_field_search_table theme function.
 */
function theme_giphy_field_search_table(&$variables) {
  $table['#theme'] = 'table';
  $table['#rows'] = array();

  foreach ($variables['table'] as $key => $val) {
    if (isset($val['button'])) {
      $row = array();
      $row[] = drupal_render($val['preview']);
      $row[] = drupal_render($val['button']);
      $table['#rows'][] = $row;
    }
  }

  return drupal_render($table);
}
