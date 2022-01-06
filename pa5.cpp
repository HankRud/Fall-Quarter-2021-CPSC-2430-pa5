//HArry Rudolph
//pa5.cpp

#include "hash.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

int posLongValidator();
int posIntValidatorFive();

int main(){

    HashTable * table = new HashTable();
    long testVal= 112312;

    //TEST BLOCK 1

    cout<<"The following are tests beginning with an empty Table"<<endl<<endl;
    
    //Attempt to remove from empty table
    cout<<"Attempting to remove from empty Table (prints 'Movie not in playlist') "<<endl;
    table->removeMovie(testVal);
    cout<<endl;
    //Attempt to display movie not in table
    cout<<"Attempting to display from empty Table (prints 'Movie not in playlist') "<<endl;
    table->displayMovie(testVal);
    cout<<endl<<endl;
    //Attempt to display all movies
    cout<<"Attempting to print all movies from empty Table (prints nothing) "<<endl;
    table->displayAll();
    cout<<endl;
    //Attempt to display all movies of a genre
    cout<<"Attempting to display Action movies (prints noting) "<<endl;
    table->displayGenre("Action");
    cout<<endl<<endl;

    //Attempt to watch movie not in 
    cout<<"Attempt to watch movie from empty table (nothing should output))"<<endl;
    table->watchMovie(testVal);
    cout<<endl<<endl;

    //Now confirm adding works by adding then displaying movie
    cout<<"Add to playlist test and print movie info"<<endl;
    Movie test = Movie("New Movie","Action","Dr.Kong","Please give me a 100",testVal,2021,0);
    table->addToPlaylist(testVal, test);
    table->displayMovie(testVal);
    cout<<endl;

    //Now test search by genre
    cout<<"Search by genre test should display movie title and ID"<<endl;
    table->displayGenre("Action");
    cout<<endl<<endl;

    //Now attempt to add duplicate movie
    cout<<"Attempting to add duplicate movie (prints 'New Movie is already in your playlist') "<<endl;
    table->addToPlaylist(testVal,test);
    cout<<endl;

    //Now attempt to watch movie 
    cout<<"Attempt to watch movie (should print 'Watched New Movie. Increased watchCount to 1;"<<endl;
    table->watchMovie(testVal);
    cout<<endl;

    //Now print all
    cout<<"Printing all movies should (prints movie infor for just new movie)"<<endl;
    table->displayAll();

    //Now remove movie and test by trying to print
    cout<<"Removing and confirming removal by trying to print , should print removal confirmation then 'Movie not in playlist'" <<endl;
    table->removeMovie(testVal);
    cout<<endl;
    table->displayMovie(testVal);
    cout<<endl<<endl;
    
    
    




    fstream fin;
    fin.open("movies.csv");
   //string to read into
    string temp;
    string id;
    string ttle;
    string gnr;
    string releaseYear;
    string direc;
    string rating;
    string tgline;


    // readin header
    getline(fin,temp);
    
    while(fin.good()){
        //read into strings
        getline(fin,id,',');
        getline(fin,ttle,',');
        getline(fin,gnr,',');
        getline(fin,releaseYear,',');
        getline(fin,direc,',');
        getline(fin,rating,',');
        getline(fin,tgline,'\n');
        //convert id to long release year to int
        long key = stol(id);
        int yr= stoi(releaseYear);
        //instantiate the movie to add and add to table
        Movie addMov = Movie(ttle,gnr,direc,tgline,key,yr,0);
        table->addToPlaylist(key,addMov);
        
    }    


    cout<<"Welcome to my movie world! What would you like to do?" << endl;
    
    int state = -1;
    while (state != 0){
        
        
        cout<<"1. Browse all movies, 2. Browse by genre, 3. Watch a movie, "<<endl;
        cout<<"4. Get movie info, 5. Remove movie: "<<endl;
        state = posIntValidatorFive();

        if (state == 1 ){
            table->displayAll();
        }
        else if(state == 2){
            string searchGenre;
            cout<< "What genre are you looking for? ";
            cin.clear();
            cin.ignore(123,'\n');
            getline(cin,searchGenre);
            cout<<endl;
            table->displayGenre(searchGenre);
        }else if (state == 3){
            cout<< "Enter ID of the movie you want to watch: ";
            long key= posLongValidator();
            bool watched = table->watchMovie(key);
            if(!watched){
                cout<<"Movie not in playlist"<<endl<<endl;
            }
        }else if (state == 4){
            cout<< "Enter ID of the movie: ";
            long key= posLongValidator();
            table->displayMovie(key);
        }else if (state == 5){
            cout<< "Enter ID of the movie you want to Remove: ";
            long key= posLongValidator();
            table->removeMovie(key);
        }else{
            state = 0;
        }
        
        cout<< "*************************"<<endl;
    }

    cout<<"Hope you enjoyed the movies. Goodbye!"<<endl;
    return 0;


}

int posIntValidatorFive(){
    int toAdd;
    bool invalid = true;
    while(invalid){
    
        if ( !(cin>> toAdd)|| toAdd < 0 || toAdd > 5){
            cout << endl <<"Please enter a positive integer less than or equal to 5 (0 to end): ";
            cin.clear();
            cin.ignore(123,'\n');
            cout << endl;
        }
        else{
            invalid = false;
        }
        
    }
    return toAdd;
   
}

int posLongValidator(){
    long toAdd;
    bool invalid = true;
    while(invalid){
    
        if ( !(cin>> toAdd)|| toAdd < 0){
            cout << endl <<"Please enter a nonnegative long  ";
            cin.clear();
            cin.ignore(123,'\n');
            cout << endl;
        }
        else{
            invalid = false;
        }
        
    }
    return toAdd;
   
}

