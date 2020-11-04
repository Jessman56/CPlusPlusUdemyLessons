#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector <int> list{};
    char userChoice {};
    bool quit {true};
    do{
        cout << "P - Print Numbers\n" << "A - Add a number \n" <<
        "M - Display mean of the numbers\n" << "S - Display the smallest number\n" <<
        "L - Display the largest number\n" << "Q - Quit" << endl;
        cin >> userChoice;
        switch (userChoice){
            case 'p': 
            case 'P': {
                if (list.size() == 0)
                    cout << "[] - The list is empty." << endl; break;
                
                cout << "[";
                for (auto allList: list) cout << allList << " ";
                cout << "]" << endl;
//                My attempt with more than needed
//                for (int i {}; i < list.size(); ++i){
//                    if (i == 0) cout << "[" << list.at(i) ;
//                    else if (i == list.size()-1){
//                    cout << list.at(i) << "]" << endl;
//                }
//                    else cout << list.at(i) << " ";
//            }
            }
                break;
            
            case 'a': 
            case 'A': {
            int addNum{};
            cout << "What number would you like to add: ";
            cin >> addNum;
            list.push_back(addNum);
            cout << addNum << " added." << endl;
            }
                break;
                
            case 'm': 
            case 'M': {
                if (list.size() == 0){ cout << "Unable to calculate the mean - no data." << endl; break;}
                double mean{};
                for (int i {}; i < list.size(); ++i){
                    mean += list.at(i); 
                }    
                mean /= list.size();
                cout << "The mean for the list is: " << mean << endl;
            }
                break;
                
            case 's': 
            case 'S': {
                if (list.size() == 0){ cout << "Unable to calculate the smallest number - list is empty." << endl; break;}
                int smallNum = list.at(0);
                for (int i {1}; i < list.size(); ++i){
                    //int smallNum = list.at(0);
                    if (smallNum > list.at(i)) smallNum = list.at(i);
                }
                cout << "Smallest number is: " << smallNum << endl;
            }
                break;
                
            case 'l': 
            case 'L': {
                if (list.size() == 0){ cout << "Unable to calculate the largest number - list is empty." << endl; break;}
                int largeNum = list.at(0);
                for (auto totList: list){
                    //int largeNum = list.at(0);
                    if (largeNum < totList) 
                        largeNum = totList;
                }
                cout << "Largest number is: " << largeNum << endl;
            }
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