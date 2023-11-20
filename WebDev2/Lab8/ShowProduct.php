
<html>
<body>
<?php

require_once "database.php";
$sqlProduct = "SELECT * FROM Product";
$resultProduct = $conn->query($sqlProduct);

echo "<h2>Product Table:</h2>";

// Check if there are results
if ($resultProduct->num_rows > 0) {
    // Output data in a table
    echo "<table border='1'>
            <tr>
                <th>Product ID</th>
                <th>Name</th>
                <th>Description</th>
                <th>Price</th>
                <th>Stock</th>
            </tr>";

    // Output data of each row
    while ($row = $resultProduct->fetch_assoc()) {
        echo "<tr>
                <td>" . $row["ProductId"] . "</td>
                <td>" . $row["Pname"] . "</td>
                <td>" . $row["Description"] . "</td>
                <td>" . $row["Price"] . "</td>
                <td>" . $row["Stock"] . "</td>
              </tr>";
    }

    echo "</table>";
} else {
    echo "0 results";
}

$conn->close();
?>
</body>
</html>

