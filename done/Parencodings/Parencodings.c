#include<stdio.h>

void change(int *p, int *w, int n)
{
	int parenthese[43];
	int num_l;
	int i,pp = 0;
	i = 0; 
	num_l = 0;
	for(pp = 0; pp < n; ++pp)
	{
		while(num_l < p[pp])
		{
			parenthese[i++] = 1;
			num_l++;
		}
		parenthese[i++] = 2;
	}
	i = 0;
	for(pp = 0; pp < 2 * n; ++pp)
	{
		if(parenthese[pp] == 2)
		{
			int pr = 1;
			int re = 1;
			int j = pp - 1;
			while(pr > 0)
			{
				if(parenthese[j] == 2)
				{
					pr++;
					re++;
				}	
				if(parenthese[j] == 1)
					pr--;
					
				j--;
			}
			w[i++] = re;
		}
	}
}
int main(void)
{
	int l;
	int P[21];
	int W[21];
	scanf("%d", &l);
	int i;
	for(i = 0; i < l; ++i)
	{
		int n;
		scanf("%d", &n);
		int j;
		for(j = 0; j < n; ++j)
			scanf("%d", &P[j]);
		change(P,W,n);
		for(j = 0; j < n - 1; ++j)
		{
			printf("%d ", W[j]);
		}
		printf("%d\n", W[j]);
	}
}