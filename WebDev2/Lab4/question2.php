<html>
<?php
include 'header.php';

//while loop
echo "While loop:<br>";
$num = 0;

while ($num < 41) {
  $num += 5;
  echo $num . " ";
}

//do while loop
$num = 0;
echo "<br><br>Do While loop:<br>";

do {
  $num += 5;
  echo $num . " ";

}while ($num < 41);


//foreach loop
$programmingLanguagesArray = ["PHP", "C++", "C#", "Python", "Java"];

echo "<br><br>Using foreach loop:<br>";
foreach ($programmingLanguagesArray as $language) {
  echo $language . " ";
}

echo "<br><br>";

echo "Using Array Iterator:<br>";
$iterator = new ArrayIterator($programmingLanguagesArray);
while ($iterator->valid()) {
    echo $iterator->current() . " ";
    $iterator->next();
}

?>

</html>
