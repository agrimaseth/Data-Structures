/*
 ============================================================================
 Name        : sp.c
 Author      : agrima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 ============================================================================
 Name        : sparsematrix.c
 Author      : agrima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void input(int *p,int row1,int col1)
{
	int i,j;
	printf("please enter the matrix:");
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			scanf("%d",(p+i*col1+j));
		}
	}
	printf("the entered matrix is:");
	for(i=0;i<row1;i++)
	{
		printf("\n");
		for(j=0;j<col1;j++)
		{
			printf("%d\t",*(p+i*col1+j));
		}
	}
	getchar();
}
void sp (int *p,int row1,int col1)
{
	int i,j,count=0,k=1;
	int *q,*s;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			printf("%d",*(p+i*col1+j));
			getchar();
			if(*(p+i*col1+j)!=0)
				count++;
		}
	}
	q=(int*)malloc((row1*col1)*sizeof(int));
	s=q;
	*q=row1;
	*(q+0*col1+1)=col1;
	*(q+0*col1+2)=count;
	for(i=0;i<row1;i++)
	{
		for(j=0;j<col1;j++)
		{
			if(*(p+i*col1+j)!=0)
			{
				*(q+k*col1+0)=i;
				*(q+k*col1+1)=j;
				*(q+k*col1+2)=*(p+i*j+j);
				k++;
			}
		}
	}
	printf("the sparse matrix is:");
	for(i=0;i<count;i++)
	{
		printf("\n");
		for(j=0;j<3;j++)
		{
			printf("%d\t",*(s+i*col1+j));
		}
	}
getchar();
}

int main() {
	int row,col;
	int *p;
	p=(int*)malloc(row*col*sizeof(int));
	printf("enter the number of rows and columns");
	scanf("%d%d",&row,&col);
	input (p,row,col);
	sp(p,row,col);
	return 0;
}

