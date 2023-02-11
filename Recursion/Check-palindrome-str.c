//Program bound to change

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct string_node{
	char data;
	struct string_node *prev_addr;
	struct string_node *next_addr;
}*head, *tail, *newNode, *freeThisNode, *clear;

void create_string(char, char[], int);
void create_list(char);
void display_list(struct string_node*);
//void reverse_string(int, char[], int);
int check_palindrome(struct string_node*, char[], int);
void free_mem();

int main()
{
	char ch, input_string[MAX];
	printf("Enter a string: ");
	ch=getchar();
	create_string(ch, input_string, 0);
	printf("String: %s", input_string);
	
	//int str_length=strlen(input_string)-1;
	//reverse_string(str_length, input_string, 0);


//change this into recursion:
	for(int i=strlen(input_string)-1; i>=0; i--)
	{
		create_list(input_string[i]);
	}
	
	printf("\nLinked list: ");
	display_list(head);
	
	printf("\n\n---\n");
	int result=check_palindrome(head, input_string, 0);
	
	if(result==0)
	{
		printf("It is a palindrome.");
	}
	else
	{
		printf("It is not a palindrome.");
	}
	
	free_mem();
	
	return 0;
}

void free_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_addr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
}

int check_palindrome(struct string_node* check, char input_string[], int i)
{
	int flag=0;
	if(check==NULL)
	{
		return flag;
	}
	else
	{
		if(check->data!=input_string[i])
		{
			flag=1;
		}
	}
	
	if(flag==1)
	{
		return flag;
	}
	else
	{
		return check_palindrome(check=check->next_addr, input_string, i+1);
	}
}

/*void reverse_string(int len, char inputString[], int i)
{
	if(i<0)
	{
		return;
	}
	else
	{
		create_list(inputString[i]);
		return reverse_string(len, inputString, i-1);
	}
}*/
void create_list(char ch)
{
	newNode=(struct string_node*)malloc(sizeof(struct string_node));
	newNode->data=ch;
	newNode->next_addr=newNode->prev_addr=NULL;
	
	if(head==NULL)
	{
		head=tail=newNode;
	}
	else
	{
		tail->next_addr=newNode;
		newNode->prev_addr=tail;
		tail=newNode;
	}
}
void create_string(char ch, char inputString[], int i)
{
	if(ch=='\n')
	{
		inputString[i]='\0';
		return;
	}
	else
	{
		inputString[i]=ch;
		ch=getchar();
		
		return create_string(ch, inputString, i+1);
	}
}

void display_list(struct string_node *print_ptr)
{
	if(print_ptr==NULL)
	{
		return;
	}
	else
	{
		printf("%c", print_ptr->data);
		return display_list(print_ptr=print_ptr->next_addr);
	}
}