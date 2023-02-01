#include <stdio.h>
#include <stdlib.h>

struct node{
	char letter;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *temp, *freeThisNode, *newNode;

void create_list(char);
void display_list(struct node*);
void rev_display_list(struct node*);
void free_mem(struct node*);

int main()
{
	head=NULL;
	char ch;
	
	printf("Enter a string: ");
	while((ch=getchar())!='\n')
	{
		create_list(ch);
	}
	
	printf("\nString before reverse: ");
	display_list(head);
	printf("String after reverse: ");
	rev_display_list(tail);
	free_mem(head);
	
	return 0;
}

void create_list(char ch)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->letter=ch;
	newNode->next_ptr=newNode->prev_ptr=NULL;
	
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

void display_list(struct node *print)
{
	if(print==NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%c", print->letter);
		display_list(print=print->next_ptr);
	}
		
}

void rev_display_list(struct node *rev)
{
	if(rev==NULL)
	{
		return;
	}
	else
	{
		printf("%c", rev->letter);
		rev_display_list(rev=rev->prev_ptr);
	}
}

void free_mem(struct node *clear)
{
	if(clear==NULL)
	{
		return;
	}
	else
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;
		free_mem(clear);
	}
}