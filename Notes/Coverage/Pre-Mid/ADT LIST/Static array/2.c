/*
    OPERATIONS:
    - initialize
    - check if empty
    - check if full
    - insert element
    - delete element at specific position
    - display
    - clear list
*/

#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 5
typedef struct{
    int arr[MAX_SIZE];
    int count;
}List;

void initList(List *list)
{
    list->count=0;
}

bool isEmpty(List *list)
{
    return (list->count==0);
}

bool isFull(List *list)
{
    return (list->count==MAX_SIZE);
}

void displayList(List *list)
{
    printf("\n===\nList: ");
    int i;
    for(i=0; i<list->count; i++)
    {
        printf("%d ", list->arr[i]);
    }

    printf("\n");
}

void insert(List *list, int elem)
{

    list->arr[list->count] = elem;
    list->count++;
    printf("\n\tElement inserted.\n\n");
}

void deleteAtPos(List *list, int index)
{
    if(index<0 || index>=list->count)
    {
        printf("\n\n\tIndex out of bounds. Try entering a different one.\n\n");
        return;
    }
    else
    {
        int i, j;
        for(i=0; i<index; i++){}

        for(j=i; j<list->count-1; j++)
        {
            list->arr[j] = list->arr[j+1];
        }

        list->count--;

        printf("\n\n\tElement deleted.\n\n");
    }
}

int main()
{
    List myList;
    initList(&myList);

    int menu=1, choice, elem;

    do{
        printf("================\n");
        printf("[1] Insert element\n");
        printf("[2] Delete element\n");
        printf("[3] Display list\n");
        printf("[4] Clear list\n");
        printf("\n\n[0]EXIT\n---\nChoice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
            if(isFull(&myList))
            {
                printf("\n\nList is already full.\n\n");
            }
            else
            {
                printf("\n--- INSERT ELEMENT ---\n");
                printf("Enter an element: ");
                scanf("%d", &elem);

            insert(&myList, elem);
            }
            break;
            case 2: 
            if(isEmpty(&myList))
            {
                printf("\n\n\tEmpty list. Nothing to delete.\n\n");
            }
            else
            {
                int pos;
                printf("\n\n--- DELETE ELEMENT AT A GIVEN POSITION ---\n");
                displayList(&myList);
                printf("\n***\nEnter a position starting from 0: ");
                scanf("%d", &pos);
                deleteAtPos(&myList, pos);
            }
            break;
            case 3: 
            if(isEmpty(&myList))
            {
                printf("\n\n\tEmpty list!\n\n");
            }
            else
            {
                //display list
                displayList(&myList);
            }
            break;
            case 4: 
            if(isEmpty(&myList))
            {
                printf("\n\n\tEmpty list!\n\n");
            }
            else
            {
                int confirm;
                printf("==============\nAre you sure? \n");
                printf("[1] Yes\n[2] No\n---\nChoice: ");
                scanf("%d", &confirm);
                switch(confirm)
                {
                    case 1:
                    initList(&myList);
                    printf("\n\n\tList cleared.\n\n");
                    break;
                    case 2: 
                    printf("\n\n\tDecided not to clear list.\n\n");
                    break;
                    default: printf("Invalid input. Try again.\n\n");
                }
            }

            break;
            case 0: menu = 0; break;

            default: printf("\n\nInvalid choice. Try again.\n\n"); break;
        }

    }while(menu);


    printf("\n********************************\n\tPROGRAM TERMINATED\n********************************");

    return 0;
}

