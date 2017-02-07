<?php

// Utility functions.

function array_concat(&$arr, $val) {
    $c = count($arr); // prevent evaluation on each iteration since PHP sucks.
    for ($i = 0; $i < $c; $i++) {
        $arr[$i] .= $val;
    }
}

function c_float($val) {
    return $val + 0.0; // gives you an idea of how dumb PHP really is, _non_?
}

?>