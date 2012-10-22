#include<stdio.h>
#include<math.h>

int main(void)
{
	double a, b, c;
	int count = 1;
	scanf("%lf %lf %lf", &a, &b, &c);
	while(a!=0 || b!=0 || c != 0)
	{
		printf("Triangle #%d\n", count);
		
		if(a == -1)
		{
			if(c <= b)
				printf("Impossible.\n");
			else
				printf("a = %.3lf\n", sqrt(c * c - b * b));
		}
		if(b == -1)
		{
			if(c <= a)
				printf("Impossible.\n");
			else
				printf("b = %.3lf\n", sqrt(c * c - a * a));
		}
		if(c == -1)
		{
			printf("c = %.3lf\n", sqrt(a * a + b * b));
		}
		count++;
		printf("\n");
		scanf("%lf %lf %lf", &a, &b, &c);
	}
	
	return 0;
}
