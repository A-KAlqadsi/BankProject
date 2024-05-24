#include<iostream>
using namespace std;



template<typename T> T myMax(T number1, T number2)
{
	return (number1 > number1) ? number1 : number2;
}


int main()
{

	cout << myMax<int>(3, 7) << endl;
	cout << myMax<double>(4.5, 8.4) << endl;
	cout << myMax<char>('a', 'f') << endl;



	system("pause>0");
	return 0;
}