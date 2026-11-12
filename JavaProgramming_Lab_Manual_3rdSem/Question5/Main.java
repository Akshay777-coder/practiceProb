// KEY CONCEPTS: abstract keyword, interface implementation, multiple interfaces
// PROBLEM STATEMENT:
// Design an abstract class 'Shape' containing an abstract method calculateArea() and a concrete method displayShapeType().
// 1. Create two interfaces: 'Scalable' (method resize(double factor)) and 'Drawable' (method draw()).
// 2. Implement subclasses 'Circle' and 'Rectangle' that extend 'Shape' and implement both 'Scalable' and 'Drawable'.
// 3. Write a test program to compute areas before and after scaling by a factor of 1.5.

interface Scalable {
    void resize(double factor);
}

interface Drawable {
    void draw();
}

abstract class Shape {
    abstract double calculateArea();

    void displayShapeType() {
        System.out.println("This is a shape.");
    }
}

class Circle extends Shape implements Scalable, Drawable {
    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.round(Math.PI * radius * radius);
    }

    @Override
    public void resize(double factor) {
        radius *= factor;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a circle.");
    }
}

class Rectangle extends Shape implements Scalable, Drawable {
    private double width;
    private double height;

    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override 
    public double calculateArea() {
        return Math.round(width * height);
    }

    @Override
    public void resize(double factor) {
        width *= factor;
        height *= factor;
    }

    @Override
    public void draw() {
        System.out.println("Drawing a rectangle.");    }
}

public class Main {
    public static void main(String[] args) {
        Circle circle = new Circle(5);
        Rectangle rectangle = new Rectangle(4, 6);
        System.out.println("Circle area before scaling: " + circle.calculateArea());
        System.out.println("Rectangle area before scaling: " + rectangle.calculateArea());
        System.out.println("Scaling shapes by a factor of 1.5...");
        circle.resize(1.5);
        rectangle.resize(1.5);
        System.out.println("Circle area after scaling: " + circle.calculateArea());
        System.out.println("Rectangle area after scaling: " + rectangle.calculateArea());
        circle.draw();
        rectangle.draw();
    }
}