//needs revision

/*
	Name: Shannen T. Nazareno
	Program: An SLL program to sort 2 unsorted list and merged them into one single sorted list
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head1, *head2, *temp, *newNode, *clear, *temp1, *temp2, *freeNode;

void errorMsg();
void createList(int, int, struct node**);
void displayList(struct node*);
void mergeList(struct node**, struct node**);
void sortFunc(struct node*);
void clearFunc();

int main()
{
	head1=head2=NULL;
	int n1, n2;
	printf("===== MERGE LISTS =====\n");
	printf("Enter the number of nodes for your first list: ");
	scanf("%d", &n1);
	printf("Enter data for your %d nodes\n", n1);
	createList(1, n1, &head1);
	printf("Enter the number of nodes for your second list: ");
	scanf("%d", &n2);
	printf("Enter data for your %d nodes\n", n2);
	createList(1, n2, &head2);
	
	printf("---\nFirst linked list: ");
	displayList(head1);
	sortFunc(head1);
	
	printf("Sorted version: ");
	displayList(head1);
	
	printf("\nSecond linked list: ");
	displayList(head2);
	sortFunc(head2);
	
	printf("Sorted version:");
	displayList(head2);

	
	mergeList(&head2, &head1);
	printf("\n***\nLinked List (Merged): ");
	sortFunc(head1);
	displayList(head1);
	
	clearFunc();
	return 0;
}

void errorMsg()
{
	printf("\n\nInvalid input. Try again.\n\n");
}

void createList(int i, int n, struct node **head)
{
	if(i>n)
	{
		printf("\n\t\tList created.\n\n");
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(*(head)==NULL)
		{
			*(head)=temp=newNode;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
		
		return createList(i+1, n, head);
	}
}

void displayList(struct node *print_ptr)
{
	if(print_ptr==NULL)
	{
		printf("\n");
	}
	else
	{
		printf("%d ", print_ptr->data);
		
		return displayList(print_ptr->next);
	}
}

void mergeList(struct node** head2, struct node **temp)
{
	if((*temp)->next==NULL)
	{
		(*temp)->next=*(head2);
		//sortFunc
	}
	else
	{
		return mergeList(head2, &(*temp)->next);
	}
}

void sortFunc(struct node*head)
{
	int temp;
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
		{
			if(temp2->data > temp2->next->data)
			{
				temp = temp2->data;
				temp2->data = temp2->next->data;
				temp2->next->data = temp;
			}
		}
	}
}

void clearFunc()
{
	clear=head1;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next;
		free(freeNode);
		freeNode=NULL;
	}
	
	head1=head2=temp=temp1=temp2=clear=newNode=freeNode=NULL;
}