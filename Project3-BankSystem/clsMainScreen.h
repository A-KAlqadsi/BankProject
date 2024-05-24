#pragma once
#include<iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionSceen.h"
#include "clsManageUsersScreen.h"
#include "clsRegisterLoginScreen.h"
#include "Globals.h"
#include "clsCurrencyMainScreen.h"
using namespace std;


class clsMainScreen: protected clsScreen 
{
private:
    enum enMainMenueOptions 
    {
        eListClients =1 ,eAddClient =2,eDeleteClient =3,
        eUpdateClient =4,eFindClient = 5,eTransactions =6,
        eManageUsers = 7, eRegisterLogin = 8, eCurrencyExchange = 9 ,eLogout = 10
    };

    static short _ReadMainMenueOption(short from,short to)
    {
        cout <<setw(37) << left << "" << "Choose what do you want to do[" << from << " - " << to << "]: ";
        return  clsInputValidate::ReadShortNumberBetween(from, to,"Enter Number between [1-10]: ");
    }

    static void _ShowAllClientsScreen()
    {
        //cout << "\nThis is show all clients screen\n";
        clsClientListScreen::ShowClientsList();
    }
    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientsScreen()
    {
        // cout << "\nThis is delete clients screen\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }
    static void _ShowUpdateClientsScreen()
    {
        //cout << "\nThis is update clients screen\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }
    static void _ShowTransactionsScreen()
    {
        // staps 
        //cout << "\nThis is transactions menue screen\n";
        clsTransactionsScreen::ShowTransactionsMenue();
    }
    static void _ShowManageUsersScreen()
    {
       // cout << "\nThis is manage users screen\n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }
    
    static void _ShowFindClientsScreen()
    {
        //cout << "\nThis is find clients screen\n";
        clsFindClientScreen::ShowFindClientScreen();

    }

    static void _GoBackToMainMenueScreen()
    {
        
        cout <<setw(37) << left << "" << "\n\tPress any key to back to main menue..";
        system("pause>0");
        ShowMainMenue();
        
    }
    static void _ShowRegisterLoginScreen()
    {
       // cout << "Register login screen will be here \n";
        clsRegisterLoginScreen::ShowRegisterUsersList();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        //cout << "Currency exchange screen will be here\n";
        clsCurrencyExchangeMainScreen::ShowCurrencyExchangeScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerformMainMenueOptions(enMainMenueOptions mainMenuOption)
    {
        switch (mainMenuOption)
        {
        case clsMainScreen::eListClients:
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eAddClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eDeleteClient:
            system("cls");
            _ShowDeleteClientsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eUpdateClient:
            system("cls");
            _ShowUpdateClientsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eFindClient:
            system("cls");
            _ShowFindClientsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eTransactions:
            system("cls");
            _ShowTransactionsScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::eManageUsers:
            system("cls");
            _ShowManageUsersScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::enMainMenueOptions::eRegisterLogin:
            system("cls");
            _ShowRegisterLoginScreen();
            _GoBackToMainMenueScreen();
            break;
        case clsMainScreen::enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenueScreen();
        case clsMainScreen::eLogout:
            system("cls");
            _Logout();
            break;
        default:
            break;
        }
    }

public :

	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Register Login.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        
        _PerformMainMenueOptions((enMainMenueOptions) _ReadMainMenueOption(1,10));
	}

};

