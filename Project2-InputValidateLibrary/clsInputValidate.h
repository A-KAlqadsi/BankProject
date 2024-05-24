#pragma once
#include<iostream>
#include"clsDate.h"

using namespace std;

class clsInputValidate
{
public:
	
	static double ValidateNumber(double Number,string errorMessage )
	{

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << endl <<errorMessage ;
			cin >> Number;

		}
		return Number;
	}

	static bool IsNumberBetween(int number, int from, int to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(short number, short from, short to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(float number, float from, float to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double number, double from, double to)
	{
		if (number >= from && number <= to)
			return true;
		else
			return false;
	}

	static bool IsDateBetween(clsDate date, clsDate from, clsDate to)
	{
		if (clsDate::IsDate1BeforeDate2(to, from))
		{
			clsDate::SwapDates(from, to);
		}

		if (date.IsDateBeforeDate2(from) || date.IsDateAfterDate2(to))
			return false;

		return true;

	}

	static int ReadIntNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		int number;
		cin >> number;
		number = ValidateNumber(number,errorMessage);

		return number;
	}

	static int ReadIntNumberBetween(int from, int to, string errorMessage ="Number is not within range, enter again:\n")
	{
		int number;
		do 
		{
			cout << "\nPlease, Enter number between (" << from << " and " << to << "): ";
			cin >> number;
			number = ValidateNumber(number, "Invalid number, Enter again: ");

			if (!IsNumberBetween(number ,from ,to))
				cout << errorMessage << endl; 

		} while (!IsNumberBetween(number, from, to));
		
		return number;
	}

	static double ReadDblNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		double number;
		cin >> number;
		number = ValidateNumber(number, errorMessage);

		return number;
	}

	static double ReadDblNumberBetween(double from, double to, string  errorMessage = "Number is not within range, enter again:\n")
	{
		double number;
		do
		{
			cout << "\nPlease, Enter number between (" << from << " and " << to << "): ";
			cin >> number;
			number = ValidateNumber(number, "Invalid number, Enter again: ");

			if (!IsNumberBetween(number ,from ,to))
				cout << errorMessage << endl;

		} while (!IsNumberBetween(number, from, to));

		return number;
	}

	static	bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString(string Message)
	{
		string text = "";
		cout << Message << endl;
		getline(cin, text);
		return text;
	}

};

