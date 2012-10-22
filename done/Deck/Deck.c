#include<stdio.h>

int main(void)
{
	int n;
	printf("# Cards  Overhang\n");
	while(scanf("%d", &n) !=EOF)
	{
		double result = 0;
		int i;
		for(i = 1; i <=n; ++i)
			result += 1.0 / 2.0 / i;
			
		printf("%5d     %.3lf\n", n, result);	
	}
	
	return 0;
}
