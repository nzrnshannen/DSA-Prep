#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct{
    int *members;
    int length;
}Set;

Set* init();
bool is_Empty(Set *set);
void insert(Set *set, int member);
void print_set(Set *set);
Set *set_union(Set *setA, Set *setB);
Set *set_intersection(Set *setA, Set *setB);
Set *set_difference (Set *setA, Set *setB);

int main()
{
    Set *setA = init();

    if(is_Empty(setA)) printf("\n\tSet A is empty.\n\n");
    else printf("Set A is not empty.\n\n");

    insert(setA, 5);
    insert(setA, 6);
    insert(setA, 7);
    insert(setA, 7);
    insert(setA, 8);
    print_set(setA);

    Set *setB = init();
    insert(setB, 7);
    insert(setB, 8);
    insert(setB, 9);
    insert(setB, 10);
    print_set(setB);

    Set *setC = set_union(setA, setB);
    printf("A union B: ");
    print_set(setC);

    Set *setD = set_intersection(setA, setB);
    printf("\nA intersection B: ");
    print_set(setD);
    return 0;
}

Set* init()
{
    Set *new_set = (Set*)malloc(sizeof(Set));
    new_set->length = 0;
    new_set->members = (int*)malloc(sizeof(int));


    return new_set;
}

bool is_Empty(Set *set)
{
    return (set->length==0);
}

void insert(Set *set, int member)
{
    bool in_set = false;
    //loop through

    for(int i=0; i<set->length; i++)
    {
        if(set->members[i] == member)
        {
            in_set=true; //element found
        }
    }

    if(!in_set) //insert element as element is not in set yet
    {
        set->members = (int*)realloc(set->members, sizeof(int) * set->length + 1); //increase size by 1
        set->members[set->length] = member;
        set->length++; // increase set length by 1
    }
}

void print_set(Set *set)
{
    for(int i=0; i<set->length; i++)
    {
        if(i==(set->length-1))
            printf("%d\n", set->members[i]);

        else
        {
            printf("%d, ", set->members[i]);
        }
    }

    printf("\n");
}

Set *set_union(Set *setA, Set *setB)
{
    Set *new = init();

    for(int i=0; i < setA->length; i++)
    {
        insert(new, setA->members[i]); 
    }

    for(int i=0; i<setB->length; i++)
    {
        insert(new, setB->members[i]);
    }

    return new;
}

Set *set_intersection(Set *setA, Set *setB)
{
    //if it's a member of a and b, insert it to new set

    Set *new = init();

    for(int i=0; i<setA->length; i++)
    {
        for(int j=0; j<setB->length; j++)
        {
            if(setA->members[i]==setB->members[j])
            {
                insert(new, setA->members[i]);
            }
        }
    }
    return new;
}

Set *set_difference (Set *setA, Set *setB)
{
    
}