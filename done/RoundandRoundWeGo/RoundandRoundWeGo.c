#include<stdio.h>
#include<string.h>


void print_num(int * a, int n)
{
	int i;
	for(i = n - 1; i >= 0; --i)
		printf("%d", a[i]);

}
void multi(int *a, int m, int *b, int n)
{
	int i;
	for(i = 0 ; i < n; ++i)
		b[i] = 0;
	int c = 0;
	for(i = 0; i < n; ++i)
	{
		c = a[i] * m + c;
		b[i] = c % 10;
		c = c / 10;
	}
	if(c > 0)
		b[0] = -1;
}
int check(int *a, int *b, int n)
{
	int i;
	int as, an, bs, bn;
	for(i = 0 ; i < n; ++i)
	{
		as = 0;
		an = 0; 
		bs = i;
		bn = 0;
		while(an <n && bn < n && a[(as + an) % n] == b[(bs + bn) % n])
		{
			an++;
			bn++;
		}
		if(an == n)
			return 1;
	}
	return 0;
		
}
int main(void)
{
	char s[62];
	int a[62];
	int b[62];
	while(scanf("%s", s) != EOF)
	{
		int i;
		int n = strlen(s);
		for(i = 0 ; i < n; ++i)
			a[n - i - 1] = s[i] - '0';
		for(i = 2; i <= n; ++i)
		{
			multi(a, i, b, n);
			if(b[0] == -1 || !check(a, b, n))
				break;
		}
		print_num(a,n);
		if(i != n+1)
			printf(" is not cyclic\n");
		else
			printf(" is cyclic\n");
	}
	return 0;
}
