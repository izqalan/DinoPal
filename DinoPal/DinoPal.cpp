#include <iostream>
#include <fstream>
#include "DinoPal.h"

using namespace std;

struct invoice
{
	double *Duration = new double;
	char CurrMonth[10];
	char name[30];
	char cell[14];
};

// struct declaration
invoice customer;

class userInputs
{
public:
	void getInput()
	{
		cout << "Name: ";
		cin >> customer.name;
		cout << "cell: ";
		cin >> customer.cell;
		cout << "Billing month: ";
		cin >> customer.CurrMonth;
		cout << "Duration: ";
		cin >> *customer.Duration;
	}

};


int main()
{
	// class declaration 
	userInputs newinput;
	double *total = NULL;
	total = new double;

	// func declaration of class userinputs
	// get user input
	newinput.getInput();

	// display user input
	userDat(customer.Duration, customer.name, customer.CurrMonth, customer.cell);

	// display total amount
	*total = CalculateRate(customer.Duration);
	
	TotalAmount(total, customer.CurrMonth);


	return 0;
}
