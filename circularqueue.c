#include <math.h>
#include <stdio.h>
#define MAXSIZE 5
int queue[MAXSIZE], front=-1,rear=-1;

int isfull()
{
	printf("%d %d\n",front, rear);
	return ((abs(rear-front)%(MAXSIZE-1)==1)||(abs(rear-front)%(MAXSIZE-1)==0))&&(front!=-1&&rear==-1);
}

int isempty()
{
	return ((rear==-1)&&(front==-1))?1:0;
}

int peek()
{
	return queue[front];
}

void insert(int e)
{
	if(isfull())
		printf("QUEUE IS FULL\n");
	else
	{
		if(isempty())
			front++;
        queue[(++rear)%MAXSIZE]=e;
		printf("ELEMENT SUCESSFULLY INSERTED\n");
	}
}

void delete()
{
	if(isempty()==1)
		printf("QUEUE IS EMPTY\n");
	else
	{
		int d=queue[front];
		if(front==rear)
			front=rear=-1;
		else
			front=(front++)%MAXSIZE;
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
