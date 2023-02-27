//Program bound to change

#include <stdio.h>
#include <stdlib.h>

struct removeNode{
	int data;
	struct removeNode *prev_addr;
	struct removeNode *next_addr;
}*head, *tail, *newNode, *clear, *freeNode;

void create_nodes(int, int);
void display_list(struct removeNode*);
void deleteFunc(int, int, int);
int delete_at_beginning();
int delete_at_end();
int delete_at_nth(struct removeNode*, struct removeNode*, int, int);
void release_mem();

int main()
{
	head=NULL;
	int n, input;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Enter data for your %d nodes:\n", n);
	create_nodes(1, n);
	printf("\nLinked list: ");
	display_list(head);
	
inputPos:
	printf("\n---\nEnter the (position) node that you want to delete: ");
	scanf("%d", &input);
	
	if(input>n || input<1)
	{
		printf("\n\nPosition does not exist. Try again.\n\n");
		goto inputPos;
	}
	
	deleteFunc(input, 0, n);
	printf("\n\n\t\tSuccessfully deleted node.\n\n");
	printf("\n\n=====\nLinked list after removing: ");
	display_list(head);
	release_mem();
	
	free(head);
	free(tail);
	free(newNode);
	free(clear);
	free(freeNode);
	head=tail=newNode=clear=freeNode=NULL;
	
	return 0;
}

int delete_at_beginning()
{
	freeNode=head;
	head=head->next_addr;
	free(freeNode);
	freeNode=NULL;
	
	return 1;
}

void release_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next_addr;
		free(freeNode);
		freeNode=NULL;
	}
	
	return;
}

int delete_at_nth(struct removeNode *prev, struct removeNode *current, int i, int pos)
{
	if(i==pos)
	{
		freeNode=current;
		prev->next_addr=current->next_addr;
		current->prev_addr=prev;
		freeNode=NULL;
		free(freeNode);
		return 1;
	}
	else
	{
		return delete_at_nth(current, current->next_addr, i+1, pos);
	}
}

int delete_at_end()
{
	freeNode=tail;
	tail=tail->prev_addr;
	tail->next_addr=NULL;
	free(freeNode);
	freeNode=NULL;
	
	return 1;
}

void deleteFunc(int pos, int flag, int n)
{
	if(flag!=0)
	{
		return;
	}
	else
	{
		if(pos==1)
		{
			flag = delete_at_beginning();
		}
		else if(pos==n)
		{
			flag = delete_at_end();
		}
		else
		{
			flag = delete_at_nth(NULL, head, 1, pos);
		}
	}
}

void create_nodes(int i, int n)
{
	if(i>n)
	{
		return;
	}
	else
	{
		newNode=(struct removeNode*)malloc(sizeof(struct removeNode));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		
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
		
		return create_nodes(i+1, n);
	}
}

void display_list(struct removeNode *print_data)
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