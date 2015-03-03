/*
size(tree)
1. If tree is empty then return 0
2. Else
     (a) Get the size of left subtree recursively  i.e., call 
          size( tree->left-subtree)
     (a) Get the size of right subtree recursively  i.e., call 
          size( tree->right-subtree)
     (c) Calculate size of the tree as following:
            tree_size  =  size(left-subtree) + size(right-
                               subtree) + 1
     (d) Return tree_size
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newnode(int data)
{
	struct node * node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;

	return node;
}

int size(struct node *node)
{
	if(node==NULL)
		return 0;
	else
		return(size(node->left) +1 +size(node->right));
}

int main(int argc, char const *argv[])
{
	/* code */
	struct node *root = newnode(1);
  	root->left        = newnode(2);
  	root->right       = newnode(3);
  	root->left->left  = newnode(4);
 	root->left->right = newnode(5);   
 
 	printf("Size of the tree is %d", size(root));  
  	getchar();
  	return 0;
	
}