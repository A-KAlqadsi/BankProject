#pragma once
#include<iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
class clsDeleteUserScreen : protected clsScreen
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

	static void  ShowDeleteUserScreen()
	{
		string userName = "";

		_DrawScreenHeader("\tDelete User Screen");
		
		cout << "\nEnter username: ";
		cin >> userName;

		while (!clsUser::IsUserExist(userName))
		{
			cout << "\nUsername is not exist, enter another one: ";
			cin >> userName;
		}

		clsUser user = clsUser::Find(userName);

		_PrintUser(user);

		cout << "\nAre you sure you want to delete this user [y/n]? ";
		char answer = 'n';
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			user.Delete();

			_PrintUser(user);
		}
		else 
		{
			cout << "\nDelete was canceled!\n";
		}






	}


};

