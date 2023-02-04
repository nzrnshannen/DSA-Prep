#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *newNode, *freeThisNode;

void create_list(int, int);
void display_list(struct node*);
int search_data(int, int, struct node*);
void release_mem(struct node*);

int main()
{
	head=NULL;
	int n, inputNumSearch, result;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	printf("Input data for your %d nodes:\n", n);
	create_list(1, n);
	printf("\nLinked list: ");
	display_list(head);
	printf("\nEnter a data to search: ");
	scanf("%d", &inputNumSearch);
	result=search_data(inputNumSearch, 1, head);
	
	if(result==0)
	{
		printf("\n\nThe data %d is not in the list!", inputNumSearch);
	}
	else
	{
		printf("\n\nThe data %d can be found in position %d.", inputNumSearch, result);
	}
	
	release_mem(head);
	return 0;
	
}

void create_list(int i, int n)
{
	if(i>n)
	{
		return;
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next_ptr=newNode->prev_ptr=NULL;
		
		if(head==NULL)
		{
			head=tail=newNode;
		}
		else
		{
			tail->next_ptr=newNode;
			newNode->prev_ptr=tail;
			tail=newNode;
		}
		
		return create_list(i+1, n);
	}
}

void display_list(struct node *display_data)
{
	if(display_data==NULL)
	{
		return;
	}
	else
	{
		printf("%d ", display_data->data);
		return display_list(display_data->next_ptr);
	}
}

int search_data(int numSearch, int i, struct node *search)
{
	static int flag=-1;
	int pos=0;
	
	if(search==NULL)
	{
		return pos;
	}
	else
	{
		if(search->data==numSearch)
		{
			flag=1;
			pos=i;
			return pos;
		}
		else
		{
			flag=-1;
			return search_data(numSearch, i+1, search=search->next_ptr);
		}
	}
}

void release_mem(struct node *clr)
{
	while(clr!=NULL)
	{
		freeThisNode=clr;
		clr=clr->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
}