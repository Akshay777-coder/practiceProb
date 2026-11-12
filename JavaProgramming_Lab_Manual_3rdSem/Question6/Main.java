// Write a multi-threaded Java application demonstrating both thread creation and synchronization:
// 1. Create Thread-1 (implementing Runnable) to print odd numbers from 1 to 20 and Thread-2 to print even numbers from 2 to 20.
// 2. Implement a shared 'PrinterResource' class with a synchronized method so that numbers are printed strictly in sequential 

class PrinterResource {
    private int nextNumber = 1;

    public synchronized void printOdd(int number) {
        try {
            while (nextNumber != number) {
                wait();
            }

            System.out.println("Thread-1 (Odd): " + number);
            nextNumber++;
            notifyAll();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    public synchronized void printEven(int number) {
        try {
            while (nextNumber != number) {
                wait();
            }

            System.out.println("Thread-2 (Even): " + number);
            nextNumber++;
            notifyAll();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }
}

class Thread_1 implements Runnable {
    private PrinterResource printer;

    public Thread_1(PrinterResource printer) {
        this.printer = printer;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 20; i += 2) {
            printer.printOdd(i);
        }
    }
}

class Thread_2 implements Runnable {
    private PrinterResource printer;

    public Thread_2(PrinterResource printer) {
        this.printer = printer;
    }

    @Override
    public void run() {
        for (int i = 2; i <= 20; i += 2) {
            printer.printEven(i);
        }
    }
}

public class Main {
    public static void main(String[] args) {
        PrinterResource printer = new PrinterResource();

        Thread thread_1 = new Thread(new Thread_1(printer));
        Thread thread_2 = new Thread(new Thread_2(printer));

        thread_1.start();
        thread_2.start();
    }
}