
class Threading extends Thread
{
    public void run()
    {
        System.out.println("Thread is extended by Thread class.");
        System.out.println("Reyna\nSage\nJett\nValorant is life.");
    }
}
public class MyThread 
{
    public static void main(String args[])
    {
        Threading mt = new Threading();
        mt.start();
    }   
}