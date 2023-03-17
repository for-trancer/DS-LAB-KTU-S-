#include <stdio.h>
int a[5],size=5,front=-1,rear=-1;

void Enqueue()
{
    int item;
    printf("\n Enter ITEM : ");
    scanf("%d",&item);
    if(rear==size-1)
    {
        printf("Queue is FULL!");
    }
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        a[rear]=item;
    }
    else
    {
        rear++;
        a[rear]=item;
    }
}

void Dequeue()
{
    if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==-1&&rear==-1)
    {
        printf("The Queue Is Empty!");
    }
    else
    {
        front=front+1;
    }
}


void Display()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("The Queue Is Empty");
    }
    else
    {
        printf("\n QUEUE \n");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",a[i]);
        }
    }
}

void Menu()
{
    int mode;
    printf("\n Select The Operation : \n 1) ENQUEUE \n 2) DEQUEUE \n 3) DISPLAY \n 4) EXIT \n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1 :Enqueue();
        Menu();
        break;
        case 2:Dequeue();
        Menu();
        break;
        case 3:Display();
        Menu();
        break;
        case 4:printf("\nExiting...!");
        break;
        default:printf("\n Invalid Mode Selection!");
        Menu();
    }
}


void main()
{
    Menu();
}