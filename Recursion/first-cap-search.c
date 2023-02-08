#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct findCapital{
	char ltr;
	struct findCapital *prev_addr;
	struct findCapital *next_addr;
} *head, *tail, *newNode, *clear, *freeNode;

void create_list(int, char, char[]);
char capital_found(struct findCapital*);
void display_characters(struct findCapital*);
void clear_mem();

int main()
{
	head=NULL;
	char input_string[MAX], ch;
	printf("Input a string: ");
	
	create_list(0, ch, input_string);
	char firstCap=capital_found(head);
	
	printf("\nString entered: %s", input_string);
	printf("...also stored in the linked list: ");
	display_characters(head);
	
	printf("\n-----");
	if(firstCap=='\0')
	{
		printf("\nThere are no capital letters in the given string.");
	}
	else
	{
		printf("\nFirst capital letter in the given string: %c", firstCap);
	}
	
	clear_mem();
	return 0;
}

void display_characters(struct findCapital *print_ch)
{
	if(print_ch==NULL)
	{
		return;
	}
	else
	{
		printf("%c ", print_ch->ltr);
		return display_characters(print_ch=print_ch->next_addr);
	}
}
char capital_found(struct findCapital *search)
{
	char ltr_found='\0';
	int flag=0;
	
	if(search==NULL)
	{
		return ltr_found;
	}
	else
	{
		if(search->ltr>= 65 && search->ltr<=90)
		{
			ltr_found=search->ltr;
			flag=1;
		}
	}
	
	if(flag==1)
	{
		return ltr_found;
	}
	else
	{
		return capital_found(search=search->next_addr);
	}
	
}

void create_list(int i, char ch, char input_string[])
{
	if(ch=='\n')
	{
		input_string[i]=NULL;
		return;
	}
	else
	{
		newNode=(struct findCapital*)malloc(sizeof(struct findCapital));
		ch=getchar();
		input_string[i]=ch;
		newNode->ltr=ch;
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
		
		return create_list(i+1, ch, input_string);
	}
}

void clear_mem()
{
	clear=head;
	while(clear!=NULL)
	{
		freeNode=clear;
		clear=clear->next_addr;
		free(freeNode);
		freeNode=NULL;
	}
}