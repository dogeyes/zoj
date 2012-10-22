import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        int n;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        for(int i = 0; i < n; ++i)
        {
            if(i > 0)
                System.out.println();
            int m = in.nextInt();
            in.nextLine();
            for(int j = 0; j < m; ++j)
            {
                String s;
                s = in.nextLine();
                String[] strings = s.split(" ");
                for(int k = 0 ; k < strings.length; ++k)
                {
                    if(k > 0)
                        System.out.print(" ");
                    for(int l = strings[k].length() - 1; l >= 0; --l)
                        System.out.print(strings[k].charAt(l));
                }
                System.out.println();
            }
        }
    }
}
