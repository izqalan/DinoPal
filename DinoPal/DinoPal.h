#include <iostream>

using namespace std;

struct invoice
{
	double Duration;
	char CurrMonth[20];
	char name[30];
	char cell[20];
};

class userInputs
{
public:
	void getInput(struct invoice *customer)
	{
		cout << "Name: ";
		cin.get(customer->name, 30);
		cin.ignore();
		cout << "cell Number: ";
		cin.get(customer->cell, 20);
		cin.ignore();
		cout << "Billing month: ";
		cin.get(customer->CurrMonth, 20);
		cin.ignore();
		cout << "Airtime (in minutes): ";
		cin >> customer->Duration;
	}

};

	double CalculateRate(double *x)
	{
		
		// calculate rate
		double total;
		double *rate = new double;
		// rate is now  pointed to total
		rate = &total;
		if (*x < 61)
			*rate = 0.85;
		else if (*x > 60 && *x < 121)
			*rate = 0.65;
		else if (*x > 120 && *x < 181)
			*rate = 0.55;
		else
			*rate = 0.35;

		total = (*x * total) + 60;
		return total;
	}

	void TotalAmount(struct invoice *customer, double *total)
	{
		// display bills
		cout << "\nYour bill for " << customer->CurrMonth << " is RM" << *total << endl;
	}

	void userDat(struct invoice *customer)
	{
		cout << "=======verification=========" << endl;
		cout << "Airtime: "<< customer->Duration << " minutes" << endl;
		cout << "Name: " << customer->name << endl;
		cout << "month: " << customer->CurrMonth << endl;
		cout << "Cellphone number: " << customer->cell << endl;
	}

