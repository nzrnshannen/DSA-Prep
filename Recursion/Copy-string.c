#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct node{
	char ltr;
	struct node *prev_addr;
	struct node *next_addr;
};

struct node *head, *tail, *newNode, *freeThisNode, *clear;

void display_list(struct node*);
void create_list(char);
void copy_string(char, struct node*);
void release_mem();

int main()
{
	head=NULL;
	char inputString[MAX];
	int i=0;
	char ch;
	
	printf("Enter a string: ");
	
	while((ch=getchar())!='\n')
	{
		inputString[i++]=ch;
		create_list(ch);
	}
	
	inputString[i]=NULL;
	
	printf("\n-----\nOriginal string: %s", inputString);
	printf("\nLinked list: ");
	display_list(head);
	
	release_mem();
	
	return 0;
}


void display_list(struct node *print)
{
	if(print==NULL)
	{
		return;
	}
	else
	{
		printf("%c", print->ltr);
		return display_list(print=print->next_addr);
	}
}

void create_list(char ch)
{
	if(ch=='\0')
	{
		return;
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->ltr=ch;
		newNode->prev_addr=newNode->next_addr=NULL;
		
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
	}
}

void release_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_addr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
	
	return;
}