#include "Movies.h"


void initmovies(Movies movie[]);
void displaymovies(Movies movie[]);
void displayamovie(Movies movie[]);
void addingamovie(Movies movie[]);
void deleteamovie(Movies movie[]);
void findmoviesbytitle(Movies movie[]);
void findmoviesbyactor(Movies movies[]);
void savemoviestofile(Movies movie[]);
void loadmoviesfromtitle(Movies movie[], bool success);
void loadData(Movies movie[], string filename);
