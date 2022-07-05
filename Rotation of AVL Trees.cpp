/* Rotation of AVL trees */




#include<bits/stdc++.h>
using namespace std;


class node
{
	public:
	  int data;
	  node * left;
	  node *right;
	  int height;
};


int max(int a,int b)
{
	return (a>b)?a:b;
}


int height(node *n)
{
	if(n==NULL)  return 0;
	return n->height;
}



node *rightrotate(node *y)
{
	node *x=y->left;
	node *t2=x->right;
	x->right=y;
	y->left=t2;
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
}


node *leftrotate(node *x)
{
	node *y=y->right;
	node *t2=x->left;
	y->left=x;
	x->right=t2;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}


int getbalance(node *n)
{
	if(n==NULL)   return 0;
	return height(n->left)-height(n->right);
}


node* newnode(int key)
{
    node* k = new node();
    k->data = key;
    k->left = NULL;
    k->right = NULL;
    k->height = 1;
    return(k);
}


node *insert(node *node,int key)
{
	if(node==NULL)  return (newnode(key));
	if(key<node->data)  node->left=insert(node->left,key);
	else if(key>node->data)  node->right=insert(node->right,key);
	else return node;
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getbalance(node);
    if (balance > 1 && key < node->left->data)
        return rightrotate(node);
    if (balance < -1 && key > node->right->data)
        return leftrotate(node);
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}


void preorder(node *root)
{
    if(root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}


int main()
  
{
    node *root = NULL;
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 20);
    root = insert(root, 50);
    root = insert(root, 10);
    root = insert(root, 24);
	  root = insert(root, 5);
	  root = insert(root, 15);
	  root = insert(root, 28);
	  root = insert(root, 4);
    cout << "Preorder traversal of the constructed AVL tree is \n";
    preorder(root);
     
    return 0;
  
}
