/**************************************************
/* Name : Arjun Ashok                  Roll No:22
/*           CIRCULAR QUEUE USING ARRAY
/* Date : 18/10/22                     Exp No : 6
***************************************************/
#include <stdio.h>
int a[5],size=5,front=-1,rear=-1;
void enqueue()
{
    int item;
    printf("ITEM : ");
    scanf("%d",&item);
    if((front==0&&rear==size-1)||front==(rear+1)%size)
    {
        printf("Full! \n");
    }
    else if(front==-1)
    {
        front=0;
        rear=0;
        a[rear]=item;
    }
    else 
    {
        rear=(rear+1)%size;
        a[rear]=item;
    }
}
void dequeue()
{
    if(front==-1&&rear==-1)
    {
        printf("Empty");
    }
    else if(front==rear)
    { 
        front=-1;
        rear=-1;
    }
    else
    {
        front=(front+1)%size;
    }
}
void display()
{
    int i;
    printf("QUEUE :-\n ");
    if(front==-1)
    {
        printf("Empty! \n");
    }
    else if(front==0&&rear==size-1)
    {
        for(i=0;i<size;i++)
        {
            printf("%d \t",a[i]);
        }
    }
    else
    {
        for(i=front;i!=rear;i=(i+1)%size)
        {
            printf("%d \t",a[i]);
        }
        printf("%d \t",a[rear]);
    }
}
void menu()
{
    int mode;
    printf("\n Select Mode \n1)ENQUEUE 2)DEQUEUE 3)DISPLAY 4)EXIT");
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
        case 4:printf("Exited");
        break;
        default:printf("Invalid Mode!");
        menu();
    }
}

void main()
{
    menu();
}
