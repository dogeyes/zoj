#include<stdio.h>

int main(void)
{
	double hangover;
	double hangs[20000];
	hangs[1] = 0.5;
	long n = 1;
	scanf("%lf", &hangover);
	while(hangover > 0.0001)
	{
		int i = 1;
		while(hangover > hangs[i])
		{
			if(i >= n)
			{
				hangs[i + 1] = hangs[i] + 1.0 / (i + 2);
				n++;
			}
			i++;
		}
		printf("%d card(s)\n", i);
		scanf("%lf", &hangover);
	}
	
	return 0;
}
