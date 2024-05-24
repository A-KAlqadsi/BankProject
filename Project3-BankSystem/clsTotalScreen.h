#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUtil.h"

class clsTotalScreen :clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(40) << Client.FullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}

public:
	static void ShowTotalBalancesScreen()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		string title = "\t  Balances List Screen";
		string subTitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";
		
		_DrawScreenHeader(title,subTitle);

		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n" << endl;
		cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number ";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n" << endl;
		

		double totalBalance = clsBankClient::GetTotalBalance();

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Accounts Available in the system!.\n";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		}
		cout << setw(25) << left << "" << "\n\t\t___________________________________________________________________________________\n" << endl;

		cout << setw(20) << left << "" << " Total Balance: ( " << fixed << setprecision(0) << totalBalance << " )\n";
		cout << setw(20) << left << "" << "( " + clsUtil::NumberToText(totalBalance) << " )" << endl;
	}

};

