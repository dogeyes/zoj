#include<stdio.h>
#include<string.h>

char source[100];
int ps;
char destination[100];
int pd;
char stack[100];
int shead;
char result[100];
int pr;
int length;

void push(int c)
{
	stack[shead++] = c;
}
int pop()
{
	if(shead == 0)
		return -1;
	else
		return stack[--shead];
}

int isempty()
{
	return shead == 0;
}
void print_result()
{
	int i;
	for(i = 0 ; i < pr; ++i)
		printf("%c ", result[i]);
	printf("\n");
}
void dfs()
{
	if(ps == length)
	{
		int pd_b = pd;
		int ps_b = ps;
		int pr_b = pr;
		int shead_b = shead;
		
		while(pd < length && pop()== destination[pd])
		{
			pd++;
			result[pr++] = 'o';
		} 
		if(pd == length && shead == 0)
		{
			print_result();
		}
		pd = pd_b;
		ps = ps_b;
		pr = pr_b;
		shead = shead_b;
		return;
	}
	push(source[ps++]);
	result[pr++] = 'i';
	dfs();
	pop();
	ps--;
	pr--;
	int tmp = pop();
	if(tmp != -1)
	{
		if(tmp == destination[pd])
		{
			pd++;
			result[pr++] = 'o';
			dfs();
			pr--;
			pd--;
		}
		push(tmp);
	}
}
int main(void)
{
	while(scanf("%s %s", source, destination) != EOF)
	{
		ps = 0; 
		pd = 0;
		pr = 0;
		length = strlen(source);
		int length2 = strlen(destination);
		printf("[\n");
		if(length == length2)
			dfs();	
		printf("]\n");
	}
	return 0;
}
