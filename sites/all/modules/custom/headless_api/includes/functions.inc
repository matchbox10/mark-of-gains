<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

  function headless_api_nodes($nid = 1) {
      $node = node_load($nid);
     # echo "this works " . $nid;
      
      drupal_json_output($node);
  }
  
function headless_api_test() {
    global $base_url; 
        $testData['title'] = 'Marks Test Data';
        $testData['body'] = 'Some Data to hold in place describing this';
        $testData['site'] = $base_url;
        $testData['image'] = 'http://www.clipartbest.com/cliparts/niX/baL/niXbaLGiB.jpeg';
        
      
      drupal_json_output($testData);
  }