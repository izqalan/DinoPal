#include <iostream>
#include "DinoPal.h"

using namespace std;

struct invoice
{
	int Duration;
	char CurrMonth[10];
	char name[30];
	char cell[14];
};

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
	
	userInputs newinput;
	newinput.getInput();

	double total = CalculateRate(customer.Duration);
	TotalAmount(total, customer.CurrMonth);


	return 0;
}
