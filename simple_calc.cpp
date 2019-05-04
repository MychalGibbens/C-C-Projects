ECE222
#include<iostream>
using namespace std;
int main()
{
    int flag = 1;
	char again = 'Y';
	while (again == 'Y'|| again == 'y')
	{
		char x;
		float num1, num2;
		cout << "What operation would you like to perform? Add +, Subtract -, or Multiply * ?" << endl;
		cin >> x;
		cout << "Please enter the first operand: ";
		cin >> num1;
		cout << "Please enter the second operand: ";
		cin >> num2;
		switch (x)
		{
		case '+': cout << num1 << "+" << num2 << "=" << num1 + num2 << "\n";
			break;
		case '-': cout << num1 << "-" << num2 << "=" << num1 - num2 << "\n";
			break;
		case '*':cout << num1 << "*" << num2 << "=" << num1 * num2 << "\n";
			break;
		default:
			cout << "Invalid operation.\n";
		}
		cout << "Would you like to perform another calculation? Y or N?\n" << endl;
		cin >> again;
	}
	if (again == 'N' || 'n')
	{
		cout << "Thank you for playing!\n" << endl;
	}
}