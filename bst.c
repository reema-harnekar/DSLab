/*
Aim:-
Program to implement binary search tree.
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct bst
{
	int data;
	struct bst *left, *right;
}node;
node * create(int d)
{
	node *ptr;
	ptr=(node*)malloc(sizeof(node));
	ptr->data=d;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}
void traverse_inorder(node *r)
{
	if(r!=NULL)
	{
		traverse_inorder(r->left);
		printf("%d\t",r->data);
		traverse_inorder(r->right);
	}
}
void insert(node **r, int d)
{
	node *temp, *ptr;
	temp=*r;
	if(temp==NULL)
	{
		ptr=create(d);
		*r=ptr;
	}
	else
	{
		if(d>temp->data)
		{
			if(temp->right==NULL)
			{
				ptr=create(d);
				temp->right=ptr;
				return;
			}
			else
			{
				temp=temp->right;
				insert(&temp,d);
			}
		}
		else
		{
			if(temp->left==NULL)
			{
				ptr=create(d);
				temp->left=ptr;
				return;
			}
		}
	}
}
int search(node *r, int d)
{
	if(r==NULL)
		return -1;
	else
	{
		if(r->data==d);
			return 1;
		if(d>r->data)
			search(r->right,d);
		else
			search(r->left,d);
	}
}

void search_node(node **x,node*root,node**parent,int num,int*f)
{
	node *temp;
	temp=root;
	if(temp==NULL)
		return;
    while(temp!=NULL)
	{
		if(temp->data==num)
	  {
		*f=1;
		*x=temp;
		return;
	  }
		*parent=temp;
		if(num>temp->data)
			temp=temp->right;
		else
			temp=temp->left;
	}

}

void delete(node**r,int num)
{
	node *temp,*parent,*xsucc,*x;
	int f=0;
	parent=NULL;
	x=NULL;xsucc=NULL;
	temp=*r;
	search_node(&x,temp,&parent,num,&f);

	if(f==0)
	{
		printf("\n The given no. is not found");
		return;
	}

	if(x->left==NULL && x->right==NULL)			   //x has no child
	{
		if(x->data > parent->data)
			parent->right=NULL;
		else
			parent->left=NULL;
	}
	 else if(x->left!=NULL && x->right==NULL)			//x has left child
	{
		if(x->data > parent->data)
			parent->right=x->left;
		else
			parent->left=x->left;
	}
	else if (x->left==NULL && x->right!=NULL)			//x has right child
	{
		if(x->data > parent->data)
			parent->right=x->right;
		else
			parent->left=x->right;
	}
	else if (x->left!=NULL && x->right!=NULL)			//x has both child
	{
		parent=x;
		xsucc=x->right;
		while(xsucc->left!=NULL)
		{
			parent=xsucc;
			xsucc=xsucc->left;
		}
		if(xsucc->data > parent->data)
			parent->right=NULL;

		else
			parent->left=NULL;
		x->data=xsucc->data;
		x=xsucc;
	}
	free(x);
}
int main()
{
	node *root;
	root=NULL;

	return 0;
}
