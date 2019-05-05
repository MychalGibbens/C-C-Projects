//ECE321 Finding smallest in the row but highest in the column ***Needs Work***
#include <stdio.h>
#include <time.h>
#include <limits.h>
#define N 5
int main()
{
	int arr[N][N]; /*Creating 2d matrix*/
	int i, j, k, index;
	srand(time(NULL)); /*Will be used to fill the matrix with random numbers*/

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 2 + 1; /*Filling i and j with random integers with a loop*/
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("\n");
		for (j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]); /*Printing the matrix*/
		}
	}
	int min = INT_MAX, max = INT_MIN;

	for (i = 0; i < N; i++)
	{
		min = INT_MAX, max = INT_MIN;
		for (j = 0; j < N; j++)
		{
			if (arr[i][j] < min){
				min = arr[i][j]; /*Searching for minimum value in each row*/
				index = j;
			}

		}
		for (k = 0; k < N; k++)
		{
			if (arr[k][index] > max) /*Searching for maximum value in each column*/
				max = arr[k][index];

		}
		if (min == max){
			printf("\n %d that is smallest in its row and highest in its column", min);
		}
	}
	return 0;

}