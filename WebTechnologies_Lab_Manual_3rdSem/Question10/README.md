##Step 1: Start XAMPP##

1. Open XAMPP Control Panel.
2. Click Start beside Apache.
3. Click Start beside MySQL.
4. Both services should show a running status.

Now open your browser and visit:
- PHP server: http://localhost/
- Database manager: http://localhost/phpmyadmin/


Step 2: Create a database
- Open phpMyAdmin.

1. Click New on the left sidebar.
2. Enter database name: college_db
3. Click Create.
- Now your database is ready.


Step 3: Create a student table
- Select the college_db database.
- Click the SQL tab and execute this query:

CREATE TABLE students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    course VARCHAR(100) NOT NULL,
    age INT NOT NULL
);

- This creates a table with five columns:
Column	Purpose
id	Unique student ID
name	Student name
email	Student email
course	Course name
age	Student age

Step 4: Create your project folder
- Go to: C:\xampp\htdocs\
- Create a new folder: StudentManagement
- Inside it, create these three PHP files:
StudentManagement/
│
├── db.php
├── index.php
└── insert.php

You can create and edit these files using VS Code.
