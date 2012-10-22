import java.util.Scanner;
public class Main {
    public static void main(String[] args)
    {
        Scanner in  = new Scanner(System.in);

        while(in.hasNext())
        {
            String s1 = in.next();
            String s2 = in.next();
            int[] result = new int[102];
            int c = 0;
            int p1, p2;
            p1 = s1.length() - 1;
            p2 = s2.length() - 1;
            int count = 0;
            while(p1 >= 0 || p2 >= 0)
            {
                c = c + c2n(s1, p1--) + c2n(s2, p2--);
                result[count++] = c % 20;
                c = c / 20;
            }
            if(c > 0)
                result[count++] = c;
            for(int i = count - 1; i >=0; --i)
                System.out.print(n2c(result[i]));
            System.out.println();
        }
    }
    public static int c2n(String s, int i)
    {
        if(i < 0)
            return 0;
        if(s.charAt(i) >= '0' && s.charAt(i) <= '9')
            return s.charAt(i) - '0';
        else
            return s.charAt(i) - 'a' + 10;
    }
    public static char n2c(int n)
    {
        if(n >= 0 && n <= 9)
            return (char)(n +'0');
        if(n >= 10 && n <= 19)
            return (char)('a' + n - 10);
        return '0';
    }
}
