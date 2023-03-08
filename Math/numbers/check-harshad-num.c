#include <stdio.h>
int sum_of_digits(int, int);

int main()
{
	int num;
	printf("===============================================\n");
	printf("\t\tCHECK IF HARSHAD NUMBER\n\n");
	printf("Enter a number: ");
	scanf("%d", &num);
	
	int r = sum_of_digits(num, 0);
	
	int check_num = num % r == 0 ? 1 : 0;
	printf("\n-----\n");
	check_num == 1 ? printf("Harshad number") : printf("Not a Hardshad number");
	
	return 0;
}

int sum_of_digits(int temp, int sum)
{
	int dig;
	if(temp==0)
	{
		return sum;
	}
	else
	{
		dig=temp%10;
		sum+=dig;
		
		return sum_of_digits(temp=temp/10, sum);
	}	
}
