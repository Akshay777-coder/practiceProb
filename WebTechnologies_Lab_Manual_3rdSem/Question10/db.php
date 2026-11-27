// Question 10. PHP Database Connectivity: Write a PHP program to establish a connection with a MySQL database, create a student table, insert student records, and display the records on a webpage.

<?php
$servername = "localhost";
$username = "root";
$password = "";
$database = "college_db";

// Create Database Connection
$conn = new mysqli(
    $servername,
    $username,
    $password,
    $database
);

// Check Connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

echo "Database Connected Successfully<br>";
?>
