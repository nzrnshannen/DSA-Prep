//sll: reverse list recursively

#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node *next;
};

void Print(struct Node*);
struct Node* Insert(struct Node*, int);
struct Node* Reverse(struct Node*, struct Node*);
int main()
{
    struct Node *head;
	head=NULL;
	
    head=Insert(head, 2);
	head=Insert(head, 6);
	head=Insert(head, 5);
	head=Insert(head, 4);
	printf("\n---\nBefore reversing: ");
	Print(head);
	
	head=Reverse(head, head);		
	printf("\n---\nAfter reversing: ");
	Print(head);
	
	struct Node *temp;
	
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(temp);
	}
	
	return 0;
}

struct Node* Insert(struct Node* head, int x)
{
    printf("Inserting %d...\n", x);
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node)); //for creating nodes
	temp->data=x;
	temp->next=NULL;
	
	if(head==NULL)//if list is empty, head will point to the first node of the list
	{
		head=temp;
        return head;
	}
	
	struct Node *temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=temp;

    return head;
}

void Print(struct Node *temp)
{
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	printf("\n");
}

struct Node* Reverse(struct Node* head, struct Node* p)
{
	if(p->next==NULL) //exit condition: if p reaches the last node, we will return (which is p is now at the second to the last node)
	{
		head=p; //head is now pointing at the last node
		return head;
	}
	
	struct Node *new_head= Reverse(head, p->next); //Reverse() is called up until when p->next is NULL
    //after executing the exit condition, new_head is pointing to the last node due to 'return head' at the if() statement
    
    //CASES AFTER THE EXIT CONDITION IS EXECUTED: 
    //(new) head is now pointing at the last node

    //since we've returned, the p is pointing at the second to the last node
    //p is not pointing anymore at the last node since we've returned due to the exit condition
    //q will point to the node next to p 
    //using q, we can store the previous node (which is p)

	struct Node *q = p->next; //q is now pointing at the next node (after p)
	q->next=p; //q (example, when at the last node, will point to the second to the last node)
	p->next=NULL; //link part of p is set to NULL

	return new_head; //after calling the Reverse() recursively, the new head will be returned (this will be reflected at the head in main())
}