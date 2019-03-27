#!/usr/bin/php
<?php
function replace_title($arg)
{
	preg_replace_callback('/(\b((title)|(TITLE))=".*?")|(?=((?<=>).*?(?=<)))(?=[^\/])'/, callback, subject);

}

if ($argc < 2)
	exit();
$file = fopen($argv[1], 'r');
while ($file && !feof($file))
	$line[] = fgets($file);
echo($line[0]);

preg_replace_callback('/^(<[Aa]) .*(((href)|(HREF))="https?:\/\/[a-zA-Z0-9_]+((.fr)|(.com)|(.co.uk)|(.org)|(.net)|(.us))").*>*.<\/[Aa]>/', callback, subject);
?>
