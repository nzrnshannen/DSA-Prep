/*
    Name: Shannen T. Nazareno
    Program: SLL to sort and remove duplicates
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *freeNode;

void clearList(struct node*);
void createList(int, int);
void displayList(struct node*);
void sortFunc(struct node*, struct node*);
void swapNodes(struct node*);
void removeDuplicates(struct node*);
void deleteNode(struct node*, struct node*, struct node*);

int main()
{
	int n;
	head=NULL;
	printf("=== REMOVE DUPLICATES FROM A SORTED SLL ===\n");
	printf("Enter the number of nodes: ");
	scanf("%d", &n);	
	printf("Enter data for your %d nodes\n", n);
	createList(1, n);
	
	printf("\n***\nBefore sorting: ");
	displayList(head);
	printf("After sorting: ");
	sortFunc(head, head);
	displayList(head);
	
	printf("\n======\nFinal linked list: ");
	removeDuplicates(head);
	displayList(head);
	
	clearList(head);
	
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

void sortFunc(struct node* temp1, struct node *temp2)
{
	if(temp1==NULL)
	{
		return;
	}
	else
	{
		swapNodes(temp2);
		
		sortFunc(temp1->next, head);
	}
}

void swapNodes(struct node *temp2)
{
	if(temp2->next==NULL)
	{
		return;
	}
	else
	{
		if(temp2->data > temp2->next->data)
		{
			int data;
			data = temp2->data;
			temp2->data = temp2->next->data;
			temp2->next->data = data;	
		}

		swapNodes(temp2->next);
	}
}

void clearList(struct node *clear)
{
	if(clear==NULL)
	{
		clear=head=temp=newNode=freeNode=NULL;
		return;
	}
	else
	{
		freeNode=(clear);
		return clearList(clear->next);
		free(freeNode);
	}
}

void removeDuplicates(struct node *key)
{
	if(key->next==NULL)
	{
		return;
	}
	else
	{
		deleteNode(key, key, key->next);
		
		if(key->next==NULL)
		{
			return;
		}
		
		return removeDuplicates(key->next);
	}
}

void deleteNode(struct node *key, struct node *prevNode, struct node *nextNode)
{
	if(nextNode==NULL)
	{
		return;
	}
	else
	{		
		if(key->data==nextNode->data)
		{
			freeNode=nextNode;
			prevNode->next=nextNode->next;
			nextNode=nextNode->next; //if not included, nextNode and freeNode are currently pointing to the node being deleted which results to nextNode not having any reference to the next node. Thus, error occurs
			free(freeNode); //if this is before the nextNode=nextNode->next, we will lose reference to the next node
			
			//So in order to prevent this issue (dangling pointers), the memory to be freed should be the last one to be executed AFTER moving the pointers
		}
		else
		{
			prevNode=nextNode;
			nextNode=nextNode->next;
		}
			//nextNode=nextNode->next; <-- if this was implemented rather than using it inside if-else, the nextNode is still pointing to that freed memory (nonsense)
		deleteNode(key, prevNode, nextNode);
	}
}

/*

		Iterative method:

void removeDuplicates() 
{
	struct node *key, *prev, *nextNode;
	
	for(key=head; key->next!=NULL; key=key->next)
	{
		prev=key;
		nextNode=key->next; 
		
		while(nextNode!=NULL)
		{
			if(key->data==nextNode->data)
			{
				freeNode=nextNode; 
				prev->next=nextNode->next;
				nextNode=nextNode->next;
				free(freeNode);
			}
			else
			{
				prev=nextNode;
				nextNode=nextNode->next;
			}
		}
		
		if(key->next==NULL)
		{
			break;
		}
	}
}



*/