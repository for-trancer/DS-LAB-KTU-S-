#include <stdio.h>
#include <stdlib.h>

int item,key;

struct node
{
    int data;
    struct node *link;
};

struct node *head=NULL;
struct node *ptr=NULL;
struct node *prev=NULL;
struct node *curr=NULL;
struct node *temp=NULL;


void InsertFirst()
{
    printf("Enter The Item : ");
    scanf("%d",&item);
    struct node *new=(struct node*) malloc(sizeof(struct node));
    new->data=item;
    new->link=head;
    head=new;
}

void DeleteFirst()
{
    if(head==NULL)
    {
        printf("List Empty!");
    }
    else
    {
        printf("Deleted Element : %d \n",head->data);
        head=head->link;
    }
}
void InsertEnd()
{
    struct node *new=(struct node*) malloc(sizeof(struct node));
    if(head==NULL)
    {
        InsertFirst();
    }
    else
    {
        printf("Enter The Item : ");
        scanf("%d",&item);
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr=ptr->link;
        }
        new->data=item;
        new->link=NULL;
        ptr->link=new;
    }
}

void DeleteEnd()
{
    if(head==NULL)
    {
        printf("List Empty!");
    }
    else if(head->link==NULL)
    {
        temp=head;
        head=NULL;
    }
    else
    {
        prev=head;
        curr=head->link;
        while(curr->link!=NULL)
        {
            prev=curr;
            curr=curr->link;
        }
        prev->link=NULL;
    }
}

void InsertSpe()
{
    struct node *new=(struct node*) malloc(sizeof(struct node));
    printf("Enter The Item : ");
    scanf("%d",&item);
    printf("Enter The Key : ");
    scanf("%d",&key);
    if(head==NULL)
    {
        printf("Insertion Not Possible!Cause List Is EMpty!");
    }
    else
    {
        ptr=head;
        while(ptr->data!=key)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        new->data=item;
        new->link=ptr->link;
        ptr=new;
    }
}

void Display()
{
    if(head==NULL)
    {
        printf("List Empty!");
    }
    else
    {
        ptr=head;
        while(ptr!=NULL)
        {
            printf("%d \t",ptr->data);
            ptr=ptr->link;
        }
    }
}

void main()
{

}