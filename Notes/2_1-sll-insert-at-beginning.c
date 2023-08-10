//(1st) sll insert at beginning: local head, return type: struct Node*

#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *link;
};

struct Node* Insert(struct Node*, int x); 
void Print(struct Node*);

int main()
{
	struct Node *head;
	head=NULL; //empty list

inputN:
	printf("How many numbers? ");
	int n, i, x;
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nImpossible to create a list. Try a different one.\n\n");
		goto inputN;
	}
	
	printf("\n\n");
	
	for(i=0; i<n; i++)
	{
		printf("Enter the number: ");
		scanf("%d", &x); //x for data
		
		//since we only passed the copy of head, we need to return in order for it to be reflected to the head in main()
		head = Insert(head, x); //a function that will pass the data (x) and insert it in the list
		
		Print(head); //a function for printing the list after we insert data at the beginning
	}	
}

struct Node* Insert(struct Node *head, int x)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); //creating a node
	temp->data=x;
	temp->link=head; //important for the first node
	
	//remember, the very first node will have the link of NULL  
	
	//Scenario: 
	//1st: inserting 1 --> 1 (head is NULL)
	//2nd: inserting 2 --> 2 1 (head is not NULL)
	//3rd; inserting 3 ---> 3 2 1 (head is not NULL)
	
	head=temp; //new inserted node will be the first node
	
	//the first node was 1, and is the last node no matter how many times we've entered new data
	
	return head; //if we will not return the head in Insert(), it will not be reflected on the head that's on the main()
}

void Print(struct Node *head) //local *head used for printing only
{
	//everytime we insert, the whole list will be printed starting from the first until the end node
	
	printf("---\nList is: ");
	
	while(head!=NULL)
	{
		printf("%d ", head->data);
		head=head->link;
	}
	
	printf("\n\n");
}

