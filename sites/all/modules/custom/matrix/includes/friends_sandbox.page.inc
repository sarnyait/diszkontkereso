<?php
/**
 * @file
 *
 *
 *
 * @author Kálmán Hosszu - hosszu.kalman@gmail.com - http://www.kalman-hosszu.com
 */

function friends_sandbox_page() {
  global $user;
  drupal_add_css(drupal_get_path('module', 'friends') . '/css/friends-style.css');
  drupal_add_css(drupal_get_path('module', 'friends') . '/css/csshake.min.css');

  //drupal_add_css(drupal_get_path('module', 'friends') . '/css/flipclock.css');
  drupal_add_js(drupal_get_path('module', 'friends') . '/js/friends-script.js');
  //drupal_add_js(drupal_get_path('module', 'friends') . '/js/flipclock.js');

  $output = 'Hey!';

  drupal_add_js(array('currentUser' => $user->uid), 'setting');


  $output.= '<div id="playground">' . friends_generate_playground($user->uid) . '</div>';


  $output .= '<hr /> PROGRAM <hr />';

  $_SESSION['test'] = 'HO!';
  $_COOKIE['test2'] = 'süti';

  return $output;
}

function friends_generate_playground($uid) {
  $output = '';
  $program = friends_get_program();
  $state = friends_get_game_state(friends_get_top_user($uid));
  for ($c = 0; $c < 5; $c++) {
    $id = 'box-' . $c;
    $class = array();
    $style = friends_get_preset($id, $program, $state);
    $up = friends_get_up($id, $uid, $program, $state, $class);
    $style = implode(';', $style);
    $class = implode(' ', $class);
    $output .= '<div class="box ' . $class . '" id="' . $id . '" data-id="' . $c . '" data-up="' . $up . '" style="' . $style . '"></div>';
  }
  return $output;
}

function friends_sandbox_ajax() {
  $uid = $_POST['uid'];
  $ouid = friends_get_top_user($uid);

  $state = friends_get_game_state($ouid);
  $state['gamestate']++;
  if (!in_array($uid, $state['users'])) {
    $state['users'][] = $uid;
  }
  variable_set('game_' . $ouid, serialize($state));
  drupal_json_output(friends_generate_playground($uid));
  exit;
}


function friends_get_program() {
  $step = array();
  $gadgets = array('box-0', 'box-1', 'box-2', 'box-3', 'box-4');
  $users = array('new', 'any', 'any', 'any', 'new');
  for ($c = 0; $c < 5; $c++) {
    $step[$c] = array(
      0 => array(
        'gadget' => $gadgets[$c],
        'action' => array(
          'click' => array(
            'css' => array('background: red'),
          )),
        'user' => $users[$c]),
    );
  }
  $step[0][0]['action']['click']['css'][] = 'border: 5px solid #ccc';
  $step[0][0]['other'] = array('box-2' => array('background: yellow'),
    'box-3' => array('border: 4px solid purple'));
  return $step;
}

function friends_get_preset($id, $program, $state) {
  $style = array();
  for ($c = 0; $c < $state['gamestate']; $c++) {
    foreach ($program[$c] as $row) {
      if ($row['gadget'] == $id) {
        $style = array_merge($style, $row['action']['click']['css']);
      }
      if (isset($row['other'])) {
        foreach ($row['other'] as $key => $value) {
          if ($key == $id) {
            $style = array_merge($style, $value);
          }
        }
      }
    }
  }
  return $style;
}

function friends_get_up($id, $uid, $program, $state, &$class) {
  foreach ($program[$state['gamestate']] as $row) {
    if ($row['gadget'] == $id) {
      switch ($row['user']) {
        case 'new':
          if (friends_get_top_user($uid) != $uid && !in_array($uid, $state['users'])) {
            return 1;
          }
          else {
            $class[] = 'shake-hard';
            return 0;
          }
          break;
        case 'any':
          return 1;
          break;
      }
    }
    else {
      $class[] = 'shake-hard';
      return 0;
    }
  }

}

function friends_get_game_state($uid) {
  $gamestate = array('gamestate' => 0, 'users' => array());
  $state = variable_get('game_' . $uid, '');
  if (empty($state)) {
    return $gamestate;
  }
  else {
    return unserialize($state);
  }
}

function friends_invite_tree($uid, &$output) {
  $results = db_select('invite_notifications', 'i')
  ->fields('i', array('inviter', 'invitee'))
  ->condition('i.inviter', $uid)
  ->execute();
  foreach ($results as $row) {
    $inviter = user_load($row->inviter);
    $invitee = user_load($row->invitee);
    $output[] = $invitee->name . ' (' . $inviter->name . ')';
    friends_invite_tree($row->invitee, $output);
  }
  return implode('<br />', $output);
}

function friends_get_top_user($uid) {
  $results = db_select('invite_notifications', 'i')
    ->fields('i', array('inviter', 'invitee'))
    ->condition('i.invitee', $uid)
    ->execute();
  foreach ($results as $row) {
    return friends_get_top_user($row->inviter);
  }
  return $uid;
}

