//ECE222 Simple function to implement a right triangle of desired size
/*			*                                                                                     
			* *                                                                                   
			* * *                                                                                 
			* * * *                                                                               
			* * * * *                                                                             
			* * * * * *                                                                           
			* * * * * * *					*/

void right_tri(int x);

#include<iostream>
using namespace std;
int main()
{
	int a = 5;
	right_tri(a);
	
	return 0;
}


void right_tri(int x)
{
	for (int i = 0; i <= x; i++)
	{
		for (int t = 0; t <= i; t++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}
