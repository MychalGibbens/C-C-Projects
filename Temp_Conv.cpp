ECE222
#include<iostream>
using namespace std;
float celtoFah(float);
float celtoKel(float);
float fahtoCel(float);
float cel, fah, kel, Fahrenheit, Celsius, Kelvin;
int main()
{
	int number;
	cout << "Please enter 1 to change from Celsius to Fahrenheit" << endl;
	cout << "Please enter 2 to change from Celsius to Kelvin" << endl;
	cout << "Please enter 3 to change from Fahrenheit to Celsius" << endl;
	cin >> number;

	while (number == 1)

	{
		if (cel >= -273.15)
		{
			cout << "Please enter the temperature in Celsius :" << endl;
			cin >> cel;
			Fahrenheit = celtoFah(cel);
			cout << "This temperature in Fahrenheit is :" << Fahrenheit << endl;
		}
		if (cel <= -273.15)
		{
			cout << "This temperature is invalid, please enter a valid temperature :" << endl;
			cin >> cel;
			Fahrenheit = celtoFah(cel);
			cout << "This temperature in Fahrenheit is : " << Fahrenheit << endl;
		}
		return 0;
	}

	while (number == 2)

	{
		if (cel >= -273.15)
		{
			cout << "Please enter the temperature in Celsius :" << endl;
			cin >> cel;
			Kelvin = celtoKel(cel);
			cout << "This temperature in Kelvin is :" << Kelvin << endl;
		}
		if (cel <= -273.15)
		{
			cout << "This temperature is invalid, please enter a valid temperature :" << endl;
			cin >> cel;
			Kelvin = celtoKel(cel);
			cout << "This temperature in Kelvn is :" << Kelvin << endl;
		}
		return 0;
	}

	while (number == 3)
	{
		if (fah >= -459.67)
		{
			cout << "Please enter the temperature in Fahrenheit :" << endl;
			cin >> fah;
			Celsius = fahtoCel(fah);
			cout << "This temperature in Celsius is :" << Celsius << endl;
		}
		if (fah <= -459.67)
		{
			cout << "This temperature is invalid, please enter a valid temperature :" << endl;
			cin >> fah;
			Celsius = fahtoCel(fah);
			cout << "This temperature in Celsius is :" << endl;
		}

		return 0;

	}
}
float celtoFah(float cel)
{
	return (cel*(1.8) + 32);
}
float celtoKel(float cel)
{
	return cel + 273.15;
}
float fahtoCel(float fah)
{
	return (fah - 32)*(.5555555);
}