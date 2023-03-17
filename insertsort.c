
#include <stdio.h>

int key,i,j,n,temp;

int arr[20];

void readData()
{
    printf("Enter The Size : ");
    scanf("%d",&n);
    printf("Enter The Elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void Sort()
{
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
while(j>=0&&arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void Display()
{
    printf("Sorted Array : \n");
    for(i=0;i<n;i++)
    {
        printf("%d \t",arr[i]);
    }
}

void main()
{
    readData();
    Sort();
    Display();
}