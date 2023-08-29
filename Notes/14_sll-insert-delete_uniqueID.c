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
void InsertStudent(StudList *A, int id, char LN[], char FN[], char MI, char course[], int yearLevel);
StudList DeleteStudent(StudList *B, int searchID);
void errorMsg();

int main()
{
    StudList L=NULL;
    int menu=1, choice, id, yearLevel;
    char course[8], LN[16], FN[24], MI; 
    

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
            printf("\n-- ADD A NEW STUDENT --\n");
            printf("\nEnter the following\n\t***\n\n");
            printf("ID: ");
            scanf("%d", &id);
            printf("First name: ");
            scanf("%s", FN);
            printf("Middle initial: ");
            scanf(" %c", &MI);
            printf("Last name: ");
            scanf("%s", LN);
            printf("Year level: ");
            scanf("%d", &yearLevel);
            printf("Course: ");
            scanf("%s", course);
            InsertStudent(&L, id, LN, FN, MI, course, yearLevel);
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

                StudList check = DeleteStudent(&L, id);

                printf("\n\n-----------\nID: %d", check->stud.ID);
                printf("\nFirst name: %s\n", check->stud.FN);
                printf("Middle Initial: %c\n", check->stud.MI);
                printf("Last name: %s\n", check->stud.LN);
                printf("Year level: %d\n", check->stud.yearLevel);
                printf("Course: %s\n", check->stud.course);  

                if(check->stud.ID==0)
                {
                    printf("\n\tStudent does not exist.\n");
                }
                else
                {
                    printf("\n\tStudent %d removed.\n", check->stud.ID);
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

void InsertStudent(StudList *A, int id, char LN[], char FN[], char MI, char course[], int yearLevel)
{
    int flag = 0;
    StudList trav;
    for(trav=*A; trav!=NULL && flag!=1; trav=trav->link)
    {
        if(trav->stud.ID == id)
            flag=1;
    }

    if(flag!=1)
    {
        StudList newNode = (StudList)malloc(sizeof(struct node));
        newNode->stud.ID = id;
        newNode->stud.MI = MI;
        newNode->stud.yearLevel = yearLevel;
        strcpy(newNode->stud.FN, FN);
        strcpy(newNode->stud.LN, LN);
        strcpy(newNode->stud.course, course);

        if(*A==NULL)
        {
            *A = newNode;
        }
        else
        {
            newNode->link = *A;
            *A = newNode;
        }

        printf("\n\n\tStudent %d added.\n\n", id);
    }
    else
    {
        printf("\n\n\tStudent already exists!\n\n");
    }
}

StudList DeleteStudent(StudList *B, int searchID)
{
    int flag=0, pos=1;
    StudList dummy, trav;

    for(trav=*B; trav!=NULL && flag!=1; trav=trav->link)
    {
        if(trav->stud.ID==searchID)
            flag = 1;
        else
            pos++;
    }

    StudList temp = (StudList)malloc(sizeof(struct node));
    temp->link=NULL;

    if(flag==1)
    {
        if(pos==1)
        {
            dummy = *B;
            *B = (*B)->link;
        }
        else
        {
            trav=*B;
            int i;
            for(i=1; i<pos-1; i++)
            {
                trav=trav->link;
            }

            dummy = trav->link;
            StudList nextNode = dummy->link;
            trav->link = nextNode;
        }
    }
    else
    {
        //allocating memory
        dummy = (StudList)malloc(sizeof(struct node));
        dummy->link = NULL;

        dummy->stud.ID = dummy->stud.yearLevel = 0;
        dummy->stud.MI = '\0';
        strcpy(dummy->stud.FN, "XXXXX");
        strcpy(dummy->stud.LN, "XXXXX");
        strcpy(dummy->stud.course, "XXXXX");
    }

    temp->stud.MI = dummy->stud.MI;
    temp->stud.ID = dummy->stud.ID;
    temp->stud.yearLevel = dummy->stud.yearLevel;
    strcpy(temp->stud.FN, dummy->stud.FN);
    strcpy(temp->stud.LN, dummy->stud.LN);
    strcpy(temp->stud.course, dummy->stud.course);
    free(dummy);
    return temp;
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
