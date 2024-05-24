#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen :protected clsScreen
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

	
	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}

		_DrawScreenHeader("\tUpdate Client Screen");

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

		cout << "\nAre you sure you want to update this client [y/n]? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			cout << "\n---------------------\n";
			_ReadClientInfo(Client);

			clsBankClient::enSaveResults saveResult = Client.Save();

			switch (saveResult)
			{
			
			case clsBankClient::svSucceeded:
				cout << "\nUpdate client succeeded.\n";
				_PrintClient(Client);
				break;
			case clsBankClient::svFaildEmptyObject:
				cout << "\nUpdate failed object is empty\n";
				break;
			case clsBankClient::svFailedAccountNumberExists:
				cout << "\nAccount number is not exists\n";
				break;
			default:
				break;
			}


		}else 
		{
			cout << "\nUpdate client cancled!\n";
		}

	}



};


