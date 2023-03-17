#include <stdio.h>

int g[20][20],visited[20],queue[20],v1,v2,v,e,i,j;
int front=-1,rear=-1;
int dequeue()
{
    if(front==-1)
    {
        return -1;
    }
    else if(front==rear)
    {
        return queue[front];
        front=rear=-1;
    }
    else
    {
        return queue[front++];
    }
}
void enqueue(int x)
{
    if(front==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else
    {
        queue[rear++]=x;
    }
}

void BFS(int s)
{
    visited[s]=1;
    printf("%d->",s);
    enqueue(s);
    while(front!=-1)
    {
        s=dequeue();
        for(i=1;i<=v;i++)
        {
        if(g[s][i]==1&&visited[i]==0)
        {
            printf("%d->",i);
            visited[i]=1;
            enqueue(i);
        }
    }
}
}

void DFS(int i)
{
    int j;
    visited[i]=1;
    printf("%d->",i);
    for(j=1;j<=v;j++)
    {
        if(g[i][j]==1&&visited[j]==0)
        {
            DFS(j);
        }
    }
}
void main()
{
    printf("Enter The Number Of Vertices : ");
    scanf("%d",&v);
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            g[i][j]=0;
        }
    }
    printf("Enter The Number Of Edges : ");
    scanf("%d",&e);
    for(i=1;i<=e;i++)
    {
        printf("Enter The Vertices ( V1 and V2 ) Where A Edge is Present : ");
        scanf("%d%d",&v1,&v2);
        g[v1][v2]=1;
        g[v2][v1]=1;
    }
    printf("Adjacency Matrix : \n");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            printf("%d \t",g[i][j]);
        }
        printf("\n");
    }
    for(i=1;i<=v;i++)
    {
        visited[i]=0;
    }
    int source;
    printf("Enter The Source : ");
    scanf("%d",&source);
    printf("DFS : \n ");
    DFS(source);
    for(i=1;i<=v;i++)
    {
        visited[i]=0;
    }
    printf("\n BFS \n");
    BFS(source);
}