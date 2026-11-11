<?php
include "db.php";

// Fetch all student records
$result = $conn->query("SELECT * FROM students");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Question 10</title>
    <style>
        body {
            font-family: Arial;
            margin: 40px;
        }

        input {
            padding: 8px;
            margin: 5px;
        }

        table {
            border-collapse: collapse;
            width: 100%;
            margin-top: 25%;
        }

        th, td {
            border: 1px solid black;
            padding: 10px;
            text-align: center;
        }

        th {
            background-color: lightblue;
        }
    </style>
</head>
<body>
    <h2>Student Registration</h2>

    <form action="insert.php" method="POST">

    <label>Name:</label>
    <input type="text" name="name" required>

    <label>Email:</label>
    <input type="email" name="email" required>

    <label>Course:</label>
    <input type="text" name="course" required>

    <label>Age:</label>
    <input type="number" name="age" required>

    <button type="submit">Add Student</button>

</form>

    <h2>Student Records</h2>

    <table>
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Email</th>
            <th>Course</th>
            <th>Age</th>
        </tr>

        <?php while ($row = $result->fetch_assoc()) {?>

        <tr>
            <td><?php echo htmlspecialchars($row['id']); ?></td>
            <td><?php echo htmlspecialchars($row['name']); ?></td>
            <td><?php echo htmlspecialchars($row['email']); ?></td>
            <td><?php echo htmlspecialchars($row['course']); ?></td>
            <td><?php echo htmlspecialchars($row['age']); ?></td>
        </tr>

        <?php } ?>
    </table>
</body>
</html>