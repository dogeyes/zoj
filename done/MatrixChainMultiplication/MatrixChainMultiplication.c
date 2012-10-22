#include<stdio.h>
#include<string.h>

struct mat{
	int m;
	int n;
};

struct mat mats[26];
struct mat stack[100];
int head;
int sum;

void push(struct mat m)
{
	stack[head++] = m;
}
struct mat pop()
{
	struct mat  tmp;
	tmp.m = -2;
	tmp.n = -2;
	if(head == 0)
		return tmp;
	return stack[--head];
}

int main(void)
{
	int n;
	scanf("%d", &n);
	int i;
	char c[2];
	int a, b;

	for(i = 0; i < 26; ++i)
	{
		mats[i].m = 0 ;
		mats[i].n = 0;
	}	
	for(i = 0 ; i < n; ++i)
	{
		scanf("%s %d %d", &c, &a,&b);
		mats[c[0] - 'A'].m = a;
		mats[c[0] - 'A'].n = b;
	}	
	
	char s[100];
	int length;
	while(scanf("%s", s) != EOF)
	{
		int flag = 0;
		struct mat tmpm;
		head = 0;
		sum = 0;		
		length = strlen(s);
		for(i = 0; i < length; ++i)
		{
			if(flag == 1)
		 		break;
			if(s[i] == '(')
			{
				tmpm.m = -1;
				push(tmpm);
			}	
			if(s[i] <= 'Z' && s[i] >= 'A')
				push(mats[s[i] - 'A']);
			if(s[i] == ')')
			{
				tmpm = pop();
				struct mat tmpm2 = pop();
				while(tmpm2.m != -1)
				{
					if(tmpm2.n != tmpm.m)
					{
						flag = 1;
						break;
					}
					sum = sum + tmpm2.m * tmpm2.n * tmpm.n;
					tmpm.m = tmpm2.m;
					tmpm2 = pop();		
				}
				push(tmpm);
			}
		}
		if(flag == 1)
			printf("error\n");
		else 
			printf("%d\n", sum);	
	}
	return 0;
}
