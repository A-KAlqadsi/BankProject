#pragma once
#include<iostream>
#include "Globals.h"
#include "clsUser.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string title, string subtitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t " << title;
		if (subtitle != "")
		{
			cout << "\n\t\t\t\t\t " << subtitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions permissions)
	{
		if (!CurrentUser.CheckAccessPermission(permissions))
		{
			cout << "\t\t\t\t\t_________________________________________";
			cout << "\n\n\t\t\t\t\t " << "Access denied, contact your admin!";
			cout << "\n\t\t\t\t\t________________________________________\n\n";
			cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << endl;
			cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}

	
	
};

