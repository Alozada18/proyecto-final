#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <iostream>



using namespace std;

struct Movies 
{

	int id;
	string title;
	int year;
	string rating;
	string actor;
	bool isfull;
};


const int SIZE = 100;



#endif
