#include<stdio.h>
#include <stdlib.h>

struct reverseList{
	int data;
	struct reverseList *prev;
	struct reverseList *next;
}*head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct reverseList*);
void reverse_list(struct reverseList*, struct reverseList*);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your list: ");
	scanf("%d", &n);
	create_list(1, n);	
	printf("\n\n=======\nLinked list before reverse: ");
	display_list(head);
	reverse_list(head, head);
	printf("Linked list after reverse: ");
	display_list(head);
	clear_mem();
	
	return 0;
}

void reverse_list(struct reverseList* currentNode, struct reverseList* nextNode)
{
	if(currentNode==NULL)
	{
		currentNode = head;
		head = tail;
		tail = currentNode;
		return;
	}
	else
	{
		nextNode=currentNode->next;
		currentNode->next=currentNode->prev;
		currentNode->prev=nextNode;
		currentNode=nextNode;
		
		return reverse_list(currentNode, nextNode);
	}
}

void display_list(struct reverseList* print_data)
{
	if(print_data==NULL)
	{
		printf("\n");
		free(print_data);
		print_data=NULL;
		return;
	}
	else
	{
		printf("%d ", print_data->data);
		return display_list(print_data->next);
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
		newNode=(struct reverseList*)malloc(sizeof(struct reverseList));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->prev=newNode->next=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next=newNode;
			newNode->prev=tail;
			tail=newNode;
		}
		
		return create_list(i+1, num_of_nodes);
	}
}

void clear_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next;
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