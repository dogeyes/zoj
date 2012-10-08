#include<stdio.h>

#define bool int
#define true 1
#define false 0
#define position(x, y) ((x)*((b) + 1) + (y))
void iteration(int ina, int inb, bool *map, int* road, int pr, int* bestroad);

int a;
int b;
int N;
int min = 1000*1000;
void print_best(int * bestroad)
{
	int i;
	for(i = 0; i < min; ++i)
	{
		switch(bestroad[i])
		{
			case 0: printf("fill A\n");break;
			case 1: printf("fill B\n");break;
			case 2: printf("empty A\n");break;
			case 3: printf("empty B\n"); break;
			case 4: printf("pour A B\n"); break;
			case 5: printf("pour B A\n"); break;
		}
	}
	printf("success\n");
}

int main(void)
{
	int i;
	int j;
	while(scanf("%d%d%d", &a, &b, &N) != EOF)
	{
		bool map[(a+1)* (b+1)];
		int road[(a+1)* (b+1)];
		int pr = 0;
		int bestroad[(a+1)*(b+1)];
		min = 1000*1000;
		for(i = 0; i <= a; ++i)
			for(j = 0; j <= b; ++j)
				map[position(i,j)] = false;
		iteration(0,0,map, road, pr, bestroad);
		print_best(bestroad);
		
	}	
	return 0;
}
void iteration(int ina, int inb, bool *map, int* road, int pr, int* bestroad)
{
	int i;
	if(inb == N)
	{	
		if(pr < min)
		{
			min = pr;
			for(i = 0; i < min; ++i)
				bestroad[i] = road[i];
		}
		return;
	}
	if(map[position(ina,inb)])
		return;
	map[position(ina,inb)] = true;

	for(i = 0; i < 6; ++i)
	{
		switch(i)
		{
			case 0: 
				road[pr++] = 0;
				iteration(a, inb, map,road,pr,bestroad);
				pr--;
				break;
			
			case 1:
				road[pr++] = 1;
				iteration(ina, b, map,road,pr,bestroad);
				pr--;
				break;
			
			case 2:
				road[pr++] = 2;
				iteration(0, inb, map, road, pr, bestroad);
				pr--;
				break;
			case 3:
				road[pr++] = 3;
				iteration(ina, 0, map,road, pr, bestroad);
				pr--;
				break;
			case 4:
				road[pr++] = 4;
				if(ina + inb < b)
				{
					iteration(0, ina + inb, map, road, pr, bestroad);
				}
				else
				{
					iteration(ina + inb - b, b, map, road, pr, bestroad);
				}
				pr--;
				break;
			case 5:
				road[pr++] = 5;
				if(ina + inb < a)
				{
					iteration(ina + inb, 0, map, road,pr,bestroad);
				}
				else
				{
					iteration(a, ina + inb -a, map,road,pr,bestroad);
				}
				pr--;
		}
	}
	map[position(ina,inb)] = false;
}


