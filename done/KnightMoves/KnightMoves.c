#include<stdio.h>
#include<string.h>

int x_seq[64];
int y_seq[64];
int length;
int map[8][8];
const x_step[8] = {1,-1,2,-2,-1,1,2,-2};
const y_step[8] = {2,-2,1,-1,2,-2,-1,1};

int bfs(int x1, int y1, int x2, int y2)
{
	int tmpx, tmpy;
	int p;
	map[x1][y1] = 1;
	x_seq[length] = x1;
	y_seq[length] = y1;
	if(x1 == x2 && y1 == y2)
		return 1;
	length++;
	p = 0;
	while(p < length)
	{
		tmpx = x_seq[p];
		tmpy = y_seq[p];
		p++;
		int nx,ny;
		int i, j;
		for(i = 0; i < 8; ++i)
		{
			nx = tmpx + x_step[i];
			ny = tmpy + y_step[i];
			if(nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && map[nx][ny] == 0)
			{
				x_seq[length] = nx;
				y_seq[length] = ny;
				length++;
				map[nx][ny] = map[tmpx][tmpy] + 1;
				if(nx == x2 && ny == y2)
					return map[nx][ny];
			}
		}
	}
}

int main(void)
{
	char s1[5];
	char s2[5];
	while(scanf("%s", &s1) != EOF)
	{
		int x1, y1, x2, y2;
		x1 = s1[0] - 'a';
		y1 = s1[1] - '1';
		scanf("%s2", &s2);
		x2 = s2[0] - 'a';
		y2 = s2[1] - '1';
		length = 0;
		int i,j;
		for(i = 0; i < 8; ++i)
			for(j = 0; j < 8; ++j)
				map[i][j] = 0;
		
		int n_move = bfs(x1,y1,x2,y2);
		printf("To get from %s to %s takes %d knight moves.\n", s1, s2, n_move - 1);
	}
	
	return 0;
}
