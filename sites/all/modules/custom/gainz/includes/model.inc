<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */



function _gainz_get_workouts($sid) {
    $result = db_query("SELECT
        Count(field_data_field_set_node_id.field_set_node_id_value) + 1 AS sets
        FROM
        field_data_field_set_node_id
        INNER JOIN node ON node.nid = field_data_field_set_node_id.entity_id
        WHERE DATE_FORMAT(FROM_UNIXTIME(node.created),'%Y-%m-%d') = DATE_FORMAT(NOW(),'%Y-%m-%d') AND
        field_data_field_set_node_id.field_set_node_id_value = :sid", array(':sid' => $sid));
    
    return $result->fetchField();
}

function _gainz_get_last_reps($sid) {
    $result = db_query("SELECT
            field_data_field_set_reps.field_set_reps_value AS reps
            FROM
            field_data_field_set_node_id
            INNER JOIN field_data_field_set_reps ON field_data_field_set_reps.entity_id = field_data_field_set_node_id.entity_id
            WHERE
            field_data_field_set_node_id.field_set_node_id_value = :sid
            ORDER BY
            field_data_field_set_node_id.entity_id DESC
            LIMIT 1", array(':sid' => $sid));
    return $result->fetchField();
}

function _gainz_get_last_weight($sid) {
        $result = db_query("SELECT
                field_data_field_set_weight.field_set_weight_value
                FROM
                field_data_field_set_node_id
                INNER JOIN field_data_field_set_weight ON field_data_field_set_weight.entity_id = field_data_field_set_node_id.entity_id
                WHERE
                field_data_field_set_node_id.field_set_node_id_value = :sid
                ORDER BY
                field_data_field_set_node_id.entity_id DESC
                LIMIT 1", array(':sid' => $sid));
    return $result->fetchField();
    
}
