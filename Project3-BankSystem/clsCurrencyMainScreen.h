#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrenciesScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculator.h"
using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:

	enum enCurrencyOptions {cListCurrencies=1, cFindCurrency = 2,
		cUpdateRate = 3,cCurrencyCalculator = 4, cMainMenue = 5};
	static short _ReadCurrenciesMenueOption(short from, short to)
	{

		cout << setw(37) << left << "" << "Choose what do you want to do[" << from << " - " << to << "]: ";
		return  clsInputValidate::ReadShortNumberBetween(from, to, "Enter Number between [1-5]: ");


	}
	
	static void _BackToCurrenciesScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to back to main menue..";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "list currencies screen will be here \n";
		clsListCurrenciesScreen::ShowCurrenciesListScreen();
		
	}
	
	static void _ShowFindCurrenciesScreen()
	{
		//cout << "find currencies screen will be here \n";
		clsFindCurrenciesScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "update rate screen will be here \n";
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "currencies calculator screen will be here \n";
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}

	static void PerformCurrencyScreenMenueOptions(enCurrencyOptions option)
	{
		switch (option)
		{
		case clsCurrencyExchangeMainScreen::cListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_BackToCurrenciesScreen();
			break;
		}
			
		case clsCurrencyExchangeMainScreen::cFindCurrency:
		{
			system("cls");
			_ShowFindCurrenciesScreen();
			_BackToCurrenciesScreen();
			break;
		}
			
		case clsCurrencyExchangeMainScreen::cUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_BackToCurrenciesScreen();
			break;
		}
		case clsCurrencyExchangeMainScreen::cCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_BackToCurrenciesScreen();
			break;
		}
		case clsCurrencyExchangeMainScreen::cMainMenue:
		{
			// here will be nothing 
		}
		}
	}


public:

	static void ShowCurrencyExchangeScreen()
	{

		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Back to Main Menue .\n";
		cout << setw(37) << left << "" << "======================================\n";
		PerformCurrencyScreenMenueOptions((enCurrencyOptions)_ReadCurrenciesMenueOption(1, 5));
	}


};

