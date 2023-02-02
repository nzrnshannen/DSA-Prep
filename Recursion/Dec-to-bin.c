#include <stdio.h>
#include <stdlib.h>

struct node{
	int bnry;
	struct node *nxt_ptr;
	struct node *prv_ptr;
}*head, *tail, *freeThisNode, *newNode;

int dec_to_bin(int, int, int, int);
void create_list(int);
void display_list(struct node*);
void clear_mem(struct node*);
void bit_list(int);

int main()
{
	head=NULL;
	int temp, input_num;
	printf("Enter a number: ");
	scanf("%d", &input_num);
	int result_bin=dec_to_bin(0, 1, input_num, 0);
	
	temp=result_bin;
	bit_list(temp);
	printf("\n---\nDecimal [%d] to binary: ", input_num);
	display_list(tail);
	
	clear_mem(head);
	return 0;
}

void bit_list(int num)
{
	int dig;
	if(num==NULL)
	{
		return;
	}
	else
	{
		dig=num%10;
		create_list(dig);
		return bit_list(num/10);
	}
}
int dec_to_bin(int i, int j, int temp, int bin)
{
	if(temp==NULL)
	{
		return bin;
	}
	else
	{
		i=temp%2;
		bin=bin+(i*j);

		return dec_to_bin(i, j*10, temp/2, bin);
	}
}

void create_list(int temp)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->bnry=temp;
	
	if(head==NULL)
	{
		head=tail=newNode;
	}
	else
	{
		tail->nxt_ptr=newNode;
		newNode->prv_ptr=tail;
		tail=newNode;
	}
}

void display_list(struct node *print_data)
{
	if(print_data==NULL)
	{
		return;
	}
	else
	{
		printf("%d", print_data->bnry);
		return display_list(print_data=print_data->prv_ptr);
	}
}

//function bound to change
void clear_mem(struct node *clear_data)
{
	if(clear_data==NULL)
	{
		return;
	}
	else
	{
		freeThisNode=clear_data;
		clear_mem(clear_data=clear_data->nxt_ptr);
		free(freeThisNode);
		freeThisNode=NULL;
	}
}
