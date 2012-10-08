#include<stdio.h>
int flaga = 0, flagb = 0, flagab = 0;
int iteration(long a, long b, int n);

int main(void)
{
	long a, b;
	while(scanf("%d%d", &a, &b) != EOF)
	{
		if(a < b)
		{
			long tmp = a;
			a = b;
			b = tmp;
		}
		flagab = 0;
		flagb = 0;
		flaga = 0;
		iteration(a, b, 2);
		if(flagab || (!flagb && flaga))
			printf("%d\n", a);
		else
			printf("%d\n", b);		
			
	}
	
	return 0;
}
int iteration(long a, long b, int n)
{
	if(a == 1)
	{
		flaga = 1;
	}
	if(b == 1)
	{
		flagb = 1;
	}
	if(a == 1 && b == 1)
	{
		flagab = 1;
		return 1;
	}
	if(n > 100)
		return 0;	
	
	while(a % n != 0 && b % n != 0 && n <= 100)
		++n;
	if(n > 100)
		return 0;
	
	if(a % n == 0)
	{
		if(iteration(a / n, b, n + 1))
			return 1;
	}
	if(b % n == 0)
	{
		if(iteration(a, b / n, n + 1))
			return 1;
	}
	
	if(iteration(a, b, n + 1))
		return 1;
		
	return 0;
}
