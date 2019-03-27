#!/usr/bin/php
<?php
	if ($argc < 2)
		exit();
	$arg = preg_replace('/[" ",\t]+/',' ',$argv[1]);
	$arg = preg_replace('/(^[" ",\t])|([" ",\t]+$)/','',$arg);
	echo "$arg\n";
?>
