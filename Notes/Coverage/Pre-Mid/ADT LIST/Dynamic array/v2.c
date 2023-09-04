#include<stdlib.h>
#include<stdio.h>
#define INITIAL_CAPACITY 10
typedef struct{
    int *arr;
    int count;
    int capacity;
}List;

void initializeList(List *list)
{
    list->count=0; //setting count to 0 (meaning, there are 0 elements in the list)
    list->capacity = INITIAL_CAPACITY; //important for resizing lists; similar to arr[MAX_SIZE] in static arrays but can be changed
    list->arr = (int*)malloc(sizeof(int)*list->capacity); //allocates memory for an array of integers with the size of list->capacity

    if(list->arr==NULL)
    {
        perror("\nMEMORY ALLOCATION FAILED\n");
        exit(1);
    }
}

int isEmpty(List *list)
{
    return (list->count==0);
}

void insert(List *list, int elem)
{
    //if array is full, double its capacity
    if(list->count==list->capacity)
    {
        list->capacity*=2;
        
        //expanding
        list->arr = (int*)realloc(list->arr, sizeof(int)*list->capacity);

        //checking if we have successfully expanded
        if(list->arr==NULL)
        {
            perror("Memory allocation failed.");
            exit(EXIT_FAILURE);
        }
    }

    //after doubling its capacity or just invoking insert(), we can now insert elem
    list->arr[list->count++] = elem;
}

void display(List *list)
{
    if(isEmpty(list))
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nList: ");
    int i;
    for(i=0; i<list->count; i++)
    {
        printf("%d ", list->arr[i]);
    }

    printf("\n");
}

void destroy(List *list)
{
    free(list->arr); //whole dynamic array freed
    free(list); //local *list freed
}

void deleteAtPos(List *list, int pos)
{
    if(isEmpty(list))
    {
        printf("\n\tList is empty\n");
        return;
    }
    else
    {
        if(pos<0 || pos>=list->count)
        {
            printf("\nIndex out of range. Position should be starting from index 0.\n");
            return;
        }
        else
        {
            int i;
            for(i=pos; i<list->count; i++)
            {
                list->arr[i] = list->arr[i+1];
            }
            
            list->count--;
        }
    }
}

int main()
{
    List *myList = (List*)malloc(sizeof(List)); // 1: allocate
    if(myList == NULL) //2: check if allocation fails
    {
        perror("MEMORY ALLOCATION FAILED");
        exit(1);
    }

    //3: initialize list
    initializeList(myList); //myList is already a pointer so there's no need to do &myList
    

    insert(myList, 5);
    insert(myList, 10);

    display(myList);

    deleteAtPos(myList, 2);

    display(myList);

    return 0;
}