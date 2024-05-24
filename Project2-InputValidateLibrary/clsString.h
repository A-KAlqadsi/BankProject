#pragma once
#include<iostream>
#include<vector>
using namespace std;

class clsString
{
private:
	string _Value;

public:
	
	clsString()
	{
		_Value = "";
	}

	clsString(string value)
	{
		_Value = value;
	}

	void SetValue(string value)
	{
		_Value = value;
	}

	string GetValue()
	{
		return _Value;
	}

	_declspec(property(get = GetValue, put = SetValue)) string Value;

 	static void PrintFirstLetterInString(string Text)
	{

		bool isFirstLetter = true;

		cout << "\nFirst Letter of this String: \n";

		for (int i = 0; i < Text.length(); i++)
		{

			if (Text[i] != ' ' && isFirstLetter)
			{
				cout << Text[i] << endl;
			}
			isFirstLetter = (Text[i] == ' ' ? true : false);

		}

	}
	
	void PrintFirstLetterInString()
	{
		PrintFirstLetterInString(_Value);
	}

	static string UpperFirstLetterOfEachWord(string Text)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && isFirstLetter)
			{
				Text[i] = toupper(Text[i]);
			}
			isFirstLetter = (Text[i] == ' ' ? true : false);

		}
		return Text;

	}

	void  UpperFirstLetterOfEachWord()
	{
		_Value =  UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string Text)
	{
		bool isFirstLetter = true;

		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ' && isFirstLetter)
			{
				Text[i] = tolower(Text[i]);
			}
			isFirstLetter = (Text[i] == ' ' ? true : false);

		}

		return Text;
	}

	void LowerFirstLetterOfEachWord()
	{
		_Value =  LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllString(string Text)
	{

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = toupper(Text[i]);
		}
		return Text;
	}
	
	void UpperAllString()
	{
		_Value =  UpperAllString(_Value);
	}

	static string LowerAllString(string Text)
	{

		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = tolower(Text[i]);
		}

		return Text;
	}
	
	void LowerAllString()
	{
		_Value =  LowerAllString(_Value);
	}

	static char InvertLetterCase(char char1)
	{
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}
	
	static string InvertAllLettersCase(string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = InvertLetterCase(Text[i]);
		}
		return Text;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountCapitalLetters(string Text)
	{
		short Counter = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (isupper(Text[i]))
				Counter++;

		}

		return Counter;
	}
	
	short CountCapitalLetters()
	{
		return CountCapitalLetters(_Value);
	}

	static short Length(string text)
	{
		return text.length();
	}

	short Length()
	{
		return _Value.length();
	} 

	static short CountSmallLetters(string Text)
	{
		short Counter = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (islower(Text[i]))
				Counter++;
		}
		return Counter;
	}

	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	enum enWhatToCount { SmallLetters = 1, CapitalLetters = 2, Punct = 3, All = 4 };
	
	static short CountLetters(string Text, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		short Counter = 0;

		if (WhatToCount == enWhatToCount::All)
			return Text.length();


		for (int i = 0; i < Text.length(); i++)
		{
			if (isupper(Text[i]) && WhatToCount == enWhatToCount::CapitalLetters)
				Counter++;

			if (islower(Text[i]) && WhatToCount == enWhatToCount::SmallLetters)
				Counter++;

			if (ispunct(Text[i]) && WhatToCount == enWhatToCount::Punct)
				Counter++;

		}

		return Counter;
	}

	static short CountLetterInString(string Text, char CharCount)
	{
		short Counter = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (Text[i] == CharCount)
				Counter++;
		}
		return Counter;
	}
	
	short CountLetterInString(char CharCount)
	{
		return CountLetterInString(_Value, CharCount);
	}

	static short CountSpecificLetter(string Text, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (MatchCase) {
				if (Text[i] == Letter)
					Counter++;
			}
			else
			{
				if (tolower(Text[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}

	short CountSpecificLetter( char CharCount, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, CharCount,MatchCase);
	}

	static bool IsVowel(char Letter)
	{
		Letter = tolower(Letter);
		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i')
			|| (Letter == 'o') || (Letter == 'u'));
	}

	static short CountVowels(string Text)
	{
		short Counter = 0;
		for (int i = 0; i < Text.length(); i++)
		{
			if (IsVowel(Text[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}

	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintAllVowelsInString(string Text)
	{
		cout << "Vowels in string are: ";
		for (int i = 0; i < Text.length(); i++)
		{
			if (IsVowel(Text[i]))
			{
				cout << Text[i] << "   ";
			}
		}
	}

	void PrintAllVowelsInString()
	{
		PrintAllVowelsInString(_Value);
	}

	static void PrintEachWordInString(string Text)
	{
		string delim = " ";
		short pos = 0;
		string sWord;

		cout << "\nYour String Words Are\n\n";
		while ((pos = Text.find(delim)) != std::string::npos)
		{
			sWord = Text.substr(0, pos);
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			Text.erase(0, pos + delim.length());

		}
		if (Text != "")
		{
			cout << Text << endl;
		}

	}

	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static short CountWords(string Text)
	{
		string delim = " ";
		short pos = 0;
		short Counter = 0;
		string sWord;

		while ((pos = Text.find(delim)) != std::string::npos)
		{
			sWord = Text.substr(0, pos);
			if (sWord != "")
			{
				Counter++;
			}
			Text.erase(0, pos + delim.length());

		}

		if (Text != "")
		{
			Counter++;
		}
		return Counter;

	}

	short CountWords()
	{
		return CountWords(_Value);
	}

	static vector<string> Split(string Text, string delimiter)
	{
		vector<string> vString;
		short pos = 0;
		string sWord;
		while ((pos = Text.find(delimiter)) != std::string::npos)
		{
			sWord = Text.substr(0, pos);
			if (sWord != "")
			{
				vString.push_back(sWord);
			}

			Text.erase(0, pos + delimiter.length());

		}
		if (Text != "")
		{
			vString.push_back(Text);
		}
		return vString;

	}

	vector<string> Split( string delimiter)
	{
		return Split(_Value, delimiter);
 	}

	static string JoinString(vector<string>vString, string delimiter)
	{
		string sWord;
		for (string& s : vString)
		{
			sWord = sWord + s + delimiter;
		}

		return sWord.substr(0, sWord.length() - delimiter.length());
	}
	
	static string JoinString(string arrString[], short length, string delim)
	{
		string sWord = "";
		for (int i = 0; i < length; i++)
		{
			sWord = sWord + arrString[i] + delim;
		}

		return sWord.substr(0, sWord.length() - delim.length());

	}

	static string TrimLeft(string Text)
	{
		for (short i = 0; i < Text.length(); i++)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(i, Text.length() - i);
			}
		}
		return "";
	}
	
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string Text)
	{
		for (short i = Text.length() - 1; i >= 0; i--)
		{
			if (Text[i] != ' ')
			{
				return Text.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string Text)
	{
		return TrimLeft(TrimRight(Text));
	}

	void Trim()
	{
		_Value =  Trim(_Value);
	}

	static string ReverseWordsInString(string S1)
	{
		vector <string> vString;
		vString = Split(S1, " ");
		string sWord = "";
		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin())
		{
			iter--;
			sWord += *iter + " ";
		}
		sWord = sWord.substr(0, sWord.length() - 1);

		return sWord;
	}

	void ReverseWordsInString()
	{
		_Value = ReverseWordsInString(_Value);
	}

	static string ReplaceWord(string Text, string strToReplace, string strReplaceTo)
	{
		short pos = Text.find(strToReplace);

		while (pos != std::string::npos)
		{
			Text = Text.replace(pos, strToReplace.length(), strReplaceTo);
			pos = Text.find(strToReplace); // find next word
		}

		return Text;

	}

	string ReplaceWord(string strToReplace, string strReplaceTo)
	{
		return ReplaceWord(_Value, strToReplace, strReplaceTo);
	}

	static string RemovePunctuations(string Text)
	{
		string Text2 = "";
		for (int i = 0; i < Text.length(); i++)
		{
			if (!ispunct(Text[i]))
			{
				Text2 += Text[i];
			}
		}

		return Text2;
	}

	void RemovePunctuations()
	{
		_Value =  RemovePunctuations(_Value);
	}


};

