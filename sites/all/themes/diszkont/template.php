<?php

function diszkont_menu_alter(&$items) {
  foreach ($items as $url => $item) {
    if (strpos($url, 'search') === 0) {
      unset($items[$url]);
    }
  }
}

function diszkont_form_search_block_form_alter(&$form, &$form_state, $form_id) {
    $form['search_block_form']['#size'] = 600;  // define size of the textfield
    // $form['search_block_form']['#default_value'] = t('Pl. Trappista sajt, marhahús'); // Set a default value for the textfield
    $form['actions']['submit']['#value'] = t('Keresés!'); // Change the text on the submit button
    // Alternative (HTML5) placeholder attribute instead of using the javascript
    $form['search_block_form']['#attributes']['placeholder'] = t('Pl. Trappista sajt, marhahús');
    $form['#action'] = '/search/products/talalat';
    $form['#submit'] = array('diszkont_search_form_submit');
} 


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
  
  /* foreach ($form['field_kategoria_tid_selective']['#options'] as $tid => &$value) {
    $query = db_select('field_data_field_kategoria', 'f')
            ->condition('f.field_kategoria_tid', $tid);
    $query->addExpression('COUNT(*)');
    $count = $query->execute()->fetchField();
    $value = $value . ' (' . $count . ')';
  } */

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

function diszkont_search_form_submit($form, &$form_state) {
  $form_state['redirect'] = 'search/products/talalat/'.$form_state['values']['search_block_form'];  
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
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/login.js', array('scope' => 'footer'));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/footer.js', array('scope' => 'footer'));
      drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/common.js', array('weight' => -13) );
	  drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/ajaxafter.js', array('weight' => -12) );
      
    if(drupal_is_front_page()) {
       drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/sticky_sidebar.js');     
          }  
    
    $path = $_SERVER['REQUEST_URI'];
    $find = 'osszes-akcio';
    $pos = strpos($path, $find);
    if ($pos !== false) {
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/slider-min.js', array('scope' => 'header', 'weight' => 20));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/pager.js', array('scope' => 'header'));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/infinite-ruler.js', array('weight' => -14) );
    }
    
    if (arg(0) ==  "taxonomy" && arg(1) == "term" && is_numeric(arg(2)) && arg(3) == "") {
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/slider-min.js', array('scope' => 'header', 'weight' => 20));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/pager.js', array('scope' => 'header'));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/infinite-ruler.js', array('weight' => -14) );
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/breadcrumb.js', array('weight' => -10) );
    }
    
    $path = $_SERVER['REQUEST_URI'];
    $find = 'search/products';
    $pos = strpos($path, $find);
    if ($pos !== false) {
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/slider-min.js', array('scope' => 'header', 'weight' => 20));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/pager.js', array('scope' => 'header'));
    drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/infinite-ruler.js', array('weight' => -14) );
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
    // drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/signup.js', array('weight' => 1));
    // drupal_add_js(drupal_get_path('theme', 'diszkont') . '/js/signupcopy.js', array('weight' => -1));
    }
    
  }
  
 