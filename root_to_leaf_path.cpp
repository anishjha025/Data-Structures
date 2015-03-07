/*
Algo:
initialize: pathlen = 0, path[1000] 
printPathsRecur(tree, path[], pathlen)
   1) If node is not NULL then 
         a) push data to path array: 
                path[pathlen] = node->data.
         b) increment pathlen 
                pathlen++
   2) If node is a leaf node then print the path array.
   3) Else
        a) Call printPathsRecur for left subtree
                 printPathsRecur(node->left, path, pathLen)
        b) Call printPathsRecur for right subtree.
                printPathsRecur(node->right, path, pathLen)

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node 
{
	int data;
	node *left,*right;
};


node *newNode(int data)
{
	struct node* node=(struct node*)malloc(sizeof(struct node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;

	return node;
}
void printans(int *arr,int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void printpathrec(struct node* node,int path[],int pathlen)
{
	if(node==NULL)
		return;
	path[pathlen++]=node->data;
	if(node->left==NULL && node->right==NULL)
		printans(path,pathlen);
	else
	{
		printpathrec(node->left,path,pathlen);
		printpathrec(node->right,path,pathlen);
	}
}

void printpaths(struct node *node)
{
	int path[1000];
	printpathrec(node,path,0);
}



int main()
{
	struct node *root=newNode(1);
	root->left =newNode(2);
	root->right=newNode(3);
	root->left->left=newNode(4);
	root->left->right=newNode(5);

	printpaths(root);

	return 0;
}