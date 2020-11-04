#include <iostream>
#include <vector>

using namespace std;

void selection();
void printNums(const vector<int>&);
void addNum(vector<int>&);
void listMean(const vector<int>&);
void smallNum(const vector<int>&);
void largeNum(const vector<int>&);

int main(){
    vector <int> list{};
    char userChoice {};
    bool quit {true};
    
    do{
        selection();
        cin >> userChoice;
        switch (userChoice){
            case 'p': 
            case 'P': 
                printNums(list);
                break;
                
            case 'a': 
            case 'A': 
                addNum(list);
                break;
                
            case 'm': 
            case 'M': 
                listMean(list);
                break;
                
            case 's': 
            case 'S':  
                smallNum(list);
                break;
                
            case 'l': 
            case 'L':  
                largeNum(list);
                break;
                
            case 'q': 
            case 'Q': quit = false;
            cout << "Goodbye Felica" << endl;
                break;
                
            default: cout << "Unknown selection, please try again";
                break;
        }
        
    }while(quit);
            
    return 0;
}
void selection(){
    cout << "P - Print Numbers\n" << "A - Add a number \n" <<
        "M - Display mean of the numbers\n" << "S - Display the smallest number\n" <<
        "L - Display the largest number\n" << "Q - Quit" << endl;
}
void printNums(const vector<int> &v){
    if (v.size() == 0)
        cout << "[] - The list is empty." << endl;
    else {
        cout << "[ ";
        for (auto nums: v){
            cout << nums << " ";
        }
        cout << "]"<< endl;
    }
        
}
void addNum(vector<int> &v){
    int added{};
    cout << "What number would you like to add: ";
    cin >> added;
    v.push_back(added);
    cout << added << " added." << endl;
}
void listMean(const vector<int> &v){
    if (v.size() == 0) 
        cout << "Unable to calculate the mean - no data." << endl;
    double mean{};
    for (auto totList: v)
        mean += totList; 
    mean /= v.size();
    cout << "The mean for the list is: " << mean << endl;
}
void smallNum(const vector<int> &v){
    if (v.size() == 0){ cout << "Unable to calculate the smallest number - list is empty." << endl; }
    int smallNum = v.at(0);
    for (auto totList: v){
        //int smallNum = v.at(0);
        if (smallNum > totList) 
            smallNum = totList;
    }
    cout << "Smallest number is: " << smallNum << endl;
}
void largeNum(const vector<int> &v){
if (v.size() == 0){ cout << "Unable to calculate the largest number - list is empty." << endl; }
    int largeNum = v.at(0);
    for (auto totList: v){
        //int largeNum = v.at(0);
        if (largeNum < totList) 
            largeNum = totList;
    }
    cout << "Largest number is: " << largeNum << endl;
}
