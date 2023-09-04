/*
    Program for testing purposes only.
*/

#include<stdio.h>
// #include<stdbool.h>
#define MAX_SIZE 10
typedef struct{
    char elem[MAX_SIZE];
    int count;
}List;

void initList(List *list);
void displayList(List *list);
void insertUniqueElem(List *list, char elem);
int isEmpty(List *list);
int isFull(List * list);

void initList(List *list)
{
    list->count=0;
}

void displayList(List *list)
{
    if(isEmpty(list))
    {
        return;
    }
    printf("\nList: ");
    int i;
    for(i=0; i<list->count; i++)
    {
        printf("%c ", list->elem[i]);
    }

    printf("\n");
}

void insertUniqueElem(List *list, char elem)
{
    if(isFull(list))
    {
        printf("\n\tList is full!");
        return;
    }
    else
    {   
        if(list->count!=0) //insertion happens at nth or end of list
        {
            int i, j;
            for(i=0; i<list->count && elem != list->elem[i]; i++){} //traverse 
            
            //if i is equals to list->count, meaning, element to be inserted is not on the list yet
            if(i==list->count)
            {
                for(j=0; j<list->count; j++)//moving elements starting from index 1 to the right
                {
                    list->elem[j+1] = list->elem[j];
                }
                
                list->elem[0] = elem; //inserting elem at the beginning
                list->count++;
                printf("\n\tElement inserted.\n");
            }
            else
            {
                printf("\n\tElement already exists.\n");
            }
            
       }
       else //insert at beginning
       {
            list->elem[0] = elem;
            list->count++;
            printf("\n\tElement inserted.\n");
       }
    }
}

int isEmpty(List *list)
{
    return (list->count == 0);
}

int isFull(List *list)
{
    return (list->count == MAX_SIZE);
}

int main()
{
    List list_one;
    initList(&list_one);

    insertUniqueElem(&list_one, 'A'); 
    displayList(&list_one);
    insertUniqueElem(&list_one, 'B'); 
    insertUniqueElem(&list_one, 'A'); 
    displayList(&list_one);

    return 0;
}