#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *clear, *start, *end, *freeNode;

void clearFunc(struct node*);
void createList(int);
void displayList(struct node*);
void rotateList(int, int);
void moveToLast(struct node*);
void moveToKPos(struct node*, struct node*, int, int);

int n;
int main()
{
	int k;
	head=NULL;
	printf("== ROTATE LIST BY K POSITIONS TO THE RIGHT ==\n");
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Enter data for your %d nodes\n", n);
	createList(1);
	printf("-----\nLinked list: ");
	displayList(head);
	
	printf("Number of positions to rotate the list: ");
	scanf("%d", &k);
	
	rotateList(0, k);
	
	printf("\nLinked list after rotating: ");
	displayList(head);
	
	clearFunc(head);
	
	return 0;
}

void createList(int i)
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
		
		return createList(i+1);
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

void rotateList(int i, int k)
{
	moveToLast(head);
	moveToKPos(NULL, head, i, k);
	
	return;
}

void moveToKPos(struct node* end, struct node *start, int i, int k)
{
	if(i>k)
	{
		end->next=NULL;
		head=start;
	}
	else
	{
		moveToKPos(start, start->next, i+1, k);
	}
}
void moveToLast(struct node* temp)
{
	if(temp->next==NULL)
	{
		temp->next=head;
	}
	else
	{
		moveToLast(temp->next);
	}
}


/* iterative version:

void rotateList(int i, int k)
{
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=head;
	
	end=NULL;
	start=head;
	
	while(i<=k)
	{
		end=start;
		start=start->next;
		i++;	
	}
	
	end->next=NULL;
	head=start;
}
*/

void clearFunc(struct node *clear)
{
	if(clear==NULL)
	{
		printf("\n");
		head=temp=newNode=clear=freeNode=NULL;
		return;
	}
	else
	{
		freeNode=clear;
		clearFunc(clear->next);
		free(freeNode);
	}
	
}