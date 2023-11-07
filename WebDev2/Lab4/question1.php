<html>
<?php
include 'header.php';
$time = date("H");

if ($time < 10) {
  echo "Have a good morning!";
}
else if ($time < 20) {
  echo "Have a good day!";
} 
else {
  echo "Have a good night!";
}
?>
</html>
