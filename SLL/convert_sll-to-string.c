/*
	Name: Shannen T. Nazareno
	Program: SLL program to convert list into a string and returns it
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

struct node{
	char data;
	struct node *next;
}*head, *temp, *newNode, *freeNode;

void createList();
void displayList(struct node*);
char* putToString(struct node*, int, char[]);
void clearList(struct node *clear);

int main()
{
	char stringArr[MAX];
	head=NULL;
	
	printf("=== LINKED LIST TO STRING === \n");
	printf("Enter a string: ");
	createList();
	printf("=====\nLinked list: ");
	displayList(head);
	
	char *ptr=putToString(head, 0, stringArr);
	
	printf("\n***\nString: %s", ptr);
	//test display: printf("\n%s", stringArr);
	return 0;
}

void createList()
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->next=NULL;
	newNode->data = getchar();
	//scanf("%c", &newNode->data);
	
	if(newNode->data=='\n')
	{
		printf("\n\n\tList created.\n\n");
	}
	else
	{
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
		
		return createList();
		
	}
}

void displayList(struct node *print)
{
	if(print==NULL)
	{
		printf("\n");
	}
	else
	{
		printf("%c", print->data);
		
		return displayList(print->next);
	}
}

char* putToString(struct node *traverse, int i, char* ptr)
{
	if(traverse==NULL)
	{
		ptr[i]='\0';
		return ptr;
	}
	else
	{
		ptr[i] = traverse->data;
		
		return putToString(traverse->next, i+1, ptr);
	}
}

void clearList(struct node *clear_ptr)
{
	if(clear_ptr==NULL)
	{
		head=temp=newNode=freeNode=NULL;
		printf("\n\n");
	}
	else
	{
		freeNode=clear_ptr;
		clearList(clear_ptr->next);
		free(freeNode);
	}
}