<!DOCTYPE html>
<html>
<head>
    <title>Delete a Product</title>
</head>
<body>
    <h2>Delete A Product</h2>
    
    <?php
    require_once "database.php";
    $showForm = true;

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        if(isset($_POST['confirm_delete'])){
            $pid = mysqli_real_escape_string($conn, $_POST['confirm_delete']);
            $sql = "DELETE FROM Product WHERE productid=?";
            $stmt = $conn->prepare($sql);

            if ($stmt) {
                $stmt->bind_param("i", $pid);

                // Execute the statement
                if ($stmt->execute()) {
                    echo "Success";
                    $printSql = "DELETE FROM Product WHERE productid=$pid";
                    echo "<pre>" . htmlentities($printSql) . "</pre>";
                    echo "<a href=\"index.php\">-Continue</a>";
                    $showForm = false; // Hide form after deletion
                } else {
                    echo "Execution failed: " . $stmt->error;
                }
            } else {
                echo "Error in preparing the statement: " . $conn->error;
            }
        } else {
            $pid = mysqli_real_escape_string($conn, $_POST['pid']);
            $sql = "SELECT pname, productid FROM Product WHERE productid=?";
            $stmt = $conn->prepare($sql);

            if ($stmt) {
                $stmt->bind_param("i", $pid);

                // Execute the statement
                if ($stmt->execute()) {
                    $result = $stmt->get_result();

                    if ($result->num_rows > 0) {
                        echo "<form method='post' action='" . $_SERVER['PHP_SELF'] . "'>";
                        echo "<p>Confirm deleting:</p>";
                        while ($row = $result->fetch_assoc()) {
                            echo "<p>" . htmlentities($row["pname"]) . "</p>";
                            echo "<input type='hidden' name='confirm_delete' value='" . htmlentities($row["productid"]) . "'>";
                        }
                        echo "<input type='submit' value='Delete Product'>";
                        echo "<a href='index.php'>Cancel</a>";
                        echo "</form>";
                        $showForm = false; // Hide the initial form after showing confirmation
                    } else {
                        echo "No products found for the given ID.";
                    }
                } else {
                    echo "Execution failed: " . $stmt->error;
                }
            } else {
                echo "Error in preparing the statement: " . $conn->error;
            }
        }
    }
    ?>

    <?php if ($showForm): ?>
    <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
        <label for="pid">Product ID:</label>
        <input type="number" id="pid" name="pid" required><br><br>
        <input type="submit" value="Check Product">
    </form>
    <?php endif; ?>
</body>
</html>
