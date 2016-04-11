<?php
/**
 * Implements hook_block_info().
 */
function friends_block_info() {
  $blocks['friends'] = array(
    'info' => t('Friends tree'),
    'cache' => DRUPAL_NO_CACHE, //don't cache this one
  );
  return $blocks;
}

function friends_block_view($delta) {
  $block = array();
  switch ($delta) {
    case 'friends':
      //use helper functions to set the blocks. Cleaner.
      $block['content'] = friends_list_friends();
      break;
  }
  return $block;
}

function friends_list_friends() {
  global $user;
  $ouid = friends_get_top_user($user->uid);
  $owner = user_load($ouid);
  $content = 'Owner: ' . $owner->name . '<br />';
  $invites = array();
  $content .= friends_invite_tree($ouid, $invites);
  return $content;
}