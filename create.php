<?php
	session_start();
	if (isset($_POST['submit']) && $_POST['submit'] === 'OK' && isset($_POST['login']) && isset($_POST['passwd']) && !empty($_POST['login']) && !empty($_POST['passwd']))
	{
		$_SESSION['login'] = $_POST['login'];
		$_SESSION['passwd'] = $_POST['passwd'];
	}
	else
		echo "ERROR\n";
	

//path ?? ./private || ../private
	if (!is_dir("./private"))
		mkdir("private");
	if (!is_file("./private/passwd"))
		touch("./private/passwd");

	
	if (!($file = file_get_contents("private/passwd")))
		$file = unserialize($file);

	if (array_search($_POST['login'], $file))
	{
		echo "ERROR\n";
		exit();
	}
	$file[] = ['login' => $_POST['login'], 'passwd' => hash('whirpool', $post['passwd'])];

	file_put_contents("private/passwd", serialize($file));
	echo "OK\n";
?>
