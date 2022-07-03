/* Height and Count of  Binary Tree Implementation */



#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;
 
int count(node *p)
{
    if(p)
      return count(p->left)+count(p->right)+1;
    return 0;
}

int height(struct node *root)
{
    int x=0,y=0;
    if(root==0)
      return 0;
    x=(height(root->left));
    y=(height(root->right));
    if(x>y)
       return x+1;
    else return y+1;
    return 0;
}

node *create()
{
    node *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    if(x==-1)
    {
        return NULL;
    }
    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Enter left child of %d:\n",x);
    p->left=create();
 
    printf("Enter right child of %d:\n",x);
    p->right=create();
    return p;
}
 
void preorder(node *t)
{
    if(t!=NULL)
{
    preorder(t->left);
    printf("%d ",t->data);
    preorder(t->right); 
}
}
 
int main()
{
    node *root;
    root=create();
    printf("\nThe preorder traversal of tree is: ");
    printf("count = %d \n",count(root));
    printf("Height = %d \n",height(root));
    preorder(root);
    return 0;
}
