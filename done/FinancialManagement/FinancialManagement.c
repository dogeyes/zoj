#include<stdio.h>

int main(void)
{
	int n = 12;
	int i;
	double sum = 0;
	double money;
	for(i = 0; i < n; ++i)
	{
		scanf("%lf", &money);
		sum += money;
	}
	printf("$%.2lf\n", sum / 12.0);
	return 0;
}
