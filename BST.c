#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}bst;

bst *find_min(bst *t)
{
while(t->lchild!=NULL)
	t=t->lchild;
return(t);
}

void insert(bst **root,int value)
{
	if(*root==NULL)
	{
		(*root)=(bst *)malloc(sizeof(bst));
		(*root)->data=value;
		(*root)->lchild=NULL;
		(*root)->rchild=NULL;
	}
	else
	{
		bst *temp;
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

void inorder(bst *root)
{
	bst *ptr;
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

void preorder(bst *root)
{
	bst *ptr;
	ptr=root;
	if(root==NULL)
	{
		return;
	}
	else if(ptr!=NULL)
	{
		printf("%d   ",ptr->data );
		preorder(ptr->lchild);
		
		preorder(ptr->rchild);
	}



}

void postorder(bst *root)
{
	bst *ptr;
	ptr=root;
	if(root==NULL)
	{
		return;
	}
	else if(ptr!=NULL)
	{
		
		postorder(ptr->lchild);
		
		postorder(ptr->rchild);
		printf("%d   ",ptr->data );
	}



}


int search(bst *root,int value)
{
	bst *tmp=root;
	
	if(tmp==NULL)
	{
		
		return 0;
	}
	else if(tmp->data==value)
	{
		
		return 1;
	}
	else if(value>tmp->data)
	{
	
		return search(tmp->rchild,value);
	}
	else if(value<tmp->data)
	{
		
		return search(tmp->lchild,value);
	}
}




bst *deletenode(bst *root,int value)
{
	bst *temp;
	if(root==NULL)
	{
		printf("\nNot found!!!\n");
	}
	if(value<root->data)
	{
	
		root->lchild=deletenode(root->lchild,value);
		return(root);

	}
	if(value>root->data)
	{
		
		root->rchild=deletenode(root->rchild,value);
		return(root);

	}

	if(root->lchild==NULL && root->rchild==NULL)
	{
		free(root);
		return(NULL);
	}
	if(root->lchild==NULL)
	{
		temp=root;
		root=root->rchild;
		free(temp);
		return(root);
	}

	if(root->rchild==NULL)
	{
		temp->lchild=root->lchild;
		root->lchild=NULL;
		free(root);
		return(root);
	}

	bst *temp1=root;
	temp=find_min(temp1->rchild);
	root->data=temp->data;
	root->rchild=deletenode(root->rchild,root->data);
	return(root);


}


int main()
{
	bst *root;
	root=NULL;
	int choice,value,n,i,flag;
	do
	{
		printf("1.Insert\n2.Inorder display\n3.Preorder display\n4.Postorder display\n5.Delete\n");
		printf("6.Search\n7.Exit\n");
		printf("Enter your choice\t");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter number of nodes :");
				scanf("%d",&n);
				for(i=0;i<n;i++)
				{
					printf("Enter value:\t");
					scanf("%d",&value);
					insert(&root,value);
				}
				break;
			case 2:
				inorder(root);
				printf("\n");
				break;
			case 3:
				preorder(root);
				printf("\n");
				break;
			case 4:
				postorder(root);
				printf("\n");
				break;
			case 5:
				printf("Enter the value to be deleted\n");
				scanf("%d",&value);
				deletenode(root,value);
				
				break;
			case 6:
				printf("Enter the value to be searched\n");
				scanf("%d",&value);
				flag=search(root,value);
				if(flag==1)
				{
					printf("Value found\n");

				}
				else
				{
					printf("Value not found\n");
				}
				break;
			case 7:
				printf("Exit");
				break;


			default:
				printf("Please enter a valid choice\n");

		}
	}while(choice!=7);


}