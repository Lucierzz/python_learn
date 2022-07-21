class MyThread extends Thread
{
    MyThread(String name)
    {
        super(name);
    }

    public void run()
    {
        int [] arr = new int [] {3,6,3,6,0,0,1,4,4};
        int sum = 0;
        //Loop through the array to calculate sum of elements
        System.out.println("hello guys!!");

        for (int i = 0; i < arr.length; i++)
        {
            sum = sum + arr[i];

            try{
                sleep(100);
            }
            catch(InterruptedException e)
            {
                e.printStackTrace();
            }
        }
        System.out.println("Sum of all the elements: " + sum);

    }
}

public class Opp
{
    public static void main(String[] args)
    {
        MyThread Assign10_202051155 = new MyThread("My Thread");
        Assign10_202051155.start();
          System.out.println("The function is running.");
    }
}