#include <iostream>
#include <fstream>
#include <time.h>
#include <cctype>
#include <lmcons.h>

using namespace std;

struct invoice
{
	double Duration = NULL;
	char CurrMonth[20];
	char name[30];
	char cell[20];
};

class userInputs
{
public:
	void getInput(struct invoice *customer)
	{
		cout << "\t\t\t\tName: ";
		cin.get(customer->name, 30);
		cin.ignore();
		cout << "\t\t\t\tMobile Number: ";
		cin.get(customer->cell, 20);
		cin.ignore();
		cout << "\t\t\t\tBilling month: ";
		cin.get(customer->CurrMonth, 20);
		cin.ignore();
		
		while (customer->Duration == NULL)
		{
			do{
				cout << "\t\t\t\tAirtime (in minutes): ";
				cin >> customer->Duration;
				if (cin.fail())
				{
					cout << "\t\t\t\t\aInvalid Input" << endl;
					cin.clear();
					cin.ignore();
				}
				else
					break;
			} while (customer->Duration == NULL && cin.fail());
		}
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
	cout << "\n\t\t\t\tYour bill for " << customer->CurrMonth << " is RM" << *total <<"\n"<< endl;
}

void userDat(struct invoice *customer)
{
	cout << "\t\t\t\t=======verification=========" << endl;
	cout << "\t\t\t\tAirtime: "<< customer->Duration << " minutes" << endl;
	cout << "\t\t\t\tName: " << customer->name << endl;
	cout << "\t\t\t\tmonth: " << customer->CurrMonth << endl;
	cout << "\t\t\t\tCellphone number: " << customer->cell << endl;
}

void reciept(struct invoice *customer)
{
	//	filename will in saved in time 24hrs time format
	//	this is to prevent overwiting previous customer input
	time_t getTime;	// get current time
	struct tm now;
	time(&getTime);	
	localtime_s(&now, &getTime);	// localtime_s is required to hold 2 parameters 
	char strTime[50]; // string for filename

	//note that %F is not compitable with windows 
	strftime(strTime, 50, "%H-%M-%S.txt", &now);
	//const char *path="\\Users\\userpc\\Desktop";
	ofstream record;
	record.open(strTime);

	record << "\t\t\t\t=======Your Billing details=========\n" << endl;
	record << "\t\t\t\tAirtime: " << customer->Duration << " minutes" << endl;
	record << "\t\t\t\tName: " << customer->name << endl;
	record << "\t\t\t\tMonth: " << customer->CurrMonth << endl;
	record << "\t\t\t\tCellphone number: " << customer->cell << endl;

	cout << "\t\t\t\tThank you. Record has been saved" << endl;

	record.close();
}

void path()
{
	TCHAR pathname[UNCLEN + 1];
	DWORD path_len = UNCLEN + 1;
	// GetComputerName
	GetUserName((TCHAR*)pathname, &path_len);
	wcout << pathname << endl;
	
}

