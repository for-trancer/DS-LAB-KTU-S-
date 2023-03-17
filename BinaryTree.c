#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};


struct node *root=NULL,*new;

struct node * createNode()
{
    new=malloc(sizeof(struct node));
    new->left=new->right=NULL;
    printf("Enter The Data : ");
    scanf("%d",&new->data);
    return new;
}

int buildTree(struct node *temp)
{
    if(root==NULL)
    {
        printf("(Root) : \n");
        temp=createNode();
        root=temp;
        buildTree(temp);
    }
    else
    {
        int mode;
        printf("%d -> [Left Child] (1/0) : ",temp->data);
        scanf("%d",&mode);
        if(mode==1)
        {
            temp->left=createNode();
            buildTree(temp->left);
        }
        printf("%d -> [Right Child] (1/0) : ",temp->data);
        scanf("%d",&mode);
        if(mode==1)
        {
            temp->right=createNode();
            buildTree(temp->right);
        }
        return 0;
    }
}

void in(struct node *root)
{
    if(root!=NULL)
    {
        in(root->left);
        printf("%d \t",root->data);
        in(root->right);
    }
}
void pre(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d \t",root->data);
        pre(root->left);
        pre(root->right);
    }
}

void main()
{
    buildTree(root);
    printf("InOrder : ");
    in(root);
    printf("\nPreOrder : ");
    pre(root);
}