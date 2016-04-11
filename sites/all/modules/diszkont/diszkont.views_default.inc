<?php
/**
 * @file
 * diszkont.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function diszkont_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'szures';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Kategória Szűrés';
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
    'field_kategoria_tid_selective' => array(
      'bef_format' => 'bef_links',
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
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div id="szuresek"><h2 id="nezet">Más nézet: <a id="soros" href="/?mode=racsos&masonry=racsos">Sorok</a><a id="racsos" href="/?mode=masonry">Dobozok</a> </h2></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area_1']['id'] = 'area_1';
  $handler->display->display_options['header']['area_1']['table'] = 'views';
  $handler->display->display_options['header']['area_1']['field'] = 'area';
  $handler->display->display_options['header']['area_1']['empty'] = TRUE;
  $handler->display->display_options['header']['area_1']['content'] = '<?php
print get_exposed_filter_output();
?>';
  $handler->display->display_options['header']['area_1']['format'] = 'php_code';
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
  /* Relationship: Taxonómia kifejezés: Logo (field_logo:fid) */
  $handler->display->display_options['relationships']['field_logo_fid']['id'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['table'] = 'field_data_field_logo';
  $handler->display->display_options['relationships']['field_logo_fid']['field'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['relationship'] = 'term_node_tid';
  /* Field: Tartalom: Ár */
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
  /* Field: Tartalom: Akciós ár */
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
  /* Field: Tartalom: Olcsóbban */
  $handler->display->display_options['fields']['field_olcsobban']['id'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['table'] = 'field_data_field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['field'] = 'field_olcsobban';
  $handler->display->display_options['fields']['field_olcsobban']['label'] = '';
  $handler->display->display_options['fields']['field_olcsobban']['element_label_colon'] = FALSE;
  /* Field: Tartalom: Százalék */
  $handler->display->display_options['fields']['field_szazalek']['id'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['field'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['label'] = '';
  $handler->display->display_options['fields']['field_szazalek']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_szazalek']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_szazalek']['element_class'] = 'szazalek';
  $handler->display->display_options['fields']['field_szazalek']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
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
  /* Field: Content: Rendered Tartalom */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['rendered_entity']['alter']['path'] = '[title]';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'diszkont';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Field: Tartalom: Termékfotó */
  $handler->display->display_options['fields']['field_termekfoto']['id'] = 'field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['table'] = 'field_data_field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['field'] = 'field_termekfoto';
  $handler->display->display_options['fields']['field_termekfoto']['label'] = '';
  $handler->display->display_options['fields']['field_termekfoto']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_termekfoto']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_termekfoto']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => 'content',
  );
  /* Field: Tartalom: Akció vége */
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
  /* Field: Tartalom: Termékleírás */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['body']['alter']['text'] = '[rendered_entity] ';
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Tartalom: Áruház */
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
  /* Field: Taxonómia kifejezés: Logo */
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
  /* Field: Tartalom: Melyik kategória? */
  $handler->display->display_options['fields']['field_kategoria']['id'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['table'] = 'field_data_field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['field'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['label'] = '';
  $handler->display->display_options['fields']['field_kategoria']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kategoria']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kategoria']['type'] = 'shs_default';
  $handler->display->display_options['fields']['field_kategoria']['settings'] = array(
    'linked' => 0,
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'products' => 'products',
    'products_display' => 'products_display',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Kategória (field_kategoria) (selective) */
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['id'] = 'field_kategoria_tid_selective';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['table'] = 'field_data_field_kategoria';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['field'] = 'field_kategoria_tid_selective';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['ui_name'] = 'Kategória (field_kategoria) (selective)';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['group'] = 1;
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['expose']['label'] = 'Kategória';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['expose']['identifier'] = 'field_kategoria_tid_selective';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['selective_display_field'] = 'field_kategoria';
  $handler->display->display_options['filters']['field_kategoria_tid_selective']['selective_items_limit'] = '1000';
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
    1 => 0,
    3 => 0,
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
    2 => 0,
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_szazalek_value_selective']['selective_display_field'] = 'field_szazalek';
  $handler->display->display_options['filters']['field_szazalek_value_selective']['selective_items_limit'] = '50';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'products' => 'products',
  );

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
  $handler->display->display_options['style_options']['masonry_resizable'] = FALSE;
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
        'field_kategoria_tid_selective' => array(
          0 => 'default',
        ),
        'field_aruhaz_tid_selective' => array(
          0 => 'default',
        ),
        'field_szazalek_value_selective' => array(
          0 => 'default',
        ),
      ),
    ),
  );
  $handler->display->display_options['path'] = 'nyitolap';

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
  /* Field: Tartalom: Akciós ár */
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
  /* Field: Tartalom: Százalék */
  $handler->display->display_options['fields']['field_szazalek']['id'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['table'] = 'field_data_field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['field'] = 'field_szazalek';
  $handler->display->display_options['fields']['field_szazalek']['label'] = '';
  $handler->display->display_options['fields']['field_szazalek']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_szazalek']['alter']['text'] = '[field_szazalek]%';
  $handler->display->display_options['fields']['field_szazalek']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_szazalek']['element_class'] = 'szazalek';
  $handler->display->display_options['fields']['field_szazalek']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
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
  /* Field: Tartalom: Melyik kategória? */
  $handler->display->display_options['fields']['field_kategoria']['id'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['table'] = 'field_data_field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['field'] = 'field_kategoria';
  $handler->display->display_options['fields']['field_kategoria']['label'] = '';
  $handler->display->display_options['fields']['field_kategoria']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_kategoria']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_kategoria']['group_columns'] = array(
    'tid' => 'tid',
  );
  /* Field: Tartalom: Áruház */
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
  $translatables['szures'] = array(
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
    t('<h4>[title]</h4>'),
    t('[rendered_entity] '),
    t('[field_aruhaz] ([field_aruhaz-tid])'),
    t('Nagyobb kedvezmény'),
    t('Olcsóbb'),
    t('Kategória'),
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
  $export['szures'] = $view;

  return $export;
}
