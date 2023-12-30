/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author ashwi
 */
class PrimeNumberFinder implements Runnable {
    private final int start;
    private final int end;

    public PrimeNumberFinder(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {
        System.out.print("Prime numbers from " + start + " to " + end + " : ");
        for (int i = start; i <= end; i++) {
            if (isPrime(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    private boolean isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i <= Math.sqrt(num); i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}

class PalindromeNumberFinder implements Runnable {
    private final int start;
    private final int end;

    public PalindromeNumberFinder(int start, int end) {
        this.start = start;
        this.end = end;
    }

    @Override
    public void run() {
        System.out.print("Palindrome numbers from " + start + " to " + end + " : ");
        for (int i = start; i <= end; i++) {
            if (isPalindrome(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }

    private boolean isPalindrome(int num) {
        int originalNum = num;
        int reversedNum = 0;

        while (num > 0) {
            int digit = num % 10;
            reversedNum = reversedNum * 10 + digit;
            num /= 10;
        }

        return originalNum == reversedNum;
    }
}

public class SequentialThreadExample {
    public static void main(String[] args) {
        // Create instances of the two Runnable classes
        PrimeNumberFinder primeFinder = new PrimeNumberFinder(0, 10);
        PalindromeNumberFinder palindromeFinder = new PalindromeNumberFinder(10, 50);

        // Create threads
        Thread t1 = new Thread(primeFinder);
        Thread t2 = new Thread(palindromeFinder);

        // Start threads sequentially
        t1.start();
        try {
            t1.join(); // Wait for t1 to finish before starting t2
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        t2.start();
    }
}

