#include<stdio.h>

int up[5][5];
int down[5][5];
int right[5][5];
int left[5][5];
int map[5][5];
int n;
int use_x[5][5];
int use_y[5][5];

int check(int x, int y, int i, int j)
{
	int tmpi, tmpj;
	if(y > 0)
	{
		tmpi = use_x[x][y - 1];
		tmpj = use_y[x][y - 1];
		if(right[tmpi][tmpj] != left[i][j])
			return 0;	
	}
	if(x > 0)
	{
		tmpi = use_x[x - 1][y];
		tmpj = use_y[x - 1][y];
		if(down[tmpi][tmpj] != up[i][j])
			return 0;		
	}
	return 1;
}
int dfs(int x, int y)
{
	if(x >= n)
		return 1;
	
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0 ; j < n; j++)
		{
			if(map[i][j] == 0)
			{
				if(check(x, y, i, j))
				{
					map[i][j] = 1;
					use_x[x][y] = i;
					use_y[x][y] = j;
					if(dfs(x + (y + 1) / n, (y + 1) % n))
						return 1;
					map[i][j] = 0;
				}
			}
		}
	return 0;
}
int main(void)
{
	int flag = 0;
	scanf("%d", &n);
	while(n != 0)
	{
		flag++;
		int i, j;
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; ++j)
			{
				scanf("%d %d %d %d", &up[i][j], &right[i][j], &down[i][j], &left[i][j]);
				map[i][j] = 0;
			}
		if(flag != 1)
			printf("\n");
		printf("Game %d: ", flag);
		if(dfs(0, 0))
			printf("Possible\n");
		else
			printf("Impossible\n");
		scanf("%d", &n);
	}
	
	return 0;
}
