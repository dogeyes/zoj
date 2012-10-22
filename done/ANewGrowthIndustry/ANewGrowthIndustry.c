#include<stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int count = 0;
	while(n--)
	{
		count++;
		if(count > 1)
			printf("\n");
		int days;
		int D[18];
		int i;
		int j;
		int map[2][22][22];
		scanf("%d", &days);
		for(i = 0 ; i < 16; ++i)
			scanf("%d", &D[i]);
		
		for(i = 0 ; i < 20; ++i)
			for(j = 0 ; j < 20; ++j)
			{
				scanf("%d", &map[0][i][j]);
			}
		int sou = 0;
		int des = 1;
		while(days--)
		{
			for(i = 0; i < 20; ++i)
				for(j = 0; j < 20; ++j)
				{
					int sum = 0;
					sum += map[sou][i][j];
					if(i > 0)
						sum += map[sou][i-1][j];
					if(j > 0)
						sum += map[sou][i][j - 1];
					if(i < 19)
						sum += map[sou][i + 1][j];
					if(j < 19)
						sum += map[sou][i][j + 1];
					sum = D[sum] + map[sou][i][j];
					if(sum < 0)
						sum = 0;
					if(sum > 3)
						sum = 3;
					map[des][i][j] = sum;
				}
			int tmp;
			tmp = sou;
			sou = des;
			des = tmp;
		}	
		for(i = 0; i < 20; ++i)
		{
			for(j = 0; j < 20; ++j)
			{
				switch(map[sou][i][j])
				{
					case 0: printf(".");break;
					case 1: printf("!");break;
					case 2: printf("X");break;
					case 3: printf("#");break;
				}
			}
			printf("\n");
		}
		count++;
	}
	return 0;
}
