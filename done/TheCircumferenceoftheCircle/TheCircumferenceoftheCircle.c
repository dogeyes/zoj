#include<stdio.h>

#define PI 3.141592653589793


int main(void)
{
	double x1, x2, x3, y1, y2, y3;
	while(scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF)
	{
		double a,b,c;
		double vx1,vy1,vx2,vy2,vx3,vy3;
		vx1 = x1 - x2;
		vy1 = y1 - y2;
		vx2 = x2 - x3;
		vy2 = y2 - y3;
		vx3 = x3 - x1;
		vy3 = y3 - y1;
		
		a = sqrt(vx1*vx1 + vy1*vy1);
		b = sqrt(vx2*vx2 + vy2*vy2);
		c = sqrt(vx3*vx3 + vy3*vy3);
		double ctheta = (vx1 * -vx3 + vy1 * -vy3) / a/c;
		double stheta = sqrt(1 - ctheta * ctheta);
		double s = a * c * stheta / 2;
		double r = a*b*c / s/4;
		printf("%.2lf\n", 2*PI*r);
	}
	return 0;
}
