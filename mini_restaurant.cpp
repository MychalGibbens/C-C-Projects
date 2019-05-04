//ECE222
/*This is an implementaton of a simple "restaurant" for the user. More menu options could be added to the case statement with 
relative ease. */

#include<iostream>
using namespace std;

int main()
{

	int option, quant;
	bool inv = true;
	int priceCalc(int p, int q);

	cout << "\t\t\t*** Welcome to my restaurant ***\n\n" << endl;
	cout << "What can I get you?\n" << endl;
	cout << "\t\tMenu: \n"<<"\t\t\t1.Kebab: 10$\n"<<"\t\t\t2.Pizza slice: 5$\n"<<"\t\t\t3.Cheeseburger: 6$\n"<<"\t\t\t4.Lasagna: 12$\n"<<"\t\t\t5.Done Ordering\n" << endl;

	int x = 0, tot = 0;
	while (inv == true)
	{
	    cout <<"I would like to order number:" <<endl;
		cin >> option;
		
		switch (option)
		{
		case 1:
		    cout << "How many would you like:" << endl;
		    cin >> quant;
		    x = priceCalc(10,quant);
			break;
		case 2:
		    cout << "How many would you like:" << endl;
		    cin >> quant;
		    x = priceCalc(5,quant);
			break;
		case 3:
	    	cout << "How many would you like:" << endl;
		    cin >> quant;   
		    x = priceCalc(6,quant);
			break;
		case 4:
		    cout << "How many would you like:" << endl;
		    cin >> quant;
		    x = priceCalc(12,quant);
			break;
		case 5:
		    cout << "\t\t\tThank you for choosing my restaurant!\n\n" << endl;
		    cout << "\t\tYour total bill comes to $" << tot << "\n" << endl;
		    inv = false;
		    continue;
		default:
			cout << "We don't have that number" << endl;
			break;
		}
		tot = tot + x;
		if(inv == true)
		{
		    cout << "\t\tYour current total is: " << tot << " $\n" << endl;
		    cout << "What else can I get you?" << endl;
	    }
	    else
	    {
	        break;
	    }
	}
	return 0;
}
int priceCalc(int p, int q)
{
	int t = p*q;
		return t;
}
