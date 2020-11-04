#ifndef _MOVIES_M_
#define _MOVIES_M_

#include <string>
#include <vector>
#include "Movie.h"
using namespace std;

class Movies {
private:
    vector <Movie> movies;

public:
    Movies();
    ~Movies();
    
    bool addMovies(string name, string rating, int watched);
    
    bool incrementWatched(string name);
    
    void display() const;
    
    
    
};
#endif // _MOVIES_M_
