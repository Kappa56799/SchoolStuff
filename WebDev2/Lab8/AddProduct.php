<!DOCTYPE html>
<html>
<head>
    <title>Add Product</title>
</head>
<body>
    <h2>Add A Product</h2>
    
    <?php
    require_once 'database.php';

    $showForm = true;

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $sql = "INSERT INTO Product (Pname, Description, Price, Stock) VALUES (?, ?, ?, ?)";

        $stmt = $conn->prepare($sql);

        $stmt->bind_param("ssdd", $pname, $description, $price, $stock);

        $pname = mysqli_real_escape_string($conn, $_POST['pname']);
        $description = mysqli_real_escape_string($conn, $_POST['description']);
        $price = mysqli_real_escape_string($conn, $_POST['price']);
        $stock = mysqli_real_escape_string($conn, $_POST['stock']);

        if (is_numeric($_POST['price']) && is_numeric($_POST['stock'])) {
            // Convert to integer values
            $price = (int)$_POST['price'];
            $stock = (int)$_POST['stock'];

            if ($stmt->execute()) {
                $printSql = "INSERT INTO Product (Pname, Description, Price, Stock) VALUES ($pname, $description, $price, $stock)";
                echo "<pre>" . htmlentities($printSql) . "</pre>";
                echo "Success";
                echo "<a href=\"index.php\">-Continue</a>";
                $showForm = false; // Hide the form after successful addition
            } else {
                echo "Error: " . $sql . "<br>" . $stmt->error;
            }
        } else {
            echo "Stock and Price must be numeric values.";
        }
    }
    ?>

    <?php if ($showForm): ?>
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
    <?php endif; ?>

</body>
</html>
