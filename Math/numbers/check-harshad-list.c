#include <stdio.h>
#include <stdlib.h>

struct checkHarshad{
	int data;
	struct checkHarshad* prev_addr;
	struct checkHarshad* next_addr;
}*head, *tail, *newNode, *freeNode, *clear;

void create_list(int, int);
int check_each_num(struct checkHarshad*);
int check_if_harshad(int, int);
void clear_mem();

int main()
{
	head=NULL;
	int n;
	printf("=============================================\n");
	printf("CHECKING LIST OF NUMBERS IF THEY ARE HARSHAD NUMBERS\n\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	printf("\n---\nEnter data for your %d nodes:\n", n);
	create_list(1, n);
	int r = check_each_num(head);
	
	if(r==1)
	{
		printf("It is not a list of Harshad numbers.");
	}
	else
	{
		printf("It is a list of Harshad numbers.");
	}
	
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
	
	return;
}

int check_if_harshad(int temp, int sum)
{
	int dig;
	if(temp==0)
	{
		return sum;
	}
	else
	{
		dig=temp%10;
		sum+=dig;
		
		return check_if_harshad(temp=temp/10, sum);
	}
}

int check_each_num(struct checkHarshad* check_ptr)
{
	static int flag = 0;
	if(check_ptr==NULL)
	{
		return flag;
	}
	else
	{
		int s = check_if_harshad(check_ptr->data, 0);
		if(check_ptr->data%s==1)
		{
			flag=1;
			return flag;
		}
		
		return check_each_num(check_ptr->next_addr);
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
		newNode=(struct checkHarshad*)malloc(sizeof(struct checkHarshad));
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