#include <iostream>
#include <windows.h>
#include "DinoPal.h"

using namespace std;
/*Documentation is as important as the codes itself */

int main()
{
	cout << "=== Thank you for subscribing to DinoPal telco Malaysia===" << endl;
	// class declaration
	userDetails write;
	double *total = NULL;
	total = new double;

	// get user input from public class function
	bool x = false;
	struct invoice userdetails;
	cout << "Please press [1] you're a returning customer [2] for else" << endl;
	cin >> x;
	cin.clear();
	cin.ignore();

	if (x == true)
	{
		write.retCust();
	}
	cout << "===== Please enter your credentials =====" << endl;
	Sleep(500);
	write.getCaller(&userdetails);

	// referencing customer struct as userdetails && display user input
	for (int i = 0; i < 3; i++)
	{
		Sleep(800);
		cout << "\t\t\t\t\tLoading..." << endl;
	}Sleep(500);
	write.userDat(&userdetails);

	// display total amount
	*total = write.CalculateRate(&userdetails.Duration);
	Sleep(1000);
	write.TotalAmount(&userdetails, total);

	// create file function
	write.reciept(&userdetails, total);

	system("pause");
	return 0;
}