/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author ashwi
 */
class MyRunnable implements Runnable {
    @Override
    public void run() {
        // Fetch the name of the current thread
        String threadName = Thread.currentThread().getName();
        System.out.println("Thread name: " + threadName);
    }
}

public class ThreadExample {
    public static void main(String[] args) {
        // Create an instance of the runnable class
        MyRunnable myRunnable = new MyRunnable();

        // Create two threads and pass the runnable instance
        Thread t1 = new Thread(myRunnable);
        Thread t2 = new Thread(myRunnable);

        // Start the threads
        t1.start();
        t2.start();
    }
}

