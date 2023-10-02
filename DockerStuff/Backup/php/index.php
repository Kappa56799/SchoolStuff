<html>
<body>
<?php
// The MySQL service named in the docker-compose.yml.
$host = 'db';

// Database use name
$user = 'kappa';

//database user password
$pass = 'rtyu';

// database name
$mydatabase = 'Test_DB';
// check the mysql connection status

$conn = new mysqli($host, $user, $pass, $mydatabase);

if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

else {
  echo "Connected to MySQL successfully!";
  echo "<br>";
}


$query1 = "DROP TABLE IF EXISTS MyGuests";
$sql = "
CREATE TABLE MyGuests (
id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
firstname VARCHAR(30) NOT NULL,
lastname VARCHAR(30) NOT NULL,
email VARCHAR(50),
reg_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
)";

$conn->query($query1);
if ($conn->query($sql) === TRUE) {
  echo "Table MyGuests created successfully";
} else {
  echo "Error creating table: " . $conn->error;
}

$Values = "INSERT INTO MyGuests (firstname, lastname, email) VALUES ('Kappa', 'Palka', 'Test@hi.com'), ('Yes', 'No', 'ye@hot.com')";

$conn->query($Values);

$Show = "SELECT * FROM MyGuests";

$result = $conn->query($Show);



if ($result->num_rows > 0) {
  echo "<table><tr><th>ID</th><th>Name</th><th>Last Name</th><th>Email</th><th>Reg Date</th></tr>";
  // output data of each row
  while($row = $result->fetch_assoc()) {
    echo "<tr><td>".$row["id"]."</td><td>".$row["firstname"]."</td><td>".$row["lastname"]. "</td><td>". $row["email"]. "</td><td>". $row["reg_date"].  "</td></tr>";
  }
  echo "</table>";
} else {
  echo "0 results";
}

$conn->close();


?>
</body>
</html>
