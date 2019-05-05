//ECE321 DLL from file
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

/*I'm fairly sure this should act as a generic program for this zig-zag style. 
Though I didn't fully experiment with it, I think that my while loop with my counter and 'a' along with the dlistEmpty loop may be redundant
in verifying which print statement is used to print the data to the outfile*/


/* Doubly linked lists */

typedef struct DListNode_tag {
	char data;
	struct DListNode_tag * next;
	struct DListNode_tag * prev;
} DListNode;


/* Type dlist */

typedef struct {
	DListNode * first;
	DListNode * last;
} dlist;


/* Empty list */

const dlist dlistEmpty = { NULL, NULL };

/* Check if a list is empty */

int dlistIsEmpty(dlist l)
{
	return l.first == NULL;
}


/* Insert as last */

void dlistInsertLast(dlist * lp, int t)
{
	DListNode * n = (DListNode *)malloc(sizeof(DListNode));

	/* Check if malloc succeeded */

	if (n == NULL) {
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}

	/* Copy the data */

	n->data = t;

	/* If the list was empty, insert just this element */

	if (lp->first == NULL) {
		n->prev = n->next = NULL;
		lp->first = lp->last = n;
	}

	/* Else, insert as last element */

	else {
		n->prev = lp->last;
		n->next = NULL;
		lp->last->next = n;
		lp->last = n;
	}
}


/* Declare any other function that you might need */

char printStart(dlist * q);
char printEnd(dlist * q);
int count = 0;

/* Main program */

int main()
{
	FILE * fin, *fout;
	dlist l = dlistEmpty;
	int x, y, a, n;

	if ((fin = fopen("INFILE.txt", "r")) == NULL)
	{
		fprintf(stderr, "Cannot open INFILE\n");
		return 1;
	}
	if ((fout = fopen("OUTFILE.txt", "w")) == NULL)
	{
		fprintf(stderr, "Cannot open OUTFILE\n");
		return 1;
	}

	while (!feof(fin)) /*While we have not reached the end of the file*/
	{
		if (fscanf(fin, "%d", &n) == 1)
		{
			dlistInsertLast(&l, n);
			/*fprintf(fout, "%d\n", n);*/
			count++; /*Adding a counter so we know how many characters we have scanned from file */
		}
	}
	a = 0;
	while (a < count) /*Only for the number of characters we scanned from the INFILE*/
	{
		if ((&l) != NULL)
		{
			if (a % 2 == 0)
			{
				x = printStart(&l);
				fprintf(fout, "%d\n", x);
				printf("run: %d\n", (a + 1)); /*Displaying to user to see if all numbers have been accessed by print statements*/
			}
			else
			{

				y = printEnd(&l);
				fprintf(fout, "%d\n", y);
				printf("run: %d\n", (a + 1)); /*Displaying to user to see if all numbers have been accessed by print statements*/
			}
			a++; /*Change the value of a so the opposite print statement will be used on next run*/
		}
	}
	printf("New file has been updated with sorted values from input file\n");
	fclose(fin);
	fclose(fout);
	system("pause");
}


char printStart(dlist * q)
{
	int a;
	a = q->first->data;

	if (q->first == q->last)
	{
		free(q->first);
		q->first = q->last = NULL; /*The last node has been deleted and now the while statement in main function will not be satisfied*/
	}
	else
	{
		q->first = q->first->next;
		free(q->first->prev);
		q->first->prev = NULL; /*Eliminating old node and making appropriate changes to pointers*/
	}
	return a;
}
char printEnd(dlist * q)
{
	int b;
	b = q->last->data;

	if (q->first == q->last)
	{
		free(q->first);
		q->first = q->last = NULL; /*The last node has been deleted and now the while statement in main function will not be satisfied*/
	}
	else
	{
		q->last = q->last->prev;
		free(q->last->next);
		q->last->next = NULL; /*Eliminating old node and making appropriate changes to pointers*/
	}
	return b;

}