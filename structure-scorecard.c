#include <stdio.h>
void main()
{
    struct Student
    {
        char name[20];
        int sub1;
        int sub2;
        int sub3;
    };
    int i,clstotal=0,total,n,tot1=0,tot2=0,tot3=0;
    printf("Enter The Number Of Students : ");
    scanf("%d",&n);
    struct Student s[n];
    printf("Enter The Details : \n \n");
    for(i=0;i<n;i++)
    {
        printf("\n \n STUDENT %d -- \n \n",i+1);
        printf("Enter Name : ");
        scanf("%s",s[i].name);
        printf("Enter The Mark Of Subject 1 : ");
        scanf("%d",&s[i].sub1);
        printf("Enter The Mark Of Subject 2 : ");
        scanf("%d",&s[i].sub2);
        printf("Enter The Mark Of Subject 3 : ");
        scanf("%d",&s[i].sub3);
    }
    printf("\n\n SCORECARD \n\n");
    for(i=0;i<n;i++)
    {
        printf("\n\n STUDENT %d -- \n\n",i+1);
        printf("Name : %s \n",s[i].name);
        total=s[i].sub1+s[i].sub2+s[i].sub3;
        tot1=tot1+s[i].sub1;
        tot2=tot2+s[i].sub2;
        tot3=tot3+s[i].sub3;
        printf("Total : %d",total);
        clstotal=clstotal+total;
    }
    printf("\n\n CLASS TOTAL : %d \n\n SUBJECT ONE : %d \n SUBJECT 2 : %d \n SUBJECT 3 : %d",clstotal,tot1,tot2,tot3);
}