#include <iostream>
#include <iomanip>
#include "Input.h"
#include <string>
#include <conio.h>
#include "Movies.h"
#include "Operations.h"
#include "Filename.h"

using namespace std;


int main()
{
	int option;
	bool done = false;

	Movies movie[SIZE];

	initmovies(movie);
	loadmoviesfromtitle(movie, false);
	loadData(movie, "movies.txt");



	while (!done)
	{
		system("cls");
		cout << " MY MOVIES APPLICATION" << endl;
		cout << " --------------------------" << endl;
		cout << " 1. Display movies" << endl;
		cout << " 2. Display a movie" << endl;
		cout << " 3. Add a movie" << endl;
		cout << " 4. Delete a movie" << endl;
		cout << " 5. Find movies by title" << endl;
		cout << " 6. Find movies by actor" << endl;
		cout << " 7. Save movies to file" << endl;
		cout << " 8. Load movies from title" << endl;
		cout << " 9. Exit application" << endl;
		cout << " --------------------------" << endl;
		cout << " Enter option number: ";

		option = getOptionFromUser();

		switch (option)
		{

		case 1:
			displaymovies(movie);
			pressAnyKey("");
			break;


		case 2:
			displayamovie(movie);
			pressAnyKey("");
			break;

		case 3:
			addingamovie(movie);
			pressAnyKey("");
			break;
		case 4:
			deleteamovie(movie);
			pressAnyKey("");
			break;
		case 5:
			findmoviesbytitle(movie);
			pressAnyKey("");
			break;

		case 6:
			findmoviesbyactor(movie);
			pressAnyKey("");
			break;

		case 7:
			savemoviestofile(movie);
			pressAnyKey("");
			break;

		case 8:
			loadmoviesfromtitle(movie, true);
			pressAnyKey("");
			break;

		case 9:
			done = true;
			break;

		default:
			pressAnyKey("Invalid option!");
			break;
		}
	}


}
