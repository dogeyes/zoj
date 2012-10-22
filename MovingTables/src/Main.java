import java.util.LinkedList;
import java.util.Scanner;

class Table{
    public int start;
    public int end;
    public boolean flag;
}
public class Main {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int k;
        k = in.nextInt();
        while(k > 0)
        {
            int n = in.nextInt();
            int sum = 0;
            Table[] tables = new Table[205];
            for(int i = 0; i < n; ++i)
            {
                int a,b;
                a = in.nextInt();
                b = in.nextInt();
                if(a > b)
                {
                    int tmp = a;
                    a = b;
                    b =a;
                }
                tables[i] = new Table();
                tables[i].start = a;
                tables[i].end = b;
                tables[i].flag = false;
            }
            int count = 0;
            while(count < n)
            {
                int i = 0;
                while(tables[i].flag)
                    ++i;

                int end = tables[i].end;
                tables[i].flag = true;
                count++;
                i++;
                while(i < n)
                {
                    if(!tables[i].flag && (end + 1) / 2 * 2 < (tables[i].start + 1) / 2 * 2)
                    {
                        count++;
                        tables[i].flag = true;
                    }
                    i++;
                }
                sum++;
            }
            System.out.println(sum * 10);
            k--;
        }
    }
}
