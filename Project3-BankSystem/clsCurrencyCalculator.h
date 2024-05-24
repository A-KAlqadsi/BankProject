#pragma once
#include<iostream>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsString.h"

class clsCurrencyCalculator : protected clsScreen
{

private:
	static void _PrintCurrencyCard(clsCurrency currency,string line)
	{
		cout << "\n" << line << "\n";
		cout << "==================================================\n";
		cout << "country    : " << currency.GetCountryName() << endl;
		cout << "Code       : " << currency.GetCurrencyCode() << endl;
		cout << "Name       : " << currency.GetCurrencyName() << endl;
		cout << "Rate(1$) = : " << currency.Rate() << endl;
		cout << "===================================================\n";
	}

	static string _ReadCurrencyCode(string message)
	{
		string choice = "";
		cout << message;
		choice = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(choice))
		{
			cout << "\nCurrency code was not found, please enter another one: ";
			choice = clsInputValidate::ReadString();
		}

		return choice;
	}

	static float _ReadAmount()
	{
		float amount = 0;
		cout << "\nEnter amount to exchange: ";
		amount = clsInputValidate::ReadFloatNumber();

		return amount;
	}


	static clsCurrency _GetCurrency(string message)
	{
		string currencyCode = "";
		cout << message;
		currencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(currencyCode))
		{
			cout << "\nCurrency code was not found, please enter another one: ";
			currencyCode = clsInputValidate::ReadString();
		}

		clsCurrency currency = clsCurrency::FindByCode(currencyCode);
		return currency;
	}


	static void _PrintCalculationsResults(float amount, clsCurrency currency1, clsCurrency currency2)
	{
		_PrintCurrencyCard(currency1, "Convert From: ");

		float amountInUSD = currency1.ConvertToUSD(amount);

		cout << amount << " " << currency1.GetCurrencyCode() << " = " << amountInUSD << " USD\n";

		if (currency2.GetCurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";
		_PrintCurrencyCard(currency2, "To:");

		float amountInCurrency2 = currency1.ConvertToOtherCurrency(currency2,amount);

		cout << amount << " " << currency1.GetCurrencyCode() << " = " << amountInCurrency2 << " " << currency2.GetCurrencyCode();



	}
public:

	static void ShowCurrencyCalculatorScreen()
	{

		char answer = 'n';
		
		do
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency currencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");


			clsCurrency currencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");

			float amount = _ReadAmount();

			_PrintCalculationsResults(amount, currencyFrom, currencyTo);


			cout << "\n\nDo you want to perform another calculation? [y/n]? ";
			cin >> answer;


		} while (answer == 'Y' || answer == 'y');

		


	}


};

