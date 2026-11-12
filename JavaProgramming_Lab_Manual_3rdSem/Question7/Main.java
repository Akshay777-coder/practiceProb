// KEY CONCEPTS: ArrayList, HashMap, Collections.sort(), Comparator/Lambda
// PROBLEM STATEMENT:
// Create a 'Student' class with fields: rollNo (int), name (String), and cgpa (double).
// 1. Store at least 5 Student objects in an ArrayList<Student> and sort them in descending order of CGPA using a custom Comparator.
// 2. Store student rollNo as key and Student object as value in a HashMap<Integer, Student> and demonstrate fast lookup by rollNo.
// 3. Iterate and display the sorted list and map entries using enhanced for-loop / EntrySet.

import java.util.ArrayList;
import java.util.HashMap;

class Student {
    private int rollNo;
    private String name;
    private double cgpa;

    public Student(int rollNo, String name, double cgpa) {
        this.rollNo = rollNo;
        this.name = name;
        this.cgpa = cgpa;
    }

    // Getters
    public int getRollNo() {
        return rollNo;
    }

    public String getName() {
        return name;
    }

    public double getCgpa() {
        return cgpa;
    }

    @Override
    public String toString() {
        return "Student{" +
                "rollNo=" + rollNo +
                ", name='" + name + '\'' +
                ", cgpa=" + cgpa +
                '}';
    }
}

public class Main {

    public static void main(String[] args) {
        Student student1 = new Student(101, "Alice", 3.8);
        Student student2 = new Student(102, "Bob", 3.5);
        Student student3 = new Student(103, "Charlie", 3.9);
        Student student4 = new Student(104, "David", 3.6);
        Student student5 = new Student(105, "Eve", 3.7);

        ArrayList<Student> studentList = new ArrayList<>();
        studentList.add(student1);
        studentList.add(student2);
        studentList.add(student3);
        studentList.add(student4);
        studentList.add(student5);

        // Sort students in descending order of CGPA
        studentList.sort((s1, s2) -> Double.compare(s2.getCgpa(), s1.getCgpa()));

        // Display sorted list
        System.out.println("Students sorted by CGPA (descending):");
        for (Student student : studentList) {
            System.out.println(student);
        }

        // Create HashMap with rollNo as key and Student object as value
        HashMap<Integer, Student> studentMap = new HashMap<>();
        studentMap.put(student1.getRollNo(), student1);
        studentMap.put(student2.getRollNo(), student2);
        studentMap.put(student3.getRollNo(), student3);
        studentMap.put(student4.getRollNo(), student4);
        studentMap.put(student5.getRollNo(), student5);

        // Demonstrate fast lookup by rollNo
        System.out.println("\nLookup by rollNo:");
        int searchRollNo = 103;
        Student foundStudent = studentMap.get(searchRollNo);
        if (foundStudent != null) {
            System.out.println("Student found: " + foundStudent);
        } else {
            System.out.println("Student with rollNo " + searchRollNo + " not found.");
        }
    }

}