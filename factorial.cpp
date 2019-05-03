//ECE222
#include<iostream>
using namespace std;

int main()
{
	int num, factorial = 1;
	cout << " Please enter a positive integer:  ";
	cin >> num;
	
	while (num)
	{
		if (num > 0)
		{
			for (int a = 1; a <= num; a++)
			{
				factorial = factorial*a;
			}

			cout << "The factorial of this number is: " << factorial << endl;
			return 0;
		}
		else
		{
			cout << "This is an invalid input, please enter a POSITIVE integer: ";
			cin >> num;
		}
	}
	return 0;
}

