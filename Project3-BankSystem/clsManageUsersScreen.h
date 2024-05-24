#pragma once
#include<iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
class clsManageUsersScreen : protected clsScreen
{
private:

	enum enManageUsersMenueOptions {
		eListUsre = 1, eAddNewUser = 2, eDeleteUser =3,
		eUpdateUser =4, eFindUser = 5, eMainMenue = 6
	};

	static short _ReadManageUsersMenueOption(short from ,short to)
	{
		
		cout << setw(37) << left << "" << "Choose what do you want to do[" << from << " - " << to << "]: ";
		return  clsInputValidate::ReadShortNumberBetween(from, to, "Enter Number between [1-6]: ");
		

	}
	
	static void _BackToManageUsersScreen()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to back to main menue..";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowListUsersScreen()
	{
		//cout << "list users screen will be here \n";
		clsListUsersScreen::ShowUsersList();
	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "Add new user screen will be here\n";
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "Delete user screen will be here\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "Update user screen will be here\n";
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	
	static void _ShowFindUserScreen()
	{
		//cout << "Find user screen will be here\n";

		clsFindUserScreen::ShowFindUserScreen();
		
	}
	
	static void _PerformManageUsersMenue(enManageUsersMenueOptions option)
	{

		switch (option)
		{
		case clsManageUsersScreen::eListUsre:
			system("cls");
			_ShowListUsersScreen();
			_BackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_BackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_BackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_BackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_BackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eMainMenue:
		{
			// here will be nothing 
		}
		
		}


	}


public:

	static void ShowManageUsersMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");
		
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Usres List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Usres.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Usres.\n";
		cout << setw(37) << left << "" << "\t[4] Update Usres.\n";
		cout << setw(37) << left << "" << "\t[5] Find Usres.\n";
		cout << setw(37) << left << "" << "\t[6] Back to Main Menue .\n";
		cout << setw(37) << left << "" << "======================================\n";

		_PerformManageUsersMenue((enManageUsersMenueOptions)_ReadManageUsersMenueOption(1, 6));

	}


};

