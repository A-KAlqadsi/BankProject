#pragma once
#include<iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include <vector>
#include "clsUtil.h"
class clsListUsersScreen : protected clsScreen 
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(20) << User.FullName();
		cout << "| " << left << setw(12) << User.Phone;
		cout << "| " << left << setw(23) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;
	}

public:

	static void ShowUsersList()
	{
		vector<clsUser> vUsers = clsUser::GetUsersList();

		string title = "\tList Users Screen";
		string subTitle = "\t(" + to_string(vUsers.size()) + ") User(s)";

		_DrawScreenHeader(title,subTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(15) << "UserName ";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(23) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;

		if (vUsers.size() == 0)
		{
			cout << "\t\t\tNo Users available in the System!.\n";
		}
		else
		{
			for (clsUser User : vUsers)
			{
				_PrintUserRecordLine(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________________________________________________________\n" << endl;


	}

};

