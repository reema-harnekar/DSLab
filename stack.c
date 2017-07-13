#include <stdio.h>
#define MAXSIZE 10
int stack[MAXSIZE], top=-1;

int isfull()
{ //returns 1 if stack is full else -1
	if(top==(MAXSIZE-1))
		return 1;
	else 
		return-1;
}

int isempty() 
{//returns 1 if stack is full else -1
	if (top==-1)
		return 1;
	else 
		return -1;
}

int peek()
{//returns the element at the top of the stack
	return stack[top];
}

int push(int e)
{  //inserts an element in the stack
	if(isfull()==1)
		printf("STACK OVERFLOW\n");
	else
	{
		stack[++top]=e;
		printf("element successfully inserted\n");
	}
}

void pop()
{  //deletes an element from the stack
	if(isempty()==1)
		printf("STACK UNDERFLOW\n");
	else
	{
		int d=stack[top--];
		printf("%d successfully deleted\n",d);
	}
}

int main()
{ 
	int ch;
	do while
	{
		printf("\tMENU\n1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
		printf("\tenter your choice\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
			       break;
			case 2:pop();
			       break();
			case 3:peek();
			       break;
		}
		




