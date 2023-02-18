#include <stdio.h>
#include <stdlib.h>
#define MAX -9999
#define MIN 9999

struct findSecond{
	int data;
	struct findSecond *next_ptr;
	struct findSecond *prev_ptr;
}*head, *tail, *newNode, *freeThisNode, *clear;

void clear_mem();
void create_list(int, int);
void display_list(struct findSecond*);
int findLargest(struct findSecond*);
int findLargest_second(struct findSecond*, int);
int findSmallest(struct findSecond*);
int findSmallest_second(struct findSecond*, int);

int main()
{
	head=NULL;
	int n;
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	create_list(1, n);
	printf("Linked list: ");
	display_list(head);
	
	//find second largest
	int largest_second=findLargest(head);

    //find second largest
	int smallest_second=findSmallest(head);
	printf("\n\n---\n");
	printf("Second largest data: %d", largest_second);
	printf("\nSecond smallest data: %d", smallest_second);
	
	clear_mem();
	return 0;
}

void clear_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;	
	}	
	return;
}

int findSmallest(struct findSecond* find_smallest)
{
	static int smallest_num=MIN;
	if(find_smallest==NULL)
	{
		int result = findSmallest_second(head, smallest_num);
		return result;
	}
	else
	{
		if(find_smallest->data<smallest_num)
		{
			smallest_num=find_smallest->data;
		}
		
		return findSmallest(find_smallest=find_smallest->next_ptr);
	}
}

int findLargest(struct findSecond* find_largest)
{
	static int largest_num=MAX;
	if(find_largest==NULL)
	{
		int result = findLargest_second(head, largest_num);
		return result;
	}
	else
	{
		if(find_largest->data>largest_num)
		{
			largest_num=find_largest->data;
		}
		
		return findLargest(find_largest=find_largest->next_ptr);
	}
}

int findLargest_second(struct findSecond *find_secondLrg, int lrg)
{
	static int lrg2nd=MAX;
	if(find_secondLrg==NULL)
	{
		return lrg2nd;
	}
	else
	{
		if(find_secondLrg->data!=lrg)
		{
			if(find_secondLrg->data>lrg2nd)
			{
				lrg2nd=find_secondLrg->data;
			}
		}
		
		return findLargest_second(find_secondLrg=find_secondLrg->next_ptr, lrg);
	}
}

int findSmallest_second(struct findSecond* find_secondSml, int sml)
{
	static int sml2nd=MIN;
	if(find_secondSml==NULL)
	{
		return sml2nd;
	}
	else
	{
		if(find_secondSml->data!=sml)
		{
			if(find_secondSml->data<sml2nd)
			{
				sml2nd=find_secondSml->data;
			}
		}
		
		
		return findSmallest_second(find_secondSml=find_secondSml->next_ptr, sml);
	}
}
void display_list(struct findSecond* print_data)
{
	if(print_data==NULL)
	{
		printf("\n");
		return;
	}
	else
	{
		printf("%d ", print_data->data);
		return display_list(print_data=print_data->next_ptr);
	}
}
void create_list(int i, int n)
{
	if(i>n)
	{
		printf("\n");
		return;
	}
	else
	{
		newNode=(struct findSecond*)malloc(sizeof(struct findSecond));
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