#include<stdio.h>
#include<string.h>

#define L 100000
int bi[3 * L];
int dec[3 * L];
int ldec;
int tmpd[3 * L];
int ltmpd;
int length;
char s[L];
int n;

void print_array(int* a, int ll)
{
	int i; 
	for(i = ll - 1; i >= 0; --i)
		printf("%d", a[i]);
}
void Oct2Bi()
{
	int i;
	for(i = 0; i < n - 2; ++i)
	{
		int tmp = s[i + 2] - '0';
		bi[i * 3] = tmp >> 2;
		bi[i * 3 + 1] = (tmp >> 1) & 1;
		bi[i * 3 + 2] = tmp & 1;
	}
/*	print_array(bi, length);*/
}
int multi(int * a, int l, int m)
{
	int c;
	int i;
	c = 0;
	for(i = 0 ; i < l; ++i)
	{
		c = a[i] * m + c;
		a[i] = c % 10;
		c = c / 10;
	}
	if(c > 0)
	{
		a[l++] = c; 
	}
	return l;
}
int add(int *a, int la, int *b, int lb, int step)
{
	int c = 0;
	int i;
	int re[L * 3];
	int lre = 0;
	for( i = 0; i < (step - la); ++i)
	{
		re[lre++] = b[i];
	}
	for(i = (step - la); i < lb; ++i)
	{
		c = c + b[i] + a[i - (step - la)];
		re[lre++] = c % 10;
		c = c / 10;
	}
	for(i = lb; i < step; ++i)
	{
		c = c + a[i - (step - la)];
		re[lre++] = c % 10;
		c = c / 10;
	}
	for(i = 0 ; i < lre; ++i)
		a[i] = re[i];
	return lre;	
}
int cat(int *a, int la, int *b, int lb, int step)
{
	int c = 0;
	int i;
	int re[L * 3];
	int lre = 0;
	for( i = 0; i < lb; ++i)
	{
		re[lre++] = b[i];
	}
	for(i = lb; i < step- la; ++i)
	{
		re[lre++] = 0;
	}
	for(i = step - la; i < step; ++i)
	{
		re[lre++] = a[i - (step - la)];
	}
	for(i = 0 ; i < lre; ++i)
		a[i] = re[i];
	return lre;	
}
void Bi2Dec()
{
	int i;
	tmpd[0] = 1;
	ltmpd = 1;
	ldec = 0;
	for(i = 0; i < length; ++i)
	{
		ltmpd = multi(tmpd, ltmpd, 5);
	/*	printf("tmp = ");
		print_array(tmpd, ltmpd);*/
		if(bi[i] == 1)
		{
			if(ldec + ltmpd > i + 1)
				ldec = add(dec, ldec, tmpd, ltmpd, i + 1);
			else
				ldec = cat(dec, ldec, tmpd, ltmpd, i + 1);
		}
	/*	printf("dec = ");
		print_array(dec, ldec);*/
	}

	
}
int main(void)
{
	while(scanf("%s", s) != EOF)
	{
		n = strlen(s);
		length = 3 * (n - 2);
		ldec = 0;
		ltmpd = 0;
		if(s[0] == '1')
		{
			printf("%s [8] = 1 [10]\n", s);
		}
		else
		{
			Oct2Bi();
			Bi2Dec();
			printf("%s [8] = 0", s);
			if(ldec > 0)
				printf(".");
			print_array(dec, ldec);
			printf(" [10]\n");
		}
	}
	return 0;
	
}
