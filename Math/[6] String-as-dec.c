#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

struct node{
	char ltr;
	struct node *prev_ptr;
	struct node *next_ptr;
}*head, *temp, *traverse, *newNode, *freeThisNode, *clear, *tail, *check;

void create_linked_list(char);
void display_linked_list();
int check_if_decimal();
void release_mem();

int main()
{
	head=NULL;
	char inputStr[MAX], ch;
	printf("Enter a string: ");

	int i=0;
	while((ch=getchar())!='\n')
	{
		inputStr[i]=ch;
		create_linked_list(ch);
		i++;
	}
	inputStr[i]='\0';
	
	printf("\nInput: ");
	display_linked_list();
	
	int result=check_if_decimal();
	
	printf("\n\n-----\n");
	if(result==0)
	{
		printf("Input can be interpreted as a decimal.");
	}
	else
	{
		printf("Input cannot be interpreted as a decimal.");
	}
	
	release_mem();
	
	return 0;
}

void create_linked_list(char c)
{
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->ltr=c;
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
	
	return;
}

void display_linked_list()
{
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%c", traverse->ltr);
		traverse=traverse->next_ptr;
	}
}

int check_if_decimal()
{
	int d_count=0, s_check=0, flag=0;
	check=head;
	
	int pos=1, loc=0;
	
	while(check!=NULL)
	{
		if(check->ltr=='-')
		{
			s_check++;
			loc=pos;
		}
		if(check->ltr=='.')
		{
			d_count++;
			
			if(d_count>1)
			{
				flag=1;
				break;
			}
		}
		else if(!(isdigit(check->ltr)))
		{
			flag=1;
			break;
		}
		
		check=check->next_ptr;
		
		pos++;
	}
	
	if(s_check==1)
	{
		if(loc>1)
		{
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	else if(s_check>1)
	{
		flag=1;
	}
	
	return flag;
	
}

void release_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeThisNode=clear;
		clear=clear->next_ptr;
		free(freeThisNode);
		freeThisNode=NULL;
	}
}