//Harry Rudolph
//hash.h

#include <iostream>
#include "movie.h"
using namespace std;

struct MovieNode
{
    long key;

    Movie value;

    MovieNode *next;

    MovieNode(long key, Movie value) : key(key), value(value)
    {
        next = nullptr;
    }
};

class HashTable
{
private:
    /* data */
    MovieNode **playlist;

    int tableSize;

    //helper hashing function
    int hashVal(long key);

public:
    //default constructor
    HashTable(/* args */);

    //desturtror
    ~HashTable();

    // add the key-value pair to the table. If the
    //key exists, print a message that the movie is already in your playlist
    void addToPlaylist(long key, Movie value);

    //If the movie is not in the playlist, return false. Else print
    //that you have watched [movie name] and increase the watchCount.
    bool watchMovie(long key);

    //remove the movie from the playlist, if it exits, else print a message that it isn't in the playlist
    void removeMovie(long key);

    //If the key exists, display information about the movie as
    //shown in the execution example. Else, tell the user that the movie is not in the playlist.
    void displayMovie(long key);

    //displays the title and the id of all the movies in the playlist.
    void displayAll();

    //displays the title and the id of all the movies in the genre.
    void displayGenre(string genre);
};
