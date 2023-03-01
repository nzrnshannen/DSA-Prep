#include <stdio.h>
#include <stdlib.h>
#define RESTRICT -9999

struct printUnique{
	int data;
	struct printUnique* next_addr;
	struct printUnique* prev_addr;
}*head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct printUnique*);
int check_existing(struct printUnique*, int, int);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	create_list(1, n);
	
	printf("\n\n================================================\n\tPRINTING ONLY UNIQUE ELEMENTS\n\nLinked list: ");
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

void create_list(int i, int n)
{
	if(i>n)
	{
		return;
	}
	else
	{
		newNode=(struct printUnique*)malloc(sizeof(struct printUnique));
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

void display_list(struct printUnique* print_data)
{
	if(print_data==NULL)
	{
		free(print_data);
		print_data=NULL;
		
		return;
	}
	else
	{
		if(print_data->data==RESTRICT)
		{
			return display_list(print_data->next_addr);
		}
		
		int r = check_existing(print_data->next_addr, 0, print_data->data);
		
		if(r==0)
		{
			printf("%d ", print_data->data);
		}
		
		return display_list(print_data->next_addr);
	}
}

int check_existing(struct printUnique* check_ptr, int flag, int num)
{
	if(check_ptr==NULL)
	{
		return flag;	
	}
	else
	{
		if(num==check_ptr->data && check_ptr->data!=RESTRICT)
		{
			check_ptr->data=RESTRICT;
			flag = 1;
		}
		
		return check_existing(check_ptr->next_addr, flag, num);
	}
}
