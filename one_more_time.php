#!/usr/bin/php
<?php
	if ($argc < 2)
		exit();
	if (!preg_match('/^[[L,l]undi,[M,m]ardi,[M,m]ercredi,[J,j]eudi,[V,v]endredi,[S,s]amedi,[D,d]imanche]" "[1-9]{2}" "[[J,j]anvier, [F,f]evrier, [M,m]ars, [A,a]vril, [M,m]ai, [J,j]uin, [J,j]uillet, [A,a]out, [S,s]eptembre, [O,o]ctobre, [N,n]ovembre, [D,d]ecembre]" "[1-9]{4}" "[0-23]" "[0-24]" "[0-59]/', $argv[1]))
	{
		echo "Wrong Format\n";
		exit();
	}
	echo "Good\n";
//	$epoch = mktime(H, M, S, Month, D,Y);
?>
