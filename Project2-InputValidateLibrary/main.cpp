#include<iostream>
#include"clsInputValidate.h"

using namespace std;



int main()
{
    cout << clsInputValidate::IsNumberBetween(5, 1, 10) << endl;
    cout << clsInputValidate::IsNumberBetween(5.5, 1.3, 10.8) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(8, 11, 2023),
        clsDate(8, 12, 2023)) << endl;

    cout << clsInputValidate::IsDateBetween(clsDate(),
        clsDate(1, 1, 2023),
        clsDate(8, 1, 2023)) << endl;

    cout << "\nPlease Enter a Number:\n";
    int x = clsInputValidate::ReadIntNumber("Invalid Number, Enter again:\n");
    cout << "x=" << x <<endl;

    int y = clsInputValidate::ReadIntNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "y=" << y << endl;

    cout << "\nPlease Enter a Double Number:\n";
    double a = clsInputValidate::ReadDblNumber("Invalid Number, Enter again:\n");
    cout << "a=" << a << endl;

    double b = clsInputValidate::ReadDblNumberBetween(1, 5, "Number is not within range, enter again:\n");
    cout << "b=" << b << endl;

    cout << endl << clsInputValidate::IsValidDate(clsDate(35, 12, 2022)) << endl;


	system("pause>0");
}