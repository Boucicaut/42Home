<?php
	session_start();
	if (!(isset($_POST['submit']) && $_POST['submit'] === "OK" && isset($_POST['login']) && isset($_POST['oldpw']) && isset($_POST['newpw'])))
	{
		echo "ERROR\n";
		exit();
	}
	if (!(is_dir("./private") || is_file("./private/passwd"))
	{
		echo "ERROR\n";
		exit();
	}
	$file = file_get_contents("./private/passwd");
	$file = unserialize($file);
	$loginhash = hash("whirlpool", $_POST['login']);
	$pwhash = hash("whirlpool", $_POST['oldpw']);
	foreach ($file as $k => $item)
	{
		if (!(array_search($loginhash, $item) && array_search($pwhash, $item)))
			continue;
		else
			$file['$k']['passwd'] = hash("whirlpool", $_POST['newpw']);
	}
	$file = serialize($file);
	file_put_contents("./private/passwd", $file);
	echo "OK\n";
?>
