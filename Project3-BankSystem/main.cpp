#include <iostream>
#include "clsLoginScreen.h"
#include "clsCurrency.h"



int main()
{


	while(true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}

	}

	system("pause>0");
	return 0;
}