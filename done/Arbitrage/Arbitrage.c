#include<stdio.h>
#include<string.h>

int main(void)
{
	int n;
	int count = 0;
	scanf("%d", &n);
	while(n != 0)
	{
		count++;
		char name[31][100];
		double map[31][31];
		int i;
		int j;
		for(i = 0 ; i < n; ++i)
			scanf("%s", name[i]);
		
		for(i = 0 ; i < n; ++i)
		{
			for(j = 0; j < n; ++j)
				map[i][j] = 0.0;
			map[i][i] = 1.0;
		}
		int m;
		scanf("%d", &m);
		for(j = 0; j < m; ++j)
		{
			char s1[100], s2[100];
			double rate;
			scanf("%s %lf %s", s1, &rate, s2);
			int n1, n2;
			for(n1 = 0; n1 < n; ++ n1)
				if(strcmp(name[n1], s1) == 0)
					break;
			for(n2 = 0; n2 < n; ++n2)
				if(strcmp(name[n2], s2) == 0)
					break;
			map[n1][n2] = rate;
		}
		int k;
		for(k = 0; k < n; ++k)
			for(i = 0; i < n; ++i)
				for(j = 0; j < n; ++j)
				{
					double tmp = map[i][k] * map[k][j];
					if(tmp > map[i][j])
						map[i][j] = tmp;
				}
		for(i = 0; i < n; ++i)
			if(map[i][i] > 1.0)
				break;
		printf("Case %d: ", count);
		if(i < n)
			printf("Yes\n");
		else
			printf("No\n");
		
		scanf("%d", &n);
	}
	return 0;
}
