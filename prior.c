/**************************************************
/* Name : Arjun Ashok                  Roll No:22
/*               PRIORITY QUEUE
/* Date : 27/10/22                     Exp No : 8
***************************************************/
#include <stdio.h>
int size,front=-1,rear=-1,i,item,p,pr,loc;
struct Prior
{
    int data;
    int priority;
}n[20],temp[1];

void enqueue()
{
    printf("Enter The item : ");
    scanf("%d",&item);
    printf("Enter The priority : ");
    scanf("%d",&p);
    if(rear==size-1)
    {
        printf("Full!");
    }
    else if(front==-1)
    {
        front=rear=0;
        n[rear].data=item;
        n[rear].priority=p;
    }
    else if(rear==size-1)
    {
        for(i=front;i<rear;i++)
        {
            temp[1]=n[i-1];
            n[i-1]=n[i];
            n[i]=temp[1];
        }
        front--;
        rear--;
        for(i=rear;i>=front;i++)
        {
            if(n[i].priority<p)
            {
                break;
            }
        }
        loc=i+1;
        rear=rear+1;
        for(i=rear;i>loc;i--)
        {
            n[i]=n[i-1];
        }
        n[loc].data=item;
        n[loc].priority=p;
    }
    else
    {
        for(i=rear;i>=front;i--)
        {
            if(n[i].priority<p)
            {
                break;
            }
        }
        loc=i+1;
        rear=rear+1;
        for(i=rear+1;i>loc;i--)
        {
            n[i]=n[i-1];
        }
        n[loc].data=item;
        n[loc].priority=p;
    }
}
void dequeue()
{
    if(front==-1)
    {
        printf("Empty!");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=front+1;
    }
}
void display()
{
    for(i=front;i<=rear;i++)
    {
        printf("%d \t",n[i].data);
    }
     printf("\n");
    for(i=front;i<=rear;i++)
    {
    printf("%d \t",n[i].priority);
    }
}
void menu()
{
    int mode;
    printf("\nEnter The Operation : \n1)Enqueue 2)Dequeue 3)Display 4)Exit\n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:enqueue();
        display();
        menu();
        break;
        case 2:dequeue();
        display();
        menu();
        break;
        case 3:display();
        menu();
        break;
        case 4:break;
        default:printf("invalid Mode Selection!");
        menu();
    }
}
void main()
{
    printf("Enter The Size : ");
    scanf("%d",&size);
    menu();
}