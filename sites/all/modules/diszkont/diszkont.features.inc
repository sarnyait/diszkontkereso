<?php
/**
 * @file
 * diszkont.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function diszkont_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

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
    'heti_ajanlat' => array(
      'name' => t('Heti ajanlat'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Heti ajánlat:
melyik hét?
melyik kategória?'),
    ),
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
