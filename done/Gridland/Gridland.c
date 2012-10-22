#include<stdio.h>
#include<math.h>

void swap(int *a, int* b)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
}
int main(void)
{
	int l;
	scanf("%d", &l);
	int i;
	for(i = 0; i < l; ++i)
	{
		int m,n;
		double result;
		scanf("%d %d", &m, &n);
		
		if(n % 2 == 0)
			swap(&m,&n);
		if(m % 2 == 0)
			result = (m - 2) * (n - 2)  + 2 * (n - 1) + 2 * (m - 1);
		else	
			result = (m - 3) * (n - 2) + n - 2 + 2 * (m - 1) + 2 * (n - 1) -1 + sqrt(2);
		printf("Scenario #%d:\n%.2lf\n\n", i + 1, result);
				
	}
	
	return 0;
}
