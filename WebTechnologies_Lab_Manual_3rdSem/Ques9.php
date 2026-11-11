<!-- 9. PHP Form Handling: Create an HTML student registration form and use PHP to receive and display the submitted student details using the POST method. -->

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Question 9</title>
</head>
<body>
    <h1>Student Registration</h1>
    <form action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']); ?>" method="POST">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required><br><br>
        <label for="email">Email:</label>
        <input type="email" id="email" name="email" required><br><br>
        <label for="age">Age:</label>
        <input type="number" id="age" name="age" required><br><br>
        <label for="course">Course:</label>
        <input type="text" id="course" name="course" required><br><br>
        <input type="submit" value="Register">
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] == 'POST') {
        $name = htmlspecialchars($_POST['name']);
        $email = htmlspecialchars($_POST['email']);
        $age = htmlspecialchars($_POST['age']);
        $course = htmlspecialchars($_POST['course']);

        echo '<h2>Registration Details</h2>';
        echo '<p>Name: ' . $name . '</p>';
        echo '<p>Email: ' . $email . '</p>';
        echo '<p>Age: ' . $age . '</p>';
        echo '<p>Course: ' . $course . '</p>';  
    }
    ?>
</body>
</html>