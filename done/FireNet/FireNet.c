#include<stdio.h>

int max = 0;
int n;
void dfs(int, int, char[4][4], int);
int check(int x, int y, char map[4][4]);
int main(void)
{
	scanf("%d", &n);
	char map[4][4];
	while(n != 0)
	{
		int i;
		for(i = 0; i < n; i++)
			scanf("%s", map[i]);
		max = 0;
		dfs(0,0,map, 0);
		printf("%d\n", max);
		scanf("%d", &n);
	}
}
void dfs(int x, int y, char map[4][4], int num)
{
	if(x >= n)
		return;
	while(x < n && map[x][y] != '.')
	{
		y = y + 1;
		x = x + y / n;
		y = y % n;
	}
	if(x >= n)
		return;
	if(map[x][y] == '.')
	{
		if(check(x,y,map))
		{
			map[x][y] = 'o';
			num++;
			if(num > max)
				max = num;
			dfs(x + (y + 1) / n, (y + 1) % n, map, num);
			map[x][y] = '.';
			num--;
		}
		dfs(x + (y + 1) / n, (y + 1) % n, map, num);
	}
	
}
int check(int x, int y, char map[4][4])
{
	return up(x,y,map) && down(x,y,map) &&right(x,y,map) &&left(x,y,map);
}
int up(int x, int y, char map[4][4])
{
	if(x == 0)
		return 1;
	x--;
	while(x >=0 && map[x][y] == '.')
		x--;
	if(x < 0 || map[x][y] == 'X')
		return 1;
	return 0;
}
int down(int x, int y, char map[4][4])
{
	if(x == n)
		return 1;
	x++;
	while(x < n && map[x][y] == '.')
		x++;
	if(x >= n || map[x][y] == 'X')
		return 1;
	return 0;
}

int left(int x, int y, char map[4][4])
{
	if(y == 0)
		return 1;
	y--;
	while(y >=0 && map[x][y] == '.')
		y--;
	if(y < 0 || map[x][y] == 'X')
		return 1;
	return 0;
}
int right(int x, int y, char map[4][4])
{
	if(y == n)
		return 1;
	y++;
	while(y <n && map[x][y] == '.')
		y++;
	if(y >= n || map[x][y] == 'X')
		return 1;
	return 0;
}
