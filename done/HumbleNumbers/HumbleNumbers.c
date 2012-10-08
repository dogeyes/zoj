#include<stdio.h>
void printhumble(int n, long hnum)
{
    printf("The %d", n);
    if(n % 10 == 1 && (n % 100 <10 || n % 100 > 20))
        printf("st");
        else
            if(n % 10 == 2 && (n % 100 < 10 || n % 100 >20))
                printf("nd");
            else 
                if(n % 10 == 3 && (n % 100 < 10 || n % 100> 20))
                    printf("rd");
                else
                    printf("th");
    
    printf(" humble number is %ld.\n", hnum);
}

int main(void)
{
	long humblenumbers[5843];
	int num = 1;
	humblenumbers[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1, p7 = 1;
	int n;
	long min;
	int pd;
    scanf("%d", &n);
	while(n != 0)
	{
		while(num < n)
		{
			min = 2 * humblenumbers[p2];
			pd = 2;
			if(min > 3 * humblenumbers[p3])
			{
				pd = 3;
				min = 3 * humblenumbers[p3];
			}
			if(min > 5 * humblenumbers[p5])
			{
				pd = 5;
				min = 5 * humblenumbers[p5];
			}
			if(min > 7 * humblenumbers[p7])
			{
				pd = 7;
				min = 7 * humblenumbers[p7];
			}
            if(min > humblenumbers[num])
                humblenumbers[++num] = min;
			switch(pd)
			{
				case 2: ++p2;break;
				case 3: ++p3;break;
				case 5: ++p5;break;
				case 7: ++p7;break;
			}
			
		}
        if(n <= num)
			printhumble(n, humblenumbers[n]);
        scanf("%d", &n);
	}
    return 0;
		
}

