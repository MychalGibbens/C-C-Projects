//ECE 321 Factorial in C
#include <stdio.h>
int factorial(int a);

int main()
{

	int second = 1,q;
	printf("Please enter a integer : \n");
	scanf("%d", &q);
	second = factorial(q);
	printf("The factorial of %d is %d\n", q, second);
	return 0;
}
int factorial(int a)
{
	if (a >= 1)
	{
		return (a*factorial(a - 1));
	}
	else
	{
		return 1;
	}
}