//ECE321    More Encryption ***Needs Work***
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char * encrypt(char *input, char key[], int kSize);
char * decrypt(char *output, char key[], int kSize);

int main()
{
	char in[] = "Hello World"; /*Given message*/
	char *input = in;/*Pointer to the message string*/
	printf("Original message: %s\n", in);
	int kSize = 4; /*Size of our key*/
	char key[] = "qwer"; /*Data of our key*/
	char* output; /*Preparing a pointer for the encrypted message*/
	output = encrypt(input, key, kSize); /*'output' will store the encrypted string*/
	printf("Encrypted Message: %s\n", output); /*Printing encrypted message*/
	char*destr = decrypt(output, key, kSize); /*Sending encrypted message to be decrypted*/
	printf("Decrypted Message: %s\n", destr); /*Printing decrypted message*/
	return 0;
}


char * encrypt(char *input, char key[], int kSize) /*'input' is pointer to char, 'key' is array of chars, 'kSize' is integer*/
{
	int count = 0;

	char * output = malloc(strlen(input) + 1);/*Allocating memory for the passed string*/
	char * p;
	if (output == NULL)
		return NULL;
	p = output;
	int index = 0;

	while (*input != '\0')
	{
		char ch = *input;
		if (isalpha(ch))
		{
			ch = tolower(ch);
			if (count >= kSize)
			{
				count = 0;
			}
			int code = ((int)(ch - 'a') + 1) + (int)(key[count] - 'a');
			if (code > 26)
			{
				code = code - 26;
			}
			if (code < 0)
			{ 
				code = code + 26;
			}
			char outch = (int)('a') + (code);
			*p = outch;
			count++;
		}
		else{
			*p = ch;

		}
		input++;
		p++;
	}
	*p = '\0';
	return output;
};

char * decrypt(char *output, char key[], int kSize)
{
	int count = 0;
	char* input = malloc(strlen(output) + 1);
	char*p;
	if (input == NULL)
		return NULL;
	p = input;
	int index = 0;
	while (*output != '\0'){
		char ch = *output;
		if (isalpha(ch)){
			ch = tolower(ch);
			if (count >= kSize)
				count = 0;
			int code = ((int)(ch - 'a') + 1) + (int)(key[count] - 'a');
			if (code > 26)
			{
				code = code - 26;
			}
			if (code < 0)
			{
				code = code + 26;
			}
			char outch = (int)('a') + (code);
			*p = outch;
			count++;
		}
		else{
			*p = ch;
		}
		output++;
		p++;
	}
	*p = '\0';
	return input;
};