#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
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


void deletetree(struct node *node)
{
	if(node==NULL)
		return;
	deletetree(node->left);
	deletetree(node->right);
	printf("node->data=%d\n",node->data );
	free(node);
}

void deltree(struct node** ref)
{
	
	deletetree(*ref);
	*ref=NULL;
}

int main()
{
	struct node *root = newnode(1);
  	root->left        = newnode(2);
  	root->right       = newnode(3);
  	root->left->left  = newnode(4);
 	root->left->right = newnode(5);   
 	deltree(&root);

 	cout<<"root="<<root<<endl;

 

}