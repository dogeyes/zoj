#include<stdio.h>

int map[100][100];

int get(int i, int j)
{
	if(i < 0 || j < 0)
		return 0;
	else
		return map[i][j];
}
int count(int i, int j)
{
	int tmp;
	tmp = get(i - 1, j) + get(i , j - 1) + get(i, j) - get(i-1, j-1);
	return tmp;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	int j;
	for(i = 0; i < n; ++i)
	{
		for(j = 0; j < n; ++j)
		{
			scanf("%d", &map[i][j]);
		}	
	}
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
		{
			map[i][j] = count(i,j);
		}
	
	int max = 0;
	int k;
	int l;
	for(i = 0; i < n; ++i)
		for(j = 0 ; j < n; ++j)
			for(k = 0 ; k < i; ++k)
				for(l = 0; l < j; ++l)
				{
					int tmp = get(i,j) - get(k-1, j) - get(i, l - 1) + get(k - 1, l - 1);
					if(tmp > max)
						max = tmp;
				}
	printf("%d\n", max);
	
	return 0;
}
