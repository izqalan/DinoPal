#include <iostream>
using namespace std;

class backend
{
public:
	double CalculateRate(double x)
	{
		// calculate rate
		double rate;
		if (x < 61)
			rate = 0.85;
		else if (x > 60 && x < 121)
			rate = 0.65;
		else if (x > 120 && x < 181)
			rate = 0.55;
		else
			rate = 0.35;

		double total = (x * rate) + 60;
		return total;
	}

	void TotalAmount(double *total, char mon[10])
	{
		// display bills

		cout << "Your bill for " << mon << " is RM" << *total << endl;
	}

	void userDat(int duration, char name[30], char mon[10], char cell[14])
	{
		cout << "verifiction" << endl;
		cout << duration << endl;
		cout << name << endl;
		cout << mon << endl;
		cout << cell << endl;
	}
};
