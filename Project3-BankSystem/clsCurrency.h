#pragma once
#include<iostream>
#include"clsString.h"
#include <fstream>
#include<string>

using namespace std;

const string CurrenciesFileName = "Currencies.txt";

class clsCurrency
{
private:
	enum enMode { eEmptyMode = 0, eUpdateMode = 1};

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	static clsCurrency _ConvertLineToCurrencyObject(string line, string seperator = "#//#")
	{
		vector <string> vCurrencies = clsString::Split(line, seperator);

		return clsCurrency(enMode::eUpdateMode, vCurrencies[0], vCurrencies[1], vCurrencies[2], stof(vCurrencies[3]));
	}
	static string _ConvertCurrencyObjectToLine(clsCurrency currency, string seperator = "#//#")
	{
		string lineData = "";
		lineData =  currency.GetCountryName () + seperator;
		lineData += currency.GetCurrencyCode()+ seperator;
		lineData += currency.GetCurrencyName() + seperator;
		lineData += to_string(currency.Rate());

		return lineData;
	}

	static void _SaveCurrenciesDataToFile(vector<clsCurrency> vCurrencies)
	{
		fstream myFile;
		myFile.open(CurrenciesFileName, ios::out); // overwrite
		if (myFile.is_open())
		{

			for (clsCurrency C : vCurrencies)
			{
				
					string line = _ConvertCurrencyObjectToLine(C);
					myFile << line << endl;
			}
			myFile.close();
		}
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}

	static vector<clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector <clsCurrency> _vCurrencies;


		fstream myFile;
		myFile.open(CurrenciesFileName, ios::in);

		if (myFile.is_open())
		{
			string lineData;
			while (getline(myFile, lineData))
			{
				clsCurrency currency = _ConvertLineToCurrencyObject(lineData);
				_vCurrencies.push_back(currency);

			}

		}
		myFile.close();
		return _vCurrencies;
	}

	void _Update()
	{
		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();
		for (clsCurrency &currency : vCurrencies)
		{
			if (currency.GetCurrencyCode() == GetCurrencyCode())
			{
				currency = *this;
				break;
			}

		}

		_SaveCurrenciesDataToFile(vCurrencies);
	}

public:
	clsCurrency(enMode mode,string countryName,string countryCode ,string currencyName,float rate)
	{
		_Mode = mode;
		_Country = countryName;
		_CurrencyCode = countryCode;
		_CurrencyName = currencyName;
		_Rate = rate;
	}
	
	bool IsEmpty()
	{
		return enMode::eEmptyMode == _Mode;
	}

	string GetCountryName()
	{
		return _Country;
	}

	string GetCurrencyCode()
	{
		return _CurrencyCode;
	}
	string GetCurrencyName()
	{
		return _CurrencyName;
	}
	

	float Rate()
	{
		return _Rate;
	}
	
	void UpdateRate(float newRate)
	{
		_Rate = newRate;
		_Update();
	}

	static clsCurrency FindByCountry(string countryName)
	{
		countryName = clsString::UpperAllString(countryName);

		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency currency : vCurrencies)
		{
			if (clsString::UpperAllString(currency.GetCountryName()) == countryName)
			{
				return currency;
			}
		}

		return _GetEmptyCurrencyObject();
	}
	
	static clsCurrency FindByCode(string currencyCode)
	{
		currencyCode = clsString::UpperAllString(currencyCode);

		vector<clsCurrency> vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency currency : vCurrencies)
		{
			if (clsString::UpperAllString(currency.GetCurrencyCode()) == currencyCode)
			{
				return currency;
			}
		}

		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string currencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(currencyCode);
		return !(C1.IsEmpty());
	}
	
	static vector<clsCurrency> GetCurrencyList()
	{
		return _LoadCurrenciesDataFromFile();
	}
	
	float ConvertToUSD(float amount)
	{
		return (float)amount / Rate();
	}

	float ConvertToOtherCurrency(clsCurrency currency2, float amount)
	{
		float amountInUSD = ConvertToUSD(amount);
		if (clsString::UpperAllString(currency2.GetCurrencyCode())== "USD")
		{
			return amountInUSD;
		}

		return (float)amountInUSD * currency2.Rate();
	} 

};

