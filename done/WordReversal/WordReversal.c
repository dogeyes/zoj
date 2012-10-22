#include<stdio.h>
#include<string.h>

int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	for(i = 0 ; i < n; ++i)
	{
		if(i > 0)
			printf("\n");
		int m;
		int j;
		char s[200];
		char *ps, *pe;
		scanf("%d", &m);
		fgets(s, 199, stdin);
		for(j = 0; j < m; ++j)
		{
			
			fgets(s, 199, stdin);
			ps = s;
			pe = s;
			while(*ps != '\0' && *ps != '\n')
			{
				pe = ps;
				while(*pe!= ' ' && *pe != '\0' && *pe != '\n')
					pe++;
				char *tmp;
				tmp = pe - 1;
				while(tmp >= ps)
				{
					putchar(*tmp);
					tmp--;
				}
				ps = pe;
				if(*ps == ' ')
				{
					putchar(' ');
					ps++;
				}
			}
			printf("\n");
		}
	}	
	
	
	return 0;
}
