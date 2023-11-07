<html>
<body>
<?php

$a1 = true;
$condition1 = 5 < 6;
$condition2 = $a1 == false;
$condition3 = "123" === 123;

$result1 = $condition1 ? 'Condition 1 is true' : 'Condition 1 is false';
$result2 = $condition2 ? 'Condition 2 is true' : 'Condition 2 is false';
$result3 = $condition3 ? 'Condition 3 is true' : 'Condition 3 is false';

echo $result1 . "<br>";
echo $result2 . "<br>";
echo $result3 . "<br>";
?>
</body>
</html
