#include<stdio.h>
#include<string.h>

char forwardstack[100][80];
int forwardhead;
char backwardstack[100][80];
int backwardhead;
char current[80];
char ins[80];

int main(void)
{
	int n;
	int i;
	int flag;
	scanf("%d", &n);
	fgets(ins, 80, stdin);
	fgets(ins, 80,stdin);
	for(i = 0 ; i < n; ++i)
	{
		strcpy(current, "http://www.acm.org/\n");
		forwardhead = 0;
		backwardhead = 0;
		fgets(ins, 80,stdin);
		flag = 0;
		if(i > 0)
			printf("\n");
		while(ins[0] != '\n' && flag == 0)
		{
			switch(ins[0])
			{
				case 'V':
					strcpy(backwardstack[backwardhead++], current);
					strcpy(current, ins + 6);
					forwardhead = 0;
					printf("%s", current);
					break;
				
				case 'B':
					if(backwardhead == 0)
					{
						printf("%s\n", "Ignored");
						break;
					}
					strcpy(forwardstack[forwardhead++], current);
					strcpy(current, backwardstack[--backwardhead]);
					printf("%s", current);
					break;
				
				case 'F':
					if(forwardhead == 0)
					{
						printf("%s\n", "Ignored");
						break;
					}
					strcpy(backwardstack[backwardhead++], current);
					strcpy(current, forwardstack[--forwardhead]);
					printf("%s", current);
					break;	
				case 'Q':
					flag = 1;
					break;				
			}
			fgets(ins, 80,stdin);
		}			
	}
	return 0;
}
