#include <stdio.h>
#include <stdlib.h>

struct splitList{
	int data;
	struct splitList* prev_addr;
	struct splitList* next_addr;
};

struct splitList *head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct splitList*);
void splitFunc(struct splitList*, int, int);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("==================================\n\tSPLIT LIST PROGRAM\n\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	printf("Enter data for your %d nodes:\n", n);
	create_list(1, n);
	
	printf("\n\n---\nLinked list before splitting: ");
	display_list(head);
	
	int pos=n/2;
	splitFunc(head, 1, pos);
	
	printf("Linked list after splitting: ");
	display_list(head);
	
	clear_mem();
	return 0;
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

void splitFunc(struct splitList* start, int i, int pos)
{
	if(i>pos)
	{
		start->prev_addr->next_addr=NULL;
		start->prev_addr=NULL;
		head->prev_addr=tail;
		tail->next_addr=head;
		head=start;
		return;
	}
	else
	{
		splitFunc(start->next_addr, i+1, pos);
	}
}
void create_list(int i, int num_of_nodes)
{
	if(i>num_of_nodes)
	{
		return;
	}
	else
	{
		newNode=(struct splitList*)malloc(sizeof(struct splitList));
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
		
		return create_list(i+1, num_of_nodes);
	}
}	

void display_list(struct splitList* print_ptr)
{
	if(print_ptr==NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%d ", print_ptr->data);
		return display_list(print_ptr->next_addr);
	}
}
