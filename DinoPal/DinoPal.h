#include <iostream>
#include <fstream>
#include <time.h>
#include <cctype>
#include <lmcons.h>
#include <string>

using namespace std;

struct invoice
{
	double Duration = NULL;
	char Custid[10];
	char CurrMonth[20];
	char name[30];
	int cell = NULL;
};

class userDetails
{
public:
	
	void getCaller(struct invoice *customer)
	{
		
		cout << "Name: ";
		cin.get(customer->name, 30);
		cin.ignore();

		cout << "Enter 4 character User ID: ";
		cin.get(customer->Custid, 10);
		cin.ignore();

		cout << "\nHello Encik/puan " << customer->name << "\n" <<endl;
		Sleep(800);
		cout << "please enter necessary details" << endl;
		Sleep(800);
		
		while (customer->cell == NULL)
		{
			do{
				cout << "Mobile Number: ";
				cin >> customer->cell;
				if (cin.fail())
				{
					cout << "\aInvalid input" << endl;
					cin.clear();
					cin.ignore();
				}
				else
					cin.ignore();
					break;
			} while (customer->cell == NULL || cin.fail());
		}

		cout << "Billing month: ";
		cin.get(customer->CurrMonth, 20);
		cin.ignore();
		
		while (customer->Duration == NULL)
		{
			do{
				cout << "Airtime (in minutes): ";
				cin >> customer->Duration;
				if (cin.fail())
				{
					cout << "\aInvalid Input" << endl;
					cin.clear();
					cin.ignore();
				}
				else
					break;
			} while (customer->Duration == NULL && cin.fail());
		}
	}


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
		cout << "\nYour bill for " << customer->CurrMonth << " is RM" << *total << "\n" << endl;
		
	}

	void userDat(struct invoice *customer)
	{
		cout << "=============verification===============" << endl;
		cout << "Airtime: " << customer->Duration << " minutes" << endl;
		cout << "Name: " << customer->name << endl;
		cout << "month: " << customer->CurrMonth << endl;
		cout << "Mobile number: +60 " << customer->cell << endl;
		Sleep(1000);
		
	}

	void reciept(struct invoice *customer, double *total)
	{
		/*	24hrs file format

		//	filename will be in saved in time 24hrs time format
		//	this is to prevent overwiting previous customer information
		
		time_t getTime;	// get current time
		struct tm now;
		time(&getTime);
		localtime_s(&now, &getTime);	// localtime_s is required to hold 2 parameters 
		char strTime[50]; // string for filename 

		//note that %F is not compitable with windows OS
		strftime(strTime, 50, "-%H-%M-%S.txt", &now);
		char filename[50];
		strcpy_s(filename, customer->name);	// prevent overwiting name 
		strcat_s(filename, strTime);
		//const char *path="C:\\Users\\%USERPROFILE%\\Desktop\\";

		*/

		// remove this bit if you want to use ^ file format
		// id based file format

		char filename[10];
		strcpy_s(filename, customer->Custid);
		strcat_s(filename, ".txt");
		
		ofstream record;
		record.open(filename);

		record << "=======Your Billing details=========\n" << endl;
		record << "Airtime: " << customer->Duration << " minutes" << endl;
		record << "Name: " << customer->name << endl;
		record << "User ID: " << customer->Custid << endl;
		record << "Month: " << customer->CurrMonth << endl;
		record << "Cellphone number: +60 " << customer->cell << endl;
		record << "\nYour bill for " << customer->CurrMonth << " is RM" << *total << "\n" << endl;

		cout << "Thank you. Your record has been saved as "<< filename << endl;

		record.close();

	}


	int retCust()
	{
		// returning customer
		cout << "*Please Enter Your ID: ";
		char DupeID[10];
		cin >> DupeID;
		cin.ignore();
	
		char filename[10];
		char notepad[15] = "notepad.exe ";
		char txt[5] = ".txt";
		strcpy_s(filename, DupeID);
		
		strcat_s(filename,14, txt);
		strcat_s(notepad, 24, filename); // notepad.exe filename.txt
		
		fstream file(filename);
		if (!file.is_open())
		{
			cout << "file does not exist :(" << endl;
		}
		else
		{
			cout << "opening file" << endl;

			system(notepad);	// pop up notepad.exe
		}
	
	
		exit(1);
		return 0;
	}

	
};

