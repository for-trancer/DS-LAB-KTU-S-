/**************************************************
/* Name : Arjun Ashok                  Roll No:22
/*       DOUBLE ENDED QUEUE USING ARRAY
/* Date : 27/10/22                     Exp No : 7
***************************************************/
#include <stdio.h>
int a[20],size=5,front=-1,rear=-1,item,i,mode,temp;
void push()
{
    printf("\n Enter The Item : \n");
    scanf("%d",&item);
    if(front==0&&rear==size-1)
    {
        printf("\n-DE Queue Overflow!\n");
    }
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        a[front]=item;
    }
    else if(front>0)
    {
        front=front-1;
        a[front]=item;
    }
    else
    {
        rear++;
        for(i=rear;i>front;i--)
        {
            a[i]=a[i-1];
        }
        a[front]=item;
    }
    printf("\nDE QUEUE | PUSH\n");
    for(i=front;i<=rear;i++)
    {
        printf("%d \t",a[i]);
    }
}

void pop()
{
    if(front==-1&&rear==-1)
    {
        printf("\n-DE Queue Underflow!");
    }
    if(rear==front)
    {
        rear=-1;
        front=-1;
    }
    else
    {
        printf("The Deleted Element is %D \n",a[front]);
        front=front+1;
    }
    printf("\nDE QUEUE | POP \n");
    for(i=front;i<=rear;i++)
    {
        printf("%d \t",a[i]);
    }
}
void inject()
{
    printf("\n Enter The Item : \n");
    scanf("%d",&item);
    if(front==0&&rear==size-1)
    {
        printf("\n-DE Queue Overflow!");
    }
    else if(front==-1&&rear==-1)
    {
        front=0;
        rear=0;
        a[front]=item;
    }
    else
    {
        rear=rear+1;
        a[rear]=item;
    }
    printf("\nDE QUEUE | INJECT \n");
    for(i=front;i<=rear;i++)
    {
        printf("%d \t",a[i]);
    }
}
void eject()
{
    if(front==-1&&rear==-1)
    {
        printf("\nDE Queue Underflow!\n");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        printf("\nThe Deleted Element is %d",a[rear]);
        rear=rear-1;
    }
    printf("\nDE QUEUE | EJECT \n");
    for(i=front;i<=rear;i++)
    {
        printf("%d \t",a[i]);
    }
}
void menu()
{
    printf("\nSelect The Mode 1)Push 2)Pop 3)Inject 4)Eject 5)Exit\n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:push();
        menu();
        break;
        case 2:pop();
        menu();
        break;
        case 3:inject();
        menu();
        break;
        case 4:eject();
        menu();
        break;
        case 5:printf("\n EXITING!!");
        break;
        default:printf("\nInvalid Mode Selection!");
        menu();
    }
}
void main()
{
    menu();
}