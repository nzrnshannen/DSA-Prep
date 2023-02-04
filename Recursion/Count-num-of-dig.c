#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
};

struct node *head, *tail, *freeThisNode, *newNode;

void create_list(int);
int display_list(struct node*);
void release_mem(struct node*);

int main()
{
	head=NULL;
	int inputNum, temp, dig;
	printf("Enter a number: ");
	scanf("%d", &inputNum);
	
	temp=inputNum;
	
	while(temp!=NULL)
	{
		dig=temp%10;
		create_list(dig);
		temp/=10;
	}
	
	printf("\nLinked list: ");
	int result=display_list(tail);
	printf("\nNumber of digits: %d", result);
	release_mem(head);
	
	return 0;
}
void create_list(int num)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=num;
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

int display_list(struct node *traverse)
{
	static int count=0;
	if(traverse==NULL)
	{
		return count;
	}
	else
	{
		count++;
		printf("%d ", traverse->data);
	}

	return display_list(traverse=traverse->prev_ptr);
}

void release_mem(struct node *clear_mem)
{
	while(clear_mem!=NULL)
	{
		freeThisNode=clear_mem;
		clear_mem=clear_mem->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
}