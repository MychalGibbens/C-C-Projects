//ECE 321 Perfect Number Checking

#include <stdio.h>

int main()
{
	/*//For Loop Method
	int i, x, y = 0;
	printf("Please enter a value to be checked: ");
	scanf("%d", &x);
	for (i = 0; i < x; i++)
	{
		if (x % i == 0)
			y = y + i;
	}
	if (y == x)
	{
		printf("\n%d is a perfect number", x);
	}
	else
	{
		printf("\n%d is not a perfect number", x);
	}

	//While Loop Method
	int i, x, y = 0;
	printf("Please enter a value to be checked: ");
	scanf("%d", &x);
	while (i < x)
	{
		if (x%i == 0)
		{
			y = y + i;
			i++;
		}
	}
	if (y == x)
	{
		printf("\n%d is a perfect number", x);
	}
	else
	{
		printf("\n%d is not a perfect number", x);
	}
	

	//Do-While Method
	int i, x, y = 0;
	printf("Please enter a value to be checked: ");
	scanf("%d", &x);
	do
	{
		if (x%i == 0)
		{
			y = y + i;
			i++;
		}
	} while (i < x);
	if (y == x)
	{
		printf("\n%d is a perfect number", x);
	}
	else
	{
		printf("\n%d is not a perfect number", x);
	} */
	
    return 0;
}
/*In the For Loop method I assigned a variable for the user input, I made a variable to be used in the for loop,
and I made a varibale for the counter. After getting the users input, I set it in a for loop and used the modulus to test to see if it is perfect by dividing it by all numbers from 1 to itself. If the sum of the resultant values was the same as the original number,
then I know that the number is perfect.

I did the same for the While Loop method but with the use of a while loop, I had to 
relocate the i++ counter.

Similarly, the Do-While method was constructed the same way but the while condition was moved outside the body of the do statement.


The program refused to run due to the CRT Secure issue again but I had no other errors or warnings appear.*/