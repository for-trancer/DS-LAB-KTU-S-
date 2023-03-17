#include <stdio.h>

int arr[20],temp;
int i,j,min_idk,size;

void readData()
{
    printf("Enter The Size  : ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void Display(int arr[20],int size)
{
    for(i=0;i<size;i++)
    printf("%d \t",arr[i]);
}

void Sort()
{
    for(i=0;i<size;i++)
    {
        min_idk=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min_idk])
            {
                min_idk=j;
            }
        }
        if(min_idk!=i)
        {
            temp=arr[min_idk];
            arr[min_idk]=arr[i];
            arr[i]=temp;
        }
    }
}

void main()
{
    readData();
    Display(arr,size);
    Sort();
    printf("\n Sorted Array \n");
    Display(arr,size);
}