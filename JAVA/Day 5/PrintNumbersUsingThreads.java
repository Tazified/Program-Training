/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author ashwi
 */
class PrintNumbers implements Runnable {
    private static final Object lock = new Object();
    private static int currentNumber = 1;
    private final int maxNumber;

    public PrintNumbers(int maxNumber) {
        this.maxNumber = maxNumber;
    }

    @Override
    public void run() {
        while (currentNumber <= maxNumber) {
            synchronized (lock) {
                // Check if it's the thread's turn to print
                if (currentNumber <= maxNumber) {
                    // Print the current number and increment it
                    System.out.println(Thread.currentThread().getName() + ": " + currentNumber++);
                }
            }
        }
    }
}

public class PrintNumbersUsingThreads {
    public static void main(String[] args) {
        int N = 18;

        // Create two threads and pass the same instance of PrintNumbers
        PrintNumbers printNumbers = new PrintNumbers(N);
        Thread t1 = new Thread(printNumbers, "Thread-1");
        Thread t2 = new Thread(printNumbers, "Thread-2");

        // Start the threads
        t1.start();
        t2.start();
    }
}


