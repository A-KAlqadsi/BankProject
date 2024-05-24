#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDepositScreen :protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n----------------------------------\n";
		cout << "First Name : " << Client.FirstName << endl;
		cout << "Last Name  : " << Client.LastName << endl;
		cout << "Full Name  : " << Client.FullName() << endl;
		cout << "Email      : " << Client.Email << endl;
		cout << "Phone      : " << Client.Phone << endl;
		cout << "Acc.Number : " << Client.AccountNumber() << endl;
		cout << "Bassword   : " << Client.PinCode << endl;
		cout << "Balance    : " << Client.AccountBalance << endl;
		cout << "----------------------------------\n";
	}

	static string  _ReadAccountNumber()
	{
		cout << "\nEnter account number: ";
		return clsInputValidate::ReadString();
	}


public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen");
		
		string accountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "\nClient with account number [" << accountNumber << "] is not exist!";
			accountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(accountNumber);

		_PrintClient(Client);

		double newBalance = 0;
		cout << "\n\nEnter account balance you want to deposit: ";
		newBalance = clsInputValidate::ReadDblNumber();
		
		cout << "\nAre you sure you want to deposit this account [y/n]? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			if (Client.Deposit(newBalance))
			{
				cout << "\nAmount Deposited Successfully.\n";
				cout << "\nNew Balance is: " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "Deposit amount is less than zero [" << newBalance << "] " << endl;
			}
			
			

		}
		else
		{

			cout << "\nOeration was cancelled\n";
		}

	}





};

