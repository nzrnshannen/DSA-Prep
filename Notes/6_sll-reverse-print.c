//sll: print list using recursion

#include<stdlib.h>
#include<stdio.h>

struct Node{
	int data;
	struct Node *next;
};

void ReversePrint(struct Node* p)
{
	if(p==NULL) //exit condition
	{
		return;
	}
	ReversePrint(p->next); //moving on to the next node 
	printf("%d ", p->data); //this won't be executed until we're done with ReversePrint() 
	
	//4 5 6 2
	
}

struct Node *Insert(struct Node *head, int data) //insert data at the end
{
	struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	
	if(head==NULL) //if list is empty...
	{
		head=temp; 			//then head will have the value of temp (meaning, this is the first node)
	}
	else
	{
		struct Node *temp1=head; //traverse ptr of type struct Node
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
		}
		
		temp1->next=temp; //will attach the newly created node to the last node
	}
	
	return head; //in order for it to be reflected to the head in main()
}

int main()
{
	struct Node *head=NULL; //local variable
	head=Insert(head, 2);
	head=Insert(head, 6);
	head=Insert(head, 5);
	head=Insert(head, 4);
	ReversePrint(head);
	
	
	struct Node *temp;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		free(head);
	}
	
	return 0;
}

