#include<iostream>
using namespace std;

template <class T>

class clsCalculator
{
private:
	T _Number1, _Number2;
public:
	
	clsCalculator(T n1, T n2)
	{
		_Number1 = n1;
		_Number2 = n2;
	}


	void DisplayResults()
	{
		cout << _Number1 << " and " << _Number2 << " operations: \n";
		cout <<"addition: " << Add() << endl;
		cout <<"subtraction: " << Sub() << endl;
		cout << "Multiply: " << Mul() << endl;
		cout << "Division: " << Div() << endl;

	}

	T Add()
	{
		return _Number1 + _Number2;
	}
	T Sub()
	{
		return _Number1 - _Number2;
	}
	T Mul()
	{
		return _Number1 * _Number2;
	}
	T Div()
	{
		return _Number1 / _Number2;
	}


};


int main()
{
	clsCalculator<int>calculator(5, 2); 
	clsCalculator<float>calculator2(5.2, 3.2);

	calculator.DisplayResults();

	cout << "\n\n";

	calculator2.DisplayResults();

	system("pause>0");
}