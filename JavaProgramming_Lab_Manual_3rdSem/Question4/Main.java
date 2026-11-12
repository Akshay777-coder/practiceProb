// Create a base class 'Employee' with attributes empId, name, and basicSalary, and a method calculateNetSalary().
// 1. Derive two subclasses: 'PermanentEmployee' (adds HRA = 20%, DA = 50%, PF deduction = 12%) and 'ContractEmployee' (hourly rate × hours worked + fixed bonus).
// 2. Override calculateNetSalary() in both subclasses using the 'super' keyword.
// 3. Demonstrate Runtime Polymorphism (Dynamic Method Dispatch) using a base class reference variable.

class Employee {
    protected int empId;
    protected String name;
    protected double basicSalary;

    public Employee(int empId, String name, double basicSalary) {
        this.empId = empId;
        this.name = name;
        this.basicSalary = basicSalary;
    }

    public double calculateNetSalary() {
        return basicSalary; // Base implementation, can be overridden
    }
}

class PermanentEmployee extends Employee {
    public PermanentEmployee(int empId, String name, double basicSalary) {
        super(empId, name, basicSalary);
    }

    @Override
    public double calculateNetSalary() {
        double hra = 0.20 * basicSalary;
        double da = 0.50 * basicSalary;
        double pf = 0.12 * basicSalary;
        return basicSalary + hra + da - pf;
    }
}

class ContractEmployee extends Employee {
    private double hourlyRate;
    private int hoursWorked;
    private double fixedBonus;

    public ContractEmployee(int empId, String name, double basicSalary, double hourlyRate, int hoursWorked, double fixedBonus) {
        super(empId, name, basicSalary);
        this.hourlyRate = hourlyRate;
        this.hoursWorked = hoursWorked;
        this.fixedBonus = fixedBonus;
    }

    @Override
    public double calculateNetSalary() {
        return (hourlyRate * hoursWorked) + fixedBonus;
    }
}

public class Main {
    public static void main(String[] args) {
        Employee emp1 = new PermanentEmployee(101, "Alice", 50000);
        Employee emp2 = new ContractEmployee(102, "Bob", 0, 200, 160, 1000);
        System.out.println("Net Salary of " + emp1.name + ": " + emp1.calculateNetSalary());
        System.out.println("Net Salary of " + emp2.name + ": " + emp2.calculateNetSalary());
    }
}