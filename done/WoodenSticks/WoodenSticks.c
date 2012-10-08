#include<stdio.h>

int l[5000];
int w[5000];
int n;

void swap(int *a, int* b, int* d, int* e)
{
	int c;
	c = *a;
	*a = *b;
	*b = c;
	c = *d;
	*d = *e;
	*e = c;
}
void badsort(int *a, int *d, int start, int end)
{
	int i,j;
	for(i = start; i < end; ++i)
		for(j = i; j < end; ++j)
		{
			if(a[i] > a[j] || (a[i] == a[j] && d[i] > d[j]))
			{
				swap(&a[i],&a[j],&d[i],&d[j]);
			}
		}
}
/*
void sort(int* a, int *d,int start, int end)
{
	if(end - start < 10)
		{
			badsort(a, d, start, end);
			return;
		}
	int middle = (start + end) / 2;
	int w1 = a[start];
	int w2 = a[middle];
	int w3 = a[end - 1];
	int l1 = d[start];
	int l2 = d[middle];
	int l3 = d[end - 1];
	if(w1 > w2 || (w1 == w2 && l1 > l2) )
		swap(&w1, &w2, &l1, &l2);
	if(w2 > w3 || (w2 == w3 && l2 > l3) )
		swap(&w2, &w3, &l2, &l3);
	if(w1 > w2 || (w1 == w2 && l1 > l2) )
		swap(&w1, &w2, &l1, &l2);
	a[start] = w1;
	d[start] = l1;
	a[end - 1] = w3;
	d[end - 1] = l3;
	
	if(end -start == 2)
		return;
	a[middle] = a[start + 1];
	d[middle] = d[start + 1];
	int p1 = start + 1;
	int p2 = end - 2;
	while(p1 < p2)
	{
		while(a[p2] > w2 && p1 < p2)
			p2--;
		a[p1] = a[p2];
		d[p1] = d[p2];
		while(a[p1] < w2 && p1 < p2)
			p1++;
		a[p2] = a[p1];
		d[p2] = d[p1];
	}
	a[p1] = w2;
	d[p1] = l2;
	int i;
	for(i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n"); 
	sort(a,d,start,p1);
	sort(a,d,p1 + 1, end);
	
}*/
int count(int *a, int n)
{
	int max = 0;
	int now_max = 0;
	int maxs[5000];
	int i;
	int j;

	for(i = 0; i < n; ++i)
	{
		now_max = 0;
		maxs[i] =0;
		for(j = 0; j <= i; ++j)
			if(a[j] > a[i] && now_max < maxs[j] + 1)
				now_max = maxs[j] + 1;
		maxs[i] = now_max;
		if(now_max > max)
			max = now_max;
	}
	return max + 1;
}
int main(void)
{
	int k;
	scanf("%d", &k);
	int i;
	for(i = 0 ; i < k; ++i)
	{
		scanf("%d", &n);
		int j;
		for(j = 0; j < n; ++j)
		{
			scanf("%d %d", &l[j], &w[j]);
		}
		badsort(l, w,0, n);
		/*for(j = 0; j < n; ++j)
		{
			printf("%d ", l[j]);
		}
		printf("\n");
		for(j = 0; j < n; ++j)
		{
			printf("%d ", w[j]);
		}
		printf("\n");*/
		
		int num = count(w, n);
		printf("%d\n", num);
	}
	return 0;
}
