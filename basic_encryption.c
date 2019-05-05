//ECE321 Basic Encryption
/*
Usage for encoding:
./hw_2_part_1 qwer

Usage for decoding:

./hw_2_part_1 -d qwer


You can pass the key and the id arguments to the command line:
https://stackoverflow.com/questions/3697299/passing-command-line-arguments-in-visual-studio-2010
*/

#include <stdio.h>
#include <ctype.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char encr[30];
char decr[30];


/* Function to encode using p as key */

void encode(char p[])
{
	int n = strlen(p);
	int c, sum, count=0;
		
	/* Here you get input from the user */
	printf("Enter the message to be encrypted: \n");

	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			int codec = tolower(c) - 'a' + 1;/*So if 'c' was 'a' it would subtract 97-97=0 but we want the numbers to start at 1 so we add 1. Then we follow this logic for following letters.*/
			int codep = tolower(p[count]) - 'a' + 1;/*Same logic for the key*/
			sum = ((int)(codec)+(int)(codep)); /*Encrypted message + Key*/
			if (sum > 26)
			{
				sum = sum - 26;
			}
			if (sum < 26)
			{
				sum = sum + 26;
			}
			
		}
		putchar(encr);
		count++;
	}
}


/* Function to decode using p as key: the reverse of the previous */

void decode(char p[])/*Encoded string will be used with key to make original message*/
{
	int n = strlen(p);
	int c, sum, count = 0;

	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			int codec = tolower(c) - 'a' + 1;/*So if 'c' was 'a' it would subtract 97-97=0 but we want the numbers to start at 1 so we add 1. Then we follow this logic for following letters.*/
			int codep = tolower(p[count]) - 'a' + 1;/*Same logic for the key*/
			sum = ((int)(codec)-(int)(codep)); /*Encrypted message - Key*/
			if (sum > 26)
			{
				sum = sum - 26;
			}
			if (sum < 26)
			{
				sum = sum + 26;
			}

		}
		putchar(decr);
		count++;
	}
}


/* Main program */

int main(int argc, char * argv[])
{
	/* Check if a key has been given */

	if (argc < 2) {
		printf("You forgot the key...\n");
		return 1;
	}

	/* Choose between encoding and decoding */

	if (argc > 2 && strcmp(argv[1], "-d") == 0)
		decode(argv[2]);
	else
		encode(argv[1]);

	return 0;
}
