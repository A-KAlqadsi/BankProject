#pragma once
#include<iostream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "Globals.h"
#include"clsUtil.h"
class clsLoginScreen :protected clsScreen
{
private:

	static bool _Login()
	{
		bool loginFaild = false;
		string userName, password;
		short faildCounter = 0;
		do
		{
			if (loginFaild)
			{
				faildCounter++;
				cout << "\nInvalid username/password!\n";
				cout << "You have " << 3- faildCounter << " trial(s) to login.\n\n";
			}

			if (faildCounter == 3)
			{
				cout << "\n\nYou are locked after 3 faild trails.\n";
				return false;
			}

			cout << "Enter username? ";
			cin >> userName;
			cout << "Enter password? ";
			cin >> password;
			CurrentUser = clsUser::Find(userName, password);
			loginFaild = CurrentUser.IsEmpty();

		} while (loginFaild );
		
		CurrentUser.RegisterLogin();

		clsMainScreen::ShowMainMenue();
		return true;
	}

public:

	static bool ShowLoginScreen()
	{
		
		system("cls");
		_DrawScreenHeader("\tLogin Screen");
		
		return _Login();
	}

	



};

