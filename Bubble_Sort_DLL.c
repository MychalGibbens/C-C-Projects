//ECE321 Bubble Sorting a Dynamic Linked List entered by user
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

typedef struct list_tag {
	int data;
	struct list_tag * next;
	struct list_tag * prev;
} ListNode;

typedef struct {
	ListNode * first;
	ListNode * last;
} queue;

void queueInsert(queue * qp, int t);
void queuePrint(queue q);
void queuePrintSorted(queue q);
void queueInit(queue * qp);


void main(){

	queue my_queue;
	int data;

	queueInit(&my_queue);
	printf("Give me numbers. 0 = exit\n");
	scanf("%d", &data);

	while (data != 0){
		queueInsert(&my_queue, data);
		scanf("%d", &data);
	}
	queuePrint(my_queue);
	queuePrintSorted(my_queue);
	printf("Bye\n");
	system("pause");
}

void queueInit(queue * qp){
	qp->first = NULL;
	qp->last = NULL;
}

void queueInsert(queue * qp, int t){

	ListNode * n = (ListNode *)malloc(sizeof(ListNode));

	if (n == NULL) {
		printf("Out of memory\n");
		exit(1);
	}

	n->data = t;
	if (qp->first == NULL) { /*True on first run of function.*/
		n->prev = n->next = NULL; /* 'prev' and 'next' will now point to NULL*/
		qp->first = qp->last = n; /*'first' and 'last' will point to the first block*/
	}
	else
	{
		n->prev = qp->last;/*Else statement is performed on second and following runs, 'prev' now points to where 'last' points*/
		n->next = NULL; /*'next' points to NULL*/
		qp->last->next = n; /*'last-next' will point to n*/
		qp->last = n; /*'last' will point to 'n'*/
	}
}



void queuePrint(queue q){

	printf("Now I will print the queue unsorted\n");
	ListNode * n;
	for (n = q.first; n != NULL; n = n->next) {
		printf("%d\n", n->data);
	}
}

void queuePrintSorted(queue q){

	ListNode *i, *j;
	int z;
	int counter=0;
	printf("Now I will print the queue sorted\n");
	for (i = q.first; i != NULL; i = i->next){
		int flag = 1;
		for (j = q.last; j > i; j = j->prev)
		{
			if ((j->prev->data) > (j->data))
			{
				z = (j->prev->data);
				(j->prev->data) = (j->data);
				(j->data) = z;
				flag = 0;
			}
			counter++;
			
		}
		if (flag == 1)
			break;
		
		printf("%d\n", i->data);
	}
	printf("%d\n", counter);

	
	
	
}

