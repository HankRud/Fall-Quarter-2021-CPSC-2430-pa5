//Harry Rudolph
//hash.cpp

#include "hash.h"
using namespace std;
//default constructor
HashTable::HashTable()
{
    tableSize = 7;
    playlist = new MovieNode* [tableSize];
}

//destructror
HashTable::~HashTable()
{
    delete[] playlist;
}

// add the key-value pair to the table. If the
//key exists, print a message that the movie is already in your playlist
void HashTable::addToPlaylist(long key, Movie value)
{
    int hashIndex = hashVal(key);
    MovieNode *toAdd = new MovieNode(key, value);
    if (playlist[hashIndex] == nullptr)
    {
        playlist[hashIndex] = toAdd;
    }
    else
    {
        
        MovieNode *curr = playlist[hashIndex];
        while (curr->next != nullptr && curr->key != key)
        {
            curr = curr->next;
        }
        if (curr->key == key)
        {
            cout << curr->value.getTitle() << " is already in your playlist." << endl;
            return;
        }
        else
        {
            curr->next = toAdd;
        }
    }
}

//If the movie is not in the playlist, return false. Else print
//that you have watched [movie name] and increase the watchCount.
bool HashTable::watchMovie(long key)
{
    int hashIndex = hashVal(key);
    MovieNode *curr = playlist[hashIndex];
    while (curr!= nullptr)
    {
        if (curr->key == key)
        {
            int cnt = curr->value.getWatchCount();
            cnt++;
            curr->value.setWatchCount(cnt);
            cout<<"Watched "<<curr->value.getTitle()<<". "<<"Increased watchCount to "<< cnt << endl;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

//remove the movie from the playlist, if it exits, else print a message that it isn't in the playlist
void HashTable::removeMovie(long key)
{
    int hashIndex = hashVal(key);
    MovieNode *curr = playlist[hashIndex];
    MovieNode *tmp = nullptr;

    if(curr != nullptr && curr->key == key){
        playlist[hashIndex]= curr->next;
        cout << "Removing " << curr->value.getTitle() << " from the playlist" << endl;
        delete curr;
        return;
    }else{

        while (curr != nullptr && curr->key != key)
        {
            tmp = curr;
            curr = curr->next;
        }
        if(curr == nullptr){
            cout << "Movie not in playlist ," << endl;
            return;
        }
        tmp->next = curr->next;
        delete curr;
    
    }
}

//If the key exists, display information about the movie as
//shown in the execution example. Else, tell the user that the movie is not in the playlist.
void HashTable::displayMovie(long key)
{
    int hashIndex = hashVal(key);
    MovieNode *curr = playlist[hashIndex];
    while (curr != nullptr)
    {
        if (curr->key == key)
        {
            curr->value.displayMovie();
            return;
        }
        curr = curr->next;
    }
    cout << "Movie not in playlist" << endl;
}

//displays the title and the id of all the movies in the playlist.
void HashTable::displayAll()
{
    for (int index = 0; index < tableSize; index++)
    {   
            MovieNode *curr = playlist[index];
            
                while (curr != nullptr )
                {
                    curr->value.displayIdTitle();
                    cout << endl;
                    curr = curr->next;
                }
            
    }
}

//displays the title and the id of all the movies in the genre.
void HashTable::displayGenre(string genre)
{
    for (int index = 0; index < tableSize; index++)
    {
        MovieNode *curr = playlist[index];
        while (curr != nullptr)
        {
            if (curr->value.getGenre() == genre)
            {
                curr->value.displayIdTitle();
                cout << endl;
            }
            curr = curr->next;
        }
    }
}

int HashTable::hashVal(long key)
{
    int toReturn = key % tableSize;
    return toReturn;
}
