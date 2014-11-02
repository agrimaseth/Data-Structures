/*
 ============================================================================
 Name        : assgn_11.c
 Author      : agrima
 Description : Doubly link List
 ============================================================================
 */



//header files used
#include<stdio.h>
#include<stdlib.h>

//structure to create a doubly link list node
typedef struct dnode
{
    char a;
    struct dnode *prev, *next;
}dnode;

// Function prototypes

void mainmenu();
dnode *create();
void display(dnode *);
dnode *insertnode( dnode *head);
dnode *insert_beg(dnode *head);
dnode *insert_btw(dnode *head);
dnode *insert_end(dnode *head);
dnode *deletenode(dnode *);
dnode *delete_beg(dnode *);
dnode *delete_btw(dnode *);
dnode *delete_end(dnode *);
void reversedisplay(dnode *);
dnode *modifynode(dnode *);

//Main start
int main()
{
    mainmenu();
    return 0;
}

//Function to display user menu
void mainmenu()
{
    int ch,run=1;
    dnode *head;
    head=NULL;
    printf("\n\t\t\tDoubly Linked List");
    printf("\nWhat operation you want to perform    :");
    while(run==1)
    {

    printf("\n1. Create list\n2. Display\n3. Insert \n4. Delete \n5. Reverse Display\n6. Modify\n7.To exit");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : head=create();break;
        case 2 : display(head);break;
        case 3 : head=insertnode(head);break;
        case 4 : head=deletenode(head);break;
        case 5 : reversedisplay(head);break;
        case 6 : head=modifynode(head);break;
        case 7 : exit(0);
        default : printf("\n !! Oooooooooops Wrong Choice !!");
        break;

    }
    printf("\nWant to make a new choice .. Press 1");
    scanf("%d",&run);
}
}

//function to create DLL
dnode *create()
{
    dnode *head,*p,*temp;
    char ch,dumc;
    printf("\nEnter a string    :");
    dumc=getchar();
    ch=getchar();
    head=(dnode *)malloc(sizeof(dnode));
    head->a=ch;
    head->next=NULL;
    head->prev=NULL;
    p=head;

    while((ch=getchar())!='\n')
    {
        p->next=(dnode *)malloc(sizeof(dnode));
        temp=p;
        p=p->next;
        p->a=ch;
        p->next=NULL;
        p->prev=temp;
    }
    return head;
}

//Function to display DLL
void display(dnode *head)
{
    dnode *p;
    p=head;
    while(p!=NULL)
    {
        printf("%c",p->a);
        p=p->next;
    }
}

//User choice menu to insert node

dnode *insertnode( dnode *head)
{
    int ch;
    printf("\nEnter where you want to insert");
    printf("\n1. At Beggining");
    printf("\n2. In Between");
    printf("\n3. At the End");

    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : head=insert_beg(head);break;
        case 2 : head=insert_btw(head);break;
        case 3 : head=insert_end(head);break;
        default : printf("\nSorry Wrong Choice");
        break;
    }
    return head;
}

//function to insert node at the beginning

dnode* insert_beg(dnode *head)
{
    dnode *p,*temp;
    char ch,dumc;
    p=head;

    temp=(dnode *)malloc(sizeof(dnode));
    if(temp==NULL)
    {
        printf("Memory not available");
    }
    else
    {
        printf("\nEnter new character value ");
        dumc=getchar();
        scanf("%c",&ch);
        temp->prev=NULL;
        temp->a=ch;
        temp->next=p;

    }
    head=temp;
    return head;
}
//function to insert node in between of the list
dnode *insert_btw(dnode *head)
{
    dnode *p,*temp,*q;
    char ch,dumc,chins;
    p=head;

    printf("\nEnter character after which you want to insert    :");
    dumc=getchar();
    scanf("%c",&ch);
    temp=(dnode *)malloc(sizeof(dnode));

    if(temp==NULL)
    {
        printf("Memory not available");
    }

    else
    {
        while((p->a)!=ch && (p->next)!=NULL)
        {
        p=p->next;
        }
        if((p->next)==NULL)
        {
            printf("\n!!!! Character not found !!!!");
            exit(0);
        }

        else
        {
            printf("Enter character you want to insert");
            dumc=getchar();
            scanf("%c",&chins);
            temp->a=chins;
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
            (temp->next)->prev=temp;
        }
    }
        return head;
}

//function to insert node at the end
dnode *insert_end(dnode *head)
{
    dnode *p,*temp;
    char ch,dumc,chins;
    p=head;
    temp=(dnode *)malloc(sizeof(dnode));

    if(temp==NULL)
    {
        printf("Memory not available");
    }

    else
    {

        while((p->next)!=NULL)
        {
        p=p->next;
        }
        printf("Enter character you want to insert");
        dumc=getchar();
        scanf("%c",&chins);
        temp->a=chins;
        p->next=temp;
        temp->next=NULL;
        temp->prev=p;
    }
    return head;
}

//user choice menu to delete nodes
dnode *deletenode(dnode *head)
{
    int ch;
    printf("\nEnter what you want to Delete");
    printf("\n1. Beggining Node");
    printf("\n2. Node In Between");
    printf("\n3. Node At the End");

    scanf("%d",&ch);
    switch(ch)
    {
        case 1 : head =  delete_beg(head);break;
        case 2 : head = delete_btw(head);break;
        case 3 : head = delete_end(head);break;
        default : printf("\nSorry Wrong Choice");
        break;
    }
    return head;

}

//function to delete node from the beginning
dnode *delete_beg(dnode *head)
{
    dnode *p,*q;
    p=head;

    p=p->next;
    if(p==NULL)
        head=NULL;
    else
    {
       p->prev=NULL;
       free(head);
       head=p;
    }
    return head;
}

//function to delete node in between
dnode *delete_btw(dnode *head)
{
        dnode *p,*q;
        char ch,dumc;
        printf("\nEnter character you want to delete:");
        dumc=getchar();
        scanf("%c",&ch);
        p=head;
        while((p->a)!=ch && (p->next)!=NULL)
        {
        p=p->next;
        }
        if((p->next)==NULL)
        {
            printf("\n!!!! Character not found !!!!");
            exit(0);
        }
        else
        {
        q=p->prev;
        q->next=p->next;
        (p->next)->prev=q;
        free(p);
        }

        return head;
}

//function to delete node from the end
dnode *delete_end(dnode *head)
{
     dnode *p,*q;
     p=head;
     while(p->next!=NULL)
     {
         p=p->next;
     }
    q=p->prev;
    q->next=NULL;
    free(p);
    return head;
}


//Function to reverse display the node

void reversedisplay(dnode *head)
{
    dnode *p,*q;
    p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    while(p!=NULL)
    {
        printf("%c",p->a);
        p=p->prev;
    }
}

//Function to modify a node value

dnode *modifynode(dnode *head)
{
    char ch,dumc,chmod;
    dnode *p;
    printf("\nEnter the character you want to modify  :");
    dumc=getchar();
    scanf("%c",&ch);
    p=head;
    while(p->a!=ch&&p->next!=NULL)
    {
        p=p->next;
    }
    printf("\nEnter new character value");
    dumc=getchar();
    scanf("%c",&chmod);
    p->a=chmod;

    return head;
}
