#include "Operations.h"
#include <iomanip>
#include "Movies.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ostream>
#include "Input.h"


void initmovies(Movies movie[]) {
	for (int i = 0; i < SIZE; i++) {
		movie[i].isfull = false;
	}
}

void displaymovies(Movies movie[]) {
	bool success = false;
	system("cls");
	cout << setiosflags(ios::left);
	cout << " ID    TITLE                         ACTOR      YEAR" << endl;
	cout << " ----- --------------------------------------- -----" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		if (movie[i].isfull == true)
		{


			cout << " " << setw(4) << movie[i].id << "  " << setw(30) << movie[i].title << " " << setw(4) << movie[i].actor << "" << setw(6) << "  " << movie[i].year << endl;

			success = true;

		}
	}
	if (success == false)
	{
		cout << "No Movies" << endl;
	}
	cout << " ---------------------------------------------------";

}




void displayamovie(Movies movie[])
{
	int a;
	bool success = false;
	system("cls");
	cout << " DISPLAY A MOVIE" << endl;
	cout << " ---------------------------------------------------" << endl;
	cout << " Enter the movie id: ";
	a = getOptionFromUser();

	for (int i = 0; i < SIZE; i++)
	{
		if (a == movie[i].id)
		{ 
			cout << " ---------------------------------------------------" << endl;
			cout << " ID            : " << movie[i].id << endl;
			cout << " TITLE         : " << movie[i].title << endl;
			cout << " YEAR          : " << movie[i].year << endl;
			cout << " RATING        : " << movie[i].rating << endl;
			cout << " MAIN ACTOR    : " << movie[i].actor << endl;
			cout << "---------------------------------------------------" << endl << endl;
			success = true;
			break;
		}
	}
	if (success == false)
	{
		cout << " ---------------------------------------------------" << endl << endl;
		cout << " Did not find any movie with that id!" << endl << endl;
		cout << " ---------------------------------------------------" << endl;
	}
}

void addingamovie(Movies movie[]) 
{
	bool success = false;
	int ia;
	string ti;
	int i = 0;
	int y;
	string act;
	string r;
	system("cls");
	cout << " ADDING A MOVIE" << endl;
	cout << " ---------------------------------------------------" << endl;
	cout << " Enter Movie id          : ";
	cin >> ia;
	cout << " Enter title             : ";
	cin.ignore();
	getline(cin, ti);
	cout << " Enter year of release   : ";
	cin >> y;
	cout << " Enter rating            : ";
	cin >> r;
	cout << " Enter main actor        : ";
	cin >> act;

	for (int i = 0; i < SIZE; i++) 
	{

		if (ia == movie[i].id && movie[i].isfull == true)
		{
			cout << " ---------------------------------------------------" << endl << endl;
			cout << " The movie id " << movie[i].id << " already exists!" << endl << endl;
			cout << " ---------------------------------------------------" << endl;
			movie[i].isfull = true;
			success = true;
			break;

		}
		else {

			for (int i = 0; i < SIZE; i++)
			{
				if (movie[i].isfull == false) 
				{

					movie[i].id = ia;
					movie[i].title = ti;
					movie[i].year = y;
					movie[i].rating = r;
					movie[i].actor = act;
					cout << " ---------------------------------------------------" << endl << endl;
					cout << " " << ti << " was added successfully !" << endl << endl;
					cout << " ---------------------------------------------------" << endl;
					success = true;
					movie[i].isfull = true;
					break;


				}

			}
			break;
		}

	}



	if (success == false)
	{

		cout << " Your movie catalog is full!" << endl;
		cout << " ---------------------------------------------------" << endl;

	}
}




