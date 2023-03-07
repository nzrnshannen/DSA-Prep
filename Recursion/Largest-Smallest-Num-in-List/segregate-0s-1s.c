#include <stdio.h>
#include <stdlib.h>

struct segregate{
	int data;
	struct segregate* prev_addr;
	struct segregate* next_addr;
}*n0, *n1, *h0, *h1, *t0, *t1, *freeNode, *clear;

void create_list(int, int);
void display_list(struct segregate*);
void zero_func(int);
void one_func(int);
void clear_mem(struct segregate*);
int zeroCount = 0;
int oneCount = 0;

int main()
{
	h0=h1=NULL;
	int n;
	printf("====================================================\n");
	printf("\t\tSEGREGATE Os AND 1s\n\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	create_list(1, n);
	printf("\n----\n");
	display_list(h0);
	display_list(h1);
	printf("\n\nNumber of 0s: %d", zeroCount);
	printf("\nNumber of 1s: %d", oneCount);
	
	return 0;
}

void clear_mem(struct segregate *head)
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next_addr;
		free(freeNode);
		freeNode=NULL;
	}
	
	free(h0);
	free(h1);
	free(n0);
	free(n1);
	free(clear);
	free(freeNode);
	free(t0);
	free(t1);
	h0=h1=n0=n1=clear=freeNode=t0=t1=NULL;
	
	return;
}

void display_list(struct segregate* print_ptr)
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
		int num;
	
	inputNum:
		printf("Data %d: ", i);
		scanf("%d", &num);
		
		switch(num)
		{
			case 0: zeroCount++; zero_func(num);
			break;
			case 1: oneCount++; one_func(num);
			break;
			default: printf("\n\nInput not applicable for this program. Try again.\n\n");
			goto inputNum;
			break;
		}
		
		return create_list(i+1, num_of_nodes);
	}
}

void zero_func(int data)
{
	n0 = (struct segregate*)malloc(sizeof(struct segregate));
	n0->data = data;
	n0->next_addr=n0->prev_addr=NULL;
	
	if(h0==NULL)
	{
		h0=t0=n0;
	}
	else
	{
		t0->next_addr=n0;
		n0->prev_addr=t0;
		t0=n0;
	}
	
	return;
}

void one_func(int data)
{
	n1 = (struct segregate*)malloc(sizeof(struct segregate));
	n1->data = data;
	n1->next_addr=n1->prev_addr=NULL;
	
	if(h1==NULL)
	{
		h1=t1=n1;
	}
	else
	{
		t1->next_addr=n1;
		n1->prev_addr=t1;
		t1=n1;
	}
	
	return;
}