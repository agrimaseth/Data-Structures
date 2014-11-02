/*
 ============================================================================
 Name        : quicksort.c
 Author      : agrima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int partition (int [],int, int);
int partition(int a[],int l, int u)
{
	int j,i;
	int v,temp;
	printf("\n the pivot element this time is:%d",a[l]);
	v=a[l];
	i=l;
	j= u+1;
	do{
		do{
			i++;
		  }while(a[i]<v&&i<=u);
		do{
			j--;

		}while(v<a[j]);
		if(i<j)
		{
			temp = a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}while(i<j);
	a[l]=a[j];
	a[j]=v;

	return j;
}

void quick_sort(int a[],int l,int u)
{
	int j,i;
	if(l<u)
	{
		j= partition(a,l,u);
		printf("\npresently the sorted list is:");
		for(i=0;i<=u;i++)
		{
			printf("%d\t",a[i]);
		}
		quick_sort(a,l,j-1);
		quick_sort(a,j+1,u);
	}
}


int main()
{
	int n,i;
	char a[30];
	printf("enter the number of elements");
	scanf("%d",&n);
	printf("now enter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);

	}


	quick_sort(a,0,n-1);
	printf("\n the sorted list is:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	return 0;



}
