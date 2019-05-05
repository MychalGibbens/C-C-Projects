//ECE321    Binary tree from file	***Needs Work***
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definition of binary tree */

#define M 32
#define N 14

typedef struct nodeTag {
	char word[M];
	struct nodeTag * left, *right;
} node, *tree;

tree insert(tree * t, const char w[M]);/* Inserts a word in the tree */

int SearchWords(tree t, const char w[M])/* Looks up a word in the tree */
{
	int val;
	char s1[] = { (t)->word };
	char s2[] = { w };
	val = strcmp(s1, s2);
	if (val = 0)
		return 1;
	else if (val < 0)
		SearchWords((t->right), w);
	else if (val > 0)
		SearchWords((t->left), w);
	return 0;

}

void printSorted(tree t)/* Prints all words lexicon in lexicographic order */
{
	if (t == NULL) {
		printf("No words in list\n");
		exit(1);
	}
	if (t->left != NULL)
	{
		printSorted(t->left);
	}
	printf("%s\n", t->word);
	if (t->right != NULL)
	{
		printSorted(t->right);
	}

}

int main()/* Main program */
{
	tree t = NULL;
	FILE * fin;
	char w[M];

	if ((fin = fopen("fairy_tails.txt", "r")) == NULL) {/* Read the lexicon from the file */
		fprintf(stderr, "Cannot open file 'words'\n");
		return 1;
	}

	// ...
	while (!feof(fin)) /*While we have not reached the end of the file*/
	{
		if (fscanf(fin, "%s", &w) == 1)
		{
			tree insert(t, w);
			/*printf("%s\n", w);*/
		}
	}
	/* Read a word from the standard input and look up*/
	printf("\nGive a word: ");
	scanf("%s", w);
	SearchWords(t, w);



	printf("\nThe lexicon contains:\n");/* Print all words in lexicographic order */
	printSorted(t);
										//...

	fclose(fin);
	return 0;
}

tree insert(tree * t, const char w[M])
{
	int val;
	if (t == NULL)
	{
		*t = (node *)malloc(sizeof(node));
		(*t)->word = w;
		(*t)->left = (*t)->right = NULL;
	}
	else
	{
		char s1[] = { (*t)->word };
		char s2[] = { w };
		val = strcmp(s1, s2);

		if (val < 0)
			insert(&((*t)->right), w);
		else
			insert(&((*t)->left), w);
	}
	return t;
}