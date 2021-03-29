<?php
	require_once '../vendor/autoload.php';

	// Verify that Twig has loaded

	function Database()
	{
		$db_host = "localhost";
		$db_user = "root";
		$db_pass = "";
		$db_name = "smart_lock";


		$db = new mysqli($db_host, $db_user, $db_pass);

		if ($db->connect_errno)
			die("Connection failed: %s\n" . $db->connect_errno);

		return $db;
	}

	$db = Database();

	$active = $db->query("SELECT * FROM smart_lock.test");
	var_dump($active->fetch_assoc());

	$db->close();
?>
