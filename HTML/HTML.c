#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

char buff[100];
int buff_size = 0;

void print_buff()
{
	int i;
	for(i = 0; i < buff_size; ++i)
	{
		printf("%c", buff[i]);
	}
	printf("\n");
	buff_size = 0;
}
void print_()
{
	int i;
	for(i = 0; i < 80; ++i)
		printf("-");
	printf("\n");
}
void dobuff(char *ps, char *pe, int num)
{
	switch(num)
	{
		case 2: 
			print_buff();
			buff_size = 0;
			break;
		case 3: 
			if(buff_size != 0)
			{
				print_buff();
				buff_size = 0;
			}
			print_();
			break;
		case 1:
			if(buff_size == 0)
			{
				if(pe - ps + buff_size > 80)
				{
					print_buff();
					buff_size = 0;
				}
				while(ps != pe)
				{
					buff[buff_size++] = *ps;
					ps++;
				}
			}
			else
			{
				if(pe - ps + buff_size + 1 > 80)
				{
					print_buff();
					buff_size = 0;
				}
				else
					buff[buff_size++] = ' ';
				while(ps != pe)
				{
					buff[buff_size++] = *ps;
					ps++;
				}	
			}
			break;
	}
}
int main(void)
{
	char s[100];
	char *ps, *pe;
	while(fgets(s, 99, stdin) != NULL)
	{
		ps = s;
		pe = s;
		while(*ps != '\0')	
		{
			while(*ps != '\0' && isspace(*ps))
			{
				++ps;
				++pe;
			}
			if(*ps == '\0')
				break;
			if(*ps == '<')
			{
				if(*(++ps) == 'b')
					dobuff(ps,pe,2);
				else
					dobuff(ps,pe,3);
				ps = ps + 3;
				pe = pe + 4;
			}
			else
			{
				while(*pe != '\0' && !isspace(*pe))
					pe++;
				dobuff(ps, pe, 1);
			}
			ps = pe;
		}
	}
	int i;
	for(i = 0; i < buff_size; ++i)
		printf("%c", buff[i]);
	return 0;
}
