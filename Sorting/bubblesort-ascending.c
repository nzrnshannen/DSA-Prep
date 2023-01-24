#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *tail, *temp1, *temp2, *traverse, *newNode;

void displayFunc();
void sortFunc();

int main()
{
	head=NULL;
	int i=1, n;
	
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data:\n", n);
	for(i; i<=n; i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->prev_ptr=newNode->next_ptr=NULL;
		
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
	}
	
	printf("\n\nBefore sorting: ");
	displayFunc();
	printf("\nAfter sorting: ");
	sortFunc();
	displayFunc();
	
	free(head);
	free(tail);
	free(newNode);
	free(temp1);
	free(temp2);
	free(traverse);
	
	head=tail=newNode=temp1=temp2=traverse;
	
	return 0;
}

void sortFunc()
{
	for(temp1=head; temp1!=NULL; temp1=temp1->next_ptr)
	{
		for(temp2=head; temp2->next_ptr!=NULL; temp2=temp2->next_ptr)
		{
			if(temp2->next_ptr->data < temp2->data) //for descending: (temp2->next_ptr->data > temp2->data)
			{
				int swap_data;
				swap_data=temp2->data;
				temp2->data = temp2->next_ptr->data;
				temp2->next_ptr->data=swap_data;
			}		
		}
	}
}

void displayFunc()
{
	for(traverse=head; traverse!=NULL; traverse=traverse->next_ptr)
	{
		printf("%d ", traverse->data);
	}
}