<!DOCTYPE html>
<html>
<head>
    <title>Update a Product</title>
</head>
<body>
    <h2>Update A Product</h2>
    
    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        <label for="pid">Product ID:</label>
        <input type="number" id="pid" name="pid" required><br><br>
          
        <label for="pname">Product Name:</label>
        <input type="text" id="pname" name="pname" required><br><br>

        <label for="description">Description:</label>
        <input type="text" id="description" name="description" required><br><br>

        <label for="price">Price:</label>
        <input type="number" id="price" name="price" required><br><br>

        <label for="stock">Stock:</label>
        <input type="number" id="stock" name="stock" required><br><br>

        <input type="submit" value="Update Product">
        <a href="index.php">Cancel</a>
    </form>

    <?php

    require_once 'database.php';

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $pname = mysqli_real_escape_string($conn, $_POST['pname']);
        $description = mysqli_real_escape_string($conn, $_POST['description']);
        $price = mysqli_real_escape_string($conn, $_POST['price']); 
        $stock = mysqli_real_escape_string($conn, $_POST['stock']);
        $pid = mysqli_real_escape_string($conn, $_POST['pid']);

        $sql = "UPDATE Product SET pname=?, description=?, price=?, stock=? WHERE productid=?";
        $stmt = $conn->prepare($sql);

        if (is_numeric($_POST['price']) && is_numeric($_POST['stock'])) {
          // Convert to integer values
          $price = (int)$_POST['price'];
          $stock = (int)$_POST['stock'];

          if ($stmt) {
              $stmt->bind_param("ssdii", $pname, $description, $price, $stock, $pid);

              // Execute the statement
              if ($stmt->execute()) {
                  if ($stmt->affected_rows > 0) {
                      echo "Product updated successfully. Data has been updated in the Product table.";
                      $printSql = "UPDATE Product SET pname='$pname', description='$description', price=$price, stock=$stock WHERE productid=$pid";
                      echo "<pre>" . htmlentities($printSql) . "</pre>";
                  } else {
                      echo "No rows updated. Check if the provided Product ID exists.";
                  }
              } else {
                  echo "Execution failed: " . $stmt->error;
              }
          } else {
              echo "Error in preparing the statement: " . $conn->error;
          }
        }
        else {
          echo "Error: Price and Stock must be numeric values.";
        }
    }
?>
</body>
</html>
