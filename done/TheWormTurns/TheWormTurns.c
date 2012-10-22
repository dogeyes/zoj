#include<stdio.h>

struct node{
	int x;
	int y;
	int pre_x;
	int pre_y;
};

int map[51][51];
struct node snake[20];
int n;
int go_snake(char c)
{
	int i;
	map[snake[19].x][snake[19].y] = 0;
	for(i = 19; i > 0; i--)
	{
		snake[i] = snake[i - 1];	
	}
	int headx,heady;
	switch(c)
	{
		case 'N': headx = snake[0].x - 1; heady = snake[0].y; break;
		case 'S': headx = snake[0].x + 1; heady = snake[0].y; break;
		case 'W': headx = snake[0].x; heady = snake[0].y - 1; break;
		case 'E': headx = snake[0].x; heady = snake[0].y + 1; break;
	}
	if(headx > 50 || headx < 1 || heady > 50 || heady < 1)
		return 1;
	if(map[headx][heady] == 1)
		return 2;
	map[headx][heady] = 1;
	snake[0].x = headx;
	snake[0].y = heady;
	snake[1].pre_x = headx;
	snake[1].pre_y = heady;
	return 0;
}

int main(void)
{
	scanf("%d", &n);
	while(n != 0)
	{
		int i, j;
		for(i = 1; i <= 50; ++i)
			for(j = 1; j <= 50; ++j)
				map[i][j] = 0;
		for(i = 0; i < 20 ; ++i)
		{
			snake[i].x = 25;
			snake[i].y = 30 - i;
			snake[i].pre_x = 25;
			snake[i].pre_y = 30 - i + 1;
			map[25][30-i] = 1;
		}
		char s[100];
		int flag;
		scanf("%s", s);
		for(i = 0; i < n; ++i)
		{
			flag = go_snake(s[i]);
			if(flag != 0)
				break;
		}
		if(flag == 0)
			printf("The worm successfully made all %d moves.\n", n);
		else if(flag == 1)
			printf("The worm ran off the board on move %d.\n", i + 1);
		else if(flag == 2)
			printf("The worm ran into itself on move %d.\n", i + 1);
			
		scanf("%d", &n);
	}
	return 0;
}
