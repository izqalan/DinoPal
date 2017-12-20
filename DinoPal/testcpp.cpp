#include <iostream>

using namespace std;

int main()
{
	struct invoice
	{
		double Duration;
		char CurrMonth[20];
		char name[30];
		char cell[20];
	};
	struct invoice customer;
	class userInputs
	{
	public:
		void getInput(struct invoice *customer)
		{
			cout << "Name: ";
			cin.get(customer->name, 30);
			cout << "cell Number: ";
			cin.get(customer->cell, 20);
			cout << "Billing month: ";
			cin.get(customer->CurrMonth, 20);
			cout << "Airtime (in minutes): ";
			cin >> customer->Duration;
		}

	};

	userInputs newinput;
	struct invoice userdetails;
	newinput.getInput(&userdetails);

	return 0;
}