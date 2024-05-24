#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindClientScreen :protected clsScreen
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

public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\tFind Client Screen");
		
		string accountNumber = "";
		cout << "\nEnte account number: ";
		accountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(accountNumber))
		{
			cout << "account number is not found, choose another one: ";
			accountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(accountNumber);
		
		if (!Client.IsEmpty())
			cout << "\nClient found:-)\n";
		else
			cout << "\nClient is not found:-(\n";

		_PrintClient(Client);

	}


};
