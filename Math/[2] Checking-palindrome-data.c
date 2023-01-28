#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head1, *head2, *traverse, *temp, *temp1, *temp2, *newNode, *currentNode, *nextNode, *tail1, *tail2, *clear, *freeThisNode;

void display_list();
void create_linked_list(int);
int display_result();
void reverse_list();
void copy_list();
void release_mem(struct node*);

int main()
{
	head1=head2=NULL;
	int inputNum, tempNum, dig;
	printf("Enter the number: ");
	scanf("%d", &inputNum);
	
	tempNum=inputNum;
	while(tempNum!=0)
	{
		dig=tempNum%10;
		create_linked_list(dig);
		tempNum/=10;
	}

	copy_list();
	reverse_list();
	printf("\n\n-----");
	display_list();
	
	int result;
	
	result=display_result();
	
	if(result==0)
	{
		printf("\n\nThe number %d is a palindrome number.", inputNum);
	}
	else
	{
		printf("\n\nThe number %d is not a palindrome number.", inputNum);
	}
	
	release_mem(head1);
	release_mem(head2);
	
	return 0;
}


void create_linked_list(int data)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->prev_ptr=newNode->next_ptr=NULL;
	
	if(head1==NULL)
	{
		head1=tail1=newNode;
	}
	else
	{
		tail1->next_ptr=newNode;
		newNode->prev_ptr=tail1;
		tail1=newNode;
	}
	
	return;
}

void reverse_list()
{
	currentNode=head2;
	while(currentNode!=NULL)
	{
		nextNode=currentNode->next_ptr;
		currentNode->next_ptr=currentNode->prev_ptr;
		currentNode->prev_ptr=nextNode;
		currentNode=nextNode;
	}
	
	struct node *swap;
	swap=head2;
	head2=tail2;
	tail2=swap;
	
	return;
}

int display_result()
{
	int flag=0;
	for(temp1=head1, temp2=head2; temp1!=NULL; temp1=temp1->next_ptr, temp2=temp2->next_ptr)
	{
		if(temp1->data==temp2->data)
		{
			continue;
		}
		else
		{
			flag=1;
			break;
		}
	}
	
	return flag;
}

void display_list()
{
	printf("\nFirst linked list: ");
	traverse=head1;
	while(traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse=traverse->next_ptr;
	}
	printf("\nSecond linked list: ");
	traverse=head2;
	while(traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse=traverse->next_ptr;
	}
}

void copy_list()
{
	temp1=head1;
	
	while(temp1!=NULL)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->next_ptr=newNode->prev_ptr=NULL;
		newNode->data=temp1->data;
		
		if(head2==NULL)
		{
			head2=tail2=newNode;
		}
		else
		{
			tail2->next_ptr=newNode;
			newNode->prev_ptr=tail2;
			tail2=newNode;
		}
		
		temp1=temp1->next_ptr;
	}
}

void release_mem(struct node *head)
{
	clear=head;
	
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
	}
	
	return;
}
