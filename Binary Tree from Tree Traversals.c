/* Binary Tree from Tree Traversals */




#include<stdio.h>
#include<stdlib.h>


struct node
{
    char data;
    struct node *left;
    struct node *right;
};


int search(char arr[],int srt,int end,char value)
{
    for(int i=srt;i<=end;i++)
    {
        if(arr[i]==value)
        {
            return i;
        }
    }
    return 0;
}


struct node *buildtree(char inorder[],char preorder[],int srt,int end)
{
    struct node *newnode(char data);
    static int preindex=0;
    if(srt>end)
    {
        return 0;
    }
    struct node *tnode=newnode(preorder[preindex++]);
    if(srt==end)
    {
        return tnode;
    }
    int inindex=search(inorder,srt,end,tnode->data);
    tnode->left=buildtree(inorder,preorder,srt,inindex-1);
    tnode->right=buildtree(inorder,preorder,inindex+1,end);
    return tnode;
}


struct node *newnode(char data)
{
    struct node *node=(struct node*)malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return (node);
}


int printinorder(struct node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    printinorder(node->left);
    printf("%c ",node->data);
    printinorder(node->right);
    return 0;
}


int main()

{
    char inorder[]={'D','E','C','B','F','A','J','I','K','H','G'};
    
    char preorder[]={'A','D','E','B','C','F','I','J','K','G','H'};
    
    int len=sizeof(inorder)/sizeof(inorder[0]);
    struct node *root=buildtree(inorder,preorder,0,len-1);
    printinorder(root);
}
