#include <stdio.h>
#include <stdlib.h>

struct determine_ave{
	int data;
	struct determine_ave* prev_ptr;
	struct determine_ave* next_ptr;
}*head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct determine_ave*);
int sum_of_nodes(struct determine_ave*, int);
void clear_func();

int main()
{
	head=NULL;
	int num_of_nodes;
	printf("==========================================\n");
	printf("\tCALCULATING FOR THE AVERAGE\n\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &num_of_nodes);
	printf("Enter data for your %d nodes: \n", num_of_nodes);
	create_list(1, num_of_nodes);
	display_list(head);
	int sum = sum_of_nodes(head, num_of_nodes);
	printf("\n\n------\nSum = %d\n", sum);
	int ave = sum/num_of_nodes;
	printf("Average: %d", ave);
	
	clear_func();
	
	return 0;
}

void clear_func()
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
	free(freeNode);
	free(clear);
	
	head=tail=newNode=freeNode=clear=NULL;
	
	return;
}

int sum_of_nodes(struct determine_ave* sum_ptr, int n)
{
	static int sum = 0;
	
	if(sum_ptr==NULL)
	{
		free(sum_ptr);
		return sum;
	}
	else
	{
		sum+=sum_ptr->data;
		return sum_of_nodes(sum_ptr->next_ptr, n);
	}
}

void display_list(struct determine_ave* print_ptr)
{
	if(print_ptr==NULL)
	{
		return;
	}
	else
	{
		printf("%d ", print_ptr->data);
		return display_list(print_ptr->next_ptr);
	}
}

void create_list(int i, int n)
{
	if(i>n)
	{
		printf("\n");
	}
	else
	{
		newNode=(struct determine_ave*)malloc(sizeof(struct determine_ave));
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
		
		return create_list(i+1, n);
	}
}