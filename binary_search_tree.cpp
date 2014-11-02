//============================================================================
// Name        : binary_search_tree.cpp
// Author      : agrima
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

class node{
public:
	int data;
	node *left;
	node *right;
};
class bst{
public:
	node* create();
	void inorder(node *root);
	void preorder(node *root);
	void postorder1(node *root);

};

class stack{
public:
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
	node * pop()
	{
		return(data[top--]);
	}
	 node * peek() {
				return (data[top]);
			}
	 int  isempty() {
	 		if (top == NULL)
	 			return (1);
	 		return (0);
	 }
};
node* bst::create()
{
	node *p,*n;
	//char ch;
	int flag,data,cont;
	node* root=NULL;
	do{
				cout<<"enter the data";
				cin>>data;
				n=new node;
				n->data=data;
				n->left=NULL;
				n->right=NULL;
				if(root==NULL)
				{
					root=n;
				}
				else
				{
					p=root;
					flag=1;
					while(flag==1)
					{
						if(n->data<p->data)
						{
							if(p->left==NULL)
							{
								p->left=n;
								flag=0;
							}
							else
								p=p->left;
						}
						if(n->data>p->data)
						{
							if(p->right==NULL)
							{
								p->right=n;
								flag=0;
							}
							else
								p=p->right;
						}
					}
				}
				cout<<"press 1 to continue & 0 to exit";
				cin>>cont;
		}while(cont!=0);
	return root;
}
void bst::inorder(node *t)
{
	stack s;
		node *p=t;
		while(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}
		while(s.top!=-1)
		{
			p=s.pop();
			cout<<" "<<p->data;

			p=p->right;

			while(p!=NULL)
			{
				s.push(p);
				p=p->left;
			}

		}

}
void bst :: preorder(node *t)
{
	stack s;
	while(t!=NULL)
	{
		cout<<t->data;
		s.push(t);
		t=t->left;
	}
	while(s.top!=-1)
	{
		t=s.pop();
		t=t->right;
		while(t!=NULL)
		{

			cout<<" "<<t->data;
			s.push(t);
			t=t->left;
		}
	}
}

void bst :: postorder1(node *root)
{
	stack s;

	 s. push(root);
	  node *prev = NULL;
	  while (!(s.isempty()))
	 // while(s.top!=0)
	  {
		  cout<<"hi";
	    node *curr = s.peek();
	    if (!prev || prev->left == curr || prev->right == curr)
	    {
	      if (curr->left)
	      {
	        s.push(curr->left);
	      }
	      else
	      {
	    	  if (curr->right)
	      	  {
	    	  	 s. push(curr->right);
	      	  }
	      	  else
	      	  {
	      		  cout << curr->data;
	      		 s.pop();
	      	  }
	      }
	    }
	    else
	    {
	    	if (curr->left == prev)
	    	{
	    		if (curr->right)
	    		{
	    			s.push(curr->right);
	    		}
	    		else
	    		{
	    			cout << curr->data;
	    			s.pop();
	    		}
	    	}
	    	else
	    	{
	    		if (curr->right == prev)
	    		{
	    			cout << curr->data;
	    			s.pop();
	    		}
	    		}
	    }
	    prev = curr;
	}
}




int main() {
	int ch;
	node *root;
	bst b;
	do{
	cout <<"\n1.creation"
			"\n2.inorder"
			"\n3.preorder"
			"\n4.postorder"
			"\n5 exit";
	cin>>ch;
	switch(ch)
	{
	case 1:
		root = b.create();
		break;
	case 2:
		b.inorder(root);
		break;
	case 3:
		b.preorder(root);
		break;
	case 4:
		b.postorder1(root);
		break;

	}
	}while(ch!=5);

	return 0;
}
