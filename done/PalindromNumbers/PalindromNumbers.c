#include<stdio.h>

int check(int n, int base)
{
	int num[20];
	int length = 0;
	while(n > 0)
	{
		num[length++] = n % base;
		n = n / base;
	}
	int i;
	for(i = 0; i <= length / 2; ++i)
		if(num[i] != num[length - i - 1])
			break;
	if(i <= length / 2)
		return 0;
	return 1;
}
int main(void)
{
	int n;
	int flag;
	scanf("%d", &n);
	while(n != 0)
	{
		int i;
		flag = 0;
		printf("Number %d is ", n);
		for(i = 2; i < 17; ++i)
		{
			if(check(n, i))
			{
				if(flag == 0)
					printf("palindrom in basis");
				printf(" %d", i);
				flag++;
			}
		}
		if(flag == 0)
			printf("not a palindrom");
		printf("\n");
		
		scanf("%d", &n);
	}
	return 0;
}
