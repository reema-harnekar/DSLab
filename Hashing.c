/*
Name:-Harnekar Reema Salahuddin
Roll No:- 16CO02
Description:-Implementation of Hashing .
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX_SIZE 10
int hash(int k)
{
	return k%MAX_SIZE;
}
int quadratic_probe(int h,int i)
{
	return (int)(h+pow(i,2))%MAX_SIZE;
}

int linear_probe(int h)
{
	return ++h%MAX_SIZE;
}

int  double_hash(int h,int i)
{
	return (h+i*linear_probe(h))%MAX_SIZE;
}



 void display(int a[])
 {
	 int i;
	 printf("Element of Array are...\n");
	 for(i=0;i<MAX_SIZE;i++)
		printf("%d\t",a[i]);
}

int main()
{
	int a[MAX_SIZE],i,h,e,count,c;
	for(i=0;i<MAX_SIZE;i++)
		a[i]=-1;
	do{
		count=0;
		printf(" Enter the Number to be stored=\n");
		scanf("%d",&e);
		h=hash(e);
		if(a[h]==-1)
		{
			a[h]=e;
			display(a);
		}
		else
			{
				while(count<MAX_SIZE)
			    {
				  count++;
				  printf("collision occured at %d\n",h);
				  printf(" Enter your choice\n");
				  printf("1.Quadratic_probing\n2.Double_hash\n3.Linear_probing\n");
				  scanf("%d",&c);
				  switch(c)
				  {
					  case 1:
							h=quadratic_probe(h,count);
							break;
					  case 2:
							h=double_hash(h,count);
							break;
					  case 3:
					        h=linear_probe(h);
					        break;
					  default :
					        printf("Invalid choice\n");
					        count--;
					        break;
				  }
					if(a[h]==-1)
					{
						a[h]=e;
						display(a);
						break;
					}

				}
			}
			if(count==MAX_SIZE)
			{
				printf("\n Array is Full or collision Resolution not successful");
				return 0;
			}
		}while(1);
	}

/*
OUTPUT:-
  Enter the Number to be stored=
25
Element of Array are...
-1	-1	-1	-1	-1	25	-1	-1	-1	-1
  Enter the Number to be stored=
21
Element of Array are...
-1	21	-1	-1	-1	25	-1	-1	-1	-1
  Enter the Number to be stored=
23
Element of Array are...
-1	21	-1	23	-1	25	-1	-1	-1	-1
 Enter the Number to be stored=
45
collision occured at 5
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
Element of Array are...
-1	21	45	23	-1	25	-1	-1	-1	-1
  Enter the Number to be stored=
89
Element of Array are...
-1	21	45	23	-1	25	-1	-1	-1	89
 Enter the Number to be stored=
87
Element of Array are...
-1	21	45	23	-1	25	-1	87	-1	89
  Enter the Number to be stored=
54
Element of Array are...
-1	21	45	23	54	25	-1	87	-1	89
 Enter the Number to be stored=
62
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
Element of Array are...
-1	21	45	23	54	25	-1	87	62	89
  Enter the Number to be stored=
2
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 4
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
Element of Array are...
2	21	45	23	54	25	-1	87	62	89
  Enter the Number to be stored=
12
collision occured at 2
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 4
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
collision occured at 5
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
3
Element of Array are...
2	21	45	23	54	25	12	87	62	89
* Enter the Number to be stored=
21
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 3
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 1
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
1
collision occured at 0
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 4
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
collision occured at 9
 Enter your choice
1.Quadratic_probing
2.Double_hash
3.Linear_probing
2
*/
