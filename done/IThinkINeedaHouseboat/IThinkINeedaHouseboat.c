#include<stdio.h>
#include<math.h>

#define PI 3.1415926554
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	for(i = 0; i < n; ++i)
	{
		double x, y;
		scanf("%lf %lf", &x, &y);
		double r2 = x * x + y * y;
		double k = PI * r2 / 100;
		k = ceil(k);
		printf("Property %d: This property will begin eroding in year %.0lf.\n", i + 1, k);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
