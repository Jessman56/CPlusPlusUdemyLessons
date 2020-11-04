#include <iostream>
#include "Movies.h"
using namespace std;

void incrementWatched(Movies &movies, string name);
void addMovie(Movies &movies, string name, string rating, int watched);





void incrementWatched(Movies &movies, string name){
    if (movies.incrementWatched(name)){
        cout << name << " has been incremented" << endl;
    }else {
        cout << name << " was not found!" << endl;
    }
}

void addMovie(Movies &movies, string name, string rating, int watched){
    if (movies.addMovies(name, rating, watched)){
        cout << name << " was added" << endl;
    }else {
        cout << name << " already existed!" << endl;
    }
}

int main(){
    Movies myMovies;
    
    myMovies.display();
    
    addMovie(myMovies, "Star Wars", "PG", 5);
    addMovie(myMovies, "Lord of the Rings", "PG-13", 8);
    addMovie(myMovies, "Pineapple Express", "R", 1000);


    myMovies.display();
    
    incrementWatched(myMovies, "Pineapple Express");
    
    myMovies.display();
    
    return 0;
}