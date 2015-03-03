/*
sameTree(tree1, tree2)
1. If both trees are empty then return 1.
2. Else If both trees are non -empty
     (a) Check data of the root nodes (tree1->data ==  tree2->data)
     (b) Check left subtrees recursively  i.e., call sameTree( 
          tree1->left_subtree, tree2->left_subtree)
     (c) Check right subtrees recursively  i.e., call sameTree( 
          tree1->right_subtree, tree2->right_subtree)
     (d) If a,b and c are true then return 1.
3  Else return 0 (one is empty and other is not)

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

int identical(struct node *a,struct node *b)
{
	if(a==NULL && b==NULL)
		return 1;
	if(a!=NULL && b!=NULL)
	{
		return(a->data==b->data && identical(a->left,b->left) && identical(a->right,b->right));
	}
	return 0;
}

int main()
{
    struct node *root1 = newnode(1);
    struct node *root2 = newnode(1);
    root1->left = newnode(2);
    root1->right = newnode(3);
    root1->left->left  = newnode(4);
    root1->left->right = newnode(5); 
 
    root2->left = newnode(2);
    root2->right = newnode(3);
    root2->left->left = newnode(4);
    root2->left->right = newnode(5); 
 
    if(identical(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
 
    
  return 0;
}