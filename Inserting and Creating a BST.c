/* Inserting and Creating Binary Search Tree */




#include<stdio.h>
#include<stdlib.h>

struct node 
{
    struct node *lchild;
    int data;
    struct node *rchild;
}*root=NULL;


void insert(int key)

{
    struct node *t=NULL;
    struct node *r,*p;
    
    if(root==NULL)
    {
        p=(struct node *)malloc(sizeof(struct node));
        p->data=key;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    
    t=root;
    while(t!=NULL)
    
    {
        r=t;
        if(key<t->data)
          t=t->lchild;
        else if(key>t->data)
          t=t->rchild;
        else 
          return;
    }
    p=(struct node *)malloc(sizeof(struct node));
    p->data=key;
    p->lchild=p->rchild=NULL;
    if(key<r->data)  r->lchild=p;
    else   r->rchild=p;
}

void inorder(struct node *p)

{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}


int main()
{
    insert(10);
    insert(5);
    insert(20);
    insert(93);
    insert(45);
    insert(9);
    insert(91);
    inorder(root);
    return 0;
}
