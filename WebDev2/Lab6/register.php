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

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $username = $_POST['username'];
    $password = $_POST['password'];
    $firstname = $_POST['firstname'];
    $lastname = $_POST['lastname'];

    $sql = "INSERT INTO User (Username, Password, FirstName, LastName) VALUES ('$username', '$password', '$firstname', '$lastname')";

    if ($conn->query($sql) === TRUE) {
        echo "Registration successful. User data has been added to the User table.";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}
?>
