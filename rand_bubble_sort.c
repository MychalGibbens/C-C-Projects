//ECE321    Bubble Sort on array of random ints
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 

void bubble_sort(int a[], int n);
int main()
{
	int flag;
	int r, n, z[20], b[20];
	for (r = 0; r < 20; r++)
	{
		b[r] = rand()%100 + 1;

	}
	printf("The original array is: \n");
	for (r = 0; r < 20; r++)
	{
		z[r] = b[r];

	}
	bubble_sort(b, 20);
	for (r = 0; r < 20; r++)
	{
		printf("%d\n", z[r]);

	}
	printf("The sorted array is: \n");
	for (r = 0; r < 20; r++)
	{
		printf("%d\n", b[r]);
	}
}
void bubble_sort(int a[], int n)
{
	int x, y, flag;
	flag = 0;
	for (x = 0; x < n; x++)
	{
		for (y = n - 1; y > x; y--)
		{
			if (a[y - 1] > a[y])
			{
				int temp = a[y - 1];
				a[y - 1] = a[y];
				a[y] = temp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}