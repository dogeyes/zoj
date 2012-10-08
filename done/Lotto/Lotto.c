#include<stdio.h>

void dfs(int position, int *num, int n, int *r, int length)
{
	int i;
	if(length == 6)
	{
		for(i = 0 ; i < 5; ++i)
			printf("%d ", r[i]);
		printf("%d", r[i]);
		printf("\n");
		return;
	}
	if(position >= n)
		return;
	r[length++] = num[position++];
	dfs(position, num, n, r, length);
	length--;
	dfs(position, num, n, r, length);	
}
int main(void)
{
	int n;
	int num[49];
	int r[6];
	int length = 0;
	int flag = 0;
	scanf("%d", &n);
	while(n != 0)
	{
		int i;
		if(flag != 0)
			printf("\n");
		flag++;
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &num[i]);		
		}
		length = 0;
		dfs(0, num, n, r, length);
		scanf("%d", &n);
	}
	return 0;
}
