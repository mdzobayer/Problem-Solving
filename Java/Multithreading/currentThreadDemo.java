public class currentThreadDemo{
    public static void main(String[] args) {
        Thread t = Thread.currentThread();

        System.out.println("\nCurrent thread : " + t + "\n");

        t.setName("My Thread");
        System.out.println("After name Change : " + t);

        try {
            for (int i = 5; i > 0; --i) {
                System.out.println(i);
                Thread.sleep(1000);
            }
        }
        catch (InterruptedException e) {
            System.out.println("Main thread interrupted.");
        }
    }
}
