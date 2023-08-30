#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int ID;
    char LN[16], FN[24], MI;
    char course[8];
    int yearLevel;
}Studrec;

typedef struct node{
    Studrec stud;
    struct node *link;
}*StudList;

void Print(StudList P);
void InsertStudent(StudList *A, Studrec stud);
Studrec DeleteStudent(StudList *B, int searchID);
void errorMsg();

int main()
{
    StudList L=NULL;
    int menu=1, choice, id;

    do{
        printf("================================\n");
        printf("[1] Add new student\n"); //insert at beginning
        printf("[2] Remove student\n"); //remove at beginning, nth, end
        printf("[3] Display student list\n");
        printf("\n[0] EXIT\n-----\nChoice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 
            Studrec inputStud;
            printf("\n-- ADD A NEW STUDENT --\n");
            printf("\nEnter the following\n\t***\n\n");
            printf("ID: ");
            scanf("%d", &inputStud.ID);
            printf("First name: ");
            scanf("%s", inputStud.FN);
            printf("Middle initial: ");
            scanf(" %c", &inputStud.MI);
            printf("Last name: ");
            scanf("%s", inputStud.LN);
            printf("Year level: ");
            scanf("%d", &inputStud.yearLevel);
            printf("Course: ");
            scanf("%s", inputStud.course);
            InsertStudent(&L, inputStud);

            break;
            case 2:
            if(L==NULL)
            {
              printf("\n\nStudent list is empty!\n\n");  
            }
            else
            {
                printf("\n-- REMOVE A STUDENT --\n");
                printf("Enter student's ID: ");
                scanf("%d", &id);

                Studrec check = DeleteStudent(&L, id);

                printf("\n\n-----------\nID: %d", check.ID);
                printf("\nFirst name: %s\n", check.FN);
                printf("Middle Initial: %c\n", check.MI);
                printf("Last name: %s\n", check.LN);
                printf("Year level: %d\n", check.yearLevel);
                printf("Course: %s\n", check.course);  

                if(check.ID==0)
                {
                    printf("\n\tStudent does not exist.\n");
                }
                else
                {
                    printf("\n\tStudent %d removed.\n", check.ID);
                }
            }
            break;

            case 3:
            if(L==NULL)
                printf("\n\nStudent list is empty!\n\n");    
            else
                Print(L);
            break;

            case 0: menu = 0; break;

            default: errorMsg(); break;
        }
    }while(menu);
    
    StudList temp;
    while(L!=NULL)
    {
        temp=L;
        L=L->link;
        free(temp);
        temp=NULL;
    }
    printf("\n\tList cleared.\n\n");
    printf("\n********************************\n\tPROGRAM TERMINATED\n\n");

    return 0;
}

void errorMsg()
{
    printf("\n\n\tInvalid input. Try again.\n\n");
}

void InsertStudent(StudList *A, Studrec stud)
{
    StudList trav;
    for(trav=*A; trav!=NULL && trav->stud.ID!=stud.ID; trav=trav->link){}
    
    if(trav==NULL)
    {
        StudList newNode = (StudList)malloc(sizeof(struct node));
        if(newNode==NULL)
        {
            printf("Memory allocation failed");
            exit(1);
        }
        
        newNode->stud = stud;
        newNode->link = *A;
        *A = newNode;

        printf("\n\tStudent %d added.\n\n", stud.ID);
    }
    else
    {
        printf("\n\nStudent already exists!\n\n");
    }
}

Studrec DeleteStudent(StudList *B, int searchID)
{
    StudList trav, temp;
    Studrec stud = {0, "XXXXX", "XXXXX", 'X', "XXXXX", 0}; //setting up dummy
    if(*B!=NULL) //check if list is empty
    {   
        if((*B)->stud.ID==searchID) //if id 
        {
            temp = *B;
            *B = (*B)->link;
            stud = temp->stud; //copy contents of stud
            free(temp);
        }
        else
        {
            //looking ahead method
            for(trav=*B; trav->link!=NULL && trav->link->stud.ID!=searchID; trav = trav->link){}

            if(trav->link!=NULL)
            {
                temp = trav->link;
                trav->link = temp->link;
                stud = temp->stud;
                free(temp);
            }
        }
    }

    return stud;
}

void Print(StudList P)
{
    int i=1;
    StudList print;
    printf("\n\tSTUDENT LIST\n=============================\n");
    for(print=P; print!=NULL; print=print->link)
    {
        printf("\tStudent %d", i++);
        printf("\n\t**********\n");
        printf("Name: %s %c. %s\n", print->stud.FN, print->stud.MI, print->stud.LN);
        printf("ID: %d\n", print->stud.ID);
        printf("Year level: %d\n", print->stud.yearLevel);
        printf("Course: %s\n", print->stud.course);
        printf("----------------------------\n");
    }
    printf("\n");
}
