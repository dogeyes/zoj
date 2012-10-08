#include<stdio.h>

int main(void)
{
	int n;
	int m;
	int map[150];
	scanf("%d", &n);
	while(n != 0)
	{
		m = 1;
		while(1)
		{
			int i;
			for(i = 0 ; i < n; ++i)
				map[i] = 1;
			int now = 0;
			int exist = n;
			while(now != 1)
			{
				map[now] = 0;
				exist--;
				int count = 0;
				while(count < m)
				{
					now = (now + 1) % n;
					if(map[now] == 1)
						count++;
				}
			}	
			if(exist == 1)
				break;	
			m++;		
		}
		printf("%d\n", m);
		scanf("%d",&n);
	}
	return 0;
}
