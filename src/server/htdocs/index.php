<?php
	require_once '../vendor/autoload.php';

	function Database()
	{
		$db_host = "localhost";
		$db_user = "root";
		$db_pass = "";
		$db_name = "smart_locker_schema";


		$db = new mysqli($db_host, $db_user, $db_pass);

		if ($db->connect_errno)
			die("Connection failed: %s\n" . $db->connect_errno);

		return $db;
	}

	$db = Database();

	$active = $db->query("SELECT * FROM smart_locker_schema.smart_lockers");
	var_dump($active->fetch_assoc());

	$db->close();
?>
