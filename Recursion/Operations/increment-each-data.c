#include <stdio.h>
#include <stdlib.h>

struct incrementData{
	int data;
	struct incrementData* prev_addr;
	struct incrementData *next_addr;
};

struct incrementData *head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct incrementData*);
void increment_func(struct incrementData*);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ", n);
	scanf("%d", &n);
	printf("Enter data for each %d nodes:\n", n);
	create_list(1, n);
	printf("\n\n==========\nLinked list before increment: ");
	display_list(head);
	increment_func(head);
	printf("Linked list after increment: ");
	display_list(head);
	
	clear_mem();
}

void clear_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next_addr;
		free(freeNode);
		freeNode=NULL;
	}
	
	free(head);
	free(tail);
	free(newNode);
	free(freeNode);
	free(clear);
	head=tail=newNode=freeNode=clear=NULL;
	
	return;
}

void increment_func(struct incrementData* incre_ptr)
{
	if(incre_ptr==NULL)
	{
		free(incre_ptr);
		incre_ptr=NULL;
		return;
	}
	else
	{
		incre_ptr->data++;
		
		return increment_func(incre_ptr->next_addr);
	}
}
void display_list(struct incrementData* print_data)
{
	if(print_data==NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%d ", print_data->data);
		
		return display_list(print_data->next_addr);
	}
}

void create_list(int i, int n)
{
	if(i>n)
	{
		printf("\n");
		return;
	}
	else
	{
		newNode=(struct incrementData*)malloc(sizeof(struct incrementData));
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
		
		return create_list(i+1, n);
	}
}