//============================================================================
// Name        : tbt_mock.cpp
// Author      : agrima
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
class node
{public:
    int lbit;
    int rbit;
    node *left;
    node *right;
    char data;
public:
    node()
    {
        lbit=rbit=0;
        left=right=NULL;
        data=NULL;
    }

};
class stack
{public:
    node *data;
    stack *pre;
public:
    void push(node* );
    node *pop();
    node *peek();
    bool isempty();
};
stack *top=NULL;
void stack::push(node *t)
{
    stack *temp=new stack;
    temp->data=t;
    temp->pre=top;
    top=temp;
}
node* stack::pop()
{
    node *ch;
    stack *temp=top;
    top=top->pre;
    ch=temp->data;
    delete(temp);
    return ch;
}
node * stack::peek()
{
    return top->data;
}
bool stack:: isempty()
{
    bool b;
    if(top==NULL)
    {
        b=1;
    }
    else
        b=0;
    return b;
}

class tbt
{
public:
    stack stack1;
    node *head;
    char post[20];
public:
    tbt()
    {
        head=new node;
    }
    void create_exp();
    void preorder();
    void inorder();
    node* insuc(node *);
    node *presuc(node *);
};

void tbt ::create_exp()
{
    int i=0;
    cout<<"enter the postfix expression";
    cin>>post;
    char token;
    while(post[i]!='\0')
    {
        token=post[i];
        node *root=new node;
        root->data=token;
        if(isalpha(token))
        {
            stack1.push(root);
        }
        else
                {
                    node *t1=stack1.peek();
                    stack1.pop();
                    node *t2=stack1.peek();
                    stack1.pop();
                    if(t1->left==NULL&&t2->left==NULL)
                    {
                        root->left=t2;
                        root->right=t1;
                        root->lbit=root->rbit=1;

                        t2->right=root;
                        t1->left=root;
                        t1->lbit=t1->rbit=0;
                        t2->lbit=t2->rbit=0;

                        stack1.push(root);

                    }
                    else if(t1->left==NULL&&t2->left!=NULL)
                    {
                        root->left=t2;
                        root->right=t1;
                        root->lbit=root->rbit=1;

                        t1->left=root;

                        node*suc2 =new node;
                        suc2=t2;
                        while(suc2->right!=NULL)
                        {
                            suc2=suc2->right;
                        }
                        suc2->right=root;
                        stack1.push(root);


                    }
                    else if(t1->left!=NULL&&t2->left==NULL)
                    {
                        root->left=t2;
                        root->right=t1;
                        root->lbit=root->rbit=1;

                        t2->right=root;

                        node *pre1=new node;
                        pre1=t1;

                        while(pre1->left!=NULL)
                        {
                            pre1=pre1->left;
                        }

                        pre1->left=root;
                        stack1.push(root);

                    }
                    else if(t1->left!=NULL&&t2->left!=NULL)
                    {
                        root->left=t2;
                                        root->right=t1;
                                        root->lbit=root->rbit=1;

                        node*pre1=new node;
                        pre1 =t1;
                        while(pre1->left!=NULL)
                        {
                            pre1=pre1->left;
                        }
                        pre1->left=root;

                        node *suc2=new node;
                        suc2=t2;
                        while(suc2->right!=NULL)
                        {
                            suc2=suc2->right;
                        }
                        suc2->right=root;

                        stack1.push(root);



                    }
                }

                i++;
            }
            node *temp=new node;
            temp=stack1.peek();
            head->left=temp;
            head->right=head;
            head->lbit=head->rbit=1;
            while(temp->left!=NULL)
            {
                temp=temp->left;
            }
            temp->left=head;
            temp=stack1.peek();
                while(temp->right!=NULL)
                    temp=temp->right;
            temp->right=head;
            stack1.pop();
}
node * tbt ::insuc(node *t)
{
    if(t->rbit==1)
    {
        t=t->right;
        while(t->lbit==1)
            t=t->left;
        return t;
    }
    else
        return t->right;
}
void tbt::inorder()
{
    node * t;
    t=new node;
    t=head->left;
    while(t->lbit==1)
        t=t->left;
    while(t!=head)
    {
        cout<<t->data;
        t=insuc(t);
    }
}
node *tbt ::presuc(node *t)
{
    if(t->lbit==1)
        return t->left;
    if(t->rbit==1)
        return t->right;
    while(t->rbit==0)
    {
        t=t->right;
    }
    return t->right;
}
void tbt::preorder()
{
    node *t;
    t=new node;
    t=head->left;

    while(t!=head)
    {
        cout<<t->data;
        t=presuc(t);
    }
}


int main() {
    int ch;
    tbt *t;
    do{
    cout << "\n\tchoose:\n1.create tree\n2.inorder traversal\n3.preorder traversal" << endl;
    cin>>ch;
    switch(ch)
    {
    case 1:
        t=new tbt;
        t->create_exp();
        break;
    case 2:
        t->inorder();
        break;
    case 3:
        t->preorder();
        break;
    }
    }while(ch!=5);
    return 0;
}
