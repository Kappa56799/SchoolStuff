<html>
<body>
<?php

$host = 'db';
$user = 'kappa';
$pass = 'rtyu';
$dbname = 'LabDb';

$conn = new mysqli($host, $user, $pass, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} else {
    echo "Connected to MySQL server successfully!<br>";
}

// SQL query to select all data from the Product table
$sqlProduct = "SELECT * FROM Product";
$resultProduct = $conn->query($sqlProduct);

echo "<h2>Product Table:</h2>";
if ($resultProduct->num_rows > 0) {
    // Output data of each row
    while ($row = $resultProduct->fetch_assoc()) {
        echo "Product ID: " . $row["ProductId"] . " - Name: " . $row["Pname"] . " - Description: " . $row["Description"] . " - Price: " . $row["Price"] . " - Stock: " . $row["Stock"] . "<br>";
    }
} else {
    echo "0 results";
}

// SQL query to select all data from the User table
$sqlUser = "SELECT * FROM User";
$resultUser = $conn->query($sqlUser);

echo "<h2>User Table:</h2>";
if ($resultUser->num_rows > 0) {
    // Output data of each row
    while ($row = $resultUser->fetch_assoc()) {
        echo "User ID: " . $row["Userid"] . " - Username: " . $row["Username"] . " - FirstName: " . $row["FirstName"] . " - LastName: " . $row["LastName"] . "<br>";
    }
} else {
    echo "0 results";
}

$conn->close();
?>
</body>
</html>
