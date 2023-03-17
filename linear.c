#include <stdio.h>
void main()
{
    int a[20],n,item,i,flag=0,pos;
    printf("Enter The Size Of The Array !");
    scanf("%d",&n);
    printf("Enter The Element : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d \t",a[i]);
    }
    printf("Enter The Element To Search : ");
    scanf("%d",&item);
    for(i=0;i<n;i++)
    {
        if(a[i]==item)
        {
            flag=1;
            pos=i+1;
            break;
        }
    }
    if(flag==0)
    {
        printf("The Element %d Not Found!",item);
    }
    if(flag==1)
    {
        printf("Element %d is found at position %d",item,pos);
    }
}