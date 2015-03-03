#include <stdio.h>
#include <stdlib.h>

struct node {
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

void preorder(struct node *node)
{
	if(node==NULL)
		return;
	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}
void inorder(struct node *node)
{
	if(node==NULL)
		return;
	
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}
void postorder(struct node *node)
{
	if(node==NULL)
		return;
	
	postorder(node->left);
	
	postorder(node->right);
	printf("%d ",node->data);
}


int main()
{
	struct node *root = newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);

	printf("Preorder\n");
	preorder(root);
	printf("\n");

	printf("Inorder\n");
	inorder(root);
	printf("\n");

	printf("Postorder\n");
	postorder(root);
	printf("\n");
}
