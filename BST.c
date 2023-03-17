#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left,*right;
};

struct Node * newNode(int data)
{
    struct Node * node;
    node=malloc(sizeof(struct Node));
    node->data=data;
    node->left=node->right=NULL;
    return node;
}

struct Node * insertNode(struct Node *node,int data)
{
    if(node==NULL)
    {
        return newNode(data);
    }
    else
    {
        if(data<=node->data)
        {
            node->left=insertNode(node->left,data);
        }
        else
        {
            node->right=insertNode(node->right,data);
        }
    }
    return node;
}

struct Node * findMin(struct Node * node)
{
    while(node->left!=NULL)
    {
        node=node->left;
    }
    return node;
}

struct Node * deleteNode(struct Node * root,int data)
{
     if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root;
            root = root->right;
            free(temp); 
        } else if (root->right == NULL) {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
}

void in(struct Node * node)
{
    if(node!=NULL)
    {
        in(node->left);
        printf("%d \t",node->data);
        in(node->right);
    }
}
void pre(struct Node * node)
{
    if(node!=NULL)
    {
        printf("%d \t",node->data);
        pre(node->left);
        pre(node->right);
    }
}
void post(struct Node * node)
{
    if(node!=NULL)
    {
       pre(node->left);
       pre(node->right);
       printf("%d \t",node->data);
    }
}


void main()
{
    int mode;
    struct Node * root=NULL;
    do
    {
        int data;
    printf("Select The Mode : 1)Insert 2)Delete 3)Display 4)Exit");
    scanf("%d",&mode);
    switch(mode)
    {
        case 1:printf("Enter The Data : ");
        scanf("%d",&data);
        root=insertNode(root,data);
        in(root);
        printf(" \n");
        break;
        case 2:printf("Enter The Node Data To Delete : ");
        scanf("%d",&data);
        root=deleteNode(root,data);
        printf(" \n");
        in(root);
        break;
        case 3:printf(" \n");
        in(root);
        printf(" \n");
        pre(root);
        printf(" \n");
        post(root);
        break;
    }
    } while (mode!=4);
}
