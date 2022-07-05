// Binary Search Tree from Preorder //




#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
	  int data;
	  node *left;
	  node *right;
};

node *newnode(int data)
{
	node *temp=new node();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

node *constructtree(int pre[],int *preindex,int low,int high,int size)

{
	if(*preindex>=size||low>high)  return NULL;
	node *root= newnode(pre[*preindex]);
	*preindex+=1;
	if(low==high)  return root;
	int i;
	for(i=low;i<=high;++i)
	{
		if(pre[i]>root->data)
		  break;
	}
	root->left=constructtree(pre,preindex,*preindex,i-1,size);
	root->right=constructtree(pre,preindex,i,high,size);
	return root;
}

node *construct(int pre[],int size)
{
	int preindex=0;
	return constructtree(pre,&preindex,0,size-1,size);
}


void inorder(node *node)
{
	if(node==NULL)  return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}

int main()
{
	int pre[]={1,2,4,9,3,5,7,12,65,23};
	int size=sizeof(pre)/sizeof(pre[0]);
	node *root=construct(pre,size);
	inorder(root);
	return 0;
}
