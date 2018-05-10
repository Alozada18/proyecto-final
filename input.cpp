#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


void pressAnyKey(string message) 
{
	cout << endl << message << endl << endl;
	cout << "<Press any key to continue>";
	char c = _getch();
}


int getOptionFromUser()
{
	int inputValue;
	
	cin >> inputValue;

	if (cin.fail() == true)
	{
		cin.clear(); 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		return(-1);
	}
	else
	{
		cin.sync();
		return(inputValue);
	}
}
