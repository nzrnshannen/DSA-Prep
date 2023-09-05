#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct node{
char *elemptr;
int count;

}*LIST;

void initList(LIST *A){
*A = (LIST)malloc(sizeof(struct node));
if(*A != NULL)
{
    (*A)->elemptr = (char*)malloc(sizeof(char)*MAX);
    (*A)->count = 0;
}else{
    printf("\n\nYour list is not empty.");
}
}

void insertSorted(LIST A, char elem){

if(A->count < MAX){

int x;

for(x = A->count - 1; x >= 0 && A->elemptr[x] > elem; x--){

A->elemptr[x + 1] = A->elemptr[x];

}

A->elemptr[x+1] = elem;
A->count++;

}

}

void displayList(LIST A){
int x;
for(x=0; x < A->count; x++){

printf("%c\n\n", A->elemptr[x]);

}
}

int main(){

LIST *L;

initList(L);

insertSorted(*L, 'B');
insertSorted(*L, 'C');
insertSorted(*L, 'D');
insertSorted(*L, 'A');

displayList(*L);


return 0;
}