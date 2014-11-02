/*
 ============================================================================
 Name        : structure_sll.c
 Author      : agrima
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdlib.h>
#include<stdio.h>
#include<string.h>


typedef struct node
{
	int roll;
	char name[20];
	int marks;
	int phno[10];
	struct node*next;
}node;
node* create()
{
	node *head,*new,*p;
	char a[20],ch,dumc;
	int i;
	head=(node*)malloc(sizeof(node));
	head=NULL;
	do{
	new=(node*)malloc(sizeof(node));
	printf("enter the roll_no");
	scanf("%d",&(new->roll));
	dumc=getchar();
	printf("enter the name");
	scanf("%[^\n]s",a);
	strcpy(new->name,a);
	printf("enter the marks");
	scanf("%d",&(new->marks));
	printf("enter the phone no");
	for(i=0;i<10;i++)
	{
		scanf("%d",&new->phno[i]);
	}
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		p=head;
	}

	else{
		p->next=new;
		p=p->next;
	}
	printf("do you want to enter more records:y/n");
	dumc=getchar();
	scanf("%c",&ch);
	}while(ch!='n');
	return head;
}
void display(node *head)
{
	node *p;
	int i;
	p=(node*)malloc(sizeof(node));
	p=head;
	while(p!=NULL)
	{
		printf("\n");
		printf("%d\t",p->roll);
		printf("%s\t",p->name);
		printf("%d\t",p->marks);
		for(i=0;i<10;i++)
		{
			printf("%d",p->phno[i]);
		}
		p=p->next;

	}
}
node *insert_beg(node *head)
{
	node *new,*temp;
	int i,flag=0;
	char a[20],dumc;
	new=(node*)malloc(sizeof(node));
	temp=head;
	if(head==NULL)
	{
		printf("the list does not exist");
	}
	else
	{
		printf("enter the roll_no");
		scanf("%d",&(new->roll));
		dumc=getchar();
		printf("enter the name");
		scanf("%[^\n]s",a);
		strcpy(new->name,a);
		printf("enter the marks");
		scanf("%d",&(new->marks));
		printf("enter the phone no");
		for(i=0;i<10;i++)
		{
				scanf("%d",&new->phno[i]);
		}
		new->next=NULL;
		while(new->roll!=temp->roll&&temp!=NULL)
		{
			temp=temp->next;
			flag=1;
		}
		if(flag!=1)
		{
			printf("the roll no already exists");
		}
		else
		{
		new->next=head;
		head=new;
		}
	}
	return head;
}
node * insert_end(node *head)
{
	node *new,*temp,*p;
	int i,flag=0;
	char a[20],dumc;
	new=(node*)malloc(sizeof(node));
	temp=head;
	p=head;
	if(head==NULL)
	{
		printf("the list does not exist");
	}
	else
	{
		printf("enter the roll_no");
		scanf("%d",&(new->roll));
		dumc=getchar();
		printf("enter the name");
		scanf("%[^\n]s",a);
		strcpy(new->name,a);
		printf("enter the marks");
		scanf("%d",&(new->marks));
		printf("enter the phone no");
		for(i=0;i<10;i++)
		{
			scanf("%d",&new->phno[i]);
		}
		new->next=NULL;

			while(p->next!=NULL)
			{
				p=p->next;
			}
			p->next=new;
	}
return head;
}
node* insert_pos(node *head)
{
	node *new,*temp,*p;
	int i,flag=0,ch;
	char a[20],dumc;
	new=(node*)malloc(sizeof(node));
	temp=head;
	p=head;
	if(head==NULL)
	{
		printf("the list does not exist");
	}
	else
	{
		printf("enter the roll_no");
		scanf("%d",&(new->roll));
		dumc=getchar();
		printf("enter the name");
		scanf("%[^\n]s",a);
		strcpy(new->name,a);
		printf("enter the marks");
		scanf("%d",&(new->marks));
		printf("enter the phone no");
		for(i=0;i<10;i++)
		{
			scanf("%d",&new->phno[i]);
		}
		new->next=NULL;
		printf("enter the roll no after which the new record is to be inserted:");
		scanf("%d",&ch);
		while(p->roll!=ch)
		{
			p=p->next;
		}
		new->next=p->next;
		p->next=new;
	}
	return head;
}
node* delete_beg(node *head)
{
	node *temp;
	temp=head;
	if(head==NULL)
	{
		printf("the list does not exist");
	}

	else
	{
		head=temp->next;
		free(temp);
	}
	return head;
}
node *delete_last(node *head)
{
	node *temp,*p;
	temp=head;
	p=(node*)malloc(sizeof(node));
	p=head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	p=temp->next;
	free(p);
	temp->next=NULL;
	return head;
}
node *delete_pos(node *head)
{
	node *temp,*p;
	temp=head;
	p=(node*)malloc(sizeof(node));
	int ch;
	printf("enter the roll no. of the record to be deleted");
	scanf("%d",&ch);
	while(temp->roll!=ch)
	{
		p=temp;
		temp=temp->next;
	}
	p->next=temp->next;
	free(temp);
	return head;
}
node *modify(node *head)
{
	node *temp,*new,*p;
	char dumc,a[20];
	int i,ch;
	temp=head;
	new=(node*)malloc(sizeof(node));
	printf("enter the roll no to be modified");
	scanf("%d",&ch);
	printf("enter the roll_no ");
	scanf("%d",&(new->roll));
	dumc=getchar();
	printf("enter the name");
	scanf("%[^\n]s",a);
	strcpy(new->name,a);
	printf("enter the marks");
	scanf("%d",&(new->marks));
	printf("enter the phone no");
	for(i=0;i<10;i++)
	{
		scanf("%d",&new->phno[i]);
	}
	new->next=NULL;
	while(temp->roll!=ch)
	{
		p=temp;
		temp=temp->next;
	}
	new->next=temp->next;
	p->next=new;
	return head;
}
node *reverse(node *head)
{
	node s[10];
	int i,n=0,j;
	node *q;
	q=head;
	for(i=0;q!=NULL;i++)
	{
		s[i]=*q;
		q=q->next;
		n++;
	}
	for(i=n-1;i>=0;i--)
	{
		printf("\n");
		printf("%d\n%d\n",s[i].roll,s[i].marks);
		printf("%s",s[i].name);
		for(j=0;j<10;j++)
		{
			printf("%d",s[i].phno[j]);
		}
	}
	return head;
}
node * revert(head)
{
	node *p,*q,*r;
	p=head;
	q=NULL;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->next;
		q->next=r;
	}
	head=q;
	return head;
}
int main()
{
	node *head;
	head=(node*)malloc(sizeof(node));
	head=NULL;
	int ch;
	do{
	printf("enter the choice:\n1.create\n2.display\n3.insert at beginning\n4.insert at the end\n5.insert at a position");
	printf("\n6.delete the first record\n7.delete the last record\n8.delete a given record\n9.modify a record");
	printf("\n10.display in reverse\n11.reverse the list");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
		head=create();
		break;
	case 2:
		display(head);
		break;
	case 3:
		head = insert_beg(head);
		break;
	case 4:
		head=insert_end(head);
		break;
	case 5:
		head=insert_pos(head);
		break;
	case 6:
		head = delete_beg(head);
		break;
	case 7:
		head=delete_last(head);
		break;
	case 8:
		head=delete_pos(head);
		break;
	case 9:
		head=modify(head);
		break;
	case 10:
		head=reverse(head);
		break;
	case 11:
		head=revert(head);
		break;

	}
	}while(ch!=12);
	return 0;
}
