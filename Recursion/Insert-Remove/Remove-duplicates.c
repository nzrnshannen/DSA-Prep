#include <stdio.h>
#include <stdlib.h>

struct removeDuplicates{
	int data;
	struct removeDuplicates *next;
	struct removeDuplicates *prev;
};

struct removeDuplicates *head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct removeDuplicates*);
int check_if_repeat(int, struct removeDuplicates*);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	create_list(1, n);
	
	printf("\n\n---\nLinked list: ");
	display_list(head);
	clear_mem();
	free(head);
	free(tail);
	free(newNode);
	free(freeNode);
	free(clear);
	head=tail=newNode=freeNode=clear=NULL;
	
	return 0;
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
}
int check_if_repeat(int num, struct removeDuplicates *check_ptr)
{
	int c = 0;
	if(check_ptr==NULL)
	{
		return c;
	}
	else
	{
		if(check_ptr->data == num)
		{
			c = 1;
			return c;
		}
		
		return check_if_repeat(num, check_ptr=check_ptr->next);
	}
}

void create_list(int start, int end)
{
	if(start>end)
	{
		return;
	}
	else
	{
		newNode=(struct removeDuplicates*)malloc(sizeof(struct removeDuplicates));
		printf("Data %d: ", start);
		scanf("%d", &newNode->data);
		newNode->next=newNode->prev=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			int r = check_if_repeat(newNode->data, head);
			if(r!=1)
			{
				tail->next=newNode;
				newNode->prev=tail;
				tail=newNode;
			}
		}
	
		return create_list(start+1, end);
	}
}

void display_list(struct removeDuplicates*print_data)
{
	if(print_data==NULL)
	{
		return;
	}
	else
	{
		printf("%d ", print_data->data);
		return display_list(print_data->next);
	}
}
