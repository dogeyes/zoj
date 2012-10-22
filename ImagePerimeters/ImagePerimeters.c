#include<stdio.h>

struct point{
	int x;
	int y;
};

struct point stack[500];
int head;
int dx[]= {0,0,1,-1,1,-1,1,-1};
int dy[]= {1,-1,0,0,1,-1,-1,1};

void push(struct point p)
{
	stack[head++] = p;
}
int isempty()
{
	return head == 0;
}
struct point pop()
{
	return stack[--head];		
}
int main(void)
{
	int n,m,x,y;
	int perimeters;
	int map[21][21];
	scanf("%d %d %d %d", &m, &n, &x, &y);
	while(n != 0)
	{
		int i,j;
		for(i = 0 ; i < m; ++i)
		{
			char s[20];
			scanf("%s", s);
			for(j = 0; j < n; ++j)
			{
				if(s[j] == '.')
					map[i][j] = 0;
				else
					map[i][j] = 1;	 	
			}
		}
		
		x--;
		y--;
		perimeters = 0;
		head = 0;
		struct point tmp;
		if(x >= 0 && x < m && y >= 0 && y < n && map[x][y] == 1)
		{
			tmp.x = x;
			tmp.y = y;
			map[x][y] = 2;
			push(tmp);
		}
		while(!isempty())
		{
			struct point now = pop();
			for(i = 0; i < 8; ++i)
			{
				int tmpx, tmpy;
				tmpx = now.x + dx[i];
				tmpy = now.y + dy[i];
				if(tmpx >= 0 && tmpx < m && tmpy >=0 && tmpy < n)
				{
					if(map[tmpx][tmpy] == 0 && i < 4)
						perimeters++;
					if(map[tmpx][tmpy] == 1)
					{
						map[tmpx][tmpy] = 2;
						tmp.x = tmpx;
						tmp.y = tmpy;
						push(tmp);
					}	
				}
				else
				{
					if(i < 4)
						perimeters++;
				}
			}
			
		}
		printf("%d\n", perimeters);
		scanf("%d %d %d %d", &m, &n, &x, &y);
	}
	return 0;
}
