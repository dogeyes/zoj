#include<stdio.h>

struct box{
	int a;
	int b;
	int c;	
};

struct box boxs[100];
int len;

void swap(int* a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}
void put_boxs(int a, int b, int c)
{
	if(a < b)
		swap(&a, &b);
	if(b < c)
		swap(&b, &c);
	if(a < b)
		swap(&a, &b);
	boxs[len].a = a;
	boxs[len].b = b;
	boxs[len].c = c;
	len++;
	boxs[len].a = b;
	boxs[len].b = c;
	boxs[len].c = a;
	len++;
	boxs[len].a = a;
	boxs[len].b = c;
	boxs[len].c = b;
	len++;

}
int main(void)
{
	int n,i,j,k,max,flag;
	int map[100][100];
	flag = 1;
	scanf("%d", &n);
	while(n != 0)
	{
		len = 0;
		max = 0;
		boxs[len].a = 1000000;
		boxs[len].b = 1000000;
		boxs[len].c = 0;
		len++;
		for(i = 0 ; i < n; ++i)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			put_boxs(a,b,c);
		}
		for(i = 0; i < len; ++i)
			for(j = 0; j < len; ++j)
				map[i][j] = 0;
		
		for(i = 0; i < len; ++i)
			for(j = 0; j < len; ++j)
			{
				if(boxs[i].a > boxs[j].a && boxs[i].b > boxs[j].b)
				{
					map[i][j] = boxs[j].c;
					if(boxs[j].c > max)
						max = boxs[j].c;
				}
				
			}
		
		for(k = 0; k < len; ++k)
			for(i = 0 ; i < len; ++i)
				for(j = 0; j < len; ++j)
				{
					if(map[i][k] > 0 && map[k][j] > 0)
					{
						int tmp = map[i][k] + map[k][j];
						if(tmp > map[i][j])
							map[i][j] = tmp;
						if(tmp > max)
							max = tmp;
					}
				}
		
		printf("Case %d: maximum height = %d\n", flag, max);
		scanf("%d", &n);
		flag++;
	}
	return 0;
}
