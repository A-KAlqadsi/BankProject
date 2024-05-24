#pragma once
#include<iostream>
#include <iomanip>
#include "clsCurrency.h"
#include<vector>
#include "clsUtil.h"
#include "clsScreen.h"

class clsListCurrenciesScreen : protected clsScreen
{
private:
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(30) << Currency.GetCountryName();
		cout << "| " << left << setw(8) << Currency.GetCurrencyCode();
		cout << "| " << left << setw(45) << Currency.GetCurrencyName();
		cout << "| " << left << setw(10) << Currency.Rate();
	}



public:

	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrencyList();

		string title = "\t Currencies List Screen";
		string subTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency";

		_DrawScreenHeader(title, subTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country ";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
		{
			cout << "\t\t\tNo Currencies available in the System!.\n";
		}
		else
		{
			for (clsCurrency Currency : vCurrencies)
			{
				_PrintCurrencyRecordLine(Currency);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;


	}



};

