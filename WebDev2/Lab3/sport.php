<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <style>
        .container {
            display: flex;
            align-items: center;
        }

        .container label {
            width: 100px;
        }
    </style>
</head>
<body>
    <h1>Sport Club Feedback Form</h1>
    <p>Please fill out this form to let us know what you think</p>
    
    <form>
        <div class="container">
            <label for="name">Full Name:</label>
            <input type="text" id="name" name="name">
        </div>
        <br>
        <div class="container">
            <label for="email">Email:</label>
            <input type="text" id="Email" name="Email">
        </div>

        <h4>Which sports do you enjoy most?</h4>
        <label for="Swimming"> Swimming</label>
        <input type="checkbox" id="Swimming" value="swimming">
        <label for="Football"> Football</label>
        <input type="checkbox" id="Football" value="football">
        <label for="Tennis"> Tennis</label>
        <input type="checkbox" id="Tennis" value="tennis">
        <br>
        <label for="Snooker">Snooker</label>
        <input type="checkbox" id="Snooker" value="snooker">
        <label for="Golf"> Golf</label>
        <input type="checkbox" id="Golf" value="golf">

        <h4>How long have you been a member of the club?</h4>
        <label for="less-than-year">Less than a year</label>
        <input type="radio" id="less-than-year" name="membership" value="Less than a year">
        <label for="one-to-two-years">One to two years</label>
        <input type="radio" id="one-to-two-years" name="membership" value="One to two years">
        <label for="more-than-two-years">More than two years</label>
        <input type="radio" id="more-than-two-years" name="membership" value="More than two years">

        <h4>Please give us any additional feedback you may have</h4>
        <label for="Feedback">Comments:</label>
        <textarea id="Feedback" name="Feedback" rows="8" cols="50">
        </textarea>

        <br>

        <button type="button">Submit</button>
        <button type="button">Reset</button>

        </form>
</body>
</html>
