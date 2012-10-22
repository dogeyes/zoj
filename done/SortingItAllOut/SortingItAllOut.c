#include<stdio.h>
#include<string.h>


int map[26][26];

void print_sequence(int n)
{
	int i, j;
	int seq[28];
	for(i = 0 ; i < n; ++i)
	{
		int sum = 0;
		for(j = 0 ; j < n; ++j)
		{
			if(map[i][j] != 0)
				sum++;
		}
		seq[n - 1 - sum] = i + 'A';
		
	}
	for(i = 0; i < n; ++i)
		printf("%c", seq[i]);
	printf(".\n");
}
int main(void)
{
	int n, m;
	int l1, l2;
	scanf("%d %d", &n, &m);
	while(n!= 0 || m != 0)
	{
		int i,j;
		int sum = 0;
		int flag = 0;
		int step = 0;
		char s[5];
		
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; ++j)
			map[i][j] = 0;
		for(i = 0; i < m; ++i)
		{
 			scanf("%s", s);
			int x, y;
			x = s[0] - 'A';
			y = s[2] - 'A';
			if(map[y][x] != 0)
			{
				flag = 2;
				step = i + 1;
				break;
			}
			if(map[x][y] == 0)
			{
				map[x][y] = 1;
				sum++;
				int i1, i2;
				for(i1 = 0 ; i1 < n; ++i1)
				{
					if(map[i1][x] != 0)
					{
						if(map[y][i1] == 1)
						{
							flag = 2;
							step = i + 1;
							break;
						}
						if(map[i1][y] == 0)
						{
							sum++;
							map[i1][y] = 1;
						}
					}
				}
				for(i2 = 0; i2 < n; ++i2)
				{
					if(map[y][i2] != 0)
					{
						if(map[i2][x] == 1)
						{
							flag = 2;
							step = i + 1;
							break;
						}
						if(map[x][i2] == 0)
						{
							sum++;
							map[x][i2] = 1;
						}
					}
				}
				for(i1 = 0; i1 < n; ++i1)
				{
					for(i2 = 0; i2 < n; ++i2)
					{
						if(map[i1][x] != 0 && map[y][i2] != 0)
						{
							if(map[i2][i1] != 0)
							{
								flag = 2;
								step = i + 1;
								break;
							}
							if(map[i1][i2] == 0)
							{
								sum ++;
								map[i1][i2] = 1;
							}
						}
					}
					if(flag == 2)
						break;
				}
			}
			if(flag == 2)
				break;	
			if(sum == n * (n - 1) / 2 && flag == 0)
			{
				flag = 1;
				step = i + 1;
				break;
			}		
			
			
/*
			for(l1 = 0; l1 < n; ++l1)
		 	{
	 			for(l2 = 0; l2 < n; ++l2)
	 			{
			 		printf("%d ", map[l1][l2]);
			 	}
			 	printf("\n");
		 	}*/
		 		
		}
/*
		for(l1 = 0; l1 < n; ++l1)
		 	{
	 			for(l2 = 0; l2 < n; ++l2)
	 			{
			 		printf("%d ", map[l1][l2]);
			 	}
			 	printf("\n");
		 	}*/
		for(i = i + 1; i < m; ++i)
		{
			scanf("%s", s);
		}
		
		switch(flag)
		{
			case 0: printf("Sorted sequence cannot be determined.\n");break;
			case 1: printf("Sorted sequence determined after %d relations: ", step);
					print_sequence(n);
					break;
			case 2: printf("Inconsistency found after %d relations.\n", step);
		}
		scanf("%d %d", &n, &m);	
	}	
	return 0;
}
