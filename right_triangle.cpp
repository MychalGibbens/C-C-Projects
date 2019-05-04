ECE222
#include<iostream>
using namespace std;
int main()
{
	for (int i = 0; i <= 6; i++)
	{
		for (int t = 0; t <= i; t++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}