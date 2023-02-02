#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_addr;
	struct node *prev_addr;
}*head, *tail, *newNode, *freeThisNode;

int find_factorial(int, int);
void clear_mem(struct node*);
void list_display(struct node*);
void create_list(int);

int main()
{
	int inputNum;
	head=NULL;
	printf("Enter a number: ");
	scanf("%d", &inputNum);
	
	int fact=find_factorial(1, inputNum);
	printf("\n[");
	list_display(head);
	printf("\n%d!: %d", inputNum, fact);
	clear_mem(head);
	return 0;
}

int find_factorial(int i, int limit)
{
	static int fact=1;
	
	if(i>limit)
	{
		return fact;
	}
	else
	{
		fact*=i;
		create_list(fact);
		return find_factorial(i+1, limit);
	}
}

void create_list(int fact)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=fact;
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

void list_display(struct node *print_data)
{
	if(print_data==NULL)
	{
		printf("]\n");
		return;
	}
	else
	{
		printf("\t%d\t", print_data->data);
		return list_display(print_data=print_data->next_addr);
	}
}

//function bound to change
void clear_mem(struct node *clear_ptr)
{
	if(clear_ptr==NULL)
	{
		return;
	}
	else
	{
		freeThisNode=clear_ptr;
		return clear_mem(clear_ptr=clear_ptr->next_addr);
		free(freeThisNode);
		freeThisNode=NULL;
	}
}