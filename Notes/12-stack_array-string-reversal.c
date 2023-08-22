//string reversal using stack

#include<stdio.h>
#include<string.h>

int top=-1;

int getTop(char S[])
{
    return S[top];
}
void Reverse(char C[], int n)
{
    char stack[n];

    //push
    for(int i=0; i<n; i++)
    {
        stack[i]=C[i];
        top++;
    }

    //pop
    for(int i=0; i<n; i++)
    {
        C[i] = getTop(stack);
        top--;
    }
}

void test(char C[], int n)
{
    int i, j;
    j=n-1;
    for(i=0; i<j; i++)
    {
        char swap;
        swap=C[j];
        C[j]=C[i];
        C[i]=swap;
        j--;
    }

}

int main()
{
    char C[51];
    printf("Enter a string: ");
    gets(C);
    Reverse(C, strlen(C));
    printf("\n=====\nUsing Reverse() function = %s", C);
    test(C, strlen(C));
    // use this to test out a different one (but not intended for stack approach just to show that they have the same result)
                //printf("Using test() function = %s", C); 
}

