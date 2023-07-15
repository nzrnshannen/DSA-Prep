#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev_addr;
	struct node *next_addr;
}*head, *tail, *newNode, *freeNode, *nextNode, *clear, *currentNode, *temp;

int n;

void errorMsg();
void createList();
void displayList();
void displayLen();


void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_nth(int, int);

void delete_at_beginning();
void delete_at_end();
void delete_at_nth(int);

void reverseList();

void clearList();

int main()
{
	head=NULL;
	int choice, pos, num;

mainMenu:
	printf("===DOUBLY-LINKED LIST===\n");
	printf("[1] Create\n");
	printf("[2] Display\n");
	printf("[3] Insert\n");
	printf("[4] Delete\n");
	printf("[5] Reverse\n");
	printf("[6] EXIT\n");
	printf("---\nChoice: ");
	scanf("%d", &choice);
	
	if(n==0 && choice>1 && choice<6)
	{
		printf("\n\n\t\tCreate a list first!\n\n\n");
		goto mainMenu;
	}
	else
	{
		switch(choice)
		{
			case 1: 
				if(n==0)
				{
					printf("\n---\nEnter the number of nodes for your linked list: ");
					scanf("%d", &n);
					createList();
				}
				else
				{
				confirm_new:
					printf("\n\nYou have an existing list already.\nWould you like to delete the entire list first in order to create a new one?\n");
					printf("[1] Yes\n");
					printf("[2] No\n");
					printf("---\nChoice: ");
					scanf("%d", &choice);
					
					switch(choice)
					{
						case 1: clearList(); 
						printf("\n\n***************\nList deleted. Enter the number of nodes for your new linked list: ");
						n=0;
						head=NULL;
						scanf("%d", &n);
						createList();
						break;
						case 2: 
						printf("\n\nDecided not to delete list. Navigating to the menu...\n\n");
						goto mainMenu;
						
						default: errorMsg(); goto confirm_new;
					}
				}
			break;
			case 2:
				displayList();
			break;
			case 3: //insert
			printf("\n\t-- INSERTION --");
			displayLen();
			printf("\n***\nEnter new data: ");
			scanf("%d", &num);
		insertPos:
			printf("Enter a position: ");
			scanf("%d", &pos);
			
			if(pos<=0||pos>n)
			{
				errorMsg();
				goto insertPos;
			}
			
			if(pos==1)
			{
				insert_at_beginning(num);
			}
			else if(pos==n)
			{
				insert_at_end(num);
			}
			else
			{
				insert_at_nth(num, pos);
			}
				
			break;
			case 4: //delete 
			printf("\n\t-- DELETION --");
			displayLen();
			if(n==1)
			{
			confirmChoiceDeletion:
				printf("\n\nYou have only 1 node left on your list.\nWould you like to delete this node instead and create a new list?\n");
				printf("[1] Yes\n");
				printf("[2] No\n");
				printf("---\nChoice: ");
				scanf("%d", &choice);
				
				switch(choice)
				{
					case 1: 
					free(head);
					head=NULL;
					n=0;
					printf("\nNode has been deleted.\nEnter the number of nodes for your new list: ");
					scanf("%d", &n);
					createList();
					goto mainMenu;
					case 2: 
					printf("\nDecided not to delete the last node.\n");
					goto mainMenu;
					break;
					default: errorMsg(); goto confirmChoiceDeletion;
				}
			}
		deletionPos:
			printf("\n***\nEnter a position: ");
			scanf("%d", &pos);
			
			if(pos<=0 || pos>n)
			{
				errorMsg();
				goto deletionPos;
			}
			
			if(pos==1)
			{
				delete_at_beginning();
			}
			else if(pos==n)
			{
				delete_at_end();
			}
			else
			{
				delete_at_nth(pos);
			}
			break;
			
			
			case 5: //reverse
			reverseList();
			break;
			case 6: 
			//exit
			clearList();
			printf("\n\n**********************************\n\n\tPROGRAM TERMINATED");
			fflush(stdin);
			free(head);
			free(tail);
			free(temp);
			free(newNode);
			free(nextNode);
			free(currentNode);
			free(clear);
			free(freeNode);
			head=tail=temp=newNode=nextNode=currentNode=clear=freeNode=NULL;
			exit(1);
			break;
			
			default: errorMsg(); goto mainMenu;
		}
		
		goto mainMenu;
	}
}

void errorMsg()
{
	printf("\n\n\t\tInvalid input. Try again.\n\n\n");
}

void createList()
{
	int i=1;
	printf("\n***\nEnter data for your %d nodes\n", n);
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next_addr=newNode->prev_addr=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next_addr=newNode;
			newNode->prev_addr=tail;
			tail=newNode;
		}
		
		i++;
	}
	
	printf("\n\tSuccessfully created a list.\n\n");
	
}

void displayList()
{
	temp=head;
	printf("\n***\nLinked list: ");
	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next_addr;
	}
	
	printf("\n\n");
}

void insert_at_beginning(int data)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->prev_addr=NULL;
	newNode->next_addr=head;
	head->prev_addr=newNode;
	head=newNode;
	
	n++;
	printf("\n\nSuccessfully inserted a node at the beginning.\n===\n\n");	
}

void insert_at_end(int data)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next_addr=NULL;
	
	tail->next_addr=newNode;
	newNode->prev_addr=tail;
	tail=newNode;
	
	printf("\n\nSuccessfully inserted a node at the end.\n===\n\n");
	n++;
}

void insert_at_nth(int data, int pos)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next_addr=newNode->prev_addr=NULL;
	
	temp=head;
	int i=1;
	while(i<pos-1)
	{
		temp=temp->next_addr;
		i++;
	}	
	
	newNode->next_addr=temp->next_addr;
	newNode->prev_addr=temp;
	temp->next_addr=newNode;
	temp->next_addr->prev_addr=newNode;
	
	n++;
	printf("\n\nSuccessfully inserted a node at position %d.\n===\n\n", pos);
}

void delete_at_beginning()
{
	freeNode=head;
	head=head->next_addr;
	free(freeNode);
	head->prev_addr=NULL;
	
	n--;
	
	printf("\n\nSuccessfully deleted a node at the beginning.\n===\n\n");
}

void delete_at_end()
{
	freeNode=tail;
	tail=tail->prev_addr;
	tail->next_addr=NULL;
	free(freeNode);
	
	n--;
	
	printf("\n\nSuccessfully deleted a node at the end.\n===\n\n");
}

void delete_at_nth(int pos)
{
	int i=1;
	temp=head;
	while(i<pos)
	{
		temp=temp->next_addr;
		i++;
	}	
	
	freeNode=temp;
	nextNode=temp->next_addr;
	temp->prev_addr->next_addr=nextNode;
	nextNode->prev_addr=temp->prev_addr;
	free(freeNode);
	n--;
	
	printf("\n\nSuccessfully deleted a node at position %d.\n===\n\n", pos);
}

void reverseList()
{
	currentNode=nextNode=head;
	while(currentNode!=NULL)
	{
		nextNode=nextNode->next_addr;
		currentNode->next_addr=currentNode->prev_addr;
		currentNode->prev_addr=nextNode;
		currentNode=nextNode;
	}
	
	currentNode=head;
	head=tail;
	tail=currentNode;
	
	printf("\n\nList reversed.\n===\n\n");
}

void clearList()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next_addr;
		free(freeNode);
		freeNode=NULL;
	}
}

void displayLen()
{
	printf("\n\n\tNumber of nodes => %d\n\n", n);
}