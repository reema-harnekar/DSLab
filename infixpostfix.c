#include <stdio.h>
#include <ctype.>
typedef struct conversion
{
	char a[30];
	int top=-1;
}stack;
stack s;

void push(char);

char pop();

void convert(char[],char[]);

char pop();

int main()
{
	char infix[30],postfix[30];
	printf("\nenter the infix expression\n");
	scanf("%s",infix);
	convert(infix,postfix);
	printf("\n5the postfix expression is %s\n",postfix);
	return 0;
}

void convert(char in[], char post[])
{
	char opr;
	for(int i=0,j=0;in[i]!='\0';i++)
	{
		if(isalpha())
		post[j++]=in[i];
		if(in[i]=='(')
		push(in[i]);
		if(in[i]=='+'||in[i]=='*'||in[i]=='/'||in[i]=='-')
		{
			if(s.top!=-1)
			{
				opr=pop();
				while(priority(opr)>=priority(in[i])
				{
					post[j++]=opr;
					opr=pop()
				}
				push(opr);
				push(in[i]);
			}
			else
			push(in[i]);
		}
		if(in[i]==')')
		{
			opr=pop(s);
			while(opr!='(')
			{
				post[j++]=opr;
				opr=pop();
			}
		}
	}
	while(s.top!=-1)
	post[j++]=pop();
	post[j]='\0';
}
