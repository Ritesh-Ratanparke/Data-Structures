/* 
  File: LinkedListQueue.c
  
  This program implements Queue Data structure using a Single Linked List.
  
  Coded by Ritesh Ratanparke. Date: 08/01/2020
  
  I've used MinGW compiler on Microsoft Windows 10
  
  (MinGW.org GCC-8.2.0-5) 8.2.0
  Copyright (C) 2018 Free Software Foundation, Inc.
       
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>

void enqueue(int); 			//inserts element into Queue, returns confirmation
int dequeue();	  			//removes element from Queue, returns element
void displayQueue();		//prints all elements in Queue from bottom to top
void fillRandom();		    //completely fills a Queue with random numbers between 1 and 100
int search(int);			//searched for element in Queue and return position
int queueLength();			//returns the number of elements in the Queue
int peek();					//returns the first element to dequeue without dequeueing it


struct node
{
	int data;
	struct node *link;

};

struct node *front=NULL,*rear=NULL;


void main()
{
	int option,res,element,n;
	printf("\n\nThis program implements a Queue and its various operations using Single Linked List,hence the Queue has no size limit\n");
	while(1)
	{
		printf("\n\n===============================================\nSelect an option\n===============================================\n\n1.Enqueue element\n2.Dequeue element\n3.Display Queue\n4.Find length of Queue\n5.Fill Queue\n6.Search\n7.Peek\n8.Quit\n===============================================\nSelected option is ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: 
				printf("\nEnter the element to enqueue: ");
				scanf("%d",&element);
				enqueue(element);
				printf("\nElement %d inserted succesfully\n",element);
				break;
				
			case 2: res = dequeue();
					if(res ==-1)
						printf("\nQueue is empty !\n");
					else
						printf("\nDequeued element is %d\n",res);
					break;
				
			case 3: displayQueue();
					break;
					
			case 4:	res = queueLength();
					if(res == -1)
						printf("\nQueue is empty !\n");	
					printf("\nThe length of the Queue is %d\n",res);
					break;
			
			case 5: printf("\nEnter the number of elements to enqueue : ");
					scanf("%d",&n);
					fillRandom(n);
					printf("\nQueue filled with %d elements\n",n);
					break;
					
			case 6: printf("\nEnter element to search for: ");
					scanf("%d",&element);
					res = search(element);
					if(res == -1)
						printf("\nElement %d not found in Queue\n",element);
					else
						printf("\nElement %d found at position %d in Queue from front end !",element,res);
					break;
				
			case 7: res = peek();
					printf("\nThe first element to dequeue will be %d",res);
					break;
			
			case 8: exit(0);
					break;
					
			default:
					printf("\nWrong option entered !!!\n");
					break;
		}
	}
	getch();
 }
 
 void enqueue(int element)
 {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = element;
	temp->link = rear;
	rear = temp;
	if(front == NULL)
	{
		front = rear;
	}
	else
	{
		front = rear;
		while(front->link != NULL)
		{
			front = front->link;
		}
	}		
 }
 
 void displayQueue()
 {	if(front == NULL)
	 printf("\nQueue is Empty !");
    else
	{
		struct node *temp;
		temp = rear;
		printf("\nThe elements in the Queue are:\n");
		printf("\nRear =>");
		while(temp != NULL)
		{	
			
			printf("  %d  ",temp->data);
			
			temp = temp->link;
		}
		printf("<= Front");
		
	}	
 }
 
 int dequeue()
 {
	if(rear == NULL && front == NULL)
	{	
		printf("\nQueue empty !");
		return -1;
	}
	else
	{	
		int res;
		struct node *temp = rear;
		res = front->data;
		while(temp->link != front)
			temp = temp->link;
		front = temp;
		temp->link = NULL;
		return res;
	}		
 }
 
 int queueLength()
 {
	if(rear==NULL && front == NULL)
		return -1;
	else
	{	
		int count=0;
		struct node *temp = rear;
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
		enqueue(res);
	}
 }
 
 int search(int element)
 {
	if(rear == NULL && front == NULL)
		printf("\nQueue Empty ! Atleast one element required for search operation");
	else
	{	
		int pos=0,found=0;
		struct node *temp = rear;
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
			return (queueLength()-pos+1);
		else
			return -1;
	}
 }
 
 int peek()
 {
	if(front == NULL)
		printf("\nQueue empty ! ");
	else
	{
		return front->data;
	}
 }
 

