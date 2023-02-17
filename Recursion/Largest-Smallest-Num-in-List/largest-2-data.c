#include <stdio.h>
#include <stdlib.h>
#define MIN -9999

struct twoLargest{
	int data;
	struct twoLargest *next_addr;
	struct twoLargest *prev_addr;
}*head, *tail, *freeThisNode, *clear, *newNode;

void create_list(int, int);
void display_list(struct twoLargest*);
int find_largest(struct twoLargest*);
int find_largest_second(struct twoLargest*, int);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	create_list(1, n);
	printf("\nLinked list:\n");
	display_list(head);
	int largest_first=find_largest(head);
	int largest_second=find_largest_second(head, largest_first);
	
	printf("\n\n---\n");
	printf("First largest data: %d\n", largest_first);
	printf("Second largest data: %d", largest_second);
	
	clear_mem();
	return 0;
	
}

void clear_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_addr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
}
int find_largest_second(struct twoLargest* find_lrg2, int largest)
{
	static int lrg2nd=MIN;
	if(find_lrg2==NULL)
	{
		return lrg2nd;
	}	
	else
	{
		if(find_lrg2->data!=largest)
		{
			if(find_lrg2->data>lrg2nd)
			{
				lrg2nd=find_lrg2->data;
			}
		}
		
		return find_largest_second(find_lrg2=find_lrg2->next_addr, largest);
	}
}

int find_largest(struct twoLargest* find_lrg)
{
	static int lrg=MIN;
	if(find_lrg==NULL)
	{
		return lrg;
	}
	else
	{
		if(find_lrg->data>lrg)
		{
			lrg=find_lrg->data;
		}
		
		return find_largest(find_lrg=find_lrg->next_addr);
	}
}
void display_list(struct twoLargest* print_data)
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
		return;
	}
	else
	{
		newNode=(struct twoLargest*)malloc(sizeof(struct twoLargest));
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