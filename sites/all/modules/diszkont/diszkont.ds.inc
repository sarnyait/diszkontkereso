<?php
/**
 * @file
 * diszkont.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function diszkont_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|products_display|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'products_display';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'acime' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|products_display|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|products_display|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'products_display';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'acime' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|products_display|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function diszkont_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'acime';
  $ds_field->label = 'A cim';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
    'taxonomy_term' => 'taxonomy_term',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<h1>[node:title] - [node:field-aruhaz] - [node:field_suly] - [node:field_urmertek] - [node:field_darab]</h1>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['acime'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function diszkont_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|products|diszkont';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'products';
  $ds_layout->view_mode = 'diszkont';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
        1 => 'field_termekfoto',
        2 => 'field_osszetevok',
        3 => 'field_tapertek',
        4 => 'field_tarolas',
        5 => 'field_csomagolas',
        6 => 'field_gyarto',
        7 => 'field_termekadatok',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
      'field_termekfoto' => 'ds_content',
      'field_osszetevok' => 'ds_content',
      'field_tapertek' => 'ds_content',
      'field_tarolas' => 'ds_content',
      'field_csomagolas' => 'ds_content',
      'field_gyarto' => 'ds_content',
      'field_termekadatok' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|products|diszkont'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function diszkont_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'diszkont';
  $ds_view_mode->label = 'Diszkont';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['diszkont'] = $ds_view_mode;

  return $export;
}
