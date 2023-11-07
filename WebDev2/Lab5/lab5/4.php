<html>
<?php
function generateRandomPassword() {
    $allChars = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+';

    //Splits the string into an array
    $charArray = str_split($allChars);

    shuffle($charArray);
    
    //Converts it back to string
    $password = implode('', $charArray);

    return $password;
}

$randomPassword = generateRandomPassword();
echo $randomPassword;

?>
</html>

