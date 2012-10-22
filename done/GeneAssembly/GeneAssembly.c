#include<stdio.h>

struct exon{
	int start;
	int end;
	int length;
	int previous;
	int index;
};

void sort(struct exon *exons, int n)
{
	int i;
	int j;
	for(i = 1 ; i <= n; ++i)
		for( j = i + 1; j <= n; ++j)
		{
			if(exons[i].start > exons[j].start || 
				(exons[i].start == exons[j].start && exons[i].end > exons[j].end))
			{
				struct exon tmp;
				tmp = exons[i];
				exons[i] = exons[j];
				exons[j] = tmp;
			}
		}
}
int main(void)
{
	int n;
	struct exon exons[1005];
	scanf("%d", &n);
	
	while(n)
	{
		int i;
		int j;
		exons[0].start = -1;
		exons[0].end = -1;
		exons[0].previous = 0;
		exons[0].length = 0;
		for(i = 1; i <= n; ++i)
		{
			scanf("%d %d", &(exons[i].start), &(exons[i].end));
			exons[i].previous = 0;
			exons[i].length = 1;
			exons[i].index = i;
 		}
		sort(exons, n);
		
		for(i = 1; i <= n; ++i)
			for(j = 0; j < i; ++j)
			{
				if(exons[i].start > exons[j].end && 1 + exons[j].length > exons[i].length)
				{
					exons[i].length = 1 + exons[j].length;
					exons[i].previous = j;
				}
			}
		
		int max = 0;
		int maxp;
		int step_n = 0;
		int step[1005];
		for(i = 1; i <= n; ++i)
		{
			if(exons[i].length > max)
			{
				max = exons[i].length;
				maxp = i;
			}
		}
		
		while(maxp != 0)
		{
			step[step_n++] = exons[maxp].index;
			maxp = exons[maxp].previous;
		}
		for(i = step_n - 1; i > 0; --i)
			printf("%d ", step[i]);
		printf("%d", step[i]);
		printf("\n");
		
		scanf("%d", &n);
	}
	return 0;
}
