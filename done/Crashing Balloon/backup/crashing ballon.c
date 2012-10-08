#include<stdio.h>
main()
{
	unsigned long a,b,c,multi;
	int i,flag;
	
    while(scanf("%d%d",&a,&b)!=EOF)
 {
    	

	flag=0;
	if(b>a)
	{
		c=b;
		b=a;
		a=c;
	}
	c=0;
		i=100;
		multi=a;
	while(i>1)
	{
		if(multi%i==0)
		{
			multi=multi/i;
		}
		i=i-1;
	} 
	if(multi==1)
	{
		c=a;
		flag++;
	}
	
			i=100;
		multi=b;
	while(i>1)
	{
		if(multi%i==0)
		{
			multi=multi/i;
		}
		i=i-1;
	} 
	if(multi==1)
	{
		c=b;
		flag++;
	}
	
	
	
		multi=a*b;
	i=100;
	while(i>1)
	{
		if(multi%i==0)
		{
			multi=multi/i;
		}
		i=i-1;
	} 
	
	if(multi==1&&flag==2)
	{
		c=a;
	}
	
printf("%d\n",c);
	
    }
    return 0;
}

//155 = 5 * 31
//195 = 5 * 39