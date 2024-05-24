#pragma once
#include<iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "Globals.h"
using namespace std;
class clsClientListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(12) << Client.Phone;
		cout << "| " << left << setw(23) << Client.Email;
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
public:
	

	static void ShowClientsList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pListClients))
		{
			return;
		}


		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string title = "\t   Clients List Screen";
		string subtitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";
		
		_DrawScreenHeader(title, subtitle);

		cout << setw(8) <<left <<""<< "\n\t_______________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(15) << "Account Number ";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(23) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\tNo Clients available in the System!.\n";
		}
		else
		{
			for (clsBankClient Client : vClients)
			{
				_PrintClientRecordLine(Client);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;


	}


};

