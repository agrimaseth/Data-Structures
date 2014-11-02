/*
 ============================================================================
 Name        : assgn.c
 Author      : agrima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include<stdio.h>
#include<stdlib.h>
void input_matrix(int [][30],int,int);
void convert(int m[][30],int,int,int [][30]);
void display(int [][30],int,int);
void add(int [][30],int [][30]);
void simple_transpose(int [][30]);
void fast_transpose(int [][30]);
int main()
{
    int m2[30][30],s1[30][30],s2[30][30],choose,r,c,m1[30][30],ch;
    do
    {
        printf("\nChoose from the following: ");
        printf("\n1. Covert into sparse\n2. Addition of sparse\n3. Simple Traspose\n4. Fast Transpose\n5. Exit");
        scanf("%d",&choose);
        switch(choose)
        {
            case 1:printf("\nEnter the number of rows: ");
                scanf("%d",&r);
                printf("\nEnter the number of columns: ");
                scanf("%d",&c);
                input_matrix(m1,r,c);
                convert(m1,r,c,s1);
                break;
            case 2: printf("\nEnter the number of rows: ");
                scanf("%d",&r);
                printf("\nEnter the number of columns: ");
                scanf("%d",&c);
                input_matrix(m1,r,c);
                convert(m1,r,c,s1);
                input_matrix(m2,r,c);
                convert(m2,r,c,s2);
                add(s1,s2);
                break;
            case 3:printf("\nEnter the number of rows: ");
                scanf("%d",&r);
                printf("\nEnter the number of columns: ");
                scanf("%d",&c);
                input_matrix(m1,r,c);
                convert(m1,r,c,s1);
                simple_transpose(s1);
                break;
            case 4:printf("\nEnter the number of rows: ");
                scanf("%d",&r);
                printf("\nEnter the number of columns: ");
                scanf("%d",&c);
                input_matrix(m1,r,c);
                convert(m1,r,c,s1);
                fast_transpose(s1);
                break;
            case 5:exit(0);
        }
        printf("\nPress 10 continue else 5 to exit: ");
        scanf("%d",&ch);
    }while(ch==10);
        return 0;
}
void input_matrix(int m[30][30],int r,int c)    //function to take input
{
    int i,j;
    printf("\nEnter the values: ");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
}
void convert(int m[30][30],int r,int c,int s[30][30]) //function to convert matrix to sparse matrix
{
    int i,j,term=0,k;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                term++;
            }
        }
    }
    k=1;
    s[0][0]=r;
    s[0][1]=c;
    s[0][2]=term;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            if(m[i][j]!=0)
            {
                s[k][0]=i;
                s[k][1]=j;
                s[k][2]=m[i][j];
                k++;
            }
        }
    }
    r=term+1;
    c=3;
    printf("\nThe sparse matrix is: \n");
    display(s,r,c);
}
void display(int s[30][30],int r,int c) //function to display matrix
{
    int i,j;
    for(i=0;i<r;i++)
    {
        printf("\n");
        for(j=0;j<c;j++)
        {
            printf("%d\t",s[i][j]);
        }
    }
    printf("\n");
}
void add(int s1[30][30],int s2[30][30]) //function to add two sparse matrix
{
    int s3[30][30],i=1,j=1,k=1;
    s3[0][0]=s1[0][0];
    s3[0][1]=s1[0][1];
    while((i<=s1[0][2])&&(j<=s2[0][2]))
    {
        if(s1[i][0]==s2[j][0])
        {
            if(s1[i][1]==s2[i][1])
            {
                s3[k][2]=s1[i][2]+s2[j][2];
                s3[k][1]=s1[i][1];
                s3[k][0]=s1[i][0];
                i++;
                j++;
                k++;
            }
            else if(s1[i][1]<s2[j][1])
            {
                s3[k][2]=s1[i][2];
                s3[k][1]=s1[i][1];
                s3[k][0]=s1[i][0];
                i++;
                k++;
            }
            else
            {
                s3[k][2]=s2[j][2];
                s3[k][1]=s2[j][1];
                s3[k][0]=s2[j][0];
                j++;
                k++;
            }
        }
        else if(s1[i][0]<s2[j][0])
        {
            s3[k][2]=s1[i][2];
            s3[k][1]=s1[i][1];
            s3[k][0]=s1[i][0];
            i++;
            k++;
        }
        else
        {
            s3[k][2]=s3[j][2];
            s3[k][1]=s3[j][1];
            s3[k][0]=s2[j][0];
            j++;
            k++;
        }
    }
    while(i<=s1[0][2])
    {
        s3[k][2]=s1[i][2];
        s3[k][1]=s1[i][1];
        s3[k][0]=s1[i][0];
        i++;
        k++;
    }
    while(j<=s2[0][2])
    {
        s3[k][2]=s2[j][2];
        s3[k][1]=s2[j][1];
        s3[k][0]=s2[j][0];
        j++;
        k++;
    }
    s3[0][2]=k-1;
    display(s3,k-1,3);
}
void simple_transpose(int s1[30][30])   //function to perform simple transpose
{
    int nxt=1,c,Term,s2[30][30];
    int n,m,terms;
    n=s1[0][0];
    m=s1[0][1];
    terms=s1[0][2];
    s2[0][0]=m;
    s2[0][1]=n;
    s2[0][2]=terms;
    for(c=0;c<=m;c++)
    {
        for(Term=1;Term<=terms;Term++)
        {
            if(s1[Term][1]==c)
            {
                s2[nxt][0]=s1[Term][1];
                s2[nxt][1]=s1[Term][0];
                s2[nxt][2]=s1[Term][2];
                nxt++;
            }
        }
    }
    printf("\nAfter transpose:\n");
    display(s2,terms+1,3);
}
void fast_transpose(int s1[30][30]) //function to perform fast matrix
{
    int rterm[20],rpos[20],i,j,row,col,num,s2[30][30];
    row=s1[0][0];
    col=s1[0][1];
    num=s1[0][2];
    s2[0][0]=col;
    s2[0][1]=row;
    s2[0][2]=num;
    for(i=0;i<=col;i++)
    {
        rterm[i]=0;
    }
    for(i=1;i<=num;i++)
    {
        rterm[s1[i][1]]++;
    }
    rpos[0]=1;
    for(i=1;i<=col;i++)
    {
        rpos[i]=rpos[i-1]+rterm[i-1];
    }
    for(i=1;i<=num;i++)
    {
        j=rpos[s1[i][1]];
        s2[j][0]=s1[i][1];
        s2[j][1]=s1[i][0];
        s2[j][2]=s1[i][2];
        rpos[s1[i][1]]=j+1;
    }
    printf("\nAfter Transpose: ");
    display(s2,num+1,3);
}
