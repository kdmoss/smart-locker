<?php
	require_once '../vendor/autoload.php';

	function Database()
	{
		$db_host = "localhost";
		$db_user = "root";
		$db_pass = "";
		$db_name = "smartlocker";

		$db = new mysqli($db_host, $db_user, $db_pass);

		if ($db->connect_errno)
			die("Connection failed: %s\n" . $db->connect_errno);

		return $db;
	}

	$db = Database();

	$active = $db->query("SELECT * FROM smartlocker.lockers");
	var_dump($active->fetch_assoc());

	$db->close();
?>
