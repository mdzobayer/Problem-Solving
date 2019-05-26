public class Child2 implements Runnable {
    Thread t;

    Child2() {
        t = new Thread(this, "Child2 Thread");
        System.out.println("Child2 thread: " + t);
        t.start();
    }

    public void run () {
        try {
            for (int i = 5; i > 0; --i) {
                System.out.println("Child2 Thread: " + i);
                Thread.sleep(500);
            }
        }
        catch (InterruptedException e) {
            System.out.println("Child2 interrupted.");
        }
        System.out.println("Exiting Child2 thread.");
    }
}
