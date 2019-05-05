/*ECE321    Count the occurences of letters in a string input by the user **Lacks error handling***	*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char string[100];
	int c = 0, d = 0, count[52] = { 0 }; /*52 total letters counting upper and lower*/

	printf("Enter a text message\n");
	gets(string); /*Getting string from user*/

	while (string[c] != '\0'&&string[d]!='\0') //string[c] and string[d] keep position and constantly check for EOL
	{
		if (string[c] >= 'a' && string[c] <= 'z')
			count[string[c] - 'a']++;/*Lower */

		c++; /*Only reading characters with value (Not Spaces or numbers)*/

		if (string[d] >= 'A' && string[d] <= 'Z')
			count[string[d] - 'A']++;
		/*Upper*/
		d++;
	}

	for (c = 0; c < 52; c++)
	{
		if (count[c] != 0)
			printf("%c occurs %d times in the entered string.\n", c + 'a', count[c]);/*Printing characters of value for lower*/
		if (count[d] != 0)
			printf("%c occurs %d times in the entered string.\n", d + 'A', count[d]);/*Printing characters of value for upper*/
		
	}
	return 0;
}