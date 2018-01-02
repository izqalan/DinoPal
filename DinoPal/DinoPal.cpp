#include <iostream>
#include <windows.h>
#include "DinoPal.h"

using namespace std;
/*Documentation is as important as the codes itself */

int main()
{
	cout << "\t\t\t=== Thank you for subscribing to DinoPal telco ===" << endl;
	cout << "\t\t\t===== Please enter your credentials =====" << endl;
	path();
	// class declaration 
	userInputs newinput;
	double *total = NULL;
	total = new double;

	// get user input from public class function
	struct invoice userdetails;
	
	newinput.getInput(&userdetails);

	// referencing customer struct as userdetails && display user input
	for (int i = 0; i < 3; i++)
	{
		Sleep(800);
		cout << "\t\t\t\t\tLoading..." << endl;
	}Sleep(500);
	userDat(&userdetails);

	// display total amount
	*total = CalculateRate(&userdetails.Duration);
	Sleep(1000);
	TotalAmount(&userdetails, total);
	reciept(&userdetails);

	system("pause");
	return 0;
}