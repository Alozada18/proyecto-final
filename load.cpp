#include <iostream>
#include <fstream>
#include "Movies.h" 
#include <iomanip>
#include "Filename.h"
#include <sstream>


using namespace std;

void loadData(Movies movie[], string filename) {
	ifstream all;
	int i = 0;


	all.open(filename);

	if (all.fail()) 
	{
		cout << "Could not open file" << endl;
		all.close();
		return;


	}

	string title, actor;
	int id, year;

	while (true) 
	{
		std::string line;
		std::getline(all, line);
		if (!all) break;
		std::istringstream iline(line);
		std::string id;
		std::getline(iline, id, '|');
		std::string title;
		std::getline(iline, title, '|');
		std::string year;
		std::getline(iline, year, '|');
		std::string rating;
		std::getline(iline, rating, '|');
		std::string actor;
		std::getline(iline, actor, '|');
		if (!all) break;
		movie[i].title = title;
		movie[i].id = stoi(id);
		movie[i].year = stoi(year);
		movie[i].rating = rating;
		movie[i].actor = actor;
		movie[i].isfull = true;

		i++;


	}


	return;


}

