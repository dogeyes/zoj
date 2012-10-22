import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        int count = 1;
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        while(n!=0)
        {
            HashMap<String, Integer> name = new HashMap<String, Integer>();
            int i;
            for(i = 0; i < n; ++i)
            {
                String s = new String();
                s = in.next();
                name.put(s, i);
            }
            int m;
            m = in.nextInt();
            double[][] map = new double[n][n];
            for(i = 0; i < n; ++i)
            {
                for(int j = 0; j < n; ++j)
                    map[i][j] = 0.0;
                map[i][i] = 1.0;
            }
            for(i = 0; i < m; ++i)
            {
                String s1 = new String();
                String s2 = new String();
                double rate;
                s1 = in.next();
                rate = in.nextDouble();
                s2 = in.next();
                map[name.get(s1)][name.get(s2)] = rate;
            }

            for(int k = 0; k < n; ++k)
                for(i = 0; i < n; ++i)
                {
                    for(int j = 0; j < n; ++j)
                    {
                        double  tmp = map[i][k] * map[k][j];
                        if(tmp > map[i][j])
                            map[i][j] = tmp;
                    }
                }
            System.out.print("Case " + count + ": ");
            for(i = 0; i < n; ++i)
                if(map[i][i] > 1.0)
                {
                    System.out.println("Yes");
                    break;
                }
            if(i == n)
                System.out.println("No");
            count++;
            n = in.nextInt();
        }
    }
}
