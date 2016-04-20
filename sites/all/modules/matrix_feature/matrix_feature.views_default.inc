<?php
/**
 * @file
 * matrix_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function matrix_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'matrix_display';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'matrix_display';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'tovább';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Alkalmaz';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Vissza';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Rendezés';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = '▲';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = '▼';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Rendezés',
      'secondary_form_block' => array(
        'default' => 0,
        'rendezes' => 0,
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'sort' => array(
      'bef_format' => 'bef_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Rendezés',
        'combine' => 1,
        'combine_param' => 'sort_bef_combine_szuresek',
        'combine_rewrite' => 'kedvezmeny Asc | Nagyobb kedvezmény előre
kedvezmeny Desc | 
ar Asc | Olcsóbb előre
ar Desc | Drágább előre',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 1,
        'secondary_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'mefibs_block_sort_bef' => array(
        'rendezes' => 'rendezes',
        'default' => 0,
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'bef_filter_description' => NULL,
        'any_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_aruhaz_tid_selective' => array(
      'bef_format' => 'bef_links',
      'more_options' => array(
        'bef_select_all_none' => 1,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => 'Mind',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'field_szazalek_value_selective' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'full_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Elemek száma oldalanként';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Mind -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Eltolás';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« első';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ előző';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'következő ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'utolsó »';
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['masonry_column_width'] = '30';
  $handler->display->display_options['style_options']['masonry_column_width_units'] = '%';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '15';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = FALSE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'aruhaz' => 'aruhaz',
    'darab' => 0,
    'elelmiszerek' => 0,
    'suly' => 0,
    'urmertekek' => 0,
  );
  /* Relationship: Taxonomy term: Logo (field_logo:fid) */
  $handler->display->display_options['relationships']['field_logo_fid']['id'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['table'] = 'field_data_field_logo';
  $handler->display->display_options['relationships']['field_logo_fid']['field'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['relationship'] = 'term_node_tid';
  /* Relationship: Content: Termék (field_termek) */
  $handler->display->display_options['relationships']['field_termek_nid']['id'] = 'field_termek_nid';
  $handler->display->display_options['relationships']['field_termek_nid']['table'] = 'field_data_field_termek';
  $handler->display->display_options['relationships']['field_termek_nid']['field'] = 'field_termek_nid';
  $handler->display->display_options['relationships']['field_termek_nid']['delta'] = '0';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Field: Taxonomy term: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'field_data_field_logo';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Egységár */
  $handler->display->display_options['fields']['field_egysegar']['id'] = 'field_egysegar';
  $handler->display->display_options['fields']['field_egysegar']['table'] = 'field_data_field_egysegar';
  $handler->display->display_options['fields']['field_egysegar']['field'] = 'field_egysegar';
  $handler->display->display_options['fields']['field_egysegar']['label'] = '';
  $handler->display->display_options['fields']['field_egysegar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_egysegar']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '1',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Termékfotó */
  $handler->display->display_options['fields']['field_termekfoto']['id'] = 'field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['table'] = 'field_data_field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['field'] = 'field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['relationship'] = 'field_termek_nid';
  $handler->display->display_options['fields']['field_termekfoto']['label'] = '';
  $handler->display->display_options['fields']['field_termekfoto']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_termekfoto']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_termekfoto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_termekfoto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_termekfoto']['settings'] = array(
    'image_style' => 'diszkont',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'termeknev';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Akciós ár */
  $handler->display->display_options['fields']['field_akciosar']['id'] = 'field_akciosar';
  $handler->display->display_options['fields']['field_akciosar']['table'] = 'field_data_field_akciosar';
  $handler->display->display_options['fields']['field_akciosar']['field'] = 'field_akciosar';
  $handler->display->display_options['fields']['field_akciosar']['label'] = '';
  $handler->display->display_options['fields']['field_akciosar']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_akciosar']['element_class'] = 'akciosar';
  $handler->display->display_options['fields']['field_akciosar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akciosar']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Százalék */
  $handler->display->display_options['fields']['field_szazalek']['id'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['field'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['label'] = '';
  $handler->display->display_options['fields']['field_szazalek']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_szazalek']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_szazalek']['element_class'] = 'szazalek';
  $handler->display->display_options['fields']['field_szazalek']['element_label_colon'] = FALSE;
  /* Field: Content: Ár */
  $handler->display->display_options['fields']['field_ar']['id'] = 'field_ar';
  $handler->display->display_options['fields']['field_ar']['table'] = 'field_data_field_ar';
  $handler->display->display_options['fields']['field_ar']['field'] = 'field_ar';
  $handler->display->display_options['fields']['field_ar']['label'] = '';
  $handler->display->display_options['fields']['field_ar']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_ar']['element_class'] = 'ar';
  $handler->display->display_options['fields']['field_ar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ar']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Olcsóbban */
  $handler->display->display_options['fields']['field_olcsobban']['id'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['table'] = 'field_data_field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['field'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['label'] = '';
  $handler->display->display_options['fields']['field_olcsobban']['element_label_colon'] = FALSE;
  /* Field: Content: Akció vége */
  $handler->display->display_options['fields']['field_akciovege']['id'] = 'field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['table'] = 'field_data_field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['field'] = 'field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['label'] = '';
  $handler->display->display_options['fields']['field_akciovege']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_akciovege']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akciovege']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'value2',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 1,
  );
  /* Field: Content: Áruház */
  $handler->display->display_options['fields']['field_aruhaz']['id'] = 'field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['table'] = 'field_data_field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['field'] = 'field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['label'] = '';
  $handler->display->display_options['fields']['field_aruhaz']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aruhaz']['alter']['text'] = '[field_aruhaz] ([field_aruhaz-tid])';
  $handler->display->display_options['fields']['field_aruhaz']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aruhaz']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_aruhaz']['group_columns'] = array(
    'tid' => 'tid',
  );
  /* Field: Content: Külső link az áruházhoz */
  $handler->display->display_options['fields']['field_aruhaz_hivatkozo']['id'] = 'field_aruhaz_hivatkozo';
  $handler->display->display_options['fields']['field_aruhaz_hivatkozo']['table'] = 'field_data_field_aruhaz_hivatkozo';
  $handler->display->display_options['fields']['field_aruhaz_hivatkozo']['field'] = 'field_aruhaz_hivatkozo';
  $handler->display->display_options['fields']['field_aruhaz_hivatkozo']['label'] = '';
  $handler->display->display_options['fields']['field_aruhaz_hivatkozo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aruhaz_hivatkozo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aruhaz_hivatkozo']['settings'] = array(
    'trim_length' => '80',
    'nofollow' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Mind';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['matrix_display'] = array(
    t('Master'),
    t('tovább'),
    t('Alkalmaz'),
    t('Vissza'),
    t('Rendezés'),
    t('▲'),
    t('▼'),
    t('kedvezmeny Asc | Nagyobb kedvezmény előre
kedvezmeny Desc | 
ar Asc | Olcsóbb előre
ar Desc | Drágább előre'),
    t('Select any filter and click on Apply to see results'),
    t('Elemek száma oldalanként'),
    t('- Mind -'),
    t('Eltolás'),
    t('« első'),
    t('‹ előző'),
    t('következő ›'),
    t('utolsó »'),
    t('term'),
    t('image from field_logo'),
    t('field_termek'),
    t('Path'),
    t('[field_aruhaz] ([field_aruhaz-tid])'),
    t('Nid'),
    t('Mind'),
    t('Block'),
    t('more'),
  );
  $export['matrix_display'] = $view;

  return $export;
}
