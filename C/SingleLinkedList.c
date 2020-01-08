/* 
  File: SingleLinkedList.c

  Coded by Ritesh Ratanparke. Date: 04/01/2020
  
  I've used MinGW compiler on Microsoft Windows 10
  
  (MinGW.org GCC-8.2.0-5) 8.2.0
  Copyright (C) 2018 Free Software Foundation, Inc.
    
*/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insertAtBeginning(int);		//Inserts a node at beginning of list
void insertAtEnd(int);				//Inserts a node at the end of list
void insertAtPosition(int,int);		//Inserts node at a given position
void deleteAtBeginning();			//Deletes a node at the beginning of the list
void deleteAtEnd();					//Deletes a node at the end of the list
void deleteAtPosition(int);			//Deletes a node at a given position
void displayAtPosition(int);		//Displays data in a node at a given position
void fillRandom(int);				//Adds given number of nodes in a list and fills them with random values (ranging from 1 to 100)
int listLength();					//Returns the number of nodes in the list
void printList();					//Displays data in all nodes in a list, starting from the first node
void swap(int,int);					//Swaps two elements of two given positions
void reverseList();					//Reverses the list

struct node					//defining structure of the linked list node
{
	int data;				//Data part
	struct node *link;		//Link part
};

struct node *root = NULL;	//Root element. Global variable

void main()
{
	int option,option2,element,pos,n,pos2;
	printf("\n\nThis program implements a single linked list and its various operations\n");
	while(1)
	{
		printf("\n\n\n===============================================\nSelect an option\n\n1.Insert element\n2.Delete element\n3.Display\n4.Find length of list\n5.Fill list\n6.Swap elements\n7.Reverse the list\n8.Quit\n===============================================\n\nSelected option is ");
		scanf("%d",&option);
		switch(option)
		{
			case 1: 
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&element);
				printf("\nWhere do you want the element inserted ?\n1.Beginning of List\n2.End of list\n3.At a position\nSelected option is : ");
				scanf("%d",&option2);
				switch(option2)
				{
					case 1: insertAtBeginning(element);
							break;
					
					case 2: insertAtEnd(element);
							break;
					
					case 3: printf("\n\nEnter the position where you want to insert the element: ");
							scanf("%d",&pos);
							insertAtPosition(element,pos);
							break;
					default:printf("\nWrong option entered !");
							break;
							
				}
				break;
				
			case 2: printf("\n\nSelect one of the options\n1.Delete at Beginning of list\n2.Delete at End of List\n3.Delete at a particular position\nOption entered is : ");
			        scanf("%d",&option2);
					switch(option2)
					{
					case 1: deleteAtBeginning();
							break;
					
					case 2: deleteAtEnd();
							break;
					
					case 3: printf("\n\nEnter the position where you want to delete the element: ");
							scanf("%d",&pos);
							deleteAtPosition(pos);
							break;
					default:printf("\nWrong option entered !");
							break;
							
					}
					break;
					
			case 3: printf("\nSelect one of the options\n\n1.Display all elements in list\n2.Display at a particular position\nSelect one of the options : ");
					scanf("%d",&option2);
					switch(option2)
					{
					case 1: printList();
							break;
					
					case 2: printf("\n\nEnter the position : ");
							scanf("%d",&pos);
							displayAtPosition(pos);
							break;
					
					default:printf("\nWrong option entered !");
							break;
							
					}
					break;
			case 4:	
					printf("\nThe length of the list is %d",listLength());
					break;
			
			case 5: printf("\nEnter number of elements to fill in list : ");
					scanf("%d",&n);
					fillRandom(n);
					break;
					
			case 6: printf("\nEnter the positions of the nodes to be swapped\n");
					scanf("%d %d",&pos,&pos2);
					swap(pos,pos2);
					break;
			
			case 7: reverseList();
					printf("\nThe list is reversed !\n");
					break;
			case 8: 
					exit(0);
					break;
			
			default: printf("\nWrong option entered !!!\n");
					break;
		}
	}
