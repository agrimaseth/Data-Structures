/*
 ============================================================================
 Name        : database.c
 Author      : agrima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
struct student
{
	int roll_no;
	int marks;
	char name[20];
};
void input(struct student s[10],int n)
{
	int i;
	printf("enter the records as roll_no,marks,name");
	for(i=0;i<n;i++)
	{
		scanf("%d%d%s",&s[i].roll_no,&s[i].marks,s[i].name);
	}
	getchar();
}
void input_p(struct student* s, int n)
{
	int i;
	printf("enter the records as roll_no,marks,name");
	for(i=0;i<n;i++,s++)
		{
			scanf("%d%d%s",&s->roll_no,&s->marks,s->name);
		}
	getchar();


}
void display_all(struct student s[10],int n)
{
	int i;
	printf("the records entered are:");
	for(i=0;i<n;i++)
	{
		printf("\n");
		printf("%d\t%d\t%s",s[i].roll_no,s[i].marks,s[i].name);
	}
	getchar();
}
void display_all_p(struct student *s,int n)
{
	int i;
	printf("the records entered are:");
	for(i=0;i<n;i++,s++)
	{
		printf("\n");
		printf("%d\t%d\t%s",s->roll_no,s->marks,s->name);
	}
	getchar();
}
void display_part(struct student s[10],int d)
{
	int i=0,e;
	e=d-1;
	while(i!=e)
	{
		++i;
	}
	printf("the details required are:");
	printf("%d\t%d\t%s",s[i].roll_no,s[i].marks,s[i].name);
	getchar();
}
void display_part_p(struct student *s,int d)
{
	int i=0,e;
	e=d-1;
	while(i!=e)
	{
		++i;
		++s;
	}
	printf("the details required are:");
	printf("%d\t%d\t%s",s->roll_no,s->marks,s->name);
	getchar();

}
void del(struct student s[10],int d,int n)
{
	struct student s1[10];
	int i,e;
	e=d-1;
	for(i=0;i!=e;i++)
	{
		s1[i]=s[i];
	}
	for(i=e;i<n;i++)
	{
		s1[i]=s[i+1];
		s1[i].roll_no=s1[i].roll_no-1;
	}
	for(i=0;i<n-1;i++)
	{
		printf("\n");
		printf("%d\t%d\t%s",s1[i].roll_no,s1[i].marks,s1[i].name);
	}

}
void del_p(struct student *s,int d,int n)
{
	struct student *s1,*s2;
	int i,e;
	e=d-1;
	s1=(struct student*)malloc(sizeof(struct student));
	s2=s1;
	for(i=0;i!=e;i++,s1++,s++)
	{
		*s1=*s;
	}
	s++;
	for(i=e;i<n-1;i++,s1++,s++)
	{
		*s1=*s;
		//s1[i].roll_no=s1[i].roll_no-1;
	}
	for(i=0;i<n-1;i++,s2++)
	{
		printf("\n");
		printf("%d\t%d\t%s",s2->roll_no,s2->marks,s2->name);
	}

}


void ins(struct student s[10], int d, int n)
{
	struct student s2[10];
	int i;
	for(i=0;i!=d-1;i++)
	{
		s2[i]=s[i];
	}
	printf("enter the new record");
	scanf("%d%d%s",&s2[i].roll_no,&s2[i].marks,s2[i].name);
	for(i=d;i<=n+1;i++)
	{
		s2[i]=s[i-1];
		s2[i].roll_no=s2[i].roll_no+1;
	}
	for(i=0;i<n+1;i++)
	{
			printf("\n");
			printf("%d\t%d\t%s",s2[i].roll_no,s2[i].marks,s2[i].name);
	}
	getchar();

}
void ins_p(struct student *s, int d,int n)
{
	struct student *s1,*s2;
		int i,e;
		e=d-1;
		s1=(struct student*)malloc(sizeof(struct student));
		s2=s1;
		for(i=0;i!=e;i++,s1++,s++)
		{
			*s1=*s;
		}
		printf("enter the new record");
		scanf("%d%d%s",&s1->roll_no,&s1->marks,s1->name);
		s1++;
		for(i=d;i<=n+1;i++,s++,s1++)
		{
			*s1=*s;
			s1->roll_no=s1->roll_no+1;
		}
		for(i=0;i<n+1;i++,s2++)
		{
			printf("\n");
			printf("%d\t%d\t%s",s2->roll_no,s2->marks,s2->name);
		}


}
void bubblesort(struct student *s,int n)
{
	int i,j;
	struct student *temp,*q;
	temp =(struct student*)malloc(sizeof(struct student));
	q =(struct student*)malloc(sizeof(struct student));
	q=s;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if((s+j)->roll_no > (s+j+1)->roll_no)
			{
				*temp=*(s+j);
				*(s+j)=*(s+j+1);
				*(s+j+1)=*(temp);
			}

		}
	}
	q++;
	for(i=0;i<n;i++,q++)
	printf("\n%d\t%d\t%s",q->roll_no,q->marks,q->name);
	getchar();

}

void selection_sort(struct student *s,int n)
{
	int i,j;
	struct student *temp,*q;
	temp =(struct student*)malloc(sizeof(struct student));
	q =(struct student*)malloc(sizeof(struct student));
	q=s;
	for(i=0;i<n;i++)
	{
		j=i;
		while(j>0 && (s+j)->roll_no < (s+j-1)->roll_no)
		{
			*temp=*(s+j);
			*(s+j)=*(s+j-1);
			*(s+j-1)=*(temp);
			j--;
		}
	}
	q++;
	for(i=0;i<n;i++,q++)
	printf("\n%d\t%d\t%s",q->roll_no,q->marks,q->name);
	getchar();

}
void bin_search(struct student *s,int n)
{
	int i,j,mid,search;
	i=0;
	j=n-1;
	mid=(i+j)/2;
	printf("enter the roll no to find");
	scanf("%d",&search);
	while( i <= j)
	   {
	      if ( (s+mid)->roll_no < search )
	         i = mid + 1;
	      else if ( (s+mid)->roll_no== search )
	      {
	         printf("%d found at location %d.\n", search, mid+1);
	         break;
	      }
	      else
	         j = mid - 1;

	      mid = (i + j)/2;
	   }
	   if ( i> j )
	      printf("Not found! %d is not present in the list.\n", search);
	   getchar();

}
int main()
{
	struct student s;
	struct student s1[10];
	int n,d,ch2,ch1;
	printf("enter the number of records  to be entered");
	scanf("%d",&n);
	printf("choose the way to operate:\n 1.with pointer\n 2. without pointer");
	scanf("%d",&ch1);
	switch(ch1)
	{
	case 1:
		{
			input_p(&s,n);

			do
				{
				printf("choose the operation to perform:\n 1.display all\n 2.display particular\n 3.delete\n 4.insert\n 5.bubble sort\n 6.selection sort\n 7.binary seach");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						display_all_p(&s,n);
					break;
					case 2:
						printf("enter the record to be displayed");
						scanf("%d",&d);
						display_part_p(&s,d);
					break;
					case 3:
						printf("\n enter the record to be deleted");
						scanf("%d",&d);
						del_p(&s,d,n);
					break;
					case 4:
						printf("\n enter the position at which record is to be inserted");
						scanf("%d",&d);
						ins_p(&s,d,n);
					break;
					case 5:
						printf("you chose to sort the records by their roll no using bubble sort");
						bubblesort(&s,n);

						break;
					case 6:
						printf("you chose to sort the records by their roll no using selection sort");
						selection_sort(&s,n);

						break;
					case 7:
						printf("you chose to search a record using binary search by their roll no");

						bin_search(&s,n);
						break;
					default:
						break;
				}
			}while(ch2!=8);

		}
		break;
	case 2:
		{
			input(s1,n);
			do
			{
				printf("choose the operation to perform:\n 1.display all\n 2.display particular\n 3.delete\n 4.insert\n 5. exit");
				scanf("%d",&ch2);
				switch(ch2)
				{
					case 1:
						display_all(s1,n);
					break;
					case 2:
						printf("enter the record to be displayed");
						scanf("%d",&d);
						display_part(s1,d);

					break;
					case 3:
						printf("\n enter the record to be deleted");
						scanf("%d",&d);
						del(s1,d,n);
					break;
					case 4:
						printf("\n enter the position at which record is to be inserted");
						scanf("%d",&d);
						ins(s1,d,n);
					break;
					default:
						printf("please enter a valid input");
						break;
				}
			}while(ch2!=5);
		}
		break;
	default:
		break;

	}
	getchar();
	return 0;
}


















