#include <stdio.h>
#include <stdlib.h>

struct poly
{
    int co;
    int expo;
};

struct poly p1[20],p2[20],p3[20];
int data,i,j,k,size,t1,t2;

void readData(struct poly x[20],int size)
{
    for(i=0;i<size;i++)
    {
        printf("\n Term %d \n",i+1);
        printf("Enter The Coefficient : ");
        scanf("%d",&x[i].co);
        printf("Enter The Exponent : ");
        scanf("%d",&x[i].expo);
    }
}

void displayData(struct poly x[20],int size)
{
    printf("( ");
    for(i=0;i<size;i++)
    {
        if(i==size-1)
        {
            printf("(%d X ^ %d)",x[i].co,x[i].expo);
            continue;
        }
        printf("(%d X ^ %d) + ",x[i].co,x[i].expo);
    }
    printf(" )");
}

void addPoly(struct poly p1[20],struct poly p2[20],int t1,int t2)
{
    i=0,j=0,k=0;
    while(i<t1&&j<t2)
    {
        if(p1[i].expo==p2[j].expo)
        {
            p3[k].expo=p1[i].expo;
            p3[k].co=p1[i].co+p2[i].co;
            i++,j++,k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            p3[k].expo=p1[i].expo;
            p3[k].co=p1[i].co;
            i++,k++;
        }
        else
        {
            p3[k].expo=p2[j].expo;
            p3[k].co=p2[j].co;
            k++,j++;
        }
    }
    while(i<t1)
    {
        p3[k].expo=p1[i].expo;
        p3[k].co=p1[i].co;
        i++,k++;
    }
    while(j<t2)
    {
        p3[k].expo=p2[j].expo;
        p3[k].co=p2[j].co;
        j++,k++;
    }
}

void Menu()
{
    int mode;
    printf("\nSelect The Operation : \n1)Display Poly\n2)Add Polynomial\n3)Exit\n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:printf("Enter The No Of Terms : ");
        scanf("%d",&size);
        readData(p1,size);
        printf("\nPolynomial :\n");
        displayData(p1,size);
        Menu();
        break;
        case 2:printf("Enter The No Of Terms Of Both Polynomial : ");
        scanf("%d%d",&t1,&t2);
        printf("Enter The First Polynomial : \n");
        readData(p1,t1);
        printf("Enter The Second Polynomial : \n");
        readData(p2,t2);
        addPoly(p1,p2,t1,t2);
        printf("\nPoly 1 : \n");
        displayData(p1,t1);
        printf("\nPoly 2 : \n");
        displayData(p2,t2);
        printf("\nAfter Addition : \n");
        displayData(p3,k);
        Menu();
        break;
        case 3:break;
    }
}

void main()
{
    Menu();
}