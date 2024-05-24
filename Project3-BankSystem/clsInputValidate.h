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
			cin >> number;
			number = ValidateNumber(number, "Invalid number, Enter again: ");

			if (!IsNumberBetween(number ,from ,to))
				cout << errorMessage ; 

		} while (!IsNumberBetween(number, from, to));
		
		return number;
	}

	static int ReadShortNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		short number;
		cin >> number;
		number = ValidateNumber(number, errorMessage);

		return number;
	}

	static int ReadShortNumberBetween(short from, short to, string errorMessage = "Number is not within range, enter again:\n")
	{
		short number;
		do
		{

			cin >> number;
			number = ValidateNumber(number, "Invalid number, Enter again: ");

			if (!IsNumberBetween(number, from, to))
				cout << errorMessage ;

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
	static float ReadFloatNumber(string errorMessage = "Invalid Number, Enter again\n")
	{
		float number;
		cin >> number;
		number = ValidateNumber(number, errorMessage);

		return number;
	}
	static float ReadFloatNumberBetween(float from, float to, string  errorMessage = "Number is not within range, enter again:\n")
	{
		float number;
		do
		{
			cin >> number;
			number = ValidateNumber(number, "Invalid number, Enter again: ");

			if (!IsNumberBetween(number, from, to))
				cout << errorMessage ;

		} while (!IsNumberBetween(number, from, to));

		return number;
	}

	static double ReadDblNumberBetween(double from, double to, string  errorMessage = "Number is not within range, enter again:\n")
	{
		double number;
		do
		{
			cin >> number;
			number = ValidateNumber(number, "Invalid number, Enter again: ");

			if (!IsNumberBetween(number ,from ,to))
				cout << errorMessage ;

		} while (!IsNumberBetween(number, from, to));

		return number;
	}

	static	bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

	static string ReadString()
	{
		string text ;
		getline(cin >> ws, text);
		return text;
	}

};

