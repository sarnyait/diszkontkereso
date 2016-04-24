<?php
/**
 * @file
 * matrix_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function matrix_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['matrix-matrix'] = array(
    'cache' => 1,
    'custom' => 0,
    'delta' => 'matrix',
    'module' => 'matrix',
    'node_types' => array(),
    'pages' => 'node/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => 0,
      ),
      'diszkont' => array(
        'region' => 'sidebar_second',
        'status' => 1,
        'theme' => 'diszkont',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Bevásárlólistám',
    'visibility' => 1,
  );

  return $export;
}
