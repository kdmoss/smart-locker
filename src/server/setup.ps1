$root_dir   = $PSScriptRoot -Replace '[\\/]', '/'
$mysql_dir  = $root_dir + '/data'
$htdocs_dir = $root_dir + '/htdocs'

(Get-Content -Path C:\xampp\mysql\bin\my.ini -Raw) | Foreach-Object {

    $_ -Replace '(?<=datadir=")(.*)(?=")',                   $mysql_dir `
       -Replace '(?<=innodb_data_home_dir=")(.*)(?=")',      $mysql_dir `
       -Replace '(?<=innodb_log_group_home_dir=")(.*)(?=")', $mysql_dir `
} | Set-Content -Path C:\xampp\mysql\bin\my.ini

(Get-Content -Path C:\xampp\apache\conf\httpd.conf -Raw) | Foreach-Object {

    $_ -Replace '(?<=DocumentRoot ")(.*)(?=")', $htdocs_dir `
       -Replace '(?<=<Directory ")(.*)(?=">)',  $htdocs_dir `
} | Set-Content -Path C:\xampp\apache\conf\httpd.conf