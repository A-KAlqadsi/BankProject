#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
class clsUpdateUserScreen :protected clsScreen
{

private:

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter first name: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter last name: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter phone: ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter password: ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permissions\n";
		User.Permissions = _ReadPermissionsToSet();

	}

	static int _ReadPermissionsToSet()
	{
		int permissions = 0;
		char answer = 'n';

		cout << "\nDo you want to give all permissions [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			return -1;
		}

		cout << "\nAllow Permissions For \n";

		cout << "\nList clients permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd new clients permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete clients permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate clients permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind clients permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nRegister Login Permission [y/n]? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			permissions += clsUser::enPermissions::pRegisterLogin;
		}
		return permissions;

	}

	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n----------------------------------\n";
		cout << "First Name : " << User.FirstName << endl;
		cout << "Last Name  : " << User.LastName << endl;
		cout << "Full Name  : " << User.FullName() << endl;
		cout << "Email      : " << User.Email << endl;
		cout << "Phone      : " << User.Phone << endl;
		cout << "Username   : " << User.UserName << endl;
		cout << "Bassword   : " << User.Password << endl;
		cout << "permissions: " << User.Permissions << endl;
		cout << "----------------------------------\n";
	}

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\tUpdate User Screen");

		string userName = "";
		cout << "\nEnte username: ";
		userName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(userName))
		{
			cout << "username is not found, choose another one: ";
			userName = clsInputValidate::ReadString();

		}

		clsUser user = clsUser::Find(userName);

		_PrintUser(user);

		cout << "\nAre you sure you want to update this user [y/n]? ";
		char answer = 'n';
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			cout << "\n\nUpdate User Info:";
			cout << "\n---------------------\n";
			_ReadUserInfo(user);

			clsUser::enSaveResults saveResult = user.Save();

			switch (saveResult)
			{

			case clsUser::enSaveResults::svSucceeded:
				cout << "\nUpdate user succeeded.\n";
				_PrintUser(user);
				break;
			case clsUser::enSaveResults::svFaildEmptyObject:
				cout << "\nUpdate failed object is empty\n";
				break;
			case clsUser::enSaveResults::svFailedUserNameExists:
				cout << "\nUsername is not exists\n";
				break;
			
			}


		}
		else
		{
			cout << "\nUpdate user cancled!\n";
		}

	}

};

