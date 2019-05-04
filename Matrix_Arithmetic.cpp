//ECE222
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
	//row and col must be const int so that we can change them later
	const int row = 10;
	const int col = 10;
	//FIRST ARRAY
	float matrix1[row][col];
	int size1;
	// allowing the user to select the size of the 2D array
	cout << "Enter the n value for the desired n x n matrix: " << endl;
	cin >> size1;
	int col1 = size1;
	int row1 = size1;
	// takes the size of the first array and allows the user to input the values for specific row and column locations.
	for (row1 = 0; row1 < size1; row1++)
	{
		for (col1 = 0; col1 < size1; col1++)
		{
			cout << "Enter a value for Row: " << row1 << " Column: " << col1 << endl;
			cin >> matrix1[row1][col1];
		}
	}
	// saves the array into a file to be used later
	ofstream outFile1("Matrix 1.txt");
	if (!outFile1.is_open())
	{
		cout << "File failed to open! " << endl;

	}
	for (row1 = 0; row1 < size1; row1++)
	{
		for (col1 = 0; col1 < size1; col1++)
		{
			outFile1 << setw(5) << matrix1[row1][col1];
		}
		outFile1 << endl;
	}


	cout << endl;

	//SECOND ARRAY

	float matrix2[row][col];

	// user sets the size of the second 2D array
	cout << "\nEnter the data for the second array:" << endl;

	// user can enter values for the second array at specific row and column locations
	for (row1 = 0; row1 < size1; row1++)
	{
		for (col1 = 0; col1 < size1; col1++)
		{
			cout << "Enter a value for Row: " << row1 << " Column: " << col1 << endl;
			cin >> matrix2[row1][col1];
		}
	}
	//saves the second array into a file to be used later.
	ofstream outFile2("Matrix 2.txt");
	if (!outFile2.is_open())
	{
		cout << "File failed to open! " << endl;

	}
	for (row1 = 0; row1 < size1; row1++)
	{
		for (col1 = 0; col1 < size1; col1++)
		{
			outFile2 << setw(5) << matrix2[row1][col1];
		}
		outFile2 << endl;
	}


	float matrixA[row][col];
	// Read in the first array and set it to class for calculation
	ifstream inFile1;

	inFile1.open("Matrix 1.txt");
	if (!inFile1.is_open())
	{
		cerr << "Error opening file." << endl;
		return 0;
	}
	while (inFile1.good())
	{
		for (row1 = 0; row1 < size1; row1++)
		{
			for (col1 = 0; col1 < size1; col1++)
			{
				inFile1 >> setw(5) >> matrix1[row1][col1];
				matrixA[row1][col1] = matrix1[row1][col1];
			}

		}

	}


	float matrixB[row][col];
	// Read in the second array and set it to class for calculation
	ifstream inFile2;

	inFile2.open("Matrix 2.txt");
	if (!inFile2.is_open())
	{
		cerr << "Error opening file." << endl;
		return 0;
	}
	while (inFile2.good())
	{
		for (row1 = 0; row1 < size1; row1++)
		{
			for (col1 = 0; col1 < size1; col1++)
			{
				inFile2 >> setw(5) >> matrix2[row1][col1];
				matrixB[row1][col1] = matrix2[row1][col1];
			}

		}

	}
	//new array 
	float matrixC[row][col];

	cout << endl;
	// allow the user to select what math function to perform on the arrays
	char again = 'y';
	do {
		int num;
		cout << "Please enter the digit corresponding to the mathmatical function you wish to perform on the two matricies: " << endl;
		cout << "1. Multiplication \n2. Addition \n3. Subtraction " << endl;
		cin >> num;
		switch (num)
		{
		case 1:
            cout << "The product of the two matricies is: " << endl;
			for (row1 = 0; row1<size1; row1++)
			{
				for (col1 = 0; col1 < size1; col1++)
				{//Sets the new array equal to zero 
					matrixC[row1][col1] = 0;
					for (int k = 0; k < size1; k++)
					{// Multiplies the two arrays then adds them to the new array
						matrixC[row1][col1] += matrixA[row1][k] * matrixB[k][col1];
					}
				}
			}

			//Output of the new array.
			for (row1 = 0; row1 < size1; row1++)
			{
				for (col1 = 0; col1 < size1; col1++)
				{
					cout << setw(5) << matrixC[row1][col1];


				}cout << endl;
			}
			break;

		case 2:
			cout << "The sum of the two matricies is: " << endl;
			//Addition of the two arrays and saved to a new array
			for (row1 = 0; row1 < size1; row1++)
			{
				for (col1 = 0; col1 < size1; col1++)
				{
					matrixC[row1][col1] = matrixA[row1][col1] + matrixB[row1][col1];
				}
			}
			// Output new array that was formed 
			for (row1 = 0; row1 < size1; row1++)
			{
				for (col1 = 0; col1 < size1; col1++)
				{
					cout << setw(5) << matrixC[row1][col1];
				}cout << endl;
			}
			break;

		case 3:
			cout << "The result of the two matricies subtracted is: " << endl;
			//This is subtracting the two arrays and setting them to a new array
			for (row1 = 0; row1 < size1; row1++)
			{
				for (col1 = 0; col1 < size1; col1++)
				{
					matrixC[row1][col1] = matrixA[row1][col1] - matrixB[row1][col1];
				}
			}
			//Output of the new array 
			for (row1 = 0; row1 < size1; row1++)
			{
				for (col1 = 0; col1 < size1; col1++)
				{
					cout << setw(5) << matrixC[row1][col1];
				}cout << endl;
			}
			break;

		default:
			cout << "Error! Invalid number." << endl;

			break;
		}
		cout << "\nWould you like to perform another math function? \nEnter y for yes. \nEnter n for no." << endl;
		cin >> again;

	} while (again == 'y' || again == 'Y');//Loop to repeat a new math operation.
	cout << "\nGoodbye!" << endl;
	inFile1.close();
	inFile2.close();

	return 0;
}