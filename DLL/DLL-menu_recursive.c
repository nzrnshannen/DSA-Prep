/*
	Name: Shannen T. Nazareno
	Program: DLL Menu (Recursive): Create, Display, Insert, Delete, Reverse, and Search
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
	struct node* prev;
}*head, *tail, *newNode, *clear, *freeNode, *temp, *nextNode, *currentNode;

void insert_at_beginning(int);
void insert_at_end(int);
void insert_at_nth(int, struct node*, int, int);

void delete_at_beginning();
void delete_at_end();
void delete_at_nth(int, int, struct node*);

void displayList(struct node*);
void createList(int);
void reverseList(struct node*, struct node*);

int searchList(struct node*, int, int, int, int);

void errorMsg();
void clearList();
void displayNo();

int n;
int main()
{
	head=NULL;
	int choice, pos, data, numSearch;

mainMenu:
	printf("===DOUBLY-LINKED LIST===\n");
	printf("[1] Create\n");
	printf("[2] Display list\n");
	printf("[3] Insert node\n");
	printf("[4] Delete node\n");
	printf("[5] Reverse list\n");
	printf("[6] Search data\n");
	printf("[7] EXIT\n---\nChoice: ");
	scanf("%d", &choice);
	
	if(n==0 && choice>1 && choice<7)
	{
		printf("\n\n\t\tCreate a list first!\n\n\n");
		goto mainMenu;
	}
	else
	{
		switch(choice)
		{
			case 1: //create 
			if(n==0)
			{
			enterNumNodes: 
				printf("\n***\nEnter the number of nodes for your linked list: ");
				scanf("%d", &n);
				if(n<=0)
				{
					errorMsg();
					goto enterNumNodes;
				}
				printf("Enter data for your %d nodes\n", n);
				createList(1);
			}
			else
			{
			
			confirmCreate:
				printf("\nYou already have an existing list.\nDo you wish to proceed by deleting the previous list in order to make a new one?\n");
				printf("[1] Yes\n[2] No\n---\nChoice: ");
				scanf("%d", &choice);
				
				switch(choice)
				{
					case 1: 
					clearList();
					head=NULL;
					n=0;
				inputNew:
					printf("\n\nList cleared. Enter the number of nodes for your new list: ");
					scanf("%d", &n);
					
					if(n<=0)
					{
						errorMsg();
						goto inputNew;
					}
					
					printf("\n***\nEnter data for your %d nodes\n", n);
					createList(1);
					break;
					case 2: 
					printf("\n\nDecided not to delete list.\nNavigating to the main menu...\n\n\n");
					goto mainMenu;
					
					default: errorMsg(); goto confirmCreate;
				}
			}
			
			break;
			
			case 2: //display
			printf("\n========\nLinked list: ");
			displayList(head);
			break;
			
			case 3: //insert
			printf("\n--- INSERTION ---\n");
			displayNo();
			printf("***\nEnter new data to insert: ");
			scanf("%d", &data);
			
			if(n==1)
			{
			
			insertOption: 
				printf("\n\nYou only have one node on the list. \nWhere do you want to insert this new data?\n[1] Before the existing node\n[2] After the existing node\n---\nChoice: ");
				scanf("%d", &choice);
				
				switch(choice)
				{
					case 1: insert_at_beginning(data); break;
					case 2: insert_at_end(data); break;
					
					default: errorMsg(); goto insertOption;
				}
				
				goto mainMenu;
			}
		enterInsertPos:
			printf("Enter position: ");
			scanf("%d", &pos);
			
			if(pos<=0 || pos>n)
			{
				errorMsg();
				goto enterInsertPos;
			}
			else if(pos==1)
				insert_at_beginning(data);
			else if(pos==n)
				insert_at_end(data);
			else
				insert_at_nth(data, head, 1, pos);
			break;
			case 4: //delete 
			if(n==1)
			{
			confirmDeletionList:
				printf("\n\nYou only have 1 node on the list.\nDo you want to delete this instead?\n[1] Yes\n[2] No\n---\nChoice: ");
				scanf("%d", &choice);
				
				switch(choice)
				{
					case 1: 
					free(head);
					head=NULL;
					n=0;
				ifCreate:
					printf("\n\n*****\nList cleared. Do you want to create a new one?\n[1] Yes\n[2] No\n---\nChoice: ");
					scanf("%d", &choice);
					switch(choice)
					{
						case 1: printf("\n\n");
					inputAgainLen:
						printf("***\nEnter the number of nodes for your new linked list: ");
						scanf("%d", &n);
						
						if(n<=0)
						{
							errorMsg();
							goto inputAgainLen;
						}
						printf("Enter data for your %d nodes", n);
						createList(1); break;
						
						case 2: printf("\n\n\tDecided not to make a new list.\n\n"); break;
						default: errorMsg(); goto ifCreate;
					}
					case 2: printf("\n\nDecided not to delete list.\n\n"); goto mainMenu;
					default: errorMsg(); //continue here. Make a goto statement, delete_at_nth(), reverseList()
					goto confirmDeletionList;
				}
			}
			printf("\n-- DELETION --\n");
			displayNo();
		inputDeletionPos:
			printf("***\nEnter position: ");
			scanf("%d", &pos);
			if(pos<=0 || pos>n)
			{
				errorMsg();
				goto inputDeletionPos;
			}
			else
			{
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
					delete_at_nth(1, pos, head);
				}
			}
			break;
			
			case 5: //reverse 
			reverseList(head, head);
			printf("\n\n\tLink reversed.\n\n\n");
			break;
			
			case 6: //search data
			printf("\n\n -- DATA SEARCH --\n");
			printf("Enter data to search: ");
			scanf("%d", &data);
			
			numSearch=searchList(head, data, 0, 0, 0);
			
			if(numSearch==0)
			{
				printf("\n\n\tData doesn't exist.\n\n\n");
			}
			
			break;
			
			case 7: //exit (clear) 
			printf("\n\n===============================================\n\n\t\tPROGRAM TERMINATED\n\n");
			clearList();
			free(head);
			free(temp);
			free(newNode);
			free(tail);
			free(nextNode);
			free(currentNode);
			free(clear);
			free(freeNode);
			head=temp=newNode=tail=nextNode=currentNode=clear=freeNode=NULL;
			exit(1);
			
			break;
			default: errorMsg(); goto mainMenu;
		}
		
		goto mainMenu;
	}
	
}

void errorMsg()
{
	printf("\n\n\t\tInvalid input. Try again.\n\n");
}

void createList(int i)
{
	if(i>n)
	{
		printf("\n\n\tList created.\n\n\n");
		return;	
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		newNode->prev=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}
		
		return createList(i+1);
	}
}

void insert_at_beginning(int data)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->prev=NULL;
	newNode->next=head;
	head->prev=newNode;
	head=newNode;
	n++;
	printf("\n\n\tSuccessfully inserted data at the beginning.\n\n\n");
}

void insert_at_end(int data)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->next=NULL;
	newNode->prev=tail;
	tail->next=newNode;
	tail=newNode;
	n++;
	printf("\n\n\tSuccessfully inserted data at the end.\n\n\n");
}

void insert_at_nth(int data, struct node *temp, int i, int pos)
{
	if(i>=pos-1)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=data;
		newNode->next=temp->next;
		newNode->prev=temp;
		temp->next=temp->next->prev=newNode;
		n++;
		printf("\n\n\tSuccessfully inserted data at position %d.\n\n\n", pos);
		return;
	}
	else
	{
		return insert_at_nth(data, temp->next, i+1, pos);
	}
}

void delete_at_beginning()
{
	freeNode=head;
	head=head->next;
	head->prev=NULL;
	free(freeNode);
	freeNode=NULL;
	n--;
	
	printf("\n\n\tSuccessfully deleted data at the beginning.\n\n\n");
}

void delete_at_end()
{
	freeNode=tail;
	tail=tail->prev;
	tail->next=NULL;
	free(freeNode);
	freeNode=NULL;
	n--;
	
	printf("\n\n\tSuccessfully deleted data at the end.\n\n\n");
}

void delete_at_nth(int i, int pos, struct node *temp)
{
	if(i==pos)
	{
		nextNode=temp->next;
		freeNode=temp;
		temp->prev->next=temp->next;
		nextNode->prev=temp->prev;
		free(freeNode);
		n--;
		printf("\n\n\tSuccessfully deleted data at position %d.\n\n\n", pos);
		
	}
	else
	{
		return delete_at_nth(i+1, pos, temp->next);
	}
}

void displayList(struct node *print_ptr)
{
	if(print_ptr==NULL)
	{
		printf("\n\n\n");
	}
	else
	{
		printf("%d ", print_ptr->data);
		return displayList(print_ptr->next);
	}
}

void clearList()
{
	//only function that's not recursive
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next;
		free(freeNode);
		freeNode=NULL;
	}

}

void displayNo()
{
	printf("Number of nodes: %d\n      >> <<\n", n);
}

void reverseList(struct node*currentNode, struct node *nextNode)
{
	if(currentNode==NULL)
	{
		currentNode=head;
		head=tail;
		tail=currentNode;
	}
	else
	{
		nextNode=nextNode->next;
		currentNode->next=currentNode->prev;
		currentNode->prev=nextNode;
		currentNode=nextNode;
		return reverseList(currentNode, nextNode);
	}
}

int searchList(struct node *search_ptr, int data, int flag, int pos, int occurrence)
{
	if(search_ptr==NULL)
	{
		if(flag==1)
		{
			printf("\n\n-----\nThe data %d is on the list.\nOccurrence: %d\n\n", data, occurrence);
		}
		return flag;
	}
	else
	{
		if(search_ptr->data==data)
		{
			flag=1;
			occurrence++;
		}
		
		return searchList(search_ptr->next, data, flag, pos+1, occurrence);
	}
}