getch();
}

void insertAtBeginning(int element)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = element;
	if(root == NULL)
	{
		root = temp;
		temp->link = NULL;
	}
	else
	{
		temp->link = root;
		root = temp;
	}
}
void insertAtEnd(int element)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));	//creating temporary variable and allocating memory,assigning value
	temp->data = element;
	temp->link = NULL;
	if( root == NULL)
	{
		root = temp;	
	}
	else
	{
		struct node *p = root;		//pointer created for traversal till last node
		while(p->link != NULL)
		{
			p = p->link;				//traversing till last node is found
		}
		p->link = temp;
	}
}

void insertAtPosition(int element,int pos)
{
	if(pos == 1)
		insertAtBeginning(element);
	else if(pos == listLength())
		insertAtEnd(element);
	else if(pos > listLength() )
		printf("\nERROR. Position entered is greater than list size !");
	else
	{
		struct node *temp = (struct node*)malloc(sizeof(struct node));
		struct node *p,*q;
		int c;
		temp->data = element;
		p = root;
		q = root;
		for(c=1;c<pos;c++)
		{
			p = p->link;  //traversing to given position
		}
		for(c=1;c<pos-1;c++)
		{
			q = q->link;  //traversing to given position
		}
		temp->link = p;
		q->link = temp;
			
	}
}

void deleteAtBeginning()
{
	root = root ->link;
}

void deleteAtEnd()
{	
	int i,l=listLength();
	struct node *p = root, *q=root;
	for(i=1;i<l-1;i++)
	{
		p = p->link;
	}
    p->link = NULL;	
}

void deleteAtPosition(int pos)
{	int l = listLength();
	if(pos == 1)
		deleteAtBeginning();
	else if(pos == l)
		deleteAtEnd();
	else if(pos>l)
		printf("\nERROR. Position entered is greater than list size !");
	else
	{	int i;
		struct node *p=root,*q=root,*r=root;
		for(i=1;i<pos;i++)
			q = q->link;
		for(i=1; i<(pos-1) ;i++)
			p = p->link;
		for(i=1;i< (pos+1) ;i++)
			r = r->link;
		q->link = NULL;
		p->link = r;
		free(q);
	}		
}

void displayAtPosition(int pos)
{
	struct node *p = root;
	int i;
	for(i=1;i<pos;i++)
	{
		p = p->link;
	}
    printf("\nThe element at position %d is %d\n",pos,p->data);	
}

int listLength()
{	int count=0;
		struct node *p = root;
		while(p != 0)
		{
			p = p->link;
			count++;
		}
		
		return count;
		
}

void printList()
{
	struct node *p = root;
	if(root == NULL)
		printf("\nList is empty !");
	else
	{
		while( p != NULL)
		{
			printf("%d ",p->data);
			p = p->link;
		}
	}
}

void fillRandom(int size)
{
	int i=0,n;
	for(i=0;i<size;i++)
	{
		n = ( rand() % 100) + 1;
		insertAtEnd(n);
	}	
}

void swap(int pos1,int pos2)
{	
	int i,temp;
	struct node *p = root,*q = root;
	for(i=1;i<pos1;i++)
	{
		p = p->link;
	}
	for(i=1;i<pos2;i++)
	{
		q = q->link;
	}
	
	temp = q->data;
	q->data = p->data;
	p->data = temp;
	
}

void reverseList()
{
	int i,j,temp,length,pos=0;
	struct node *p,*q;
	i=1; j=listLength();
	while(i<j)
	{
		p=q=root;	//bring pointers to first node
		for(pos=1;pos<i;pos++)
		{
			p=p->link;	//navigate p to position "i"
		}
		for(pos=1;pos<j;pos++)
		{
			q = q->link;	//navigate q to position "j"
		}
		temp = q->data;
		q->data = p->data;  //swap data of position i and j
		p->data = temp;
		i++;				
		j--;
		
	}
}