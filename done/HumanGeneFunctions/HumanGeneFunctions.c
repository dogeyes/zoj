#include<stdio.h>
#include<string.h>

void str2num(char *s, int *g, int l)
{
	int i;
	for(i = 1; i <= l; ++i)
	{
		switch(s[i - 1])
		{
			case 'A':g[i] = 0;break;
			case 'C':g[i] = 1; break;
			case 'G':g[i] = 2; break;
			case 'T':g[i] = 3;break;
		}
	}
}
int main(void)
{
	int n;
	int i;
	int map[105][105];
	int score[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,-1000}};
	int g1[105];
	int g2[105];

	scanf("%d", &n);
	for(i = 0; i < n; ++i)
	{
		int l1,l2;
		int j,k;
		char s1[102];
		char s2[102];
		scanf("%d %s", &l1, s1);
		scanf("%d %s", &l2, s2);
		
		str2num(s1,g1,l1);
		str2num(s2,g2,l2);
		
		map[0][0] = 0;
		
		for(k = 1; k <= l2; ++k)
			map[0][k] = map[0][k - 1] + score[4][g2[k]];
		for(j = 1; j <= l1; ++j)
			map[j][0] = map[j - 1][0] + score[g1[j]][4];
		
		for(j = 1; j <= l1; ++j)
			for(k = 1; k <= l2; ++k)
			{
				int tmp;
				map[j][k] = map[j-1][k-1] + score[g1[j]][g2[k]];
				tmp = map[j-1][k] + score[g1[j]][4];
				if(tmp > map[j][k])
					map[j][k] = tmp;
				tmp = map[j][k-1] + score[4][g2[k]];
				if(tmp > map[j][k])
					map[j][k] = tmp;
			}
		printf("%d\n", map[l1][l2]);
/*		for(j = 0 ; j < l1; ++j)
		{
			for(k = 0; k < l2; ++k)
				printf("%-3d ", map[j][k]);
			printf("\n");
		}*/
							
	}
	return 0;
}
