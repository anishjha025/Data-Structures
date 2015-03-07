#include <iostream>
#include <string.h>
using namespace std;

struct node
{
char data;
node *lchild,*rchild;
};

class tree
{   node *root;
    void postorder1(node*);
    void preorder1(node*);
	node *createpreorder(char *,char *);/*create tree from pre+in*/
	node *createpostorder(char *,char *);/*create tree from post+in*/
    public:


    void createpre(char *pre,char *in)
 	{
	root=createpreorder(pre,in);
	}/*create tree from pre+in*/
    void createpos(char *pos,char *in)
    {
    root=createpostorder(pos,in);
    }/*create tree from post+in*/
    void dividepre(char *,char *,char *,char *,char *,char *);//to create subtrees
    void dividepos(char *,char *,char *,char *,char *,char *);//to create subtrees
    void preorder(){preorder1(root);}
    void postorder(){postorder1(root);}
    int belongs(char ,char a[]);
};

int tree::belongs(char x,char a[])
{
int i;
	for(i=0;a[i]!='\0';i++)
		if(a[i]==x)
		return(1);
return 0;
}

int main()
{
tree t;
char pre[20],in[20],post[20];
int ch;
do
{
    cout<<"\nMenu\n1.Preorder+inorder\n2.Postorder+inorder\n3.exit\n";
    cout<<"Please enter your choice:\t";
    cin>>ch;
    switch(ch)
    {
    case 1:
    cout<<"\nenter the preorder:\t";
    cin>>pre;
    cout<<"\nenter the inorder :\t";
    cin>>in;
    t.createpre(pre,in);
    cout<<"\npostorder of the binary tree is:\t";
    t.postorder();
    break;

    case 2:
    cout<<"\nenter the postorder:\t";
    cin>>post;
    cout<<"\nenter the inorder  :\t";
    cin>>in;
    t.createpos(post,in);
    cout<<"\npreorder of the binary tree is:\t";
    t.preorder();
    break;

    default:
    cout<<"invalid choice\n";
    break;

    }
}while(ch!=3);

}

node *tree::createpreorder(char *pre,char *in)
{
char  pre1[20],pre2[20],in1[20],in2[20];
node *p=NULL;
if(strlen(pre)==0)
    return(NULL);
p=new node;
p->data=pre[0];
dividepre(pre,in,pre1,pre2,in1,in2);
p->lchild=createpreorder(pre1,in1);
p->rchild=createpreorder(pre2,in2);
return p;
}

node *tree::createpostorder(char *pos,char *in)
{
int len;
char pos1[20],pos2[20],in1[20],in2[20];
node *p=NULL;
if (strlen(pos)==0)
return(NULL);
p=new node;
len=strlen(pos);
p->data=pos[len-1];
dividepos(pos,in,pos1,pos2,in1,in2);
p->lchild=createpostorder(pos1,in1);
p->rchild=createpostorder(pos2,in2);
return p;
}

void tree::dividepre(char *pre,char *in,char *pre1,char *pre2,char *in1,char *in2)
{
int i,j,k;
for(i=0;in[i]!=pre[0];i++)//inorder of left subtree
    in1[i]=in[i];
in1[i]='\0';
i++;
for(j=0;in[i+j]!='\0';j++)//inorder of right subtree
    in2[j]=in[i+j];
in2[j]='\0';
i=j=0;
for(k=1;pre[k]!='\0';k++)
    if(belongs(pre[k],in1))
        pre1[i++]=pre[k];   //preorder of left subtree
    else
        pre2[j++]=pre[k];   //preorder of right subtree
pre1[i]=pre2[j]='\0';

}

void tree::dividepos(char *pos,char *in,char *pos1,char *pos2,char *in1,char *in2)
{
int i,j,k;
char x=pos[strlen(pos)-1];
for(i=0;in[i]!=x;i++)
    in1[i]=in[i];
in1[i]='\0';
i++;
for(j=0;in[i+j]!='\0';j++)
    in2[j]=in[i+j];
in2[j]='\0';
i=j=0;
for(k=0;k<strlen(pos)-1;k++)
    if(belongs(pos[k],in1))
        pos1[i++]=pos[k];
    else
        pos2[j++]=pos[k];
pos1[i]=pos2[j]='\0';

}

void tree::postorder1(node *t)
{
if(t!=NULL)
{
    postorder1(t->lchild);
    postorder1(t->rchild);
    cout<<t->data;
}
}

void tree::preorder1(node *t)
{
if(t!=NULL)
{
        cout<<t->data;
        preorder1(t->lchild);
        preorder1(t->rchild);
}
}



