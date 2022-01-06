//Harry Rudolph
//PA5
//movie.h
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

class Movie{
    private:
    string title, genre, director, tagline; 
    long id; 
    int year, watchCount; 

    public:

    //parametrized constructor
    Movie(string title, string genre, string director, string tagline, long id, int year ,int watchCount);

    //copy cosntructor
    Movie(const Movie &other);

    //copy assignment
    Movie& operator = (const Movie & other);
    
    //displays idand title
    void displayIdTitle();

    //displays movie
    void displayMovie();

    //gets the movies genre
    string getGenre();

    //gets the title
    string getTitle();


    void setWatchCount(int count);

    int getWatchCount();

    
    
};