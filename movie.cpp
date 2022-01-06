//Harry Rudolph
//movie.cpp

#include "movie.h"
#include <string>
using namespace std;

//parametrized constructor
Movie::Movie(string title, string genre, string director, string tagline, long id, int year, int watchCount) : title(title), genre(genre), director(director), id(id), year(year), watchCount(watchCount)
{
}

//copy cosntructor
Movie::Movie(const Movie &other)
{
    title = other.title;
    genre = other.genre;
    director = other.director;
    tagline = other.tagline;
    id = other.id;
    year = other.year;
    watchCount = other.watchCount;
}

//copy assignment
Movie &Movie ::operator=(const Movie &other)
{
    if (&other != this)
    {
        title = other.title;
        genre = other.genre;
        director = other.director;
        tagline = other.tagline;
        id = other.id;
        year = other.year;
        watchCount = other.watchCount;
    }
    return *this;
}

void Movie::displayIdTitle()
{
    cout << "IMDB id: " << id << endl;
    cout << "Title: " << title << endl;
}

void Movie::displayMovie()
{
    displayIdTitle();
    cout << "Director: " << director << endl;
    cout << "Genre: " << genre << endl;
    cout << "Tagline: " << tagline << endl;
    cout << "Year: " << year << endl;
    cout << "You've watched it " << watchCount << " time(s)." << endl;
}

string Movie:: getGenre(){
    return genre;
}

string Movie:: getTitle(){
    return title;
}

void Movie:: setWatchCount(int count){
    watchCount = count;
}

int Movie:: getWatchCount(){
    return watchCount;
}