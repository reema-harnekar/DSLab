//program to implement Binary Search Tree
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
void insert(node **r, int d)
{
	node *temp;
	temp=*r;
	if(temp==NULL)
	{
		printf("The given number is not found\n");
		return; 
	}
	else
	{
		if(temp->data==d)
		{
			if(temp->left==NULL&&temp->right==NULL)
				free(temp);
		}
		else
		{
			if(d>temp->data)
				delete(r->right,d);
			else
				delete(r->left,d);
			
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
int main()
{
	node *root;
	root=NULL;
	insert(&root,5);
	insert(&root,6);
	insert(&root,7);
	traverse_inorder(root);
	if(search(root,7))
		printf("the number is found\n");
	else
		printf("numbernot found\n");
	return 0;
}
