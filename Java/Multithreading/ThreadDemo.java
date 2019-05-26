
public class ThreadDemo {
    public static void main(String [] args) {
        new NewThread(); // Create a new thread
        new Child2();    // Create a new thread

        try {
            for (int i = 5; i > 0; --i) {
                System.out.println("Main Thread: " + i);
                Thread.sleep(1000);
            }
        }
        catch(InterruptedException e) {
            System.out.println("Main thread Interrupted.");
        }


    }
}
