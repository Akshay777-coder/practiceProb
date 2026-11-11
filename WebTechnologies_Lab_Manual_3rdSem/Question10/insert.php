<?php
include "db.php";

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $email = $_POST['email'];
    $course = $_POST['course'];
    $age = $_POST['age'];

    // Prepare SQL Statement
    $sql = $conn->prepare(
        "INSERT INTO students (name, email, course, age) VALUES (?, ?, ?, ?)"
    );

    $sql->bind_param("sssi", $name, $email, $course, $age);

    if ($sql->execute()) {
        echo "Student record inserted successfully!";
        echo "<br><a href='index.php'>Go Back</a>";
    } else {
        echo "Error: " . $sql->error;
    }

    $sql->close();
}

$conn->close();
?>