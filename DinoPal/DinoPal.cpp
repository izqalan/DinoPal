#include <iostream>
#include <fstream>
#include "DinoPal.h"

using namespace std;

struct invoice
{
	int Duration;
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
		cin >> customer.Duration;
	}

};


int main()
{
	// class declaration 
	userInputs newinput;
	backend newbackend;

	// func declaration of class userinputs
	// get user input
	newinput.getInput();

	// display user input
	newbackend.userDat(customer.Duration, customer.name, customer.cell, customer.CurrMonth);

	// display total amount
	double total = newbackend.CalculateRate(customer.Duration);
	newbackend.TotalAmount(&total, customer.CurrMonth);


	return 0;
}
