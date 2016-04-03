<?php
/**
 * @file
 * diszkont.features.inc
 */

/**
 * Implements hook_views_api().
 */
function diszkont_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function diszkont_node_info() {
  $items = array(
    'products' => array(
      'name' => t('Products'),
      'base' => 'node_content',
      'description' => t('A termékek (név, leírás, fotó)'),
      'has_title' => '1',
      'title_label' => t('Cím'),
      'help' => '',
    ),
    'products_display' => array(
      'name' => t('Products Display'),
      'base' => 'node_content',
      'description' => t('A termékek változó adatai (kiszerelés, ár, stb.) felviteléhez'),
      'has_title' => '1',
      'title_label' => t('Cím'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
