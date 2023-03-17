#include <stdio.h>
int front=-1,rear=-1,item,p,i,size,temp,pos;
struct queue
{
    int data;
    int priority;
};
void enqueue()
{
    struct queue x[size];
    printf("Enter The Item : ");
    scanf("%d",&item);
    printf("Enter Its Priority : ");
    scanf("%d",&p);
    if(front==0&&rear==size-1)
    {
        printf("Priority Queue Overflow!");
    }    
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        x[rear].data=item;
        x[rear].priority=p;
    }
    else if(rear==size-1)
    {
        temp=front-1;
        while(temp<rear)
        {
            x[temp].data=x[temp+1].data;
            x[temp].priority=x[temp+1].priority;
            temp++;
        }
        pos=rear;
        while(p<x[pos].priority)
        {
            pos--;
            if(pos==0)
            {
                break;
            }
        }
        rear=rear+1;
        temp=rear;
        while(temp>front)
        {
            x[temp-1].data=x[temp].data;
            x[temp-1].priority=x[temp].priority;
        }
        x[pos].data=item;
        x[pos].priority=p;
        }
        for(i=front;i<=rear;i++)
        {
            printf("%d \t",x[i].data);
            printf("\n");
            printf("%d \t",x[i].priority);
        }
}


void display()
{
    if(front==-1&&rear==-1)
    {
        printf("Prior Queue is Empty!");
    }
    else
    {
        printf("Under Construction!");
    }
}

void menu()
{
    int mode;
    printf("Select The Operation : \n1)Enqueue\n2)Display\n3)Exit");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:enqueue();
        menu();
        break;
        case 2:display();
        menu();
        break;
        case 3:break;
        default:printf("Invalid Option!");
        menu();
    }
}


void main()
{
    printf("Enter The Size : ");
    scanf("%d",&size);
    menu();
}