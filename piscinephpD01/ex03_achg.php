#!/usr/bin/php
<?php
function ft_split($str){
        $ret = array_filter(explode(" ", $str));
        sort($ret);
        return $ret;
    }


/* ENLEVER CA, MAIN !! */
	print_r(ft_split("  hello    my name   is"));


?>
