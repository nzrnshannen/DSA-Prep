#include <stdio.h>
#include <stdlib.h>

struct findDeficient{
	int data;
	struct findDeficient *prev_addr;
	struct findDeficient *next_addr;
}*head, *tail, *clear, *freeNode, *newNode;

void create_list(int, int);
void display_list(struct findDeficient*);
void find_func(struct findDeficient*);
int check_num(int, int, int);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	create_list(1, n);	
	
	printf("\nLinked list: ");
	display_list(head);
	
	printf("\n\n======\n");
	find_func(head);
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
	/*head=tail=newNode=freeNode=clear=NULL;*/
	return;
}

int check_num(int data, int sum, int i)
{
	if(i>data/2)
	{
		return sum;
	}
	else
	{
		if(data%i==0)
		{
			sum+=i;
		}
		
		return check_num(data, sum, i+1);
	}
	
}

void find_func(struct findDeficient* find_ptr)
{
	if(find_ptr==NULL)
	{
		return;
	}
	else
	{
		int sum=check_num(find_ptr->data, 0, 1);
		if(find_ptr->data>sum)
		{
			printf("%d is a deficient number", find_ptr->data);
		}
		else
		{
			printf("%d is not a deficient number", find_ptr->data);
		}
		
		printf("\n");
		
		return find_func(find_ptr->next_addr);
	}
}

void display_list(struct findDeficient* print_ptr)
{
	if(print_ptr==NULL)
	{
		return;
	}
	else
	{
		printf("%d ", print_ptr->data);
		return display_list(print_ptr->next_addr);
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
		newNode=(struct findDeficient*)malloc(sizeof(struct findDeficient));
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