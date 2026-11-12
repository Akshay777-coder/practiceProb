// Write a robust Java console program that processes user-supplied command-line arguments or console inputs to perform
// array element divisions while handling various standard runtime exceptions:
// Declare an integer array int[] numbers = {100, 200, 300, 400, 500} ;.
// Accept two inputs from the user:
// An index position k representing the element in the array to be divided.
// A divisor value d to divide numbers[k].
// 3. Enclose the processing inside a structured try block with specific, separate catch blocks for:
// O ArithmeticException (when divisor d = 0).
// ArrayIndexOutOfBoundsException (when index k < 0 or k ≥ numbers.length).
// o	NumberFormatException (when user enters a non-numeric string like "abc"). 
// o	A generalized Exception block to intercept any other unexpected runtime issues. 
// 4.	Implement a finally block that prints a mandatory cleanup status message, confirming that the input scanner/stream session has finished regardless of whether an exception occurred. 



import java.util.Scanner;

class Main {
    public static void main(String[] args) {

        int[] numbers = {100, 200, 300, 400, 500};
        Scanner sc = new Scanner(System.in);

        try {
            System.out.print("Enter array index (k): ");
            String input1 = sc.nextLine();

            System.out.print("Enter divisor (d): ");
            String input2 = sc.nextLine();

            int k = Integer.parseInt(input1);
            int d = Integer.parseInt(input2);

            int result = numbers[k] / d;

            System.out.println("Array Element: " + numbers[k]);
            System.out.println("Divisor: " + d);
            System.out.println("Result: " + result);
        }

        catch (ArithmeticException e) {
            System.out.println("Error: Division by zero is not allowed.");
        }

        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Error: Invalid array index.");
        }

        catch (NumberFormatException e) {
            System.out.println("Error: Please enter numeric values only.");
        }

        catch (Exception e) {
            System.out.println("Unexpected Error: " + e.getMessage());
        }

        finally {
            System.out.println("Cleanup: Input session finished.");
            sc.close();
        }
    }
}