void deleteamovie(Movies movie[]) 
{
	int ig;
	bool success = false;
	system("cls");
	cout << " DELETING A MOVIE" << endl;
	cout << " ---------------------------------------------------" << endl;
	cout << " Enter movie id: ";
	cin >> ig;
	for (int i = 0; i < SIZE; i++) 
	{
		if (movie[i].isfull == true && movie[i].id == ig)
		{
			cout << " Deleating " << movie[i].title << "(" << movie[i].year << ")..." << endl;
			cout << " Done!" << endl << endl;
			cout << " ---------------------------------------------------" << endl;
			success = true;
			movie[i].isfull = false;
			break;
		}
	}


	if (success == false)
	{

		cout << " Did not find any movie with that id!" << endl;
		cout << " ---------------------------------------------------" << endl;

	}
}
void findmoviesbytitle(Movies movie[])
{
	system("cls");
	string ti;
	cout << setiosflags(ios::left);
	bool success = false;
	bool dplay = true;
	cout << " DISPLAY A MOVIE" << endl;
	cout << " ---------------------------------------------------" << endl;
	cout << " Enter title name: ";
	cin.ignore();
	getline(cin, ti);

	cout << setiosflags(ios::left);
	for (int i = 0; i < SIZE; i++) 
	{
		if (ti == movie[i].title) 
		{
			if (dplay == true) 
			{
				cout << " ---------------------------------------------------" << endl << endl;
				cout << " ID    TITLE                         ACTOR      YEAR" << endl;
				cout << " ----- --------------------------------------- -----" << endl;

				success = true;

				dplay = false;
			}
			cout << " " << setw(4) << movie[i].id << "  " << setw(30) << movie[i].title << " " << setw(4) << movie[i].actor << "" << setw(6) << "  " << movie[i].year << endl;

		}


	}

	cout << " ---------------------------------------------------" << endl;


	if (success == false)
	{

		cout << " Did not find any movie with that title!" << endl << endl;
		cout << " ---------------------------------------------------" << endl;
	}
}


void findmoviesbyactor(Movies movie[]) 
{
	system("cls");
	string act;
	bool success = false;
	bool dplay = true;
	cout << setiosflags(ios::left);
	cout << " DISPLAY A ACTOR" << endl;
	cout << " ---------------------------------------------------" << endl;
	cout << " Enter the actor's name: ";
	cin.ignore();
	getline(cin, act);

	cout << setiosflags(ios::left);
	for (int i = 0; i < SIZE; i++)
	{
		if (act == movie[i].actor) 
		{
			if (dplay == true)
			{
				cout << " ---------------------------------------------------" << endl << endl;
				cout << " ID    TITLE                         ACTOR      YEAR" << endl;
				cout << " ----- --------------------------------------- -----" << endl;
				dplay = false;

			}
			cout << " " << setw(4) << movie[i].id << "  " << setw(30) << movie[i].title << " " << setw(4) << movie[i].actor << "" << setw(6) << "  " << movie[i].year << endl;

			success = true;

		}

	}
	cout << " ---------------------------------------------------" << endl;

	if (success == false)
	{

		cout << " Did not find any movie associated with that actor!" << endl << endl;
		cout << " ---------------------------------------------------" << endl;
	}
}

void savemoviestofile(Movies movie[]) 
{
	ofstream ofs;

	system("cls");
	cout << " SAVING TO FILE" << endl;
	cout << " ---------------------------------------------------" << endl << endl;
	ofs.open("movies.txt");

	if (ofs.fail())
	{
		cout << " Could not save to file !" << endl;
		cout << " ---------------------------------------------------" << endl << endl;
	}

	else {

		for (int i = 0; i < SIZE; i++)
		{
			if (movie[i].isfull == true)
			{
				ofs << movie[i].id << "|" << movie[i].title << "|" << movie[i].year << "|"
					<< movie[i].rating << "|" << movie[i].actor << "|" << endl;
			}
		}
		cout << " Your movies were successfully saved !" << endl;
		cout << " ---------------------------------------------------" << endl << endl;

	}




}

void loadmoviesfromtitle(Movies movie[], bool success) 
{
	ifstream all;
	int i = 0;
	system("cls");

	cout << " LOADING FROM FILE" << endl;
	cout << " ---------------------------------------------------" << endl << endl;

	all.open("movies.txt");

	if (all.fail()) 
	{
		cout << "Could not load file!" << endl;
		cout << " ---------------------------------------------------" << endl << endl;
		all.close();
		return;
	}



	while (!all.eof())
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

	if (success == true) {
		cout << " Your movies were successfully loaded !" << endl;
		cout << " ---------------------------------------------------" << endl << endl;
	}


	return;


}
