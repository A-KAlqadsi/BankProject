#pragma once
#include<iostream>
#include"clsPerson.h"
#include "clsString.h"
#include <vector>
#include <string>
#include <fstream>
#include "clsDate.h"
#include "clsUtil.h"
string UsersFileName = "Users.txt";
string LoginRegisterFile = "LoginRegister.txt";
class clsUser :public clsPerson
{

private:

	enum enMode {eEmptyMode = 0,eUpdateMode =1,eAddNewMode =2};
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkedForDelete = false;
	
	static clsUser _ConvertLineToUserObject(string line, string seperator = "#//#")
	{
		vector <string> vUsers = clsString::Split(line, seperator);

		return clsUser(enMode::eUpdateMode, vUsers[0], vUsers[1], vUsers[2], vUsers[3], vUsers[4],
			clsUtil::DecryptText(vUsers[5]), stoi(vUsers[6]));
	}

	string _PrepareLoginInRecord(string seperator = "#//#")
	{
		string DataLine = "";
		DataLine += clsDate::GetSystemDateTimeString() + seperator;
		DataLine += UserName + seperator;
		DataLine +=clsUtil::EncryptText(Password) + seperator;
		DataLine += to_string(Permissions);
		return DataLine;
	}

	static string _ConvertUserObjectToLine(clsUser User, string seperator = "#//#")
	{
		string lineData ="";
		lineData = User.FirstName + seperator;
		lineData += User.LastName + seperator;
		lineData += User.Email + seperator;
		lineData += User.Phone + seperator;
		lineData += User.UserName + seperator;
		lineData +=clsUtil::EncryptText(User.Password)+ seperator;
		lineData += to_string(User.Permissions);

		return lineData;
	}
	static void _SaveUsersDataToFile(vector<clsUser> vClients)
	{
		fstream myFile;
		myFile.open(UsersFileName, ios::out); // overwrite
		if (myFile.is_open())
		{

			for (clsUser C : vClients)
			{
				if (C._MarkedForDelete == false)
				{
					string line = _ConvertUserObjectToLine(C);
					myFile << line << endl;
				}

			}
			myFile.close();
		}
	}
	
	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector <clsUser> _vUsers;


		fstream myFile;
		myFile.open(UsersFileName, ios::in);

		if (myFile.is_open())
		{
			string lineData;
			while (getline(myFile, lineData))
			{
				clsUser User = _ConvertLineToUserObject(lineData);
				_vUsers.push_back(User);

			}

		}
		myFile.close();
		return _vUsers;
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _AddDataLineToFile(string line)
	{
		fstream myFile;
		myFile.open(UsersFileName, ios::app);// append the data to the end of the file
		if (myFile.is_open())
		{
			myFile << line << endl;
		}
		myFile.close();
	}

	void _Update()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();
		for (clsUser& C : _vUsers)
		{
			if (C.UserName == UserName)
			{
				C = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}

	struct stLoginRegister ;

	static stLoginRegister _ConvertLoginRegisterUserToRecordObject(string line, string seperator = "#//#")
	{
		vector<string> vLoginUsers = clsString::Split(line, seperator);
		stLoginRegister LoginRegister;
		LoginRegister.RegisterDate = vLoginUsers[0];
		LoginRegister.UserName = vLoginUsers[1];
		LoginRegister.Password = clsUtil::DecryptText(vLoginUsers[2]);
		LoginRegister.Permissions = stoi(vLoginUsers[3]);

		return LoginRegister;

	}

	static vector<stLoginRegister> _LoadLoginUsersDataFromFile()
	{
		vector<stLoginRegister> _vLoginUsers;

		fstream myFile;
		myFile.open(LoginRegisterFile, ios::in);

		if (myFile.is_open())
		{
			string lineData;
			while (getline(myFile, lineData))
			{
				stLoginRegister LoginUser = _ConvertLoginRegisterUserToRecordObject(lineData);
				_vLoginUsers.push_back(LoginUser);
			}
		}

		myFile.close();
		return _vLoginUsers;

	}


public:

	enum enPermissions 
	{
		eAll = -1 , pListClients = 1 , pAddNewClient = 2,pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64,pRegisterLogin =128
	};

	struct stLoginRegister
	{
		string RegisterDate;
		string UserName;
		string Password;
		int Permissions;
	};

	clsUser(enMode mode, string firstName, string lastName, string email,string phone,
	string username, string password ,int permissions) : clsPerson(firstName, lastName, email, phone)
	{
		_Mode = mode;
		UserName = username;
		Password = password;
		Permissions = permissions;
		
	}
	
	void SetUserName(string username)
	{
		_UserName = username;
	}
	
	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string password)
	{
		_Password = password;
	}
	string GetPassword()
	{
		return _Password;
	}

	__declspec (property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int permissions)
	{
		_Permissions = permissions;
	}

	int GetPermissions()
	{
		return _Permissions;
	}

	__declspec (property(get = GetPermissions, put = SetPermissions)) int Permissions;

	bool MarkedForDeleted()
	{
		return _MarkedForDelete;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}
	
	string FullName()
	{
		return FirstName + " " + LastName;
	}

	static clsUser Find(string userName)
	{
		fstream myFile;
		myFile.open(UsersFileName, ios::in); // read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsUser user = _ConvertLineToUserObject(line);
				if (user.UserName == userName)
				{
					myFile.close();
					return user;
				}

			}
			myFile.close();
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string userName,string password)
	{
		fstream myFile;
		myFile.open(UsersFileName, ios::in); // read mode

		if (myFile.is_open())
		{
			string line;
			while (getline(myFile, line))
			{
				clsUser user = _ConvertLineToUserObject(line);
				if (user.UserName == userName && user.Password == password)
				{
					myFile.close();
					return user;
				}

			}
			myFile.close();
		}
		return _GetEmptyUserObject();
	}

	static bool IsUserExist(string userName)
	{
		clsUser user = Find(userName);

		return (!user.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFailedUserNameExists = 2 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::eEmptyMode:

			return enSaveResults::svFaildEmptyObject;

		case enMode::eUpdateMode:
			_Update();
			return enSaveResults::svSucceeded;
		case enMode::eAddNewMode:
			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResults::svFailedUserNameExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::eUpdateMode;

				return enSaveResults::svSucceeded;
			}


		}


	}

	static clsUser GetAddNewUserObject(string userName)
	{
		return clsUser(enMode::eAddNewMode, "", "", "", "", userName, "", 0);
	}

	bool Delete()
	{
		vector <clsUser> _vUsers;
		_vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}

		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();

		return true;
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CheckAccessPermission(enPermissions permission)
	{
		if (this->Permissions == enPermissions::eAll)
			return true;

		if ((permission & this->Permissions) == permission)
			return true;
		else
			return false;

	}
	
	static vector<stLoginRegister> GetLoginUsersList()
	{
		
		return _LoadLoginUsersDataFromFile();
	}

	void RegisterLogin()
	{
		string DataLine =_PrepareLoginInRecord();

		fstream myFile;
		myFile.open(LoginRegisterFile, ios::app);
		if (myFile.is_open())
		{
			myFile << DataLine << endl;
		}
		myFile.close();

	}
};

