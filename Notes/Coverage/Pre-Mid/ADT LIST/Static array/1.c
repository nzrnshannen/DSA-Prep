#include<stdio.h>
#define MAX_SIZE 5 //maximum size of the array

typedef struct{
    int data[MAX_SIZE];
    int size;
}StaticArray;

void printStatic(StaticArray B[])
{
    printf("\nArray: ");
    int i;
    for(i=0; i<B->size; i++)
    {
        printf("%d ", B->data[i]);
    }

    printf("\n");
}
void initStaticArray(StaticArray A[])
{
    A->size=0; //size or count is 0 at first
}

void setUniqueValue(int data, StaticArray B[])
{
    int i, flag=0;
    for(i=0; i<B->size && flag!=1; i++)
    {
        if(B->data[i]==data)
            flag=1;
    }

    if(flag==1)
    {
        printf("\n\nElement already exists!\n\n");
    }
    else
    {
        if(B->size<MAX_SIZE)
        {
            B->data[B->size++] = data;
            printf("\n\tData inserted.\n");
        }
    }
}


int main()
{
    StaticArray List;
    initStaticArray(&List); //initialize
    int choice, menu=1;
    do{
        printf("Do you want to insert a (unique) number?\n");
        printf("[1] Yes\n[2] No\n-----\nChoice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: 
            int data;
            printf("\n*****\nEnter data: ");
            scanf("%d", &data);
            setUniqueValue(data, &List);
            printf("\n");
            break;
            case 2: menu=0; break;
            default: printf("\n\nInvalid input. Try again.\n\n");
        }
    }while(menu && List.size<=MAX_SIZE-1);

    printStatic(&List);
    if(List.size==MAX_SIZE-1)
        printf("\n\n---Array is already full.---\n\n");

    return 0;
}