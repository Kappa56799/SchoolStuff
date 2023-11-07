<html>
<?php
$lab5_1_path = 'lab5.1.txt';
$lab5_2_path = 'lab5.2.txt';

$lab5_1_content = file_get_contents($lab5_1_path);

echo "<h3>Content of $lab5_1_path:</h3>";
echo "<pre>$lab5_1_content</pre>";

$lab5_2_content = file_get_contents($lab5_2_path);

$combined_content = $lab5_1_content . $lab5_2_content;

echo "<h3>Combined Content:</h3>";
echo "<pre>$combined_content</pre>";
?>

</html>
