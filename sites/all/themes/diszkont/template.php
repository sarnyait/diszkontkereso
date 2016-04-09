<?php

function diszkont_form_alter(&$form, &$form_state, $form_id) {
switch($form_id){
case 'views_exposed_form':

  foreach ($form['field_aruhaz_tid_selective']['#options'] as $tid => &$value) {
    $query = db_select('field_data_field_aruhaz', 'f')
            ->condition('f.field_aruhaz_tid', $tid);
    $query->addExpression('COUNT(*)');
    $count = $query->execute()->fetchField();
    $value = $value . ' (' . $count . ')';
  }
  
  foreach ($form['field_kategoria_tid_selective']['#options'] as $tid => &$value) {
    $query = db_select('field_data_field_kategoria', 'f')
            ->condition('f.field_kategoria_tid', $tid);
    $query->addExpression('COUNT(*)');
    $count = $query->execute()->fetchField();
    $value = $value . ' (' . $count . ')';
  }

  break;
}




  if ( TRUE === in_array( $form_id, array( 'user_login', 'user_login_block', 'user_register_form') ) )
    $form['name']['#attributes']['placeholder'] = t( 'email' );
    $form['pass']['#attributes']['placeholder'] = t( 'jelszó' );
    $form['name']['#attributes']['placeholder'] = t( 'email' );
    $form['mail']['#attributes']['placeholder'] = t( 'jelszó' );
    $form['account']['name']['#attributes']['placeholder'] = t(' felhasználónév ');
    $form['account']['mail']['#attributes']['placeholder'] = t(' email ');
    $form['account']['pass']['pass1']['#attributes']['placeholder'] = t(' jelszó ');
    $form['account']['pass']['pass2']['#attributes']['placeholder'] = t(' jelszó ismét ');
	
}

 function diszkont_preprocess_html(&$variables) {  
 drupal_add_library('system', 'ui');
 $variables['body_attributes_array'] = array(
   'role'  => 'document',
   'class' => &$variables['classes_array'],
   'id' => 'pid-' . drupal_clean_css_identifier(drupal_get_path_alias($_GET['q']))
 );
 }


  function diszkont_preprocess_page(&$vars) {
  
    /* drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/slider-min.js', array('scope' => 'header', 'weight' => 20)); */
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/login.js', array('scope' => 'footer'));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/footer.js', array('scope' => 'footer'));
     
    if(drupal_is_front_page()) {
      drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/common.js', array('weight' => -13) );
      drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/infinite-ruler.js', array('weight' => -14) );
	  drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/ajaxafter.js', array('weight' => -12) );
      /* drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/pager.js', array('scope' => 'footer')); */
      drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/sticky_sidebar.js', array('scope' => 'footer'));
    }
    
    $path = $_SERVER['REQUEST_URI'];
    $find = '?mode=racsos&masonry=racsos';
    $pos = strpos($path, $find);
    if ($pos !== false) {
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/masonry-extra.js', array('weight' => -12));
    }
    
    
    $path = $_SERVER['REQUEST_URI'];
    $find = 'koszonjuk';
    $pos = strpos($path, $find);
    if ($pos !== false) {
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/signup.js', array('weight' => 1));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/signupcopy.js', array('weight' => -1));
    }
    
  }
  
 