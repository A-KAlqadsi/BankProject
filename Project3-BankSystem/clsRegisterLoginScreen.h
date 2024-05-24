#pragma once
#include<iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include <vector>
class clsRegisterLoginScreen :protected clsScreen
{
private:

	static void _PrintRegisterUserRecord(clsUser::stLoginRegister RegisterUser)
	{
		cout << setw(8) << left << "" << "| " << left << setw(35) << RegisterUser.RegisterDate;
		cout << "| " << left << setw(20) << RegisterUser.UserName;
		cout << "| " << left << setw(20) << RegisterUser.Password;
		cout << "| " << left << setw(10) << RegisterUser.Permissions;
	}
	
public:
	

	static void ShowRegisterUsersList()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pRegisterLogin))
		{
			return;
		}

		vector<clsUser::stLoginRegister> vUsers = clsUser::GetLoginUsersList();

		string title = "\tList Register Users Screen";
		string subTitle = "\t(" + to_string(vUsers.size()) + ") Register User(s)";

		_DrawScreenHeader(title, subTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;

		if (vUsers.size() == 0)
		{
			cout << "\t\t\tNo Users available in the System!.\n";
		}
		else
		{
			for (clsUser::stLoginRegister User : vUsers)
			{
				_PrintRegisterUserRecord(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;


	}

};

