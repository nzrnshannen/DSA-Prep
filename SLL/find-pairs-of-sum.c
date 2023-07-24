/*
    Name: Shannen T. Nazareno
    Program: SLL program to find pairs of entered sum
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *freeNode;

void createList(int, int);
void displayList(struct node*);
void moveKey(struct node*, int);
void findPairs(struct node*, struct node*, int);
void clearFunc(struct node*);

int flag;

int main()
{
	int n, sum;
	head=NULL;
	printf("=== FIND PAIRS EQUAL TO SUM ===\n");
	
	printf("\nEnter the number of nodes for your linked list: ");
	scanf("%d", &n);
	printf("Enter data for your %d nodes\n", n);
	createList(1, n);
	printf("Enter sum = ");
	scanf("%d", &sum);
	printf("\n\n=========\nLinked list: ");
	displayList(head);
	printf("Sum: %d\n", sum);
	moveKey(head, sum);
	if(flag!=1)
	{
		printf("\nNo such pair.");
	}
	
	clearFunc(head);
	return 0;
}

void createList(int i, int n)
{
	if(i>n)
	{
		printf("\n\n\tList created.\n\n");
	}
	else
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
		
		return createList(i+1, n);
	}
}

void displayList(struct node *print)
{
	if(print==NULL)
	{
		printf("\n\n");
	}
	else
	{
		printf("%d ", print->data);
		
		return displayList(print->next);
	}
}

/*
Iterative method: 

int findPairs(int);

int findPairs(int sum){
	struct node* temp1, *temp2;
	int flag=0;
	
	for(temp1=head;temp1!=NULL; temp1=temp1->next)
	{
		for(temp2=temp1; temp2!=NULL; temp2=temp2->next)
		{
			if(temp2==temp1)
			{
				continue;
			}
			else
			{
				if((temp1->data+temp2->data) == sum)
				{
					if(flag!=1)
					{
						printf("\nPairs:\n");
					}
					printf("(%d, %d)\n", temp1->data, temp2->data);
					flag =1;
				}
			}
		}
	}
	
	return flag;
}

*/

void moveKey(struct node *temp1, int sum)
{
	if(temp1==NULL)
	{
		return;
	}
	else
	{
		findPairs(temp1, temp1->next, sum);
		return moveKey(temp1->next, sum);
	}
}

void findPairs(struct node *temp1, struct node *temp2, int sum)
{
	if(temp2==NULL)
	{
		return;
	}
	else
	{
		if(temp2!=temp1)
		{
			if((temp1->data + temp2->data)==sum)
			{
				if(flag!=1)
				{
					printf("\n------\nPairs:\n");
				}
				
				printf("(%d, %d)\n", temp1->data, temp2->data);
				flag=1;
			}
		}
		
		findPairs(temp1, temp2->next, sum);
	}
}

void clearFunc(struct node *clear)
{
	if(clear==NULL)
	{
		printf("\n");
		head=temp=clear=freeNode=newNode=NULL;
	}
	else
	{
		freeNode=clear;
		clearFunc(clear->next);
		free(freeNode);
	}
}