/**************************************************
/* Name : Arjun Ashok                  Roll No:22
/*            ARRAY OPERATIONS
/* Date : 28/09/22                     Exp No : 3
***************************************************/
#include <stdio.h>
int pos,x,size,i;
int arr[20];

void insert()
{
    printf("Enter The Position : ");
    scanf("%d",&pos);
    printf("Enter The Element : ");
    scanf("%d",&x);
    if(pos>size)
    {
        printf("Not Possible");
    }
    else
    {
        for(i=size;i>=pos;i--)
        {
            arr[i+1]=arr[i];
        }
        size=size+1;
        arr[pos]=x;
    }
}

void delete()
{
    printf("Enter The Position To Delete : ");
    scanf("%d",&pos);
    for(i=pos;i<size;i++)
    {
        arr[i]=arr[i+1];
    }
    size=size-1;
}

void display()
{
    printf("\n");
    for(i=0;i<size;i++)
    printf("%d \t",arr[i]);
}
void menu()
{
    int mode;
    printf("Select The Operation\n1)Insert 2)Delete 3)Display 4)Exi\n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:insert();
        display();
        menu();
        case 2:delete();
        display();
        menu();
        case 3:display();
        menu();
        case 4:break;
        default:printf("Error!");
    }
}
void main()
{
    printf("Enter The Array Size : ");
    scanf("%d",&size);
    printf("Enter The Array Elements : ");
    for(i=0;i<size;i++)
    scanf("%d",&arr[i]);
    menu();
}
