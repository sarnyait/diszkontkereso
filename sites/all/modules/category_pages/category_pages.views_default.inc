<?php
/**
 * @file
 * category_pages.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function category_pages_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'osszes_akcio';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Osszes akcio';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
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
  $handler->display->display_options['style_options']['masonry_column_width'] = '33';
  $handler->display->display_options['style_options']['masonry_column_width_units'] = '%';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '20';
  $handler->display->display_options['style_options']['masonry_resizable'] = FALSE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = FALSE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Fejléc: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div id="szuresek"><h2 id="nezet">Más nézet: <a id="soros" href="/?mode=racsos&masonry=racsos">Sorok</a><a id="racsos" href="/?mode=masonry">Dobozok</a> </h2></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Fejléc: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<?php
print get_exposed_filter_output();
?>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
  /* Relationship: Tartalom: Taxonomy terms on node */
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
  /* Relationship: Taxonómia kifejezés: Logo (field_logo:fid) */
  $handler->display->display_options['relationships']['field_logo_fid']['id'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['table'] = 'field_data_field_logo';
  $handler->display->display_options['relationships']['field_logo_fid']['field'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['relationship'] = 'term_node_tid';
  /* Relationship: Tartalom: Termék (field_termek) */
  $handler->display->display_options['relationships']['field_termek_nid']['id'] = 'field_termek_nid';
  $handler->display->display_options['relationships']['field_termek_nid']['table'] = 'field_data_field_termek';
  $handler->display->display_options['relationships']['field_termek_nid']['field'] = 'field_termek_nid';
  $handler->display->display_options['relationships']['field_termek_nid']['delta'] = '0';
  /* Mező: Tartalom: Hivatkozás */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Útvonal */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  /* Mező: Tartalom: Ár */
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
  /* Mező: Tartalom: Akciós ár */
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
  /* Mező: Tartalom: Olcsóbban */
  $handler->display->display_options['fields']['field_olcsobban']['id'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['table'] = 'field_data_field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['field'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['label'] = '';
  $handler->display->display_options['fields']['field_olcsobban']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Százalék */
  $handler->display->display_options['fields']['field_szazalek']['id'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['field'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['label'] = '';
  $handler->display->display_options['fields']['field_szazalek']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_szazalek']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_szazalek']['element_class'] = 'szazalek';
  $handler->display->display_options['fields']['field_szazalek']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Cím */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'termeknev';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Termékfotó */
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
  /* Mező: Tartalom: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'field_termek_nid';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Akció vége */
  $handler->display->display_options['fields']['field_akciovege']['id'] = 'field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['table'] = 'field_data_field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['field'] = 'field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['label'] = '';
  $handler->display->display_options['fields']['field_akciovege']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akciovege']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_akciovege']['settings'] = array(
    'interval' => 2,
    'interval_display' => 'time ago',
  );
  /* Mező: Tartalom: Áruház */
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
  /* Mező: Taxonómia kifejezés: Logo */
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
  /* Sort criterion: kedvezmeny */
  $handler->display->display_options['sorts']['field_szazalek_value']['id'] = 'field_szazalek_value';
  $handler->display->display_options['sorts']['field_szazalek_value']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['sorts']['field_szazalek_value']['field'] = 'field_szazalek_value';
  $handler->display->display_options['sorts']['field_szazalek_value']['ui_name'] = 'kedvezmeny';
  $handler->display->display_options['sorts']['field_szazalek_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_szazalek_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_szazalek_value']['expose']['label'] = 'Nagyobb kedvezmény';
  /* Sort criterion: ar */
  $handler->display->display_options['sorts']['field_akci_s_r_value']['id'] = 'field_akci_s_r_value';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['table'] = 'field_data_field_akciosar';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['field'] = 'field_akciosar_value';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['ui_name'] = 'ar';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_akci_s_r_value']['expose']['label'] = 'Olcsóbb';
  /* Contextual filter: Tartalom: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Mind';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Tartalom: Közzétéve */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Tartalom: Típus */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'products_display' => 'products_display',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Áruház (field_aruhaz) (selective) */
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['id'] = 'field_aruhaz_tid_selective';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['table'] = 'field_data_field_aruhaz';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['field'] = 'field_aruhaz_tid_selective';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['ui_name'] = 'Áruház (field_aruhaz) (selective)';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['label'] = 'Üzletláncok';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['identifier'] = 'field_aruhaz_tid_selective';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['selective_display_field'] = 'field_aruhaz';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: százalék (field_szazalek) (selective) */
  $handler->display->display_options['filters']['field_szazalek_value_selective']['id'] = 'field_szazalek_value_selective';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['field'] = 'field_szazalek_value_selective';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['ui_name'] = 'százalék (field_szazalek) (selective)';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_szazalek_value_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['label'] = 'Akció mértéke';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['identifier'] = 'field_szazalek_value_selective';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_szazalek_value_selective']['selective_display_field'] = 'field_szazalek';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['selective_items_limit'] = '50';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'osszesakcio');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['masonry_column_width'] = '30';
  $handler->display->display_options['style_options']['masonry_column_width_units'] = '%';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '10';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = TRUE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['mefibs'] = array(
    'blocks' => array(
      0 => array(
        'name' => 'Rendezes',
        'machine_name' => 'rendezes',
        'submit_button' => 'Submit',
        'reset_button' => NULL,
        'reset_button_label' => 'Alaphelyzet',
        'autosubmit' => '1',
        'autosubmit_hide' => NULL,
      ),
    ),
    'extras' => array(
      'sort' => -1,
      'items_per_page' => -1,
    ),
    'frontpage' => array(
      'secondary_form_block' => array(),
      'sort_block' => array(
        0 => 'rendezes',
      ),
      'filter' => array(
        'field_kategoria_tid_selective' => array(),
        'field_aruhaz_tid_selective' => array(
          0 => 'default',
        ),
        'field_szazalek_value_selective' => array(
          0 => 'default',
        ),
      ),
      'other' => array(
        'items_per_page' => array(),
        'offset' => array(),
      ),
    ),
    'osszesakcio' => array(
      'filter' => array(
        'field_aruhaz_tid_selective' => array(
          0 => 'default',
        ),
        'field_szazalek_value_selective' => array(
          0 => 'default',
        ),
      ),
      'other' => array(
        'items_per_page' => array(),
        'offset' => array(),
      ),
      'sort_block' => array(
        0 => 'rendezes',
      ),
      'secondary_form_block' => array(),
    ),
  );
  $handler->display->display_options['path'] = 'osszes-akcio-views';

  /* Display: masonry */
  $handler = $view->new_display('mode', 'masonry', 'masonry');
  $handler->display->display_options['displays'] = array(
    'frontpage' => 'frontpage',
  );
  $handler->display->display_options['mode_id'] = 'masonry';
  $handler->display->display_options['mode_name'] = 'Masonry';

  /* Display: racsos */
  $handler = $view->new_display('mode', 'racsos', 'racsos');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'lista-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Mező: Tartalom: Akciós ár */
  $handler->display->display_options['fields']['field_akci_s_r']['id'] = 'field_akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['table'] = 'field_data_field_akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['field'] = 'field_akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['label'] = '';
  $handler->display->display_options['fields']['field_akci_s_r']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_akci_s_r']['element_class'] = 'akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akci_s_r']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Mező: Tartalom: Százalék */
  $handler->display->display_options['fields']['field_szazalek']['id'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['field'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['label'] = '';
  $handler->display->display_options['fields']['field_szazalek']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_szazalek']['alter']['text'] = '[field_szazalek]%';
  $handler->display->display_options['fields']['field_szazalek']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_szazalek']['element_class'] = 'szazalek';
  $handler->display->display_options['fields']['field_szazalek']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Cím */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>[title]</h4>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'termeknev';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Mező: Tartalom: Kategória (display) */
  $handler->display->display_options['fields']['field_kategoria']['id'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['table'] = 'field_data_field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['field'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['label'] = '';
  $handler->display->display_options['fields']['field_kategoria']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kategoria']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kategoria']['group_columns'] = array(
    'tid' => 'tid',
  );
  /* Mező: Tartalom: Áruház */
  $handler->display->display_options['fields']['field_aruhaz']['id'] = 'field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['table'] = 'field_data_field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['field'] = 'field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['label'] = '';
  $handler->display->display_options['fields']['field_aruhaz']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aruhaz']['element_label_colon'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'frontpage' => 'frontpage',
  );
  $handler->display->display_options['mode_id'] = 'racsos';
  $handler->display->display_options['mode_name'] = 'racsos';
  $translatables['osszes_akcio'] = array(
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
    t('Mind'),
    t('Select any filter and click on Apply to see results'),
    t('Elemek száma oldalanként'),
    t('- Mind -'),
    t('Eltolás'),
    t('« első'),
    t('‹ előző'),
    t('következő ›'),
    t('utolsó »'),
    t('<div id="szuresek"><h2 id="nezet">Más nézet: <a id="soros" href="/?mode=racsos&masonry=racsos">Sorok</a><a id="racsos" href="/?mode=masonry">Dobozok</a> </h2></div>'),
    t('<?php
print get_exposed_filter_output();
?>'),
    t('term'),
    t('image from field_logo'),
    t('field_termek'),
    t('Útvonal'),
    t('[field_aruhaz] ([field_aruhaz-tid])'),
    t('Nagyobb kedvezmény'),
    t('Olcsóbb'),
    t('Üzletláncok'),
    t('Akció mértéke'),
    t('Page'),
    t('more'),
    t('masonry'),
    t('Masonry'),
    t('racsos'),
    t('[field_szazalek]%'),
    t('<h4>[title]</h4>'),
    t('Kategóriák'),
  );
  $export['osszes_akcio'] = $view;

  $view = new view();
  $view->name = 'taxonomy_menu';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Taxonomy menu';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Kategóriák';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Alaphelyzet';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_accordion_plugin_style';
  $handler->display->display_options['style_options']['title_field'] = 'name_1';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name_2' => 'name_2',
    'name' => 'name',
  );
  /* Relationship: Taxonómia kifejezés: Szülő kifejezés */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Relationship: Taxonómia kifejezés: Tartalom using Kategória (display) */
  $handler->display->display_options['relationships']['reverse_field_kategoria_node']['id'] = 'reverse_field_kategoria_node';
  $handler->display->display_options['relationships']['reverse_field_kategoria_node']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_kategoria_node']['field'] = 'reverse_field_kategoria_node';
  $handler->display->display_options['relationships']['reverse_field_kategoria_node']['required'] = TRUE;
  /* Mező: Taxonómia kifejezés: Kifejezésazonosító */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = 'taxonomy/term/[tid]';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Mező: Taxonómia kifejezés: Név */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['name_1']['label'] = '';
  $handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
  /* Mező: Taxonómia kifejezés: Név */
  $handler->display->display_options['fields']['name_2']['id'] = 'name_2';
  $handler->display->display_options['fields']['name_2']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name_2']['field'] = 'name';
  $handler->display->display_options['fields']['name_2']['label'] = '';
  $handler->display->display_options['fields']['name_2']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['name_2']['alter']['path'] = '[tid]';
  $handler->display->display_options['fields']['name_2']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['name_2']['element_label_colon'] = FALSE;
  /* Mező: COUNT(DISTINCT Taxonómia kifejezés: Név) */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '([name])';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['separator'] = '';
  /* Contextual filter: Taxonómia kifejezés: Név */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['exception']['title'] = 'Mind';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['override'] = TRUE;
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['validate']['fail'] = 'summary';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Taxonómiaszótár: Programok által használt név */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'elelmiszerek' => 'elelmiszerek',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Kategóriák';
  $translatables['taxonomy_menu'] = array(
    t('Master'),
    t('Kategóriák'),
    t('more'),
    t('Apply'),
    t('Alaphelyzet'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Szülő'),
    t('field_kategoria'),
    t('taxonomy/term/[tid]'),
    t('.'),
    t('([name])'),
    t('Mind'),
    t('Block'),
  );
  $export['taxonomy_menu'] = $view;

  $view = new view();
  $view->name = 'taxonomy_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy page';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
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
  $handler->display->display_options['style_options']['masonry_column_width'] = '33';
  $handler->display->display_options['style_options']['masonry_column_width_units'] = '%';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '20';
  $handler->display->display_options['style_options']['masonry_resizable'] = FALSE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = FALSE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Fejléc: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div id="szuresek"><h2 id="nezet">Más nézet: <a id="soros" href="/?mode=racsos&masonry=racsos">Sorok</a><a id="racsos" href="/?mode=masonry">Dobozok</a> </h2></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Fejléc: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<?php
print get_exposed_filter_output();
?>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h3>Nincs termék a kategóriában</h3>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Tartalom: Taxonomy terms on node */
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
  /* Relationship: Taxonómia kifejezés: Logo (field_logo:fid) */
  $handler->display->display_options['relationships']['field_logo_fid']['id'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['table'] = 'field_data_field_logo';
  $handler->display->display_options['relationships']['field_logo_fid']['field'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['relationship'] = 'term_node_tid';
  /* Relationship: Tartalom: Termék (field_termek) */
  $handler->display->display_options['relationships']['field_termek_nid']['id'] = 'field_termek_nid';
  $handler->display->display_options['relationships']['field_termek_nid']['table'] = 'field_data_field_termek';
  $handler->display->display_options['relationships']['field_termek_nid']['field'] = 'field_termek_nid';
  $handler->display->display_options['relationships']['field_termek_nid']['delta'] = '0';
  /* Relationship: Tartalom: Kategória (field_category) */
  $handler->display->display_options['relationships']['field_category_tid']['id'] = 'field_category_tid';
  $handler->display->display_options['relationships']['field_category_tid']['table'] = 'field_data_field_category';
  $handler->display->display_options['relationships']['field_category_tid']['field'] = 'field_category_tid';
  $handler->display->display_options['relationships']['field_category_tid']['relationship'] = 'field_termek_nid';
  /* Mező: Tartalom: Ár */
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
  /* Mező: Tartalom: Akciós ár */
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
  /* Mező: Tartalom: Olcsóbban */
  $handler->display->display_options['fields']['field_olcsobban']['id'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['table'] = 'field_data_field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['field'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['label'] = '';
  $handler->display->display_options['fields']['field_olcsobban']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Százalék */
  $handler->display->display_options['fields']['field_szazalek']['id'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['field'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['label'] = '';
  $handler->display->display_options['fields']['field_szazalek']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_szazalek']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_szazalek']['element_class'] = 'szazalek';
  $handler->display->display_options['fields']['field_szazalek']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Cím */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>[title]</h4>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'termeknev';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Mező: Tartalom: Termékfotó */
  $handler->display->display_options['fields']['field_termekfoto']['id'] = 'field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['table'] = 'field_data_field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['field'] = 'field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['relationship'] = 'field_termek_nid';
  $handler->display->display_options['fields']['field_termekfoto']['label'] = '';
  $handler->display->display_options['fields']['field_termekfoto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_termekfoto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_termekfoto']['settings'] = array(
    'image_style' => 'diszkont',
    'image_link' => 'content',
  );
  /* Mező: Tartalom: Body */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['relationship'] = 'field_termek_nid';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Akció vége */
  $handler->display->display_options['fields']['field_akciovege']['id'] = 'field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['table'] = 'field_data_field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['field'] = 'field_akciovege';
  $handler->display->display_options['fields']['field_akciovege']['label'] = '';
  $handler->display->display_options['fields']['field_akciovege']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akciovege']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_akciovege']['settings'] = array(
    'interval' => 2,
    'interval_display' => 'time ago',
  );
  /* Mező: Tartalom: Áruház */
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
  /* Mező: Taxonómia kifejezés: Logo */
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
  /* Sort criterion: kedvezmeny */
  $handler->display->display_options['sorts']['field_szazalek_value']['id'] = 'field_szazalek_value';
  $handler->display->display_options['sorts']['field_szazalek_value']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['sorts']['field_szazalek_value']['field'] = 'field_szazalek_value';
  $handler->display->display_options['sorts']['field_szazalek_value']['ui_name'] = 'kedvezmeny';
  $handler->display->display_options['sorts']['field_szazalek_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_szazalek_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_szazalek_value']['expose']['label'] = 'Nagyobb kedvezmény';
  /* Sort criterion: ar */
  $handler->display->display_options['sorts']['field_akci_s_r_value']['id'] = 'field_akci_s_r_value';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['table'] = 'field_data_field_akciosar';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['field'] = 'field_akciosar_value';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['ui_name'] = 'ar';
  $handler->display->display_options['sorts']['field_akci_s_r_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_akci_s_r_value']['expose']['label'] = 'Olcsóbb';
  /* Contextual filter: Kategória */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['ui_name'] = 'Kategória';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title'] = 'Mind';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'elelmiszerek' => 'elelmiszerek',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'elelmiszerek' => 'elelmiszerek',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '3';
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = TRUE;
  /* Contextual filter: Tartalom: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['exception']['title'] = 'Mind';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Tartalom: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title'] = 'Mind';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  /* Filter criterion: Tartalom: Közzétéve */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Tartalom: Típus */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'products_display' => 'products_display',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Áruház (field_aruhaz) (selective) */
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['id'] = 'field_aruhaz_tid_selective';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['table'] = 'field_data_field_aruhaz';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['field'] = 'field_aruhaz_tid_selective';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['ui_name'] = 'Áruház (field_aruhaz) (selective)';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['label'] = 'Üzletláncok';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['identifier'] = 'field_aruhaz_tid_selective';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['selective_display_field'] = 'field_aruhaz';
  $handler->display->display_options['filters']['field_aruhaz_tid_selective']['selective_items_limit'] = '100';
  /* Filter criterion: százalék (field_szazalek) (selective) */
  $handler->display->display_options['filters']['field_szazalek_value_selective']['id'] = 'field_szazalek_value_selective';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['field'] = 'field_szazalek_value_selective';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['ui_name'] = 'százalék (field_szazalek) (selective)';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_szazalek_value_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['label'] = 'Akció mértéke';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['identifier'] = 'field_szazalek_value_selective';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_szazalek_value_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => '1',
    3 => '3',
  );
  $handler->display->display_options['filters']['field_szazalek_value_selective']['selective_display_field'] = 'field_szazalek';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['selective_items_limit'] = '50';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'frontpage');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['masonry_column_width'] = '33';
  $handler->display->display_options['style_options']['masonry_column_width_units'] = '%';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '10';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = TRUE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = FALSE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['mefibs'] = array(
    'blocks' => array(
      0 => array(
        'name' => 'Rendezes',
        'machine_name' => 'rendezes',
        'submit_button' => 'Submit',
        'reset_button' => NULL,
        'reset_button_label' => 'Alaphelyzet',
        'autosubmit' => '1',
        'autosubmit_hide' => NULL,
      ),
    ),
    'extras' => array(
      'sort' => -1,
      'items_per_page' => -1,
    ),
    'frontpage' => array(
      'secondary_form_block' => array(),
      'sort_block' => array(
        0 => 'rendezes',
      ),
      'filter' => array(
        'field_kategoria_tid_selective' => array(),
        'field_aruhaz_tid_selective' => array(
          0 => 'default',
        ),
        'field_szazalek_value_selective' => array(
          0 => 'default',
        ),
      ),
      'other' => array(
        'items_per_page' => array(),
        'offset' => array(),
      ),
    ),
  );
  $handler->display->display_options['path'] = 'kategoria';

  /* Display: masonry */
  $handler = $view->new_display('mode', 'masonry', 'masonry');
  $handler->display->display_options['displays'] = array(
    'frontpage' => 'frontpage',
  );
  $handler->display->display_options['mode_id'] = 'masonry';
  $handler->display->display_options['mode_name'] = 'Masonry';

  /* Display: racsos */
  $handler = $view->new_display('mode', 'racsos', 'racsos');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'lista-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Mező: Tartalom: Akciós ár */
  $handler->display->display_options['fields']['field_akci_s_r']['id'] = 'field_akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['table'] = 'field_data_field_akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['field'] = 'field_akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['label'] = '';
  $handler->display->display_options['fields']['field_akci_s_r']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_akci_s_r']['element_class'] = 'akciosar';
  $handler->display->display_options['fields']['field_akci_s_r']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_akci_s_r']['settings'] = array(
    'thousand_separator' => ' ',
    'prefix_suffix' => 1,
  );
  /* Mező: Tartalom: Százalék */
  $handler->display->display_options['fields']['field_szazalek']['id'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['field'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['label'] = '';
  $handler->display->display_options['fields']['field_szazalek']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_szazalek']['alter']['text'] = '[field_szazalek]%';
  $handler->display->display_options['fields']['field_szazalek']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_szazalek']['element_class'] = 'szazalek';
  $handler->display->display_options['fields']['field_szazalek']['element_label_colon'] = FALSE;
  /* Mező: Tartalom: Cím */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h4>[title]</h4>';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'termeknev';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Mező: Tartalom: Kategória (display) */
  $handler->display->display_options['fields']['field_kategoria']['id'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['table'] = 'field_data_field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['field'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['label'] = '';
  $handler->display->display_options['fields']['field_kategoria']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kategoria']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kategoria']['group_columns'] = array(
    'tid' => 'tid',
  );
  /* Mező: Tartalom: Áruház */
  $handler->display->display_options['fields']['field_aruhaz']['id'] = 'field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['table'] = 'field_data_field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['field'] = 'field_aruhaz';
  $handler->display->display_options['fields']['field_aruhaz']['label'] = '';
  $handler->display->display_options['fields']['field_aruhaz']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aruhaz']['element_label_colon'] = FALSE;
  $handler->display->display_options['displays'] = array(
    'frontpage' => 'frontpage',
  );
  $handler->display->display_options['mode_id'] = 'racsos';
  $handler->display->display_options['mode_name'] = 'racsos';
  $translatables['taxonomy_page'] = array(
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
    t('Mind'),
    t('Select any filter and click on Apply to see results'),
    t('Elemek száma oldalanként'),
    t('- Mind -'),
    t('Eltolás'),
    t('« első'),
    t('‹ előző'),
    t('következő ›'),
    t('utolsó »'),
    t('<div id="szuresek"><h2 id="nezet">Más nézet: <a id="soros" href="/?mode=racsos&masonry=racsos">Sorok</a><a id="racsos" href="/?mode=masonry">Dobozok</a> </h2></div>'),
    t('<?php
print get_exposed_filter_output();
?>'),
    t('<h3>Nincs termék a kategóriában</h3>'),
    t('term'),
    t('image from field_logo'),
    t('field_termek'),
    t('term from field_category'),
    t('<h4>[title]</h4>'),
    t('[field_aruhaz] ([field_aruhaz-tid])'),
    t('Nagyobb kedvezmény'),
    t('Olcsóbb'),
    t('Üzletláncok'),
    t('Akció mértéke'),
    t('Page'),
    t('more'),
    t('masonry'),
    t('Masonry'),
    t('racsos'),
    t('[field_szazalek]%'),
    t('Kategóriák'),
  );
  $export['taxonomy_page'] = $view;

  return $export;
}
