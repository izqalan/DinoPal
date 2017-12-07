#include <iostream>
using namespace std;


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

	void TotalAmount(double *total,char mon[10])
	{
		// display bills

		cout << "Your bill for " << mon << " is RM" << *total << endl;
	}

	void userDat(double *duration, char name[30], char mon[10], char cell[14])
	{
		cout << "verification" << endl;
		cout << "Air time: "<<*duration << endl;
		cout << "Name: " <<name << endl;
		cout << "month: " << mon << endl;
		cout << "Cellphone number: " <<cell << endl;
	}

