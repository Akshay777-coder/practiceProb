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