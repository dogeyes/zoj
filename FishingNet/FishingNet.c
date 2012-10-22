#include<stdio.h>

int map[1001][1001];
int min[1001][1001];

int main(void)
{
	int n,m;
	
	scanf("%d %d", &n, &m);
	while(n != 0 || m != 0)
	{
		int x, y;
		int i,j,k;
		for(i = 0; i < n; ++i)
			for( j = 0; j < n; ++j)
			{
				map[i][j] = 2000;
				min[i][j] = 2000;
			}
		for(i = 0 ; i < m; ++i)
		{
			scanf("%d %d", &x, &y);
			x--;
			y--;
			map[x][y] = 1;
			map[y][x] = 1;
		}
		int tmp;
		for(k = 0; k < n; ++k)
			for(i = 0; i < n; ++i)
				for(j = 0; j < n; ++j)
				{
					if(i != j && j != k && i != k)
					{
						tmp = map[i][k] + map[k][j];
						if(tmp < min[i][j])
						{
							min[i][j] = tmp;
							min[j][i] = tmp;		
						}
						else
						{
							tmp = min[i][k] + min[k][j];
							if(tmp < min[i][j])
							{
								min[i][j] = tmp;
								min[j][i] = tmp;
							}
						}
					}
				}
		
		int flag = 0;
		for(i = 0; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
			{
				if(map[i][j] == 1 && min[i][j] != 2)
				{
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}
		
		if(flag)
			printf("Imperfect\n\n");
		else
			printf("Perfect\n\n");	
		scanf("%d %d", &n, &m);
	}
	return 0;
	
}
