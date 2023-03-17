#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *front;
struct node *rear;
struct node *temp;
struct node *ptr;

int data;

void Display()
{
    if(front==NULL)
    {
        printf("Queue is Empty!");
    }
    else
    {
        ptr=front;
        while(ptr!=NULL)
        {
            printf("%d \t",ptr->data);
            ptr=ptr->link;
        }
    }
}

void Enqueue(int data)
{
    struct node *new=malloc(sizeof(struct node));
    new->data=data;
    if(front==NULL)
    {
        front=new;
        rear=new;
        rear->link=NULL;
    }
    else 
    {
        new->link=NULL;
        rear->link=new;
        rear=new;
    }
}

void Dequeue()
{
    if(front==NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        temp=front;
        front=front->link;
        free(temp);
    }
}

void Menu()
{
    int mode;
    printf("\nSelect The Operation : \n1)Push\n2)Pop\n3)Display\n4)Exit\n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:printf("Enter The Data  : ");
        scanf("%d",&data);
        Enqueue(data);
        Display();
        Menu();
        break;
        case 2:Dequeue();
        Display();
        Menu();
        break;
        case 3:Display();
        Menu();
        break;
        case 4:break;
        default : printf("Invalid Mode Selection!");
        Menu();
    }
}

void main()
{
    Menu();
}