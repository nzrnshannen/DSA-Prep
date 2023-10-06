 //sll: reverse linked list (iterative approach)

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};

//Note: if you don't want to use double pointers, just return the struct Node*

struct Node* Reverse(struct Node*); 
struct Node* Insert(struct Node*, int); 
void Print(struct Node*);

int main()
{
	struct Node *head; //local
	head=NULL;
	
	head=Insert(head, 2);
	head=Insert(head, 4);
	head=Insert(head, 6);
	head=Insert(head, 8);
	Print(head);
	head=Reverse(head);
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

struct Node* Reverse(struct Node *head)
{
	struct Node *current, *prev, *next; 
	current=head; //pointing at the first node
	prev=NULL; //prev is set to NULL first because current is still pointing at the first node

	while(current!=NULL)
	{
		next=current->next; //will keep track of the next node once the reversal is implemented
		//we cannot go to the next node due to the link part being modified 
		
		current->next=prev; //changing the links; current->next now pointing to the prev
		prev=current; //jumps to the node that the current has been pointing. current pointer atm can now move to the next node
		current=next; //jumps to the next node. both pointers to Node are now pointing at the same node
	}
	
	//prev pointer is now at the end of the list
	head=prev; 
	//head will be pointing to the prev as reversal of links is now finished between nodes
	
	return head;
}

struct Node* Insert(struct Node *head, int x) //insert at end
{
	struct Node* insert_ptr=(struct Node*)malloc(sizeof(struct Node)); //creating a new node
	insert_ptr->data=x;
	insert_ptr->next=NULL;
	
	if(head==NULL)
	{
		head=insert_ptr;	
		return head;
	}	
	
	struct Node *temp1=head;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=insert_ptr;
	
	return head;
	
}

void Print(struct Node *temp) //temp to print all the list starting from the head to the end of the node
{
	printf("---\nList is: ");
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	printf("\n\n");
}

