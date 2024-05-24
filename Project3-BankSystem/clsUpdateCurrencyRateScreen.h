#pragma once
#include<iostream>
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsScreen.h"


class clsUpdateCurrencyRateScreen : clsScreen
{


private:

	static void _PrintCurrencyCard(clsCurrency currency)
	{
		cout << "\n\nCurrency Card:\n";
		cout << "==================================================\n";
		cout << "country    : " << currency.GetCountryName() << endl;
		cout << "Code       : " << currency.GetCurrencyCode() << endl;
		cout << "Name       : " << currency.GetCurrencyName() << endl;
		cout << "Rate(1$) = : " << currency.Rate() << endl;
		cout << "===================================================\n";
	}

	static float _ReadNewRate()
	{
		float newRate = 0;
		cout << "\nEnter new Rate : ";
		newRate = clsInputValidate::ReadFloatNumber();

		return newRate;
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		
		_DrawScreenHeader("\tUpdate Currency Screen");

		string choice = "";
		cout << "\nPlease Enter Currency Code: ";
		choice = clsInputValidate::ReadString();
		
		while (!clsCurrency::IsCurrencyExist(choice))
		{
			cout << "\nCurrency code was not found, please enter another one: ";
			choice = clsInputValidate::ReadString();
		}

		clsCurrency currency = clsCurrency::FindByCode(choice);

		_PrintCurrencyCard(currency);

		char answer = 'n';
		cout << "\nAre you sure you want to update the rate of this currency?[y/n]? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:";
			cout << "\n-----------------------\n";
			

			currency.UpdateRate(_ReadNewRate());

			cout << "\nCurrency Rate updated successfully!\n";

			_PrintCurrencyCard(currency);

		}
		else
		{
			cout << "\nUpdate Currency canceled!\n";
		}

	}


};

