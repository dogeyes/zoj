import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: dexctor
 * Date: 12-10-19
 * Time: 下午3:29
 * To change this template use File | Settings | File Templates.
 */
public class YukarisBirthday {
    public static int pow(int a, int b)
    {
        if(b == 0)
            return 1;
        if(b % 2 == 0)
            return pow(a * a, b / 2);
        else
            return a * pow(a, b -1);
    }
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        while(in.hasNextInt())
        {
            int minr, mink;
            int r, k;
            int n = in.nextInt() - 1;
            minr = n;
            mink = 2;
            k = 2;
            r = (int)(Math.log((n + 1)) / Math.log(2)) - 1;
            r = r + 1;
            while(r > 1)
            {
                int tmp = k * (pow(k, r) - 1) / (k - 1);
                if(tmp == n)
                {
                    if(k * r < minr * mink || (k * r == minr * mink && r < minr))
                    {
                        minr = r;
                        mink = k;
                    }
                    r--;
                    k++;
                }
                if(tmp > n)
                    r--;
                if(tmp < n)
                {
                    int tmpk =(int)Math.pow(n / 2 + 1, 1.0 / (double)r);
                    if(tmpk <= k)
                        k++;
                    else
                        k = tmpk;
                }
            }
            if(n < mink * minr)
            {
                mink = n;
                minr = 1;
            }
            System.out.println(minr + " " + mink);

        }
    }
}
