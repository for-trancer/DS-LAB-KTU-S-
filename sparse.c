#include <stdio.h>

int m,n,p,q,i,j,k,count=0,r1,r2,c1,c2;

int a[20][20],b[20][20],x[20][20],y[20][20],c[20][20],T[20][20];

void Display(int x[20][20],int m,int n)
{
    printf("\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d \t",x[i][j]);
        }
            printf("\n");
    }
        printf("\n");
}

void Transpose()
{
    k=1;
    printf("Enter The Order : ");
    scanf("%d%d",&m,&n);
    b[0][1]=m;
    b[0][2]=n;
    printf("Enter The Elements : ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    b[0][0]=m;
    b[0][1]=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                T[k][0]=j;
                T[k][1]=i;
                T[k][2]=a[i][j];
                k++;
                count++;
            }
        }
    }
    b[0][2]=count;
    T[0][0]=n;
    T[0][1]=m;
    T[0][2]=count;
    printf("Sparse Matrix : ");
    Display(a,m,n);
    printf("Triple Form : ");
    Display(b,count+1,3);
    printf("Transpose : ");
    Display(T,count+1,3);
}

void Add()
{
    printf("Enter The Order : ");
    scanf("%d %d",&m,&n);
    printf("Enter The Order : ");
    scanf("%d %d",&p,&q);
    if(m==p&&n==q)
    {
    printf("Enter The Elements : ");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter The Elements : ");
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    k=0;
    x[0][0]=m;
    x[0][1]=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++) 
            if(a[i][j]!=0)
            {
                k++;
                x[k][0]=i;
                x[k][1]=j;
                x[k][2]=a[i][j];
            }
        }
    }
    x[0][2]=k;
      k=0;
      y[0][0]=p;
      y[0][1]=q;
    for(i=0;i<p;i++)
    {
        for(j=0;j<q;j++)
        {
            if(b[i][j]!=0)
            {
                k++;
                y[k][0]=i;
                y[k][1]=j;
                y[k][2]=a[i][j];
            }
        }
    }
    y[0][2]=k;
    r1=x[0][0];
    r2=y[0][0];
    c1=x[0][1];
    c2=y[0][1];
    c[0][0]=x[0][0];
    c[0][1]=x[0][1];
    m=1,n=1,k=1;
    for(i=0;i<r1;i++)
    {
        for(j=0;j<c1;j++)
        {
            if(x[m][0]==i&&x[m][1]==j&&y[n][0]==i&&y[n][1]==j)
            {
                c[k][0]=x[m][0];
                c[k][1]=x[m][1];
                c[k][2]=x[m][2]+y[m][2];
                m++,n++,k++;
            }
            else if(x[m][0]==i&&x[m][1]==j)
            {
                c[k][0]=x[m][0];
                c[k][1]=x[m][1];
                c[k][2]=x[m][2];
                m++,k++;
            }
            else if(y[n][0]==i&&y[n][1]==j)
            {
               c[k][0]=y[n][0];
                c[k][1]=y[n][1];
                c[k][2]=y[n][2];
                n++,k++;
            }
        }
    }
    printf("Sparse Matrix After Addtion : ");
    Display(c,k,3);
    }
    else
    {
        printf("Sparse Addition Not Possible!");
    }
}

void Menu()
{
    int mode;
    printf("Select the Operation : \n1)Transpose\n2)Addtion\n3)Exit\n");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:Transpose();
        Menu();
        case 2:Add();
        Menu();
        case 3:break;
        default:printf("Invalid Mode Selection!");
        Menu();
    }
}
void main()
{
    Menu();
}
