#include <stdio.h>
#include <stdlib.h>
 
 struct node 
 {
     int co;
     int expo;
     struct node *link;
 };

 struct node *Phead,*Qhead,*Rhead;


 struct node * createList()
 {
     struct node *ptr,*head=NULL;
     int n,i;
     printf("Enter The Number Of Terms : ");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
         struct node *new;
         new=malloc(sizeof(struct node));
         new->link=NULL;
         printf("Enter The Co Efficient And Data : ");
         scanf("%d %d",&new->co,&new->expo);
         if(head==NULL)
         {
             head=new;
         }
         else
         {
             ptr=head;
             while(ptr->link!=NULL)
             {
                 ptr=ptr->link;
             }
             ptr->link=new;
         }
     }
     return head;
 }

 void display(struct node *head)
 {
     struct node *ptr;
     printf("Polynomial : \n");
     if(head==NULL)
     {
         printf("Empty!");
     }
     else
     {
         ptr=head;
         printf(" \n ( ");
         while(ptr->link!=NULL)
         {
             printf(" %d X ^ %d + ",ptr->co,ptr->expo);
             ptr=ptr->link;
         }
         printf(" %d X ^ %d ) \n",ptr->co,ptr->expo);
     }
 }

 struct node * addPoly()
 {
     struct node *new,*ptr,*P,*Q,*R,*head=NULL;
     P=Phead;
     Q=Qhead;
     while(P!=NULL&&Q!=NULL)
     {
         if(P->expo==Q->expo)
         {
             new=malloc(sizeof(struct node));
             new->link=NULL;
             new->co=P->co+Q->co;
             new->expo=P->expo;
             P=P->link;
             Q=Q->link;
         }
         else if(P->expo>Q->expo)
         {
             new=malloc(sizeof(struct node));
             new->link=NULL;
             new->co=P->co;
             new->expo=P->expo;
             P=P->link;
         }
         else
         {
             new=malloc(sizeof(struct node));
             new->link=NULL;
             new->co=Q->co;
             new->expo=Q->expo;
             Q=Q->link; 
         }
         if(head==NULL)
         {
             head=new;
             R=head;
         }
         else
         {
             R->link=new;
             R=new;
         }
     }
         while(P!=NULL)
         {
             new=malloc(sizeof(struct node));
             new->link=NULL;
             new->co=P->co;
             new->expo=P->expo;
             P=P->link;
             if(head==NULL)
             {
                 head=new;
                 R=head;
             }
             else
             {
                 R->link=new;
                 R=new;
             }
         }
         while(Q!=NULL)
         {
             new=malloc(sizeof(struct node));
             new->link=NULL;
             new->co=Q->co;
             new->expo=Q->expo;
             Q=Q->link;
             if(head==NULL)
             {
                 head=new;
                 R=head;
             }
             else
             {
                 R->link=new;
                 R=new;
             }
         }
         return head;
     }
     

 void main()
 {
     Phead=Qhead=Rhead=NULL;
     printf("Enter The First Polynomial : ");
     Phead=createList();
     printf("Enter The Second Polynomial : ");
     Qhead=createList();
     Rhead=addPoly();
     display(Phead);
     display(Qhead);
     display(Rhead);
 }

