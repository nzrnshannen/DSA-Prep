//program bound to change

#include <stdio.h>
#include <stdlib.h>

struct sortList{
	int data;
	struct sortList *next_addr;
	struct sortList *prev_addr;
};

struct sortList *head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct sortList*);
void clear_mem();
void missingData(struct sortList*);
void findMissing(struct sortList*, int, int);

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	create_list(1, n);
	display_list(head);
	
	printf("\n\n--------------\nThe missing elements between %d and %d are: ", head->data, tail->data);
	missingData(head);
	
	clear_mem();
	return 0;
}

void findMissing(struct sortList* add_missing, int j, int diff)
{
	if(j==diff)
	{
		return;
	}
	else
	{
		printf("%d ", add_missing->data + j);
		return findMissing(add_missing, j+1, diff);
	}
}

void missingData(struct sortList* ptr)
{
	static int diff=0;
	
	if(ptr->next_addr==NULL)
	{
		return;
	}
	else
	{
		diff=ptr->next_addr->data - ptr->data;
		
		if(diff>1)
		{
			return findMissing(ptr, 1, diff);
		}
		
		diff=0;
		return missingData(ptr->next_addr);
	}
}

void clear_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode = clear;
		clear = clear->next_addr;
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

void display_list(struct sortList* print_data)
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
		newNode=(struct sortList*)malloc(sizeof(struct sortList));
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