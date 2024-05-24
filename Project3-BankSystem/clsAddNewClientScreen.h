#pragma once
#include<iostream>
#include "clsBankClient.h";
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter first name: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter last name: ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter email: ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter phone: ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter password: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter account balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}
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
	
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t   Add New Client Screen");
		

		string accountNumber = "";
		cout << "\nEnter account number: ";
		accountNumber = clsInputValidate::ReadString();
		
		while (clsBankClient::IsClientExist(accountNumber))
		{
			cout << "\naccount number already exists, choose another one: ";
			accountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(accountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults saveResults;

		saveResults = NewClient.Save();

		switch (saveResults)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << " \nAccount Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nAccount adding failed, because object is empty!\n";
			break;
		}
			
		case clsBankClient::enSaveResults::svFailedAccountNumberExists:
		{
			cout << "\nAccount failed, because account number already exists!\n";
			break;
		}
			
		}



	}


};

