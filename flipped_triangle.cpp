#include <iostream>
using namespace std;

int main() {
	int m, y;
	for (int y = 5; y >= 1; y--)
	{
		for (m = 0; m < 5 - y; m++)
		{
			cout << " ";
		}
		for (m = 0; m < ((2*y)-1); m++)
		{
			if (m % 2 == 0);
				cout <<"*";
		}
		cout << endl;
	}
	return 0;
}
