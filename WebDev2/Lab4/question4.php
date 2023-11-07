<!DOCTYPE html>
<html>
<head>
    <title>Number Form</title>
</head>
<body>
    <form action="" method="post">
        <label for="num">Enter an Integer: </label>
        <input type="number" name="num" id="num" required>
        <input type="submit" value="Submit">
    </form>

<?php
  include 'header.php';

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
      if (isset($_POST["num"])) {
        $num = intval($_POST["num"]);

        if ($num > 0) {
            for ($i = 1; $i <= $num; $i++) {
                echo "<p style='font-size: {$i}rem;'>Hello PHP!</p>";
            }
        } else {
            echo "Please enter a positive integer.";
        }

      }
  }
?>
</body>
</html>

