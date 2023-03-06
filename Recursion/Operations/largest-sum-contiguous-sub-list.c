#include <stdio.h>
#include <stdlib.h>
#define MAXSUM -999

struct subList{
	int data;
	struct subList* prev_ptr;
	struct subList *next_ptr;
}*head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct subList*);
void clear_mem();
int subFunc(struct subList*, int);

int main()
{
	head=NULL;
	int n;
	printf("=======================================================\n");
	printf("\tLARGEST SUM OF CONTIGUOUS SUB LIST\n\n");

inputNum:
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<0)
	{
		printf("\n\nINPUT NOT APPLICABLE FOR THIS PROGRAM. TRY AGAIN.\n\n---\n");
		goto inputNum;
	}
	printf("Enter data for your %d nodes:\n", n);
	create_list(1, n);
	
	printf("\n------\nLinked list: ");
	display_list(head);
	int result = subFunc(head, MAXSUM);
	
	printf("\nLargest sum (contiguous) = %d ", result);
	clear_mem();
	
	return 0;
}

void clear_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next_ptr;
		free(freeNode);
		freeNode=NULL;
	}
	
	free(head);
	free(tail);
	free(newNode);
	free(clear);
	free(freeNode);
	head=tail=newNode=clear=freeNode=NULL;
	return;
}

int subFunc(struct subList* add_ptr, int sum)
{
	static int maxSum = MAXSUM;
	
	if(add_ptr==NULL)
	{
		return maxSum;
	}
	else
	{
		sum+=add_ptr->data;
		
		if(sum<0)
		{
			sum=0;
		}
		
		if(maxSum < sum)
		{
			maxSum = sum;
		}
	}
	
	return subFunc(add_ptr->next_ptr, sum);
}

void create_list(int i, int num_of_nodes)
{
	if(i>num_of_nodes)
	{
		return;
	}
	else
	{
		newNode=(struct subList*)malloc(sizeof(struct subList));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
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
		
		return create_list(i+1, num_of_nodes);
	}
}

void display_list(struct subList* print_ptr)
{
	if(print_ptr==NULL)
	{
		free(print_ptr);
		print_ptr=NULL;
		return;
	}
	else
	{
		printf("%d ", print_ptr->data);
		
		return display_list(print_ptr->next_ptr);
	}
}