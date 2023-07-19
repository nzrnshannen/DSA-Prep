/*
	Name: Shannen T. Nazareno
	Program: An SLL Program to check if the given string (stored in a list form) is a Palindrome or not
*/

#include<stdio.h>
#include<stdlib.h>

struct stringNode{
	char data;
	struct stringNode *next;
}*head1, *head2, *temp, *newNode, *freeNode, *clear;

void createList(char);
//void displayList(struct stringNode*); <--redundant
void clearFunc();
void reverseList(struct stringNode*, struct stringNode*, struct stringNode*);
int checkPalindrome(int, struct stringNode*, struct stringNode*);

int n;

int main()
{
	head1=head2=NULL;
	char ch;
	
	printf("=== PALINDROME CHECK ===\nEnter a string: ");
	while((ch=getchar())!='\n')
	{
		createList(ch);
	}
	
	head2=head1;
	reverseList(NULL, head2, head2);
	
	int r=checkPalindrome(1, head1, head2);
	
	if(r==1)
	{
		printf("\n===\nIt is a Palindrome.\n");
	}
	else
	{
		printf("\n===\nIt is not a Palindrome.\n");
	}
	
	clearFunc();
	
	return 0;
}

	

void createList(char ch)
{
	newNode=(struct stringNode*)malloc(sizeof(struct stringNode));
	newNode->data=ch;
	newNode->next=NULL;
	
	if(head1==NULL)
	{
		head1=temp=newNode;
	}
	else
	{
		temp->next=newNode;
		temp=newNode;
	}
	
	n++;
}

/*
void displayList(struct stringNode *print_ptr) //redundant
{
	if(print_ptr==NULL)
	{
		printf("\n");
	}
	else
	{
		printf("%c", print_ptr->data);
		
		return displayList(print_ptr->next);
	}
}

*/

void reverseList(struct stringNode *prevNode, struct stringNode* current, struct stringNode* nextNode)
{
	if(current==NULL)
	{
		head2=prevNode;
	}
	else
	{
		nextNode=nextNode->next;
		current->next=prevNode;
		
		return reverseList(current, nextNode, nextNode);
	}
}

int checkPalindrome(int flag, struct stringNode *t1, struct stringNode *t2)
{
	if(t1==NULL || flag==0)
	{
		return flag;
	}
	else
	{
		if(t1->data!=t2->data)
		{
			flag=0;
		}
		
		return checkPalindrome(flag, t1->next, t2->next);
	}
}

void clearFunc()
{
	clear=head1;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next;
		free(freeNode);
		freeNode=NULL;
	}
	
	head1=head2=temp=newNode=clear=freeNode=NULL;
}
