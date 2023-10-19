<!DOCTYPE html>
<html>
<head>
    <title>Time Greeting Form</title>
</head>
<body>
    <form action="" method="post">
        <label for="hour">Enter the hour: </label>
        <input type="number" name="hour" id="hour" min = 0 max = 23 required>
        <input type="submit" value="Submit">
    </form>

<?php
  include 'header.php';

  if ($_SERVER["REQUEST_METHOD"] == "POST") {
      if (isset($_POST["hour"])) {
          $hour = intval($_POST["hour"]);

          if ($hour < 10) {
              echo "Have a good morning!";
          } elseif ($hour < 18) {
              echo "Have a good day!";
          } elseif ($hour < 23) {
              echo "Good evening!";
          } else {
              echo "Switch off the computer!";
          }
      }
  }
?>
</body>
</html>

