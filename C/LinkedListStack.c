/* 
  File: LinkedListStack.c
  
  This program implements Stack Data structure using a Single Linked List.
  
  Coded by Ritesh Ratanparke. Date: 08/01/2020
  
  I've used MinGW compiler on Microsoft Windows 10
  
  (MinGW.org GCC-8.2.0-5) 8.2.0
  Copyright (C) 2018 Free Software Foundation, Inc.
       
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

void push(int); 			//inserts element into stack, returns confirmation
int pop();		  			//removes element from stack, returns element
void displayStack();		//prints all elements in stack from bottom to top
void fillRandom();		    //completely fills a stack with random numbers between 1 and 100
int search(int);			//searched for element in stack and return position
int stackLength();			//returns the number of elements in the Stack


struct node
{
	int data;
	struct node *link;

};

struct node *top=NULL;


void main()
{
	int option,res,element,n;
	printf("\n\nThis program implements a Stack and its various operations using Single Linked List,hence the stack has no size limit\n");
	while(1)
	{
		printf("\n\n===============================================\nSelect an option\n===============================================\n\n1.Push element\n2.Pop element\n3.Display Stack\n4.Find length of Stack\n5.Fill Stack\n6.Search\n7.Quit\n===============================================\nSelected option is ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: 
				printf("\nEnter the element to be pushed in stack: ");
				scanf("%d",&element);
				push(element);
				printf("\nElement %d inserted succesfully\n",element);
				break;
				
			case 2: res = pop();
					if(res ==-1)
						printf("\nStack is empty !\n");
					else
						printf("\nPoped element is %d\n",res);
					break;	
				
			case 3: displayStack();
					break;
			case 4:	res = stackLength();
					if(res == -1)
						printf("\nStack is empty !\n");	
					printf("\nThe length of the Stack is %d\n",res);
					break;
			
			case 5: printf("\nEnter the number of elements to push : ");
					scanf("%d",&n);
					fillRandom(n);
					printf("\nStack filled with %d elements\n",n);
					break;
					
			case 6: printf("\nEnter element to search for: ");
					scanf("%d",&element);
					res = search(element);
					if(res == -1)
						printf("\nElement %d not found in stack\n",element);
					else
						printf("\nElement %d found at position %d in stack from top !",element,res);
					break;
			
			case 7: exit(0);
					break;
					
			default:
					printf("\nWrong option entered !!!\n");
					break;
		}
	}
	getch();
 }
 
 void push(int element)
 {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = element;
	temp->link = top;
	top = temp;
	temp= NULL;
 }
 
 void displayStack()
 {	if(top == NULL)
	 printf("\nStack is Empty !");
    else
	{
		struct node *temp;
		temp = top;
		printf("\nThe elements in the stack are:\n");
		while(temp != NULL)
		{	
			printf("\n\t||  %d  ||",temp->data);
			temp = temp->link;
		}
		printf("\n\t==========\n");
	}	
 }
 
 int pop()
 {
	if(top == NULL)
	{	
		//printf("\nStack empty !");
		return -1;
	}
	else
	{	
		int res;
		struct node *temp = top;
		res = temp->data;
		top = top->link;
		temp->link = NULL;
		free(temp);
		return res;
	}		
 }
 
 int stackLength()
 {
	if(top==NULL)
		return -1;
	else
	{	
		int count=0;
		struct node *temp = top;
		while(temp != NULL)
		{
			count++;
			temp = temp->link;
		}
		free(temp);
		return count;
	}
 }
 
 void fillRandom(int num)
 {
	int i,res;
	for(i=0;i<num;i++)
	{
		res =( rand() % 100)+1;
		push(res);
	}
 }
 
 int search(int element)
 {
	if(top == NULL)
		printf("\nStack Empty ! Atleast one element required for search operation");
	else
	{	
		int pos=0,found=0;
		struct node *temp = top;
		while(temp != NULL)
		{
			pos++;
			if(temp->data == element)
			{
				found = 1;
				break;
			}
			temp = temp->link;
		}
		if(found == 1)
			return pos;
		else
			return -1;
	}
 }
 

