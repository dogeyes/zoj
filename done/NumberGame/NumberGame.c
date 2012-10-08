#include<stdio.h>

long win_p;
int know[3000000];
long dele_remain(long remain, int c)
{
	int i;
	for(i = 1; i <= (20 / c); ++i)
	{
		if((1 << (i*c)) > remain)
			break;
		remain = remain & ~(1 << (i * c));
	}
	for(i = 2; i < 21; ++i)
	{
		if(remain < (1 << i))
			break;
		if(!(remain & (1 << i)))
		{
			int j;
			for(j = 1; j <= (21 - i) /c; ++j)
				if((1 << (j * c + i)) <= remain)
					remain = remain & ~(1 << (j * c + i));
				else
					break;
		}
	}
	
/*	printf("dele %d: ", c);
	for(i = 2; i < 21; ++i)
	{
		if(remain & (1 << i))
			printf("%d ", i);
	}
	printf("\n");*/
	
	return remain;
}
int win_stat(long remain)
{
	long remain_copy;
	int i;
	if(remain == 0 || know[remain] == 2)
		return 0;
	else if(know[remain] == 1)
		return 1;
	for(i = 2; i < 21; ++i)
	{
		if((remain & (1 << i)))
		{
			remain_copy = remain;
			remain_copy = dele_remain(remain_copy, i);
			if(!win_stat(remain_copy))
			{
				know[remain] = 1;
				return 1;
			}
		}
	}
	know[remain] = 2;
	return 0;
}
void iteration(long remain)
{
	long remain_copy;
	int i;
	for(i = 2; i < 21; i++)
	{
		if(remain & (1 << i))
		{
			remain_copy = remain;
			remain_copy = dele_remain(remain_copy, i);
			if(win_stat(remain_copy))
				continue;
			else
			{
				win_p = win_p | (1 << i);
			}
		}

	}
}
int main(void)
{
	int n;
	int i;
	scanf("%d", &n);
	for(i = 0; i < 2100000; ++i)
		know[i] = 0;
	for(i = 0; i < n; ++i)
	{	
		long remain;
		int j;
		
		remain = 0;
		win_p = 0;
		int remain_num;
		scanf("%d", &remain_num);
		for(j = 0; j < remain_num; ++j)
		{
			int tmp;
			scanf("%d", &tmp);
			remain = remain | (1 << tmp);
		}
		iteration(remain);
		printf("Scenario #%d:\n", i + 1);
		if(win_p > 0)
		{
			printf("The winning moves are:");
			for(j = 0; j < 21; ++j)
				if(win_p & (1 << j))
					printf(" %d", j);
			printf(".\n\n");
		}
		else
			printf("There is no winning move.\n\n");
	}
	return 0;
}
