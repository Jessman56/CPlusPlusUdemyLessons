#include <iostream>
#include "Movies.h"

using namespace std;

Movies::Movies(){
    
}
Movies::~Movies(){
    
}
    
bool Movies::addMovies(string name, string rating, int watched){
    for(const Movie &movie: movies){
        if (movie.getName() == name)
            return false;
    }
    Movie temp {name, rating, watched};
    movies.push_back(temp);
    return true;
}
    
bool Movies::incrementWatched(string name){
    for(Movie &movie: movies){
        if (movie.getName() == name){
            movie.incrementWatched();
            return true;
        }
    }
    return false;
    
}
    
void Movies::display() const{
    if(movies.size() == 0){
        cout << "Sorry, there are no movies to display" << endl;
    } else{
        cout << "\n---------------------------------------------" <<endl;
        for(const Movie &movie: movies){
        movie.display();
    }
        cout << "\n---------------------------------------------" <<endl;
    }
    
}

