#include <stdio.h>
#include <stdlib.h>

struct checkPrime{
	int data;
	struct checkPrime *next_addr;
	struct checkPrime *prev_addr;
};

struct checkPrime *head, *tail, *newNode, *freeThisNode, *clear;

void create_linked_list(int, int);
void display_list(struct checkPrime*);
void check_if_prime(struct checkPrime*);
int prime_or_not(int);
void free_mem();

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	create_linked_list(1, n);
	printf("\nLinked list: ");
	display_list(head);
	printf("\n\n--------\n");
	check_if_prime(head);
	
	free_mem();
	return 0;
}

void free_mem()
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
int prime_or_not(int i, int num)
{
	int flag=0;
	
	if(i>num/2)
	{
		return flag;
	}
	else
	{
		if(num%i==0)
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		return flag;
	}
	else
	{
		return prime_or_not(i+1, num);
	}
}

void check_if_prime(struct checkPrime *chck_ptr)
{	
	int result;
	if(chck_ptr==NULL)
	{
		return;
	}
	else
	{
		if(chck_ptr->data==1)
			result=1;
		else
			result=prime_or_not(2, chck_ptr->data);
		
		if(result==1)
		{
			printf("%d [Not Prime]\n", chck_ptr->data);
		}
		else
		{
			printf("%d [Prime]\n", chck_ptr->data);
		}
		
		return check_if_prime(chck_ptr=chck_ptr->next_addr);
	}
}
void display_list(struct checkPrime *print_data)
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
void create_linked_list(int i, int limit)
{
	if(i>limit)
	{
		return;
	}
	else
	{
		newNode=(struct checkPrime*)malloc(sizeof(struct checkPrime));
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
		
		return create_linked_list(i+1, limit);
	}
}