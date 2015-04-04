<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 module_load_include('inc', 'gainz', 'includes/model');

function gainz_set_form($form, &$form_state) {
    
    $reps = _gainz_get_last_reps(arg(5));
    $weight = _gainz_get_last_weight(arg(5));
    
    
    
 $form['weight'] = array(
    '#type' => 'textfield', //you can find a list of available types in the form api
    '#title' => 'What Weight You lifting?',
     '#description' => 'Leave 0 for bodyweight',
    '#size' => 12,
    '#maxlength' => 12,
    '#default_value' => $weight ? $weight : 12, 
    '#required' => FALSE, //make this field required 
  );
  $form['reps'] = array(
    '#type' => 'textfield', //you can find a list of available types in the form api
    '#title' => 'How Many Reps?',
    '#size' => 3,
    '#maxlength' => 3,
    '#default_value' =>  $reps ? $reps : 12,  
    '#required' => FALSE, //make this field required 
  );
    $form['set_number'] = array(
    '#type' => 'textfield', //you can find a list of available types in the form api
    '#title' => 'Set Number?',
    '#size' => 3,
    '#maxlength' => 3,
    '#default_value' =>  _gainz_get_workouts(arg(5)),  
    '#required' => FALSE, //make this field required 
  );
  

$form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Workout'),
    );
  
  return $form;
}
function gainz_set_form_validate($form, &$form_state) {
  if (!($form_state['values']['weight'] > 0)){
    form_set_error('price', t('Price must be a positive number.'));
  }
}
function gainz_set_form_submit($form, &$form_state) {
    global $user;
    
    $node = new stdClass();
    $node->type = 'my_workout_log';
    $node->status = 1;
    $node->title = arg(5) . "_" . $user->uid;
    $node->uid = $user->uid;
    $node->language = LANGUAGE_NONE;
    $node->field_set_node_id['und'][0]['value'] = arg(5);
    $node->field_set_weight['und'][0]['value'] = $form_state['values']['weight'];
    $node->field_set_reps['und'][0]['value'] = $form_state['values']['reps'];
    $node->field_set_number['und'][0]['value'] = 1;
    
    node_save($node);
    drupal_set_message('Saved');
}