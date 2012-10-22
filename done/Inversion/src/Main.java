import java.util.Scanner;

public class Main {
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        int n;
        n = in.nextInt();
        while(n !=0)
        {
            int[] permu = new int[n + 1];
            char c = (in.next()).charAt(0);
            for(int i = 1; i <= n; ++i)
            {
                permu[i] = in.nextInt();
            }
            switch(c)
            {
                case 'P': permu2invers(permu, n);break;
                case 'I': invers2permu(permu, n);break;
            }

            n = in.nextInt();
        }
    }
    public static void permu2invers(int[] perm, int n)
    {
        int[] invers = new int[n + 1];

        for(int i = 1; i <= n; ++i)
        {
            int sum =0;
            for(int j = 1; j < i; ++j)
            {
                if(perm[j] > perm[i])
                    sum++;
            }
            invers[perm[i]] = sum;
        }
        printArray(invers, n);
    }
    public static void invers2permu(int[] invers, int n)
    {
        int[] permu = new int[n + 1];
        for(int i = 1; i <= n; ++i)
        {
            permu[i] = 0;
        }
        for(int i = 1; i <= n; ++i)
        {
            int j = 0;
            int count = 0;
            while(count <= invers[i])
            {
                j++;
                if(permu[j] == 0)
                    count++;
            }
            permu[j] = i;
        }
        printArray(permu, n);
    }
    public static void printArray(int[] A, int n)
    {
        int i;
        for(i = 1; i < n; ++i)
        {
            System.out.print(A[i] + " ");
        }
        System.out.println(A[i]);
    }
}
