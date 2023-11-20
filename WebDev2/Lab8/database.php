<?php
    $host = 'db';
    $user = 'kappa';
    $pass = 'rtyu';
    $dbname = 'LabDb';

    // Create connection to MySQL
    $conn = new mysqli($host, $user, $pass, $dbname);

    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
?>
