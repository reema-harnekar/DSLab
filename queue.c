#include <stdio.h>
#define MAXSIZE 10
int queue[MAXSIZE], front=-1,rear=-1;

int isfull()
{ //returns 1 if stack is full else -1
	return rear==MAXSIZE-1;
}

int isempty()
{//returns 1 if stack is full else -1
	if ((rear==-1)&&(front==-1))
		return 1;
	else
		return 0;
}

int peek()
{//returns the element at the top of the stack
	printf("Front=%d",front);
	return queue[front];
}

void insert(int e)

{  //inserts an element in the stack
	if(isfull())
		printf("QUEUE IS FULL\n");
	else
	{
		if(isempty())
			front++;
		queue[++rear]=e;
		printf("ELEMENT SUCESSFULLY INSERTED\n");
	}
}

void delete()
{  //deletes an element from the stack
	if(isempty()==1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		int d=queue[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
		printf("%d successfully deleted\n",d);
	}
}

int main()
{
    int ch,e;
    do
    {
        printf("\n\tMENU\n1.PEEK\n2.DELETE\n3.INSERT\n4.EXIT\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("element at the front of queue is:%d",peek());
                   break;
            case 2:delete();
                   break;
            case 3:printf("\nenter the element to be inserted:");
                   scanf("%d",&e);
                   insert(e);
                   break;
            case 4:return 0;
        }
    }while(1);
    return 0;
}

