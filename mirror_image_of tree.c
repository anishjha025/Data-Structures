#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}tree;


void insert(tree **root,int value)
{
	if(*root==NULL)
	{
		(*root)=(tree *)malloc(sizeof(tree));
		(*root)->data=value;
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;
	}
	else
	{
		tree *temp;
		temp=(*root);
		if(value<=temp->data)
		{
			insert(&(temp->lchild),value);
		}
		else
		{
			insert(&(temp->rchild),value);
		}
	}
}


void inorder(tree *root)
{
	tree *ptr;
	ptr=root;
	if(root==NULL)
	{
		return;
	}
	else if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		printf("%d   ",ptr->data );
		inorder(ptr->rchild);
	}



}

void mirror(tree *head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		mirror(head->lchild);
		mirror(head->rchild);

		tree *temp;
		temp=head->lchild;
		head->lchild=head->rchild;
		head->rchild=temp;
	}
}


int main()
{
	tree *root;
	root=NULL;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int value;
		scanf("%d",&value);
		insert(&root,value);
	}

	inorder(root);
	printf("\n");
	mirror(root);
	inorder(root);
	printf("\n");

}