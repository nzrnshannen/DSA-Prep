#include <stdio.h>
#include <stdlib.h>
#define MAX_DIFF -999

struct maxDiff{
	int data;
	struct maxDiff *prev_addr;
	struct maxDiff *next_addr;
}*head, *tail, *newNode, *free_node, *clear, *data1, *data2, *temp2;

void create_list(int, int);
void display_list(struct maxDiff*);
int find_max(struct maxDiff*, int);
int traverse_max(struct maxDiff*, struct maxDiff*, int);

void free_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		free_node=clear;
		clear=clear->next_addr;
		free(free_node);
		free_node=NULL;
	}
}

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your list: ");
	scanf("%d", &n);
	create_list(1, n);
	printf("Linked list: ");
	display_list(head);
	int result = find_max(head, MAX_DIFF);
	
	printf("\n\n-----\nMax difference: %d", result);
	printf("\nMinuend = %d\nSubtrahend = %d", data1->data, data2->data);
	
	free_mem();
	return 0;
}

int find_max(struct maxDiff* temp1, int maxno)
{
	if(temp1==NULL)
	{
		return maxno;
	}
	else
	{	
		int result = traverse_max(temp1, head, maxno);
		maxno=result;
		return find_max(temp1=temp1->next_addr, maxno);
	}
}

int traverse_max(struct maxDiff* temp1, struct maxDiff* temp2, int maxno)
{
	int diff;
	if(temp2==NULL)
	{
		return maxno;
	}
	else
	{
		diff=temp1->data-temp2->data;
		if(diff>maxno)
		{
			maxno=diff;
			data1=temp1;
			data2=temp2;
		}
		
		return traverse_max(temp1, temp2=temp2->next_addr, maxno);
	}
}
void display_list(struct maxDiff *print_data)
{
	if(print_data==NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%d ", print_data->data);
		return display_list(print_data=print_data->next_addr);
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
		newNode=(struct maxDiff*)malloc(sizeof(struct maxDiff));
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