// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<stack>

#define max 10
using namespace std;

class node{
public:

	char data;
	int lbit;
	node *left;
	int rbit;
	node *right;

public:
	node()
	{
		data = NULL;
		lbit = rbit = 0;
		left = right = NULL;
	}
};

class tbt{

	stack <node*> stack1;
	char post[max];
	node *head;



public:
	tbt()
	{
		head=new node();
	}
	void create()
	{
		int i = 0;
		char token;
		cout << "\n\npls input postfix expression for tree:";
		cin >> post;
		while (post[i] != '\0')
		{
			token = post[i];
			node *root = new node;
			root->data = token;
			if (isalpha(token))
			{
				stack1.push(root);
			}
			else
			{

				node *t1 = stack1.top();
				stack1.pop();
				node *t2 = stack1.top();
				stack1.pop();

				if (t1->left == NULL && t2->left==NULL)
				{


					//attached to root
					root->left = t2;
					root->right = t1;
					root->lbit = root->rbit = 1;

					//attached children
					t2->right = root;
					t1->left = root;
					t1->lbit = t1->rbit = 0;
					t2->lbit = t2->rbit = 0;
					stack1.push(root);

				}
				else if (t1->left == NULL && t2->left!=NULL)
				{


					//attached to root
					root->left = t2;
					root->right = t1;
					root->lbit = root->rbit = 1;

					t1->left = root;
					//imp stuff
					node *suc2 = new node;
					suc2 = t2;

					while (suc2->right != NULL)
						suc2 = suc2->right;

					suc2->right = root;
					stack1.push(root);

				}
				else if (t2->left == NULL && t1->left!=NULL)
				{


					//attached to root
					root->left = t2;
					root->right = t1;
					root->lbit = root->rbit = 1;

					t2->right = root;
					//imp stuff
					node *pre1 = new node;
					pre1 = t1;
					while (pre1->left != NULL)
						pre1 = pre1->left;

					pre1->left = root;
					stack1.push(root);

				}
				else if (t1->left != NULL && t2->left != NULL)
				{


					//attached to root
					root->left = t2;
					root->right = t1;
					root->lbit = root->rbit = 1;


					//find out pre and suc
					node *pre1 = new node;
					pre1 = t1;
					while (pre1->left != NULL)
						pre1 = pre1->left;

					pre1->left = root;


					node *suc2 = new node;
					suc2 = t2;

					while (suc2->right != NULL)
						suc2 = suc2->right;

					suc2->right = root;
					stack1.push(root);


				}

			}
			i++;
		}
		node *temp = new node;
		temp= stack1.top();
		head->left = temp;
		head->lbit=head->rbit = 1;
		head->right = head;

		while (temp->left != NULL)
			temp = temp->left;

		temp->left = head;
		temp = stack1.top();
		while (temp->right != NULL)
			temp = temp->right;

		temp->right = head;
		stack1.pop();

	}


	node *presuc(node *t)
	{
		if (t->lbit == 1)
			return t->left;
		if (t->rbit == 1)
			return t->right;
		while (t->rbit == 0)
			t = t->right;
		return t->right;
	}

	void preorder()
	{
		node *t = new node;
		t = head->left;
		cout << "\n";
		while (t != head)
		{
			cout << " " << t->data;
			t = presuc(t);
		}
	}/*End of inorder()*/



	node *insuc(node *t)
	{
		if (t->rbit == 1)
		{
			t = t->right;
			while (t->lbit == 1)
				t = t->left;
			return t;
		}
		else
			return t->right;
	}

	void inorder()
	{
		node *t;
		t = head->left;
		cout << "\n";
		while (t->lbit == 1)
			t = t->left;

		while (t != head)
		{
			cout << " " << t->data;
			t = insuc(t);

		}
	}



};


int main()
{
	tbt *theone;
	int a;
	do{
		cout << "\n\n**********MENU FOR THEONE*********";
		cout << "\n\n1. for Creation of TBT";
		cout << "\n\n2. FOr Preoreder transversal of tbt";
		cout << "\n\n3. For Inorder transversal of tbt";
		cout << "\n\n4. for exit\npls press: ";
		cin >> a;
		switch (a)
		{
		case 1:
			theone=new tbt();
			theone->create();
			cout << "\n\ncreation is done successfully";
			break;

		case 2:
			cout << "\n\nPreorder transversal : ";
			theone->preorder();
			break;

		case 3:
			cout << "\n\nInorder transversal: ";
			theone->inorder();
			break;


		}
	} while (a != 4);

}





