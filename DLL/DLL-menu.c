//Program bound to change

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *temp, *newNode, *traverse, *tail, *freeThisNode, *currentNode, *nextNode, *clear;

int n;

void createList(int);
void insertAtBeginning();
void insertAtEnd();
void insertAtPos(int);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPos(int);
void printList();
void reverseList();
void releaseMemforNew();
void releaseMem();

int main()
{
	head=NULL;
	int choice;
	
menuChoice:
	printf("What to do now?\n");
	printf("\t\tMENU\n");
	printf("\t[1] Create list\n");
	printf("\t[2] Insert data\n");
	printf("\t[3] Delete data\n");
	printf("\t[4] Reverse list\n");
	printf("\t[5] Display list\n");
	printf("\t[6] EXIT\n");
	printf("\t---\n");
	printf("Choose: ");
	scanf("%d", &choice);
	
	switch(choice)
	{
		case1:
		case 1:
		printf("\n\nYou chose [1] as your input.\n\n"); 
		if(head==NULL)
		{
			int number_of_nodes;
			printf("Input the number of nodes you want for your linked list: ");
			scanf("%d", &number_of_nodes);
			n=number_of_nodes;
			createList(number_of_nodes);
		}
		else
		{
			int ch;
			printf("You have already created your linked list.\n");
			printf("Would you like to make a new one?\n");
			printf("\t[1] Yes\n");
			printf("\t[2] No\n");
			printf("---\n");
			printf("Choice: ");
			scanf("%d", &choice);
			if(choice==1)
			{
				printf("\n\nClearing everything...\n");
				releaseMemforNew();
				int no_of_nodes;
				printf("\n\nInput the number of nodes for your new linked list: ");
				scanf("%d", &no_of_nodes);
				
				createList(no_of_nodes);
			}
			else if(choice==2)
			{
				goto menuChoice;
			}
		}
		
		goto menuChoice;
		break;
		
		case 2: 
		printf("\n\nYou chose [2] as your input.\n\n");
		if(head!=NULL)
		{
			int inputPos;
		inputInsPos:
			printf("Enter position for your node to be inserted: ");
			scanf("%d", &inputPos);
			
			if(inputPos==1)
			{
				insertAtBeginning();
			}
			else if(inputPos>1 && inputPos<n)
			{
				insertAtPos(inputPos);
			}
			else if(inputPos==n)
			{
				insertAtEnd();
			}
			else if(inputPos>n)
			{
				printf("\n\nPosition exceeds to the number of nodes. Try again.\n\n");
				goto inputInsPos;
			}
			else if(inputPos<=0)
			{
				printf("\n\nInvalid position. Try again.\n\n");
				goto inputInsPos;
			}
		}
		else
		{
			printf("\n\nYou currently don't have any list. Choose [1] as the input instead.\n\n");
			goto menuChoice;
		}
		
		goto menuChoice;
		break;
		case 3:
		if(head!=NULL)
		{
			int deletePos;
		inputDeletePos:
			printf("Enter the position of the node to be deleted: ");
			scanf("%d", &deletePos);
			
			if(deletePos==1)
			{
				deleteAtBeginning();
			}
			else if(deletePos>1 && deletePos<n)
			{
				deleteAtPos(deletePos);
			}
			else if(deletePos > n)
			{
				printf("\n\nPosition exceeds to the number of nodes. Try again.\n\n");
				goto inputDeletePos;
			}
			else if (deletePos==n)
			{
				deleteAtEnd();
			}
			else if(deletePos<=0)
			{
				printf("\n\nInvalid position. Try again.\n\n");
				goto inputDeletePos;
			}
		}
		else
		{
			printf("\n\nYou currently don't have any list. Choose [1] as the input instead.\n\n");
			goto menuChoice;
		}
		
		goto menuChoice;
		
		break;
		case 4: 
		if(head!=NULL)
		{
			printf("\nList before reversing: ");
			printList();
			printf("List after reversing: ");
			reverseList();
			printList();
		}
		else
		{
			printf("\n\nYou currently don't have any list. Choose [1] as the input insead.\n\n");
			goto menuChoice;
		}
		
		goto menuChoice;
		break;
		case 5: 
		
		if(head==NULL)
		{
			printf("\n\nLinked list is currently empty. Choose [1] to create one.\n\n");
			goto menuChoice;
		}
		
		printList();
		goto menuChoice;
		break;
		
		case 6: 
		releaseMem();
		printf("\n\n===END OF PROGRAM===\n");
		break;
		
		default:printf("\n\nInvalid input. Try again.\n\n");
		goto menuChoice; break;
	}
}

