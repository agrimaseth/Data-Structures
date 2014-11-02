/*
 ============================================================================
 Name        : string.c
 Author      : agrima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
int input1(char a[]);
void stcat(char a[],char b[],int k,int l);
int stcomp(int k, int l);
void stpal1(char a[], int k);
void stpal2(char b[],int l);
void reverse1(char a[],int k);
void reverse2(char b[],int l);
int substring1(char a[]);
int substring2(char b[]);
int input_p1(char *str1);
void stcat_p(char *str1,char *str2,int len1,int len2);
void pal(char *str,int len);
void reverse(char *str);
void substring(char *pstr1);
int main()
{
    char a[10],b[10],ch1;
    int c,ch,s,len1,len2;
    system("clear");
    printf("\n enter the way of operation on strings:\n 1.without pointer.\n 2.with pointer");
    scanf("%d",&ch);
    switch(ch)
    {
		case 1:
		{
			scanf("%c",&ch1);
			len1=input1(a);
			printf("the length is: %d",len1);
    			len2=input1(b);
			printf("the length is %d",len2);
			do
				{
					printf("\n choose the operation to perform:\n1.stringappend.\n2.stringcompare\n3.palindrome\n4.reverse\n5.substring\n6.exit");
					scanf("%d",&s);

					switch(s)
					{

						case 1:
							stcat(a,b,len1,len2);
							break;
						case 2:
    						  	c=stcomp(len1,len2);
    						 	printf("%d",c);
							break;
						case 3:
    							stpal1(a,len1);
    							stpal2(b,len2);
							break;
						case 4:
    							reverse1(a,len1);
    							reverse2(b,len2);
							break;
						case 5:
							substring1(a);
							substring2(b);
							break;
						case 6:
							printf("you chose to exit");
    						getchar();
					}
				}while(s!=6);
                 }
		break;
		case 2:
		{
			scanf("%c",&ch1);
			len1=input_p1(a);
			printf("the length is %d",len1);
			len2=input_p1(b);
			printf("the length is %d",len2);
			do
				{
					printf("\n");
					printf("\n choose the operation to perform:\n1.stringappend.\n2.stringcompare\n3.palindrome\n4.reverse\n5.substring\n6.exit");
					scanf("%d",&s);

					switch(s)
					{
						case 1:
							stcat_p(a,b,len1,len2);
							break;
						case 2:
    						  	c=stcomp(len1,len2);
    						 	printf("%d",c);
							break;
						case 3:
    							pal(a,len1);
    							pal(b,len2);
							break;
						case 4:
    							reverse(a);
    							reverse(b);
							break;
						case 5:
							substring(a);
							substring(b);
							break;
						case 6:
							printf("you chose to exit");
    						getchar();
					}
				}while(s!=6);

			break;

		}

    }
    return 0;
}
int input1(char a[])
{
    int i=0,k;
    char ch;
    printf("enter the string:");
    do
        {
            ch=getchar();
            a[i]=ch;
            i++;
        } while(ch!='\n');
        i--;
        a[i]='\0';
        k=i;
        for(i=0;i<k;i++)
        {
            printf("%c",a[i]);
        }
        getchar();
        return k;
}
int input_p1(char *str1)
{
	char ch;
	int i=0,k;
	printf("\n enter string:");
	do
	{
		ch=getchar();
		*str1= ch;
		str1++;
		i++;
	}while(ch!='\n');
	(str1--);
	*str1='\0';
	 k=(--i);
	return (k);

}

void stcat(char a[],char b[],int k,int l)
{
    char c[20];
    int j,i;
   for(i=0;i<k;i++)
   {
       c[i]=a[i];
   }
   for(i=k,j=0;j<=l;i++,j++)
   {
       c[i]=b[j];
   }
   printf("the appended string is:");
   for(i=0;c[i]!='\0';i++)
   {
       printf("%c",c[i]);
   }
    getchar();
}
void stcat_p(char *str1,char *str2,int len1,int len2)
{
	char *e,*p;
	e=(char*)malloc((len1+len2)*sizeof(char));
	p=e;
	for(;*str1!='\0';str1++,e++)
	{
		*e=*str1;
	}
	for(;*str2!='\0';str2++,e++)
	{
		*e=*str2;
	}
	*e='\0';
	printf("\n the appended string is:");
	for(;*p!='\0';p++)
	{
		printf("%c",*p);
	}
	getchar();


}

int stcomp(int k,int l)
{
    if(k==l)
        return 0;
    else
        return 1;
}
void stpal1(char a[],int k)
{
    int i;
    char c[20];
    for(i=0;i<k;i++,k--)
    {
        c[i]=a[k-1];
        i='\0';
    }
    for(i=0;i<k;i++)
    {
        if(c[i]!=a[i])
            break;
    }
    if(i==k)
        printf("\n the first string is a palindrome");
    else
        printf("\n the first string is not palindrome");
    getchar();

}
void stpal2(char b[],int l)
{
    int i;
    char c[20];
    for(i=0;i<l;i++,l--)
    {
        c[i]=b[l-1];
        i='\0';
    }
    for(i=0;i<l;i++)
    {
        if(c[i]!=b[i])
            break;
    }
    if(i==l)
        printf("\n the second string is a palindrome");
    else
        printf("\n the second string is not palindrome");
    getchar();

}
void pal(char *str,int len)
{
	char *p,*e;
	int i;
	p=(char*)malloc(len*sizeof(char));
	e=p;
	for(i=len-1;i>=0;i--,p++)
	{
		*p=str[i];
	}
	*p='\0';
	for(;*e!='\0'&&*str!='\0';str++,e++)
	{
		if(*e!=*str)
		break;
	}
	//printf("%c",*e);
	//printf("%c",*str);

	if(*e=='\0'&&*str=='\0')
		printf("\nit is a palindromic string");
	else
		printf("\nit is not a palindromic string");
	getchar();


}

void reverse1(char a[],int k)
{
    int i;
    for(i=k-1;i>=0;i--)
    {
        printf("%c",a[i]);
    }
    getchar();
}
void reverse2(char b[],int l)
{
    int i;
    for(i=l-1;i>=0;i--)
    {
        printf("%c",b[i]);
    }

    getchar();
}
void reverse(char *str)
{
	int count=0;
	while(*str!=0)
	{
		str++;
		count++;
	}
	str--;
	while(count!=0)
	{
		printf("%c",*str);
		count--;
		str--;
	}
	getchar();
}

int substring1(char a[])
{
	int k=0,i=0,l,j,flag;
	char ch,c[10];
	printf("check the first string: enter the string to be checked");
	do
	{
		ch=getchar();
		c[i]=ch;
		i++;
	}while(ch!='\n');
	i--;
	c[i]='\0';
	l=i;

	for(i=0;i<=l;i++)
	{
		flag=0;
		for(j=k;a[j]!='\0';j++)
		{
			if(c[i]==a[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			k=j+1;
		}
		else
		{
			break;
		}
	}
	if(c[i]=='\0')
	{
		printf("it is a substring");
	}
	else
	{
		printf("it is not a substring");
	}
	getchar();
	return 0;

}
int substring2(char b[])
{
	int k=0,i=0,l,j,flag;
	char ch,c[10];
	printf("check the second string: enter the string to be checked");
	do
	{
		ch=getchar();
		c[i]=ch;
		i++;
	}while(ch!='\n');
	i--;
	c[i]='\0';
	l=i;
	for(i=0;i<=l;i++)
	{
		flag=0;
		for(j=k;b[j]!='\0';j++)
		{
			if(c[i]==b[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			k=j+1;
		}
		else
		{
			break;
		}
	}
	if(c[i]=='\0')
	{
		printf("it is a substring");
	}
	else
	{
		printf("it is not a substring");
	}
	getchar();
	return 0;

}
void substring(char *pstr1)
{
	char *p1,*p2,*s3;
	p1=pstr1;
	s3=(char*)malloc(10*sizeof(char));
	int flag=0,count=0,len;
	printf("enter the string to be checked");
	len=input_p1(s3);
	p2=s3;
	while(*p1!='\0')
	{
		if(*p1==*p2)
		{
			for(count=0;count<len-1;count++)
			{
				p2++;
				p1++;
				if(*p2!=*p1)
				{
					flag=0;
					break;
				}
				else
				flag=1;

			}
		}
		p2=s3;
		p1++;
	}
	if(flag==1)
		printf("it is a substring");
	else
		printf("it is not a substring");


	getchar();
}

