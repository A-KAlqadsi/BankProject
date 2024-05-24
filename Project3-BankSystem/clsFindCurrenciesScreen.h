#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrenciesScreen : protected clsScreen
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
	
	enum enFindBy { eCurrencyCode = 1, eCountryName = 2};
	
	static enFindBy _FindByCodeOrCountry()
	{
		short choice = 0;
		cout << "\nFind By: [1] Code or [2] Country ? ";
		choice = clsInputValidate::ReadShortNumberBetween(1, 2, "Number must be between [1] and [2]");

		return(enFindBy)choice;
	}
	
	static void _ShowResult(clsCurrency currency)
	{
		if (!currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";

			_PrintCurrencyCard(currency);
		}
		else
		{
			cout << "\nCurrency not found! :-(\n";
		}
	}
	
	static void _FindByCode()
	{
		string choice = "";
		cout << "\nPlease Enter Currency Code: ";
		choice = clsInputValidate::ReadString();
		clsCurrency currency =  clsCurrency::FindByCode(choice);

		_ShowResult(currency);

	}

	static void _FindByCountry()
	{
		string choice = "";
		cout << "\nPlease Enter Country Name: ";
		choice = clsInputValidate::ReadString();
		clsCurrency currency = clsCurrency::FindByCountry(choice);

		_ShowResult(currency);

	}


public:


	static void ShowFindCurrencyScreen()
	{
		
		_DrawScreenHeader("\tFind Currency Screen");
		enFindBy option = _FindByCodeOrCountry();

		if (option == enFindBy::eCurrencyCode)
		{
			_FindByCode();
		}
		else
		{
			_FindByCountry();
		}

	}


};

