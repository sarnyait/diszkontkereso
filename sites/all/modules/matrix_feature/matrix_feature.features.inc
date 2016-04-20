<?php
/**
 * @file
 * matrix_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function matrix_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function matrix_feature_node_info() {
  $items = array(
    'order' => array(
      'name' => t('Sorrend'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Cím'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
