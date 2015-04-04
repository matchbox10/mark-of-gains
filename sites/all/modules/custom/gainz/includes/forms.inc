<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function gainz_set_form($form, &$form_state) {
  
 $form['price'] = array(
    '#type' => 'textfield', //you can find a list of available types in the form api
    '#title' => 'What is Your Price?',
    '#size' => 10,
    '#maxlength' => 10,
    '#required' => TRUE, //make this field required 
  );
  

$form['submit_button'] = array(
    '#type' => 'submit',
    '#value' => t('Click Here!'),
    );
  
  return $form;
}
function gainz_set_form_validate($form, &$form_state) {
  if (!($form_state['values']['price'] > 0)){
    form_set_error('price', t('Price must be a positive number.'));
  }
}
function gainz_set_form_submit($form, &$form_state) {
}