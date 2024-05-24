#pragma once
#include<iostream>
#include"clsPerson.h"
#include "clsString.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;
string ClientsFileName = "Clients.txt";
string TransferFileName = "TransferInfo.txt";

class clsBankClient : public clsPerson
{

private:
	
	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string line, string seperator = "#//#")
	{
		vector<string> vClient = clsString::Split(line, seperator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2],
			vClient[3], vClient[4], vClient[5], stof(vClient[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> _vClientsData;


		fstream myFile;
		myFile.open(ClientsFileName, ios::in);

		if (myFile.is_open())
		{
			string lineData;
			while (getline(myFile, lineData))
			{
				clsBankClient Client = _ConvertLineToClientObject(lineData);
				_vClientsData.push_back(Client);

			}

		}
		myFile.close();
		return _vClientsData;
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string separator = "#//#")
	{
		string lineData = "";
		lineData = Client.FirstName + separator;
		lineData += Client.LastName + separator;
		lineData += Client.Email + separator;
		lineData += Client.Phone + separator;
		lineData += Client.AccountNumber() + separator;
		lineData += Client.PinCode + separator;
		lineData += to_string(Client.AccountBalance);

		return lineData;
	}

	static void _SaveClientDataToFile(vector<clsBankClient> vClients)
	{
		fstream myFile;
		myFile.open(ClientsFileName, ios::out); // overwrite
		if (myFile.is_open())
		{

			for (clsBankClient C : vClients)
			{
				if (C._MarkedForDelete == false) 
				{
					string line = _ConvertClientObjectToLine(C);
					myFile << line << endl;
				}

			}
			myFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string line)
	{
		fstream myFile;
		myFile.open(ClientsFileName, ios::app);// append the data to the end of the file
		if (myFile.is_open())
		{
			myFile << line << endl;
		}
		myFile.close();
	}

	string PrepareTransferInfo(clsBankClient DestinationClient, double Amount,string UserName, string seperator = "#//#")
	{
		string lineData = "";
		lineData += clsDate::GetSystemDateTimeString() + seperator;
		lineData += AccountNumber() + seperator;
		lineData += DestinationClient.AccountNumber() + seperator;
		lineData += to_string(Amount) + seperator;
		lineData += to_string(AccountBalance) + seperator;
		lineData += to_string(DestinationClient.AccountBalance) + seperator;
		lineData += UserName;
		return lineData;
	}

	void _RegisterTransferLog(clsBankClient DestinationClient, double Amount, string UserName)
	{
		string TransferData = PrepareTransferInfo(DestinationClient, Amount, UserName);
		fstream myFile;
		myFile.open(TransferFileName, ios::app);
		if (myFile.is_open())
		{
			myFile << TransferData << endl;
			myFile.close();
		}
	}
    
	struct stTransferLog;

	static stTransferLog _ConvertTransferLogLineToRecord(string line, string seperator = "#//#")
	{
		stTransferLog transferLog;
		vector<string >vTransferLog = clsString::Split(line, seperator);
		transferLog.Date = vTransferLog[0];
		transferLog.SourceAccount = vTransferLog[1];
		transferLog.DestinationAccount = vTransferLog[2];
		transferLog.Amount = stod(vTransferLog[3]);
		transferLog.SourceBalance = stod(vTransferLog[4]);
		transferLog.DestinationBalance = stod(vTransferLog[5]);
		transferLog.User = vTransferLog[6];
		return transferLog;
	}
	
	static vector<stTransferLog> _LoadTransferLogDataFromFile()
	{
		fstream myFile;
		vector<stTransferLog> vTransferLogs;
		myFile.open(TransferFileName, ios::in);
		if (myFile.is_open())
		{
			string lineData;
			while (getline(myFile,lineData))
			{
				stTransferLog transferLog = _ConvertTransferLogLineToRecord(lineData);
				vTransferLogs.push_back(transferLog);
			}
		}
		myFile.close();
		return vTransferLogs;
	}

public:

	struct stTransferLog
	{
		string Date;
		string SourceAccount;
		string DestinationAccount;
		double Amount;
		double SourceBalance;
		double DestinationBalance;
		string User;
	};

	clsBankClient(enMode mode , string firstName , string lastName,
		string email,string phone ,string accountNumber, string pinCode,
		float accountBalance):clsPerson(firstName,lastName,email,phone)
	{
		_Mode = mode;
		_AccountNumber = accountNumber;
		PinCode = pinCode;
		AccountBalance = accountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string pinCode)
	{
		_PinCode = pinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float balance)
	{
		_AccountBalance = balance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	string FullName()
	{
		return FirstName + " " + LastName;
	}

	static clsBankClient Find(string accountNumber)
	{
		fstream myFile;
		myFile.open(ClientsFileName, ios::in); // read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile,line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);
				if (client.AccountNumber() == accountNumber)
				{
					myFile.close();
					return client;
				}
				
			}
			myFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string accountNumber, string pinCode)
	{
		fstream myFile;
		myFile.open(ClientsFileName, ios::in);// read mode

		if (myFile.is_open())
		{			
			string line;
			while (getline(myFile,line))
			{
				clsBankClient client = _ConvertLineToClientObject(line);

				if (client.AccountNumber() == accountNumber && client.PinCode == pinCode)
				{
					myFile.close();
					return client;
				}

			}
			myFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string accountNumber)
	{
		clsBankClient client = Find(accountNumber);
		
		return (!client.IsEmpty());

	}

	enum enSaveResults { svFaildEmptyObject =0, svSucceeded = 1,svFailedAccountNumberExists = 2 };

	enSaveResults Save() 
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			
			return enSaveResults::svFaildEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
		case enMode::AddNewMode:
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFailedAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;

				return enSaveResults::svSucceeded;
			}

			
		}

		
	}

	static clsBankClient GetAddNewClientObject(string accountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", accountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		
		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveClientDataToFile(_vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	bool Deposit(double amount)
	{
		if (amount < 0)
		{
			return false;
		}
		else 
		{
			_AccountBalance += amount;
			Save();
		}
		
	}
	
	bool Withdraw(double amount)
	{
		if (amount > AccountBalance || amount <0)
		{
			return false;
		}
		else
		{
			_AccountBalance -= amount;
			Save();
		}
		
	}

	bool Transfer(double Amount , clsBankClient& DestinationClient)
	{
		if (Amount > AccountBalance || Amount < 0)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(DestinationClient, Amount, CurrentUser.UserName);
		return true;
	}

	static double GetTotalBalance()
	{
		vector<clsBankClient> vClients = GetClientsList();
		double totalBalance = 0;
		for (clsBankClient Client : vClients)
		{
			totalBalance += Client.AccountBalance;
		}

		return totalBalance;
	}

	static vector<stTransferLog> GetTransferLogList()
	{
		return _LoadTransferLogDataFromFile();
	}
	

};