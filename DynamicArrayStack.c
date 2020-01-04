/* 
  
  File: DynamicArrayStack.c

  Coded by Ritesh Ratanparke. Date: 03/01/2020
  
  I've used the concepts of Dynamic memory allocation and pointers to create a dynamic array,
  using which I've implemented Stack Data Structure. I've used MinGW compiler on Microsoft Windows 10
  
  (MinGW.org GCC-8.2.0-5) 8.2.0
  Copyright (C) 2018 Free Software Foundation, Inc.
    
  If you want a better understanding of the Data Structure itself, check out my other code StaticArrayStack.c

  Thank you	
   
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *stack,size,top=-1; //declaring stack pointer,top variable and size globally to avoid passing too many function parameters

void createStack(int);  //creates a new stack of given size
void push(int); 		//inserts element into stack
int pop();  			//removes element from stack
void traverse();		//prints all elements in stack from bottom to top
void resize(int);		//resizes a stack dynamically
void fillRandom();		//completely fills a stack with random numbers between 1 and 100

int main()
{
	int i,element,option,size2;
	printf("\nThis program implements stack using a dynamic array via pointers\nEnter the size for the stack  ");
	scanf("%d",&size);
	createStack(size); 
	while(1)
	{
		
		printf("\n\nChoose your options\n1.Push Element\n2.Pop Element\n3.Traverse the stack\n4.Know stack status\n5.Change size of stack\n6.Randomly fill the stack\n7.Quit\n\nOption Entered: ");
		scanf("%d",&option);
	    switch(option)
        {
				case 1 : printf("\n\nEnter the element to be pushed\n");
						 scanf("%d",&element);		
						 push(element);			//invoke push()
						 break;
				
				case 2 : printf("\n\nThe element popped is %d\n",pop());		//invoke pop()
						 break;
						 
				case 3 : traverse();		//invoke traverse()
						 break;
 
				case 4 : printf("\n\nCapacity of stack is %d, number of elements in stack is %d\n",size,top+1); 
						 break;
				
				case 5:	printf("\n\nEnter new size for the stack\n",size2);
						scanf("%d",&size2);
						resize(size2);
						break;
				
				case 6:	fillRandom();
						break;
				
				case 7: free(stack);	//freeing allocated memory for stack
						exit(0);		//function to exit program
						break;
						
				default: printf("\nWrong option entered !\n");
						 break;	
		}
	}
getch();
return 1;
}

void createStack(int size)
{	
	stack = (int *)calloc(size,sizeof(int)); // allocating memory for stack pointer
}	
void push(int element)
{
	if(top==size-1)		//condition for stack to be full
		printf("\nStack full !");
		
	else
	{
		top++;
		*(stack+top) = element;	
	}	
}

int pop()
{
	int element;
	if(top == -1)		//condition for stack to be empty
		printf("\nThe stack is empty !");
		
	else
	{
		element = *(stack+top);
		top--;
	}
	return element;
}	

void traverse()
{
	int i=0;
	if(top==-1)
		printf("\nStack is empty !");
		
	else
	{	printf("\nResult:");
		for(i=0;i<top+1;i++)
		printf("%d ", *(stack+i) );	
	}
}

void resize(int size2)
{
 	int option2;
if(size2>=size)
	{	
		size = size2;
		realloc(stack,size*( sizeof(int) ) ); //allocating new size for stack
		printf("\n\nStack size changed to %d",size);
	}
	
else if(size2<size)
	{	if(size2< (top+1) )
		{	printf("\n\nWARNING. Entered stack size is lesser than current stack size,you will lose %d elements. Press 1 to continue, press 2 to exit  ",(top+1)-size2);	
			scanf("%d",&option2);
			if( option2 == 1)
			{	
				size = size2;
				realloc(stack,size*( sizeof(int) ) );
				top= size-1;
				printf("\nStack size changed to %d",size);
			}	
		}
		else
		{	size = size2;
			realloc(stack,size*( sizeof(int) ) );
			top= size-1;
			printf("\nStack size changed to %d",size);
		}	
	}
}

void fillRandom()
{	int i;
	if(top==-1)
	{
		for(i=0;i<size;i++)
		{
			*(stack+i) = ( rand() % 100) + 1;	//filling random values between 1 and 100
		}
		top = size-1;
	}
	else
	{
		for(i=top+1;i<size;i++)
		{
			*(stack+i) = ( rand() % 100) + 1;	
		}
		top = size-1;
	}	
}	