void createList(int n)
{
	int i=1;
	printf("Input data for your %d nodes:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->prev_ptr=newNode->next_ptr=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next_ptr=newNode;
			newNode->prev_ptr=tail;
			tail=newNode;
		}
	}
	printf("\n");
}

void insertAtBeginning()
{
	int num;
	printf("Input data to be inserted at the beginning: ");
	scanf("%d", &num);
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=num;
	
	newNode->next_ptr=head;
	head->prev_ptr=newNode;
	head=newNode;
	
	return;
}

void insertAtPos(int pos)
{
	int num;
	int i=1;
	printf("Input data to be inserted at the given position: ");
	scanf("%d", &num);
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=num;
	newNode->prev_ptr=newNode->next_ptr=NULL;
	
	temp=head;
	
	while(i<pos-1)
	{
		temp=temp->next_ptr;
		i++;
	}
	newNode->next_ptr=temp->next_ptr;
	newNode->prev_ptr=temp;
	temp->next_ptr->prev_ptr=newNode;
	temp->next_ptr=newNode;
	
	printf("\n");
	return;
}


void insertAtEnd()
{
	int num;
	printf("Input data to be inserted at the end: ");
	scanf("%d", &num);
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=num;
	newNode->next_ptr=newNode->prev_ptr=NULL;
	
	tail->next_ptr=newNode;
	newNode->prev_ptr=tail;
	tail=newNode;
	
	printf("\n");
	return;
}

void deleteAtBeginning()
{
	freeThisNode=head;
	head=head->next_ptr;
	head->prev_ptr=NULL;
	free(freeThisNode);
	
	printf("\n");
	return;
}

void deleteAtPos(int pos)
{
	int i=1;
	temp=head;
	while(i<pos)
	{
		temp=temp->next_ptr;
		i++;
	}
	
	freeThisNode=temp;
	temp->prev_ptr->next_ptr=temp->next_ptr;
	temp->next_ptr->prev_ptr=temp->prev_ptr;
	free(freeThisNode);
	
	printf("\n");
	return;
}

void deleteAtEnd()
{
	freeThisNode=tail;
	tail=tail->prev_ptr;
	tail->next_ptr=NULL;
	free(freeThisNode);
	
	printf("\n");
	return;
}

void reverseList()
{
	currentNode=head;
	
	while(currentNode!=NULL)
	{
		nextNode=currentNode->next_ptr;
		currentNode->next_ptr=currentNode->prev_ptr;
		currentNode->prev_ptr=nextNode;
		currentNode=nextNode;
	}
	
	currentNode=head;
	head=tail;
	tail=currentNode;
	
	return;
}

void printList()
{
	printf("\nLinked list: ");
	for(traverse=head; traverse!=NULL; traverse=traverse->next_ptr)
	{
		printf("%d ", traverse->data);
	}
	
	printf("\n\n");
}

void releaseMemforNew()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
	}
	
	return;
}

void releaseMem()
{
	clear=head;
	while(clear!=NULL)
	{
		nextNode=clear->next_ptr;
		freeThisNode=clear;
		clear=nextNode;
		free(freeThisNode);
	}
	
	free(head);
	free(temp);
	free(tail);
	free(newNode);
	free(nextNode);
	free(traverse);
	free(currentNode);
	free(clear);
	free(freeThisNode);
	
	head=temp=tail=newNode=nextNode=currentNode=clear=traverse=freeThisNode=NULL;
	
	return;
}