TYPE=TRIGGERS
triggers='CREATE DEFINER=`root`@`localhost` TRIGGER `tr_locker_checkout_generate_combo` BEFORE INSERT ON `locker_checkout` FOR EACH ROW SET NEW.combination = FLOOR(RAND() * 10000)'
sql_modes=1098907648
definers='root@localhost'
client_cs_names='utf8mb4'
connection_cl_names='utf8mb4_unicode_ci'
db_cl_names='utf8mb4_general_ci'
created=161703647268
