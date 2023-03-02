#include <stdio.h>
#include <stdlib.h>
#define RESTRICT -9999

struct countOccurence{
	int data;
	struct countOccurence* prev_addr;
	struct countOccurence* next_addr;
};

struct countOccurence *head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
void display_list(struct countOccurence*);
void occurenceFunc(struct countOccurence*);
int countFunc(struct countOccurence*, int, int);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	create_list(1, n);
	printf("\n-------------------------\nLinked list: ");
	display_list(head);
	occurenceFunc(head);
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
	free(clear);
	free(freeNode);
	free(newNode);
	
	head=tail=clear=freeNode=newNode=NULL;
	return;
}

int countFunc(struct countOccurence* temp2, int count, int num)
{
	if(temp2==NULL)
	{
		return count;
	}
	else
	{
		if(temp2->data==num && temp2->data!=RESTRICT)
		{
			count++;
			temp2->data=RESTRICT;
		}
		
		return countFunc(temp2->next_addr, count, num);
	}
}

void occurenceFunc(struct countOccurence* temp1)
{
	if(temp1==NULL)
	{
		return;
	}
	else
	{
		
		if(temp1->data==RESTRICT)
		{
			return occurenceFunc(temp1->next_addr);
		}
		
		int c = countFunc(temp1->next_addr, 1, temp1->data);
		
		if(temp1->data!=RESTRICT)
		{
			printf("%d occurs %d times\n", temp1->data, c);
		}
		
		return occurenceFunc(temp1->next_addr);
	}
}

void display_list(struct countOccurence* print_data)
{
	if(print_data==NULL)
	{
		printf("\n\n");
		return;
	}
	else
	{
		printf("%d ", print_data->data);
		
		return display_list(print_data->next_addr);
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
		newNode=(struct countOccurence*)malloc(sizeof(struct countOccurence));
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
		
		return create_list(i+1, n);
	}
}