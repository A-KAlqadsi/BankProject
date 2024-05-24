#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{
private:

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n\nClient Card:\n";
		cout << "\n-------------------------\n";
		cout << "Full Name   :" << Client.FullName() << endl;
		cout << "Acc. Number :" << Client.AccountNumber() << endl;
		cout << "Balance     :" << Client.AccountBalance << endl;
		cout << "\n-------------------------\n";

	}

	static string _ReadAccountNumber(string Message)
	{
		cout << Message;
		string accountNumber = "";
		accountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "\naccount number is not found, choose another one: ";
			accountNumber = clsInputValidate::ReadString();

		}
		return accountNumber;
	}
	
	static double _ReadAmount(clsBankClient SourceClient)
	{
		cout << "\n\nEnter the amount you want to trasfer: ";
		double amount = clsInputValidate::ReadDblNumber();

		while (amount > SourceClient.AccountBalance || amount < 0)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another amount? ";
			cin >> amount;
		}
		return amount;
	}

public:

	static void ShowTransferScreen()
	{
		
		_DrawScreenHeader("\tTransfer Operation Screen");
		
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("\nEnter the account number you want to transfer From: "));
		_PrintClientCard(SourceClient);

		
		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("\nEnter the account number you want to transfer To: "));
		_PrintClientCard(DestinationClient);

		double Amount = _ReadAmount(SourceClient);

		char answer = 'n';
		cout << "\nAre you sure you want to perform this operation? [y/n]? ";
		cin >> answer;
		
		if (answer == 'y' || answer == 'Y')
		{
			
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				
				cout << "\nTransfer done Successfully\n";

			}
			else
			{
				cout << "\nTransfer faild\n";
			}
			
		}
		else
		{
			cout << "\nTransfer operation was canceled!\n";
		}
		_PrintClientCard(SourceClient);

		_PrintClientCard(DestinationClient);
	}


};

