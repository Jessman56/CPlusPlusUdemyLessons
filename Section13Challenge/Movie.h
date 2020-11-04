#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>
using namespace std;

class Movie {
private:
    string name;
    string rating;
    int watched;
public:
    Movie(string name, string rating, int watched);
    Movie(const Movie &source);
    ~Movie();
    
    void setName(string name) { this->name = name;}
    string getName() const {return name; }
    
    void setRating(string rating) { this->rating = rating;}
    string getRating() const {return rating; }
    
    void setWatched(int watched) { this->watched = watched;}
    int getWatched() const {return watched; }
    
    void incrementWatched(){ ++watched;}
    
    void display() const;
    
};

#endif // _MOVIE_H_
