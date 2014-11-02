//============================================================================
// Name        : expression.cpp
// Author      : agrima
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class node
{
public:
	char data;
	node *left;
	node *right;
};
class expt
{
public:
	node * create();
	void inorder(node *);
	void preorder(node *);
	void postorder(node *);
};
expt e;
class stack
{public:
	node *data[30];
	int top;
public:
	stack()
	{
		top=-1;
	}
	void push(node *top1)
	{
		data[++top]=top1;
	}
	node* pop()
	{
		return data[top--];
	}

};
stack s;

node* expt::create()
{
	node *root;
	node *top1;
	char post[20];
	char c;
	int i=0;
	cout<<"\n enter the postfix expression:";
	cin>>post;
	//while((c=getchar())!='\n')
	while(post[i]!='\n')
	{
		c=post[i];
		if(isalpha(c))
		{
			top1=new node();
			top1->data=c;
			top1->left=NULL;
			top1->right=NULL;
		}
		else
		{
			top1=new node();
			top1->data=c;
			node *pop1=new node;
			pop1=s.pop();
			node *pop2=new node;
			pop2=s.pop();
			top1->left=pop2;
			top1->right=pop1;
			s.push(top1);


		}
		i++;
	}
	top1=s.pop();
	return top1;
}
void expt::preorder(node *root)
{
	if(root!=NULL)
		{
			cout<<root->data;
			preorder(root->left);
			preorder(root->right);
		}
}

int main() {
	int ch;
	node * root=new node;
	do{
		cout<<"\n\t\tchoose:\n1.create\n2.preorder traversal\n3.inorder\n4.postorder";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"hi";
			root=e.create();
			break;
		case 2:
			e.preorder(root);
			break;
		case 3:
			break;
		case 4:
			break;
		}
	}while(ch!=5);

	return 0;
}
