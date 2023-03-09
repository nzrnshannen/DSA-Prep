#include <stdio.h>

int check_if_abundant(int, int, int);
void all_abundant(int, int);

int flag=0;
int main()
{
	int input, limit;
	printf("========================================\n");
	printf("\tABUNDANT NUMBER CHECK\n\n");
	printf("Enter a number: ");
	scanf("%d", &input);
	
	int r=check_if_abundant(0, 1, input);
	int output=r>input?printf("\n\n---\n%d is an abundant number.", input) : printf("\n\n---\n%d is not an abundant number.", input);
	
	printf("\n\n========\nInput a limit: ");
	scanf("%d", &limit);
	printf("\n\n=-=-=-=-=-=-=-=-=-=\nPRINTING ALL ABUNDANT NUMBERS FROM 1 TO %d:\n\n", limit);
	all_abundant(1, limit);
	return 0;
	
}

void all_abundant(int start, int end)
{
	if(start>end)
	{
		if(flag==0)
		{
			
			printf("\nUnfortunately, there are no abundant numbers in the given range.\n");
		}
		return;
	}
	else
	{
		int r=check_if_abundant(0, 1, start);
		
		if(r>start)
		{
			flag=1;
			printf("%d ", start);
		}
		
		return all_abundant(start+1, end);
	}
}

int check_if_abundant(int sum, int i, int num)
{
	if(i==num)
	{
		return sum;
	}
	else
	{
		if(num%i==0)
		{
			sum+=i;
		}
		
		return check_if_abundant(sum, i+1, num);
	}
}