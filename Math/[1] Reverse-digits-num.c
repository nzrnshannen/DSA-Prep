//reverse digits of a given integer	

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next_ptr;
	struct node *prev_ptr;
}*head, *temp, *traverse, *newNode, *freeThisNode, *tail, *currentNode, *nextNode, *clear;

void storeData(int);
void releaseMem();
void printList();
int newNum();

int main()
{
	head=NULL;
	int num, dig;
	printf("Enter a number: ");
	scanf("%d", &num);
	
	int holder=num;
	
	while(holder!=0)
	{
		dig=holder%10;
		storeData(dig);
		holder/=10;
	}
	
	printf("\nSeparating the digits using linked list (in reverse): ");
	printList();
	num = newNum();
	printf("\nNew number (reversed): %d", num);
	releaseMem();
	return 0;
}

void storeData(int num)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=num;
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
}

void printList()
{
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse=traverse->next_ptr;
	}
}

int newNum()
{
	int result=0;
	temp=head;
	while(temp!=NULL)
	{
		result=result*10+temp->data;
		temp=temp->next_ptr;
	}
	
	return result;
}

void releaseMem()
{
	clear=head;
	while(clear!=NULL)
	{
		nextNode=clear->next_ptr;
		freeThisNode=clear;
		clear=nextNode;
		free(freeThisNode);
	}

//the next ff. lines are (maybe) redundant in terms of freeing the memory:
	free(head);
	free(tail);
	free(temp);
	free(newNode);
	free(nextNode);
	free(clear);
	free(freeThisNode);
	free(traverse);
	free(currentNode);
	
	head=tail=temp=newNode=nextNode=clear=freeThisNode=traverse=currentNode=NULL;
	
	return;
}