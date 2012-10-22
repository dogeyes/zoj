#include<stdio.h>

struct node{
	int up;
	int down;
	int left;
	int right;
	int num;
};

int n;
struct node mats[30];
int len;
int map[6][6];

void put_mats(int up, int right, int down, int left)
{
	int i;
	for(i = 0 ; i < len; ++i)
	{
		if(mats[i].right == right && mats[i].left == left && mats[i].down == down && mats[i].up == up)
		{
			mats[i].num++;
			break;
		}
	}
	if(i >= len)
	{
		mats[len].right = right;
		mats[len].left = left;
		mats[len].up = up;
		mats[len].down = down;
		mats[len].num = 1;
		len++;
	}
}
int check(struct node p, int i , int j)
{
	if(i > 0)
		if(p.up != mats[map[i-1][j]].down)
			return 0;
	
	if(j > 0)
		if(p.left != mats[map[i][j - 1]].right)
			return 0;
	
	return 1;	
}
int dfs(int i, int j)
{
	if(i >= n)
		return 1;
	int k;
	for(k = 0 ; k < len; ++k)
	{
		if(mats[k].num > 0 && check(mats[k], i, j))
		{
			map[i][j] = k;
			mats[k].num--;
			if(dfs(i + (j + 1) / n, (j + 1) % n))
				return 1;
			mats[k].num++;
		}
	}
	return 0;
}
int main(void)
{
	int i;
	int flag =0;
	scanf("%d", &n);
	while(n != 0)
	{
		len = 0;
		for(i = 0 ; i < n * n; ++i)
		{
			int up, down, right, left;
			scanf("%d %d %d %d", &up, &right, &down, &left);
			put_mats(up, right, down, left);
		}
		if(flag > 0)
			printf("\n");
		printf("Game %d: ", flag + 1);
		if(dfs(0,0))
			printf("Possible\n");
		else
			printf("Impossible\n");
		scanf("%d", &n);
		flag++;
	}
	
	return 0;
}
