#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	struct node* left;
	int data;
	struct node* right;
}bst;
bst* creation(int d)
{
	bst* newnode=(bst*)malloc(sizeof(bst));
	newnode->left=NULL;
	newnode->data=d;
	newnode->right=NULL;
	return newnode;
}
void addnode(bst **l,int d)
{
	if((*l) == NULL)
	{
		(*l)=creation(d);
		return;
	}
	else if((*l)->data == d)
	{
		printf("\nSimilar Elements Can't Be Added");
		return;
	}
	else if(d > (*l)->data)
	{
		if((*l)->right == NULL)
		{
			(*l)->right = creation(d);
			return;
		}	
		addnode(&((*l)->right),d);
	}
	else if(d < (*l)->data)
	{
		if((*l)->left == NULL)
		{
			(*l)->left = creation(d);
			return;
		}
		addnode(&((*l)->left),d);
	}
//	printf("\nNode Added");
}
void inorder(bst * i)
{
	if(i == NULL)
	{
//		printf("\nNo Tree Exists In INORDER");
		return;
	}
	inorder(i->left);
	printf("%d ",i->data);
	inorder(i->right);
}
void preorder(bst * pr)
{
	if(pr == NULL)
	{
//		printf("\nNo Tree Exists In PREORDER");
		return;
	}
	printf("%d ",pr->data);
	preorder(pr->left);
	preorder(pr->right);
}
void postorder(bst * po)
{
	if(po == NULL)
	{
//		printf("\nNo Tree Exists In POSTORDER");
		return;
	}
	postorder(po->left);
	postorder(po->right);
	printf("%d ",po->data);
}
int main()
{

	int dt=0,n=0,e=0;	
	bst *root=NULL;
	printf("\nAdd Elements(1) / Inorder Traversal(2) / Preorder Traversal(3) / Postorder Traversal(4) / Exit(5)");
	while(1)
	{
		printf("\nEnter Your Choice: ");
		scanf("%d",&e);
		switch(e)
		{
			case 1:printf("\nEnter Data: ");
				   scanf("%d",&dt);
				   addnode(&root,dt);
				   break;
			case 2:printf("\nINORDER: ");inorder(root);
				   break;
			case 3:printf("\nPREORDER: ");preorder(root);
			       break;
			case 4:printf("\nPOSTORDER: ");postorder(root);
			       break;
			case 5:return 0;
			default:printf("\nEnter A Correct Option");
		}
	}
}
