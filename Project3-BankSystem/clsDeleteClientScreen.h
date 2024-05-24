#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;
class clsDeleteClientScreen : protected clsScreen
{

private:
	static void _PrintClient(clsBankClient Client)
	{
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
	}

public:
	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\tDelete Client Screen");

		string accountNumber = "";
		cout << "\nEnte account number: ";
		accountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "account number is not found, choose another one: ";
			accountNumber = clsInputValidate::ReadString();

		}
		
		clsBankClient Client = clsBankClient::Find(accountNumber);

		_PrintClient(Client);

		cout << "\nAre you sure you want to delete this client [y/n]? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			cout << "\nClient Deleted Successfully!\n";
			Client.Delete();
			 
			_PrintClient(Client);
		}
		else
		{
			cout << "\nDelete clinet cancled!\n";
		}

	}




};

