#include <iostream>
#include <string>

using namespace std;

int main(){
    string pyramid{};
    cout << "Enter what you would like to make a pyramid" << endl;
    getline(cin, pyramid);
    string pyramidRev{pyramid};
    int len = pyramidRev.length() - 1;

    for (size_t i {0}; i < (pyramidRev.length() / 2); ++i) {
        swap(pyramidRev.at(i), pyramidRev.at(len));
        len--;
    }
    
    for (size_t i {0}, j {pyramid.length()}; i < pyramid.length(); ++i, --j){
        string space (j, ' ');
        
        if(i == 0 && j == pyramid.length()) {
            cout << space << pyramid.at(i) << endl;
        } else {
            cout << space << pyramid.substr(0,i+1) + pyramidRev.substr(j,i) << endl;
        }
    }
    return 0;
}
