#!/usr/bin/php
<?php
	if ($argc < 2)
		exit();
	if (!preg_match('/(^(([Mm]ardi)|([Ll]undi)|([Mm]ercredi)|([Jj]eudi)|([Vv]endredi)|([Ss]amedi)|([Dd]imanche)) (?!00)(([0-2][0-9])|([3][0-1])) (([Jj]anvier)|([Ff]evrier)|([Mm]ars)|([Aa]vril)|([Mm]ai)|([Jj]uin)|([Jj]uillet)|([Aa]out)|([Ss]eptembre)|([Oo]ctobre)|([Nn]ovembre)|([Dd]ecembre)) [0-2][0-9]{3} ([0-1][0-9]|2[0-3]):([0-1][0-9]|2[0-3]):[0-5][0-9]$)/', $argv[1]))
	{
		echo "Wrong Format\n";
		exit();
	}
	$array = explode(" ", $argv[1]);
	if (count($array) != 5)
		exit();
	$time = explode(":",$argv[1]);
	$hour = intval(substr($time[0], -2));
	$min = intval($time[1]);
	$sec = intval($time[2]);
	$month = $array[2];
	$year = $array[3];
	$day = $array[1];
	$month = preg_replace('/(^[Jj]anvier)/',1,$month);
	$month = preg_replace('/(^[Ff]evrier)/',2,$month);
	$month = preg_replace('/(^[Mm]ars)/',3,$month);
	$month = preg_replace('/(^[Aa]vril)/',4,$month);
	$month = preg_replace('/(^[Mm]ai)/',5,$month);
	$month = preg_replace('/(^[Jj]uin)/',6,$month);
	$month = preg_replace('/(^[Jj]uillet)/',7,$month);
	$month = preg_replace('/(^[Aa]out)/',8,$month);
	$month = preg_replace('/(^[Ss]eptembre)/',9,$month);
	$month = preg_replace('/(^[Oo]ctobre)/',10,$month);
	$month = preg_replace('/(^[Nn]ovembre)/',11,$month);
	$month = preg_replace('/(^[Dc]ecembre)/',12,$month);
	
	$epoch = mktime($hour, $min, $sec, $month, $day, $year);
	echo "$epoch\n";
?>
