#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the array

struct List {
    int arr[MAX_SIZE]; // Static array to hold elements
    int size; // Current size of the list
};

void initList(struct List *list) //setting the current size of the list to 0 at first
{
    list->size = 0; // Initialize size to 0
}

void append(struct List *list, int element) {
    if (list->size < MAX_SIZE) //if current size is lesser than MAX_SIZE, element can be appended
    {
        list->arr[list->size++] = element; // Append element and increment size
        //we use list->arr as the *list in here is acting like a pointer to pointer to the array 
        //list->arr[0]; after appending, size will be increased
    } 
    else 
    {
        //no more elements to append as static array is now full
        printf("List is full. Cannot append.\n");
    }
}

int get(struct List *list, int index) 
{
    if (index >= 0 && index < list->size) 
    {
        return list->arr[index]; // Return element at the given index
    }
    printf("Index out of bounds.\n");
    return -1; // Just an example, you might want to handle errors differently
}

int size(struct List *list) {
    return list->size; // Return the current size of the list
}

int main() {
    struct List list;
    initList(&list); //initialize list first to have a current size of 0
    
    append(&list, 5); //size = 1
    append(&list, 10); //size = 2
    append(&list, 15); //size = 3
    
    printf("Element at index 0: %d\n", get(&list, 0));
    printf("Element at index 1: %d\n", get(&list, 1));
    printf("Element at index 2: %d\n", get(&list, 2));
    
    printf("List size: %d\n", size(&list));
    
    return 0;
}
