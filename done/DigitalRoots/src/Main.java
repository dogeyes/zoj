import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        while(true)
        {
            String s = in.next();
            long n = 0;
            for(int i = 0; i < s.length(); ++i)
            {
                n = n + s.charAt(i) - '0';
            }
            if(n == 0)
                break;
            while(n >= 10)
            {
                long sum = 0;
                while(n > 0)
                {
                    sum = sum + n % 10;
                    n = n / 10;
                }
                n = sum;
            }
            System.out.println(n);
        }
    }
}
