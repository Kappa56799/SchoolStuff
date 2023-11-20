<html>
<head>
    <title>Add Product</title>
</head>
<body>
    <h2>Add A Product</h2>
    
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


        $sql = "INSERT INTO Product (Pname, Description, Price, Stock) VALUES (?, ?, ?, ?)";

        $stmt = $conn->prepare($sql);

        $stmt->bind_param("ssdd", $pname, $description, $price, $stock);

        $pname = mysqli_real_escape_string($conn, $_POST['pname']);
        $description = mysqli_real_escape_string($conn, $_POST['description']);
        $price = mysqli_real_escape_string($conn, $_POST['price']);
        $stock = mysqli_real_escape_string($conn, $_POST['stock']);

        // Execute the statement
        if ($stmt->execute()) {
            echo "Product added successfully. Data has been added to the Product table.";
        } else {
            echo "Error: " . $sql . "<br>" . $stmt->error;
        }
        
    }
    ?>

    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        <label for="pname">Product Name:</label>
        <input type="text" id="pname" name="pname" required><br><br>

        <label for="description">Description:</label>
        <input type="text" id="description" name="description" required><br><br>

        <label for="price">Price:</label>
        <input type="number" id="price" name="price" required><br><br>

        <label for="stock">Stock:</label>
        <input type="number" id="stock" name="stock" required><br><br>

        <input type="submit" value="Add Product">
    </form>
</body>
</html>

