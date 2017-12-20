#include <iostream>
#include <fstream>
#include "DinoPal.h"

using namespace std;

int main()
{
	cout << "=== Thank you for subscribing to DinoPal telco ===" << endl;
	cout << "===== Please enter your credentials =====" << endl;

	// class declaration 
	userInputs newinput;
	double *total = NULL;
	total = new double;

	// func declaration of class userinputs
	// get user input from public class function
	struct invoice userdetails;
	newinput.getInput(&userdetails);

	// referencing customer struct as userdetails && display user input
	userDat(&userdetails);

	// display total amount
	*total = CalculateRate(&userdetails.Duration);
	
	TotalAmount(&userdetails, total);

	system("pause");
	return 0;
}