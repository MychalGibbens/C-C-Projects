//ECE222
#include<iostream>
using namespace std;

int main()
{
	char newArea = 'Y';
	while (newArea == 'Y' || newArea == 'y')
	{
		int number;
		cout << "Enter '1' for the area of a triangle:" << endl;
		cout << "Enter '2' for the area of a rectangle:" << endl;
		cin >> number;
		if (number == 1)
		{
			float triArea, base, height;
			{

				cout << "Enter the base of the triangle: " << endl;
				cin >> base;
				cout << "Enter the height of the triangle: " << endl;
				cin >> height;
				triArea = base * height * .5;
				cout << "The area of the triangle is: " << triArea << endl;
				cout << "Would you like to find another area? Enter Y/y for yes or N/n for no." << endl;
				cin >> newArea;
			}


		}
		else
		{
			if (number == 2)
			{
				float recArea, length, width;
				{
					cout << "Enter the width of the rectangle: " << endl;
					cin >> width;
					cout << "Enter the length of the reactangle: " << endl;
					cin >> length;
					recArea = width * length;
					cout << "The area of the rectangle is: " << recArea << endl;
					cout << "Would you like to find another area? Enter Y/y for yes or N/n for no." << endl;
					cin >> newArea;
				}
			}
			else
			{
				cout << "The number you have entered is invalid." << endl;
				return 0;
			}

		}
	}
	
}