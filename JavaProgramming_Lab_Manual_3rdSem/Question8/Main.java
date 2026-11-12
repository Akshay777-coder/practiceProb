// Design and implement an interactive, menu-driven Automated Teller Machine (ATM) and Transaction Terminal in Java using switch statements: 
// 1.	Prompt the user for an initial account balance and present a menu with options:
// o	Case 1: Check Current Balance
// o	Case 2: Deposit Amount
// o	Case 3: Withdraw Amount (enforce a daily withdrawal limit of Rs. 20,000 and ensure the account cannot be overdrawn)
// o	Case 4: Currency Denomination Calculator (accept an amount and compute the minimum number of notes for Rs. 500, Rs. 200, and Rs. 100 using a switch/fall-through design)
// o	Case 5: Exit Session
// 2.	Implement the outer operation selector using a standard switch construct with appropriate break statements and a default handler for invalid inputs. 
// 3.	Demonstrate the use of both primitive (int/char) and String based switch-case evaluation where applicable.

class ATM {
    private double balance;
    private static final double DAILY_WITHDRAWAL_LIMIT = 20000.0;

    public ATM(double initialBalance) {
        this.balance = initialBalance;
    }

    public void checkBalance() {
        System.out.println("Current Balance: Rs. " + balance);
    }

    public void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            System.out.println("Deposited: Rs. " + amount);
        } else {
            System.out.println("Invalid deposit amount.");
        }
    }

    public void withdraw(double amount) {
        if (amount > DAILY_WITHDRAWAL_LIMIT) {
            System.out.println("Withdrawal amount exceeds daily limit of Rs. 20,000.");
        } else if (amount > balance) {
            System.out.println("Insufficient funds. Cannot withdraw Rs. " + amount);
        } else if (amount <= 0) {
            System.out.println("Invalid withdrawal amount.");
        } else {
            balance -= amount;
            System.out.println("Withdrawn: Rs. " + amount);
        }
    }

    public void currencyDenominationCalculator(int amount) {
        int remainingAmount = amount;
        int notes500 = 0, notes200 = 0, notes100 = 0;

        switch (remainingAmount / 500) {
            case 1:
                notes500 = remainingAmount / 500;
                remainingAmount %= 500;
                // fall through
            case 2:
                notes200 = remainingAmount / 200;
                remainingAmount %= 200;
                // fall through
            case 3:
                notes100 = remainingAmount / 100;
                remainingAmount %= 100;
                break;
            default:
                break;
        }

        System.out.println("Currency Denominations for Rs. " + amount + ":");
        System.out.println("Rs. 500 notes: " + notes500);
        System.out.println("Rs. 200 notes: " + notes200);
        System.out.println("Rs. 100 notes: " + notes100);
    }
}

public class Main {
    public static void main(String[] args) {
        ATM atm = new ATM(10000.0); // Initialize with Rs. 10,000
        // Implementation of the ATM and Transaction Terminal goes here
        atm.checkBalance();
        atm.deposit(5000.0);
        atm.withdraw(15000.0);
        atm.currencyDenominationCalculator(15000);
    }
}