 #include <stdio.h>
 #include <stdlib.h>

 struct stack
 {
     int data;
     struct stack *link;
 };

 int data;

struct stack *top;
struct stack *ptr;
struct stack *temp;

void Display()
{
    if(top==NULL)
    {
        printf("List is empty!");
    }
    else 
    {
        ptr=top;
        while(ptr!=NULL)
        {
            printf("%d \t",ptr->data);
            ptr=ptr->link;
        }
    }
}

void Push(int data)
{
    struct stack* new=malloc(sizeof(struct stack));
    new->data=data;
    new->link=top;
    top=new;
}

void Pop()
{
    if(top==NULL)
    {
        printf("List is Empty!");
    }
    else
    {
        temp=top;
        top=top->link;
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
        Push(data);
        Display();
        Menu();
        break;
        case 2:Pop();
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