//ECE321	Check whether a letter input by a user is a vowel
#include <stdio.h>
char vowel_checker(c);/*Declaring a function that will be used to check the letter.*/
int main()
{
	char n;
	printf("Enter a letter to be checked: ");/*Getting a letter from the user to be sent to function.*/
	scanf("%c", &n);
	vowel_checker(n); /*Goes to function*/
	return 0;
}
char vowel_checker(c)
{
	int lower, upper;
	lower = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	upper = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
	if (lower || upper)
		printf("%c is a vowel.", c); /*Whether upper or lower is true(1), this will display that it is a vowel.*/
	else
		printf("%c is NOT a vowel.", c);/*If neither is true, it will say it is not a vowel.*/
}