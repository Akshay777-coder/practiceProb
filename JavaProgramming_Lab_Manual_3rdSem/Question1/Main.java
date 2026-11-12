import java.util.Scanner;
import java.lang.Math;

class Solution {
    public boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public boolean isArmstrong(int n) {
        int originalNumber = n;
        int sum = 0;
        int numberOfDigits = String.valueOf(n).length();
        while (n > 0) {
            int digit = n % 10;
            sum += Math.pow(digit, numberOfDigits);
            n /= 10;
        }
        return sum == originalNumber;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a number: ");
        int number = scanner.nextInt();
        Solution solution = new Solution();
        if (solution.isPrime(number)) {
            System.out.println("number" + number + " is a prime number.");
        } else {
            System.out.println("number" + number + " is not a prime number.");
        }
        if (solution.isArmstrong(number)) {
            System.out.println("number" + number + " is an Armstrong number.");
        } else {
            System.out.println("number" + number + " is not an Armstrong number.");
        }
    }
}
