#include<stdio.h>
#include<math.h>

int main(void)
{
	int i;
	int R[16],G[16],B[16];
	for(i = 0; i < 16; ++i)
	{
		scanf("%d %d %d", &R[i], &G[i], &B[i]);
	}
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	while(r != -1 || g != -1 || b != -1)
	{
		double min = 200000;
		int num;
		for(i = 0 ; i < 16; ++i)
		{
			double tmp = sqrt(pow(r - R[i], 2.0)+ pow(g - G[i], 2.0)+ pow(b - B[i], 2.0));
			if(tmp < min)
			{
				min = tmp;
				num = i;
			}
		}
		
		printf("(%d,%d,%d) maps to (%d,%d,%d)\n", r, g, b, R[num], G[num], B[num]);
		scanf("%d %d %d", &r, &g, &b);
	}
	
	return 0;
}
