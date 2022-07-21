
class Threads implements Runnable
{
    public void run()
    {
        System.out.println("Thread is implemented by Runnable.");
        System.out.println("Reyna\nSage\nJett\nValorant is life.");
    }
}
public class YourThread 
{
    public static void main(String args[])
    {
        Threading mt = new Threading();
        Thread t = new Thread(mt);
        t.start();

       
    }   
}