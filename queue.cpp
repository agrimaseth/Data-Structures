#include<iostream>
using namespace std;
#include<stdio.h>
#define max 2
class queue
{
    int data[max],front,rear;
public:
    queue();
    int isempty();
    int isoverflow();
    void enqueue(int value);
    int dequeue();
};
queue::queue()
{
    front=-1;
    rear=-1;
}
int queue::isempty()
{
    if(front==-1&&rear==-1)
        return 1;
    return 0;
}
int queue::isoverflow()
{
    if(front==(rear+1)%max)
        return 1;
    return 0;
}
void queue::enqueue(int value)
{
    if(isoverflow())
        cout<<"\n\n\tQueue Overflow\n";
    else
    {
        if(isempty())
        {
            front=0;
            rear=0;
            data[rear]=value;
        }
        else
        {
            rear=(rear+1)%max;
            data[rear]=value;
        }
    }
}
int queue::dequeue()
{
    int temp;
    if(isempty())
    {
        cout<<"\n\tEmpty queue\n";
        return -1;
    }
    else
    {
        temp=data[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
             front=(front+1)%max;
    }
    return temp;
}
int main()
{
    int ch,data,value;
    queue q;
    do
    {
        cout<<"\n\n\t!!!!**** MAIN MENU ****!!!!\n\n";
        cout<<"\t1. Add a record\n\t2. Delete a Record\n\t3. Check Empty\n\t4. Check Underflow\n\t5. Check Overflow\n\t6. Exit\n";
        cin>>ch;
        switch(ch)
        {
        case 1:
            cout<<"\n\tEnter the data to insert:\t";
            cin>>data;
            q.enqueue(data);
            break;
        case 2:
            value=q.dequeue();
            if(value!=-1)
            cout<<"\n\tThe deleted item is:\t"<<value;
            break;
        case 3:
            if(q.isempty())
                cout<<"\n\tEmpty queue\n";
            else
                cout<<"\n\tNot Empty\n";
            break;
        case 4:
            if(q.isempty())
                cout<<"\n\tQueue underflow\n";
            else
                cout<<"\n\tNot Underflow\n";

            break;
        case 5:
            if(q.isoverflow())
                cout<<"\n\tQueue Overflow\n";
            else
                cout<<"\n\tNot overflow\n";
            break;
        }
    }while(ch!=6);
    return 0;
}
