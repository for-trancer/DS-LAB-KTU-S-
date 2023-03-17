#include <stdio.h>
void main()
{
    int a[20],n,low=0,mid,high,flag=0,x,pos,i;
    printf("Enter The Size : ");
    scanf("%d",&n);
    printf("Enter The Elements  : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the element to search : ");
    scanf("%d",&x);
    while(low=high)
    {
        mid=(low+high)/2;
        if(mid==x)
        {
            flag=1;
            pos=mid;
            break;
        }
        else if(x>mid)
        {
            low=mid+1;
        }
        else if(x<mid)
        {
            high=mid-1;
        }
    }
    if(flag==1)
    {
        printf("The Element %d is found at %d",x,pos);
    }
    if(flag==0)
    {
        printf("element not found!");
    }
}