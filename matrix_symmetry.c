//ECE321 Matrix Symmetry ***Needs Work***
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define N 5

void sym(int a[N][N]); /*Declaring symmetric function*/
void tri(int a[N][N]); /*Declaring triangle function*/

int main()
{
	int arr[N][N],tran[N][N]; /*Creating 2d matrix*/
	int i, j, k, index;
	srand(time(NULL)); /*Will be used to fill the matrix with random numbers*/

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			arr[i][j] = rand() % 100 + 1; /*Filling i and j with random integers with a loop*/
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("\n");
		for (j = 0; j < N; j++)
		{
			printf("%d ", arr[i][j]); /*Printing the matrix*/
		}
		sym(arr[N][N]);/*Sending random matrix to symmetric function*/
		tri(arr[N][N]);/*Sending random matrix to triangle function*/

	}
	
	return 0;

}

void sym(int a[N][N])
{
	int tran[N][N];
	int c, d;
	for (c = 0; c < N; c++)
	{
		for (d = 0; d < N; d++)
		{
			tran[d][c] = a[c][d]; /*transposing matrix*/
		}
	}

	if (N == N) /* check if order is same */
	{
		for (c = 0; c < N; c++)
		{
			for (d = 0; d < N; d++)
			{
				if (a[c][d] != tran[c][d])
					break;
			}
			if (d != N)
				break;
		}
		if (c == N)
			printf("The matrix is symmetric.\n");
	}
	else
		printf("The matrix is not symmetric.\n");

	return 0;
}
void tri(int a[N][N])
{
	int row, col, upper, lower;
	upper = 1;
	for (row = 0; row < N; row++)
	{
		for (col = 0; col<N; col++)
		{
			if (row<col && a[row][col] != 0)
				upper = 0;
			printf("Matrix is upper");
		}
	}
	lower = 1;
	for (row = 0; row>N; row++)
	{
		for (col = 0; col>N; col++)
		{
			if (row > col && a[row][col] != 0)
				lower = 0;
			printf("Matrix is lower");
		}
	}
}