#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double absl(double a)
{
	return (a > 0)?a : -a;
}
int main(void)
{
	double precision = 0.5e-12;
	double data[2001];
	data[1000] = 1;
	data[2000] = 0.75;
	int i;
	double num;
	for(i = 0 ; i < 2001; ++i)
	{
		double x = i / 1000.0;
		if(i == 1000)
			continue;
		num = round(absl((1-x)*(2-x)) / 3.0 / precision);
		num = pow(num, 1.0/3.0) + 10;
		int j;
		double sum = data[1000] + (x - 1) * (data[2000] - data[1000]);
		for(j = 1; j <= num; j++)
			sum = sum + (1-x)*(2-x) / j/(j+1)/(j+2)/(j+x); 
		data[i] = sum;
		
	}
	for(i = 0; i < 2001; ++i)
	{
		printf("%5.3f %16.12f\n", i / 1000.0, data[i]);
	}
	return 0;
}
