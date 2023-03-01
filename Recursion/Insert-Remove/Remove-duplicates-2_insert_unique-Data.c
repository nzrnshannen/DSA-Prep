#include <stdio.h>
#include <stdlib.h>

struct uniqueData{
	int data;
	struct uniqueData* prev_addr;
	struct uniqueData* next_addr;
};

struct uniqueData *head, *tail, *newNode, *freeNode, *clearNode;

void create_list(int, int);
void display_list(struct uniqueData*);
int checkExisting(int, struct uniqueData*, int);
void clear_mem();

int main()
{
	head=NULL;
	int n;	
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	create_list(1, n);
	printf("\n\n=======\nLinked list: ");
	display_list(head);
	clear_mem();
	
	return 0;
}

void clear_mem()
{
	clearNode=head;
	while(clearNode!=NULL)
	{
		freeNode=clearNode;
		clearNode=clearNode->next_addr;
		free(freeNode);
		freeNode=NULL;
	}
	
	free(head);
	free(tail);
	free(newNode);
	free(clearNode);
	free(freeNode);
	head=tail=newNode=clearNode=freeNode=NULL;
	
	return;
}

void display_list(struct uniqueData* print_ptr)
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
		newNode=(struct uniqueData*)malloc(sizeof(struct uniqueData));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next_addr=newNode->prev_addr=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			int result = checkExisting(newNode->data, head, 0);
			if(result!=1)
			{
				tail->next_addr=newNode;
				newNode->prev_addr=tail;
				tail=newNode;
			}
		}
		
		return create_list(i+1, num_of_nodes);
	}
}

int checkExisting(int check_data, struct uniqueData* check_ptr, int flag)
{
	if(check_ptr==NULL || flag == 1)
	{
		return flag;
	}	
	else
	{
		if(check_ptr->data == check_data)
		{
			flag = 1;
		}
	
		
		return checkExisting(check_data, check_ptr->next_addr, flag);
	}
}