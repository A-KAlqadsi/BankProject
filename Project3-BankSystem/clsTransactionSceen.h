#pragma once
#include "clsMainScreen.h";
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h";
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalScreen.h"
#include "clsTransferScreen.h"
#include"clsTransferLogsScreen.h"
using namespace std;


class clsTransactionsScreen :protected clsScreen
{
private:

    enum enTransactionOptions {
        eDeposite = 1, eWithdraw = 2,
        eShowTotalBalance = 3,eTransfer = 4,eTransferLog = 5 ,eBackToMain = 6
    };

    static short _ReadTransactionOption(short from, short to)
    {
        cout << setw(37) << left << "" << "Choose what do you want to do[" << from << " - " << to << "]: ";
        return  clsInputValidate::ReadShortNumberBetween(from, to, "Enter Number between [1-6]: ");
    }

    static void _BackToTransactionsScreen()
    {
        cout << "\nPress any key to back to main menue...";
        system("pause>0");
        ShowTransactionsMenue();
    }
    static void _WithdrawOperation()
    {
        //cout << "\nHere will be the withdraw screen \n";
        clsWithdrawScreen::ShowWithdrawScreen();
    }
    static void _DepositeOperation()
    {
       // cout << "\nHere will be the Deposite screen \n";
        clsDepositScreen::ShowDepositScreen();
    }
    static void _TotalBalanceOperation()
    {
       // cout << "\nHere will be the Total balance screen \n";
        clsTotalScreen::ShowTotalBalancesScreen();

    }
    static void _TransferOperation()
    {
        //cout << "here will be transfer screen";
        clsTransferScreen::ShowTransferScreen();
    }
    static void _ShowTransferLogScreen()
    {
        //cout << "tranfer log screen will be here \n";
        clsTransferLogsScreen::ShowTransferLogsScreen();
    }
    static void _PerformTransactionsOptions(enTransactionOptions options)
    {
        switch (options)
        {
        case clsTransactionsScreen::eWithdraw:
            system("cls");
            _WithdrawOperation();
            _BackToTransactionsScreen();
            break;
        case clsTransactionsScreen::eDeposite:
            system("cls");
            _DepositeOperation();
            _BackToTransactionsScreen();
            break;
        case clsTransactionsScreen::eShowTotalBalance:
            system("cls");
            _TotalBalanceOperation();
            _BackToTransactionsScreen();
            break;
        case clsTransactionsScreen::enTransactionOptions::eTransfer:
            system("cls");
            _TransferOperation();
            _BackToTransactionsScreen();
        case clsTransactionsScreen::enTransactionOptions::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _BackToTransactionsScreen();
        case clsTransactionsScreen::eBackToMain:
        {
                // do nothing here the main screen will handle it
        }
        }

    }

public:

    static void ShowTransactionsMenue()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
        {
            return;
        }

        system("cls");
        _DrawScreenHeader("\t\tTransactions Screen");
        
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransactions Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Show Total balance.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[5] Back to main screen.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsOptions((enTransactionOptions)_ReadTransactionOption(1, 6));
    }

};


