#include<stdio.h>

struct point{
	double x;
	double y;
};

double line_point(struct point point1, struct point point2, struct point point3)
{	
	double tmp = ((point3.y-point1.y)*(point1.x-point2.x) - (point1.y-point2.y)*(point3.x-point1.x));
	if(tmp < 1e-5 && tmp > -1e-5)
		tmp = 0;
	return tmp;
}
int iscross(struct point point1, struct point point2, struct point point3, struct point point4)
{
	if(line_point(point1, point2, point3)* line_point(point1, point2, point4) < 0 &&
		line_point(point3, point4, point1)* line_point(point3, point4, point2) < 0)
			return 1;
	if(line_point(point1, point2, point3) == 0 && line_point(point1, point2, point4) == 0 &&
		line_point(point3, point4, point1) == 0 && line_point(point3, point4, point2) == 0)
			return 2;
	if(line_point(point1, point2, point3)* line_point(point1, point2, point4) == 0 || 
		line_point(point3, point4, point1)* line_point(point3, point4, point2) == 0)
			return 1;
	return 0;
}
int check(struct point* points, int n)
{
	if(n < 3)
		return 0;
	int i;
	int j;
	for(i = 0 ; i < n; ++i)
	{
		for(j = i + 1; j < n; ++j)
		{
			int flag;
			if(j - i == 1 && (j + 1)% n == i)
				flag = 1;
			else 
				flag = 0;
			
			if(flag)
				
		}	
	}
	return 1;
}

double caculate_tri(struct point point2, struct point point3)
{
	return (point2.x*point3.y-point2.y*point3.x) / 2.0;
}
double caculate_area(struct point* points, int n)
{
	double area = 0.0;
	int i;
	
	for(i = 0; i < n; ++i)
	{
		area += caculate_tri(points[i], points[(i + 1) % n]);		
	}
	return area>=0?area:-area;
}

int main(void)
{
	int n;
	int flag;
	double area;
	int count = 1;
	struct point points[1001];
	
	scanf("%d", &n);
	
	while(n != 0)
	{
		int i;
		for(i = 0 ; i < n; ++i)
		{
			scanf("%lf %lf", &(points[i].x), &(points[i].y));
		}
		flag = 0;
		if(count > 1)
			printf("\n");
		if(check(points, n))
			area = caculate_area(points, n);
		else
			flag = 1;
		if(flag)
			printf("Figure %d: Impossible\n", count);
		else
			printf("Figure %d: %.2lf\n", count, area);
		count++;
		scanf("%d", &n);	
	}
	return 0;
}
