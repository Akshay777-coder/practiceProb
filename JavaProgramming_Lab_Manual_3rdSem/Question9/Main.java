// Design and implement a 3-level class hierarchy in Java to demonstrate Multilevel Inheritance using a university student domain:
// 1.	Base Class (Person):
// o	Data members: name (String) and age (int).
// o	Methods: A parameterized constructor and displayPersonInfo() to print the person's name and age.
// 2.	Intermediate Class (Student):
// o	Extends Person.
// o	Additional data members: rollNumber (int) and course (String).
// o	Methods: A parameterized constructor calling super(...) and displayStudentInfo() to print roll number and course.
// 3.	Derived Class (Result):
// o	Extends Student.
// o	Additional data members: marks1 (double), marks2 (double), and marks3 (double).
// o	Methods: calculateTotal(), calculatePercentage(), and displayResultCard() to print the complete student academic report.
// 4.	In the main() method of the driver class, instantiate a Result object and show that it successfully accesses all methods and properties across the entire inheritance chain.


class Person {
    protected String name;
    protected int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void displayPersonInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

class Student extends Person {
    protected int rollNumber;
    protected String course;

    public Student(String name, int age, int rollNumber, String course) {
        super(name, age);
        this.rollNumber = rollNumber;
        this.course = course;
    }

    public void displayStudentInfo() {
        System.out.println("Roll Number: " + rollNumber);
        System.out.println("Course: " + course);
    }
}

class Result extends Student {
    protected double marks1, marks2, marks3;

    public Result(String name, int age, int rollNumber,
                  String course, double marks1,
                  double marks2, double marks3) {

        super(name, age, rollNumber, course);
        this.marks1 = marks1;
        this.marks2 = marks2;
        this.marks3 = marks3;
    }

    public double calculateTotal() {
        return marks1 + marks2 + marks3;
    }

    public double calculatePercentage() {
        return calculateTotal() / 3;
    }

    public void displayResultCard() {
        System.out.println("\n===== STUDENT RESULT CARD =====");

        displayPersonInfo();
        displayStudentInfo();

        System.out.println("Marks 1: " + marks1);
        System.out.println("Marks 2: " + marks2);
        System.out.println("Marks 3: " + marks3);

        System.out.println("Total Marks: " + calculateTotal());
        System.out.println("Percentage: " + calculatePercentage() + "%");
    }
}

class Main {
    public static void main(String[] args) {

        Result student = new Result(
            "Akshay", 20, 101, "BCA",
            85, 90, 95
        );

        student.displayResultCard();
    }
}
