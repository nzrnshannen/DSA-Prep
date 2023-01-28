//program bound to change

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *prev_ptr;
	struct node *next_ptr;
}*head, *temp, *traverse, *newNode, *tail, *clear, *currentNode, *nextNode, *freeThisNode;

void create_linked_list(int);
void reverse_list();
int count_trailing();
int check_trailing();
void release_mem();

int main()
{
	head=NULL;
	int input_num, temp_num;
	printf("Enter a number: ");
	scanf("%d", &input_num);
	temp_num=input_num;
	
	int holder;
	
	if(input_num==0)
	{
		printf("\n\nTrailing zeroes: %d", 1);
		exit(1);
	}
	
	while(temp_num!=NULL)
	{
		holder=temp_num%10;
		create_linked_list(holder);
		temp_num/=10;
	}
	
	reverse_list();
	int check=check_trailing();
	
	if(check==1)
	{
		int count=count_trailing();
		printf("\n\nTrailing zeroes: %d", count);
	}
	else
	{
		printf("\n\nThere are no trailing zeroes in the given number %d.", input_num);
	}
	
	release_mem();
	return 0;
}

void create_linked_list(int num)
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

void reverse_list()
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
}

int check_trailing()
{
	if(tail->data==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int count_trailing()
{
	temp=head;
	int count;

	while(temp!=NULL)
	{
	
		if(temp->data==0)
		{
			count++;
		}
		else
		{
			count=0;
		}
		
		temp=temp->next_ptr;
	
	}
	
	return count;
}

void release_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
}