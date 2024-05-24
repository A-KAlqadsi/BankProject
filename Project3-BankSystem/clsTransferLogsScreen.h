#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include "clsScreen.h"
#include <vector>
#include<iomanip>

class clsTransferLogsScreen : protected clsScreen
{
private:
	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLog transferLog)
	{
		cout << setw(8) << left << "" << "| " << left << setw(35) << transferLog.Date;
		cout << "| " << left << setw(15) << transferLog.SourceAccount;
		cout << "| " << left << setw(15) << transferLog.DestinationAccount;
		cout << "| " << left << setw(12) << transferLog.Amount;
		cout << "| " << left << setw(14) << transferLog.SourceBalance;
		cout << "| " << left << setw(14) << transferLog.DestinationBalance; 
		cout << "| " << left << setw(12) << transferLog.User;
	}

public:

	static void ShowTransferLogsScreen()
	{

		vector<clsBankClient::stTransferLog> vTransferLogs = clsBankClient::GetTransferLogList();

		string title = "\tTransfer Log List Screen";
		string subtitle = "\t(" + to_string(vTransferLogs.size()) + ") Transfer(s) log";

		_DrawScreenHeader(title, subtitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time ";
		cout << "| " << left << setw(15) << "s.Acct";
		cout << "| " << left << setw(15) << "d.Acct";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(14) << "s.Balance";
		cout << "| " << left << setw(14) << "d.Balance";
		cout << "| " << left << setw(12) << "User";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________________________________\n" << endl;

		if (vTransferLogs.size() == 0)
		{
			cout << "\t\t\tNo Transfer logs registered in the System!.\n";
		}
		else
		{
			for (clsBankClient::stTransferLog tranferLog : vTransferLogs)
			{
				_PrintTransferLogRecordLine(tranferLog);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________________________________\n" << endl;


	}


};

