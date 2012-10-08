#include<stdio.h>
#include<string.h>
int length;
int k;
void str2num(char* s, int* cip)
{
	int i;
	for(i = 0 ; i < length; i++)
	{
		if(s[i] == '.')
			cip[i] = 27;
		if(s[i] == '_')
			cip[i] = 0;
		if(s[i] <= 'z' && s[i] >= 'a')
			cip[i] = s[i] - 'a' + 1;
		
	}		
}
void cipher2plain(int* cipher, int* plain)
{
	int i;
	for(i = 0; i < length; i++)
	{
		plain[(i*k)%length] = (cipher[i] + i) % 28;
	}
}
void num2str(int *plain, char* s)
{
	int i;
	for(i = 0; i < length; i++)
	{
		if(plain[i] == 0)
			s[i] = '_';
		if(plain[i] == 27)
			s[i] = '.';
		if(plain[i] >= 1 && plain[i] <= 26)
			s[i] = 'a' + plain[i] -1;
	}
	s[length] = '\0';
}
int mmod(int a, int b)
{
	a = a % b;
	if(a < 0)
		a = a + b;
	return a;
}

int main(void)
{
	char s[71];
	int ciphercode[71];
	int plaincode[71];
	char result[71];
	scanf("%d", &k);
	while(k != 0)
	{
		scanf("%s", s);
		length = strlen(s);
		int i;
		str2num(s, ciphercode);
		cipher2plain(ciphercode, plaincode);
		num2str(plaincode, result);
		printf("%s\n", result);		
		scanf("%d", &k);
	}
	
	return 0;
}
