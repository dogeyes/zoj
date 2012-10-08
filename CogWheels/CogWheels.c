#include<stdio.h>

int gcd(int a, int b)
{
	int c;
	while(b > 0)
	{
		c = a % b;
		a = b;
		b =c; 
	}
	return a;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	int num;
	int wheel[21];
	for(i = 0; i < n; ++i)
	{
		scanf("%d", &num);
		int j;
		for(j = 0; j < num; ++j)
			scanf("%d", &a[j]);
		int rnum;
		scanf("%d", &rnum);
		if(i > 0)
			printf("\n");
		printf("Scenario #%d:\n", i + 1);
		int k;
		for(k = 0; k <= rnum; ++k)
		{
			int a,b;
			scanf("%d %d", &a, &b);
			if(dfs(a,b,))
		}	
	}
	return 0;
		
}