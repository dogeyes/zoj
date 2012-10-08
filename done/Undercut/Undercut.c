#include<stdio.h>

int main(void)
{
	int n;
	int flag = 0;
	
	scanf("%d", &n);
	while(n != 0)
	{
		int i;
		int A = 0;
		int B = 0;
		int ac[20],bc[20];
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &ac[i]);
		}
		for(i = 0; i < n; ++i)
		{
			scanf("%d", &bc[i]);
		}
		for(i = 0; i < n; ++i)
		{
			int tmpa = ac[i];
			int tmpb = bc[i];
			if(tmpa > tmpb + 1)
				A += tmpa;
			else if(tmpb > tmpa + 1)
				B += tmpb;
			else if(tmpa == 1 && tmpb == 2)
				A += 6;
			else if(tmpa == 2 && tmpb == 1)
				B += 6;
			else if(tmpa == tmpb + 1)
				B += (tmpa + tmpb);
			else if(tmpb == tmpa + 1)
				A += (tmpa + tmpb);
		}
		if(flag >  0)
			printf("\n");
		printf("A has %d points. B has %d points.\n", A, B);
		flag++;
		scanf("%d", &n);
	}
	return 0;
}
