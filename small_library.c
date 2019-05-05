//ECE321 Small Library  ***Needs Work***
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

typedef struct list_tag /*Creating the basis of my structure that will hold the users input inforamtion*/
{
	char title[30];
	char author[20];
	int year;
	float price;
	struct list_tag * next;
	struct list_tag * prev;
}ListNode;

typedef struct /*Preparing a queue to keep track of multiple sets of user input*/
{
	ListNode * first;
	ListNode * last;
}queue;

void insert(queue * lp, char t[30], char a[20], int y, float p);/*Function for the user to input data*/
void display();/*Function to display current list to console*/
char queueHead(queue * q);/*Function that will display current head of the list and asks user if they would like to delete this one or move on to the next*/
int deletionchoice(); /*Function for the user to decide which book to delete*/
int printchoice(); /*Function for user to choose which printing method*/
void print_queue(queue * q); /*Function for printing current library*/
int menu();/*Function for asking user how they would like to traverse the program*/
void remoove(queue * q);/*Function to delte a book*/

int main()
{
	queue * myqueue;
	char fake[30], new[20];
	int i = 0,y;
	float p;
	int ch;
	do
	{
		ch = menu();
		switch (ch)
		{
		case 1: /*Inseartion of a new book*/
			insert(myqueue, fake[30], new[20], y, p);
			break;
		case 2:/*Display current list of books*/
			display();
			break;
		case 3:/*Remove book from library*/
			queueHead(myqueue);
		case 4:/*Print current list of books*/
			print_queue(myqueue);
		case 5:/*Exit program*/
			exit(0);
		default:
			printf("Invalid selection.");
		}
	} while (1);
}

void insert(queue * qp, char t[30], char a[20], int y, float p)
{
	ListNode * n = (ListNode*)malloc(sizeof(ListNode));
	int i;

	if (n = NULL)
	{
		printf("Out of memory \n");
		exit(1);
	}
	printf("Enter the Book Title: \n");
	fgets(t, 30, stdin);
	t[strlen(t) - 1] = '\0';
	printf("Enter the author's name: \n");
	a[strlen(a) - 1] = '\0';
	fgets(a, 20, stdin);
	printf("Enter year: \n");
	scanf("%d", n->year);
	printf("Enter the price of book: \n");
	scanf("%f", n->price);

	if (qp->last == NULL)
	{
		qp->first = qp->last = n; /*Should be true on first run*/
	}
	else
	{
		qp->last->next = n; /*Following runs will execute this piece of code*/
		qp->last = n;
	}

	FILE*file = fopen("Book", "a");
	if (file != NULL)
	{
		fwrite(n, sizeof(ListNode), 1, file); /*Storing book to different file*/
		fclose(file);
	}
	else
	{
		printf("Could not read file.\n");
	}
}

void remoove(queue * q)
{
	ListNode * n;
	
	if (q->first == NULL)
	{
		printf("Empty library \n");
		exit(1);
	}
	n = q->first;
	q->first = q->first->next; /*Moving pointer from current book to next book and deleting the current book*/
	free(n);
	if (q->first == NULL)
	{
		q->last == NULL;
	}
}

void display()
{
	ListNode * n = (ListNode*)malloc(sizeof(ListNode));
	FILE*file = fopen("Book", "rb");
	if (file != NULL)
	{
		while (!feof(file))
		{
			fread(n, sizeof(ListNode), 1, file);
			printf("%s\t\t%s\t\t%d\t%f\n", n->title, n->author, n->year, n->price);
		}
		fclose(file);
	}
	else
	{
		printf("Could not read file.\n");
		return;
	}
}

int menu()
{
	int ch;
	printf("Please enter\n1 for Insert\n2 for Print\n3 for Removal\n4 for Printng Option\n5 to Exit\n");
	scanf("%d", &ch); /*Asking user how they would like to proceed*/
	return ch;
}

char queueHead(queue * q)
{
	ListNode * temp;
	int ch;
	char a[30];
	if (q->first == NULL)
	{
		printf("Empty Library \n");
		exit(1);
	}
	a[30] = q->first->title; /*Asking user if they would like to delete current head of library list*/
	printf("Would you like to delete %s?\n", a);
	deletionchoice(); /*User makes their choice*/
	switch (ch)
	{
	case 1:
		remoove(q); /*If yes, they delete the book*/
		break;
	case 2:
		q->first = q->first->next;
		queueHead(q); /*If no, they are asked again if they would like to delete the next book*/
		break;
	default:
		printf("Invalid selection.");
	}while (1);
}

int deletionchoice()
{
	int ch;
	printf("Please enter\n1 for Deletion\n2 for next book\n");
	scanf("%d", &ch);
	return ch;
}
int printchoice()
{
	int ch;
	printf("Please enter\n1 to print list as it was entered\n2 list sorted by publication year\n");
	scanf("%d", &ch); /*Asking user how they would like to print the library*/
	return ch;
}

void print_queue(queue * q)
{
	ListNode * n, * eye, * jay;
	int ch, x, i, z = 0;
	float y;
	char a[30];
	char b[20];
	if (q->first == NULL)
	{
		printf("Empty Library \n");
		exit(1);
	}
	printf("How would you like to print the list of books?\n", a);
	printchoice();
	switch (ch)
	{
	case 1: /*printing as it was entered into the library*/
		for (n = q->first; n != NULL; n = n->next) 
		{
			a[30] = n->title;
			b[20] = n->author;
			x = n->year;
			y = n->price;
			while (a[i] != '\0')
			{
				printf("%c", a[i++]);
			}
			printf("\n");
			while (b[i] != '\0')
			{
				printf("%c", b[i++]);
			}
			printf("\n");
			printf("%d\n", x);
			printf("%f\n", y);
		}
		break;
	case 2: /*sorting from oldest to newest*/
		printf("Now I will print the queue sorted\n");
		for (eye = q->first; eye != NULL; eye = eye->next) {
			int flag = 1;
			for (jay = q->last; jay > eye; jay = jay->prev)
			{
				if ((jay->prev->year) > (jay->year))
				{
					z = (jay->prev->year);
					(jay->prev->year) = (jay->year);
					(jay->year) = z;
					flag = 0;
				}
			}
			if (flag == 1)
				break;
			a[30] = jay->title;
			b[20] = jay->author;
			x = jay->year;
			y = jay->price;
			while (a[i] != '\0')
			{
				printf("%c", a[i++]);
			}
			printf("\n");
			while (b[i] != '\0')
			{
				printf("%c", b[i++]);
			}
			printf("\n");
			printf("%d\n", x);
			printf("%f\n", y);
		}
		break;
	default:
		printf("Invalid selection.");
	}while (1);
}