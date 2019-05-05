//ECE321 Max of Mins and Min of Maxs    ***Needs Work***
#define _CRT_SECURE_NO_WARNINGS
#define N 5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, j, k, A[N], B[N], max_of_mins, min_of_maxs;
	int a[N][N] = { 0 }; /*Initializing the 'empty' 2D array to store random values.*/
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			a[i][j] = rand()%100; /*Storing random values to the 2D array*/
		}
	}

	for (i = 0; i < N; i++)
	{
		printf("\n");
		for (j = 0; j < N; j++)
		{
			printf("%d ", a[i][j]); /*Printing the array*/
		}
	}
	
	for (i = 0; i < N+1; i++)
	{
		B[i] = a[i][0];  /*Stores first column to B*/
		//printf("\n%d", B[i]); //Test 1    Success
	}
	/*Confused on this section, I think I need another loop to do this for each row and each column of the 2D array but im not sure what other loops to put inside it.*/
	for (j = 0; j < N; j++)
	{
		A[j] = a[0][j]; /*Stores first row to A*/
		printf("\n%d", A[i]); //Test 2  Fail
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (a[i][j] >= A[i]) /*Comparing element of 2d array to element of row*/
			{
				A[i] = a[i][j]; /*If array value is greater, replace the row element*/
			}
		}
	}


	for (j = 0; j < N; i++)
	{
		for (i = 0; i < N; j++)
		{
			if (a[i][j] >= B[j]) /*Comparing element of 2d array to element of column*/
			{
				B[j] = a[i][j]; /*If array value is greater, replace the column element*/
			}
		}
	} 

	max_of_mins = A[0]; /*Picking a spot for the greatest and lowest to be moved.*/
	min_of_maxs = B[0];

	for (i = 0; i < N; i++)
	{
		if (A[i]>max_of_mins)
		{
			max_of_mins = A[i]; /*Greatest value of rows should now be at A[0] position*/
		}
		if (B[i]>min_of_maxs)
		{
			min_of_maxs = B[i]; /*Lowest value of columns should now be at B[0] position*/
		}
	}
	printf("Highest value of the smallest numbers is %d \n", A[i]); /*Printing the values*/
	printf("Lowest value of the highest numbers is %d \n ", B[i]);
}