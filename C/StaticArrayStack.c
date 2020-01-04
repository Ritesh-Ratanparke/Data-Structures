#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define CAPACITY 6

void push(int);
int pop(void);
void traverse(void);
int isEmpty(void);
int isFull(void);
int stack[CAPACITY],top=-1,option,element;

void main()
{
	printf("\nThis program implements stack using a static array with size %d\n",CAPACITY);
	
	
	void push(int element)
	{
		if( top == CAPACITY-1)
			printf("\nStack is Full !");
		else
		{
			top++;
			stack[top]=element;
			printf("\nElement %d inserted !", element);
		}		
	}

	int pop()
	{
		int element;
		if( top == -1)
			printf("Stack is Empty !!");
		else
		{
			element=stack[top];
			top--;
		}
		return element;
	}
	
	void traverse()
	{
		int i;
		if( top == -1)
			printf("\nThe stack is empty ! Cannot Traverse !\n");
		else
		{
		for(i=0;i<top+1;i++)
		{
			printf(" %d",stack[i]);
		}
		}
	}
	
	while(1)
	{
		
		printf("\nChoose your options\n1.Push Element\n2.Pop Element\n3.Traverse the stack\n4.Know stack status\n5.Quit\n");
		scanf("%d",&option);
	    switch(option)
        {
				case 1 : printf("\nEnter the element to be pushed\n");
						 scanf("%d",&element);
						 push(element);
						 break;
				
				case 2 : printf("\nThe element popped is %d\n",pop());
						 break;
						 
				case 3 : traverse();
						 break;
 
				case 4 : if( top == -1)
							printf("\nStack is empty !\n ");
						 else if( top == CAPACITY-1)
							printf("\nStack is full !\n"); 
						 else
							printf("\nCapacity of stack is %d, number of elements in stack is %d\n",CAPACITY,top+1); 
						 break;
				
				case 5:	exit(0);	
				default: printf("\nWrong option entered !\n");
						 break;	
		}
	}
	
getch();
}