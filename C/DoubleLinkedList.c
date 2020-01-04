/* 
  File: DoubleLinkedList.c

  Coded by Ritesh Ratanparke. Date: 05/01/2020
  
  I've used MinGW compiler on Microsoft Windows 10
  
  (MinGW.org GCC-8.2.0-5) 8.2.0
  Copyright (C) 2018 Free Software Foundation, Inc.
       
*/
#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<math.h>

void insertAtBeginning(int);		//Inserts a node at beginning of list
void insertAtEnd(int);				//Inserts a node at the end of list
void insertAtPosition(int,int);		//Inserts node at a given position
void deleteAtBeginning();			//Deletes a node at the beginning of the list
void deleteAtEnd();					//Deletes a node at the end of the list
void deleteAtPosition(int);		    //Deletes a node at a given position
int displayAtPosition(int);	    	//Displays data in a node at a given position
void fillRandom(int);				//Adds given number of nodes in a list and fills them with random values (ranging from 1 to 100)
int listLength();					//Returns the number of nodes in the list
void printList();					//Displays data in all nodes in a list, starting from the first node
void swap(int,int);					//Swaps two elements of two given positions
void search(int);					//Searches for given element and returns position in list

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root = NULL;

void main()
{
	int option,option2,element,pos,n,pos2;
	printf("\n\nThis program implements a double linked list and its various operations\n");
	while(1)
	{
		printf("\n\n===============================================\nSelect an option\n\n1.Insert element\n2.Delete element\n3.Display\n4.Find length of list\n5.Fill list\n6.Swap elements\n7.Search\n8.Quit\n===============================================\n\nSelected option is ");
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
					
			case 3: printf("\nSelect one of the options\n\n1.Display all elements in list\n2.Display at a particular position\n\nSelect one of the options : ");
					scanf("%d",&option2);
					switch(option2)
					{
					case 1: printList();
							break;
					
					case 2: printf("\n\nEnter the position : ");
							scanf("%d",&pos);
							printf("\nThe element at position %d is %d",pos,displayAtPosition(pos));
							break;
					
					default:printf("\nWrong option entered !");
							break;
							
					}
					break;
			case 4:	
					printf("\nThe length of the list is %d",listLength());
					break;
			
			case 5: printf("\nEnter the number of elements to insert : ");
					scanf("%d",&n);
					fillRandom(n);
					break;
					
			case 6: printf("\nEnter the positions of the nodes to be swapped\n");
					scanf("%d %d",&pos,&pos2);
					swap(pos,pos2);
					break;
					
			case 7: 
					printf("\nEnter element to search for: ");
					scanf("%d",&element);
					search(element);
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
 


void insertAtBeginning(int element)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = element;
	if(root == NULL)
	{
		root = temp;
		temp->right = NULL;
		temp->left = NULL;
	}
	else
	{
		temp->left  = NULL;
		temp->right = root;
		root->left = temp;
		root = temp;
	}	

}
void insertAtEnd(int element)
{
	if(root==NULL)
		insertAtBeginning(element);
	else
	{
		struct node *p=root,*temp;
		temp = (struct node*)malloc(sizeof(struct node));
		while(p->right != NULL)
		{
			p = p->right;
		}
		temp->left = p;
		temp->data = element;
		p->right = temp;
		temp->right = NULL;
	}
}

void insertAtPosition(int element,int pos)
{
	if(pos==1)
		insertAtBeginning(element);
	else if(pos == listLength() )
		insertAtEnd(element);
	else if(pos <=0)
	{
		printf("\nIncorrect position entered\n");
	}
	else
	{	
		struct node *p = root,*temp,*q;
		temp = (struct node*)malloc(sizeof(struct node));
		int i;
		temp->data = element;
		for(i=1;i<pos;i++)
		{
			p = p->right;
		}
		q = p->left;
		p->left = temp;
		temp->right =p;
		q->right = temp;
		
	}	
}

void printList()
{
	if(root == NULL)
		printf("\nList empty !");
	else
	{	
		int i;
		struct node *p = root;
		printf("\n\nThe elements of the list are : ");
		while(p != NULL)
		{
			printf("%d ",p->data);
			p = p->right;
		}
			
	}
}

int displayAtPosition(int pos)
{
	int i;
	struct node *p = root;
	for(i=1;i<pos;i++)
	{
		p=p->right;
	}
	return p->data;
}

void deleteAtBeginning()
{
	root = root->right;
}

void deleteAtEnd()
{
	struct node *p = root,*q;
	while(p->right != NULL)
	{
		p=p->right;
	}
	q = p->left;
	p->left = NULL;
	q->right = NULL;
	
}

void swap(int pos1, int pos2)
{
	if( pos1==pos2 || pos1<=0 || pos2<=0)
		printf("\nIncorrect swap positions entered\n");
	else
	{
		int i;
		struct node *p=root,*q=root;
		for(i=1;i<pos1;i++)
		{
			p=p->right;
		}
		for(i=1;i<pos2;i++)
		{
			q =q->right; 
		}
		i = q->data;
		q->data = p->data;
		p->data = i;	
	}
}

void fillRandom(int n)
{
	int i=0,num;
	for(i=0;i<n;i++)
	{
		num = (rand() % 100)+1;
		insertAtEnd(num);
	}	
	
}

void deleteAtPosition(int pos)
{	
	struct node *p=root,*q=root,*r=root;
	if(pos<=0)
		printf("\nIncorrect position entered !");
	else
	{
		int i;
		for(i=1;i<pos;i++)
		{
			p = p->right;
		}
		q = p->left;		//pointer q points to node left of position
		r = p->right;		//pointer r points to node right of position
		p->left = NULL;
		p->right = NULL;
		q->right = r;
		r->left = q;
	}	
}

int listLength()
{
	if(root == NULL)
		return 0;
	else
	{	
		int count=0;
		struct node *p = root;
		while(p != NULL)
		{
			count++;
			p = p->right;
		}
		return count;
	}
}

void search(int element)
{	
    int count=0,found=0;
	struct node *p=root;
		while(p != NULL)
		{   
			count++;
			if(p->data == element)
			{	
				found++;
				break;
			}	
		    p = p->right;
			
		}
	
	if(count>=1&&found==1)
		printf("\nGiven search element %d was found at position %d in the list !\n",element,count);
	else
		printf("\nGiven search element %d not found in the list !\n",element);
	
	
}
