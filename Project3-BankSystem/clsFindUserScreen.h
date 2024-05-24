#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
class clsFindUserScreen : protected clsScreen
{
private:
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
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");

		string userName = "";
		cout << "\nEnte username: ";
		userName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(userName))
		{
			cout << "username is not found, choose another one: ";
			userName = clsInputValidate::ReadString();

		}

		clsUser user = clsUser::Find(userName);

		if (!user.IsEmpty())
		{
			cout << "\nUser found successfully\n";

			_PrintUser(user);

		}
		else
		{
			cout << "\nUser is not found\n";
		}

	}

};

