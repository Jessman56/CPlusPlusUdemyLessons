#include <iostream>
#include <string>

using namespace std;

int main(){
    const string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    const string key  {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    bool keepCipher {true};
    
    do {
        int userDecision{};
        
        cout << "1: Encrypt a message.\n2: Decrypt a message.\n3: Quit" << endl;
        cin >> userDecision;
        cin.ignore();
        
        
        switch (userDecision){
            case 1: {
                string encryptMess {};
                string output{};
                
                cout << "What message would you like to encrypt?" << endl;
                getline(cin, encryptMess);
                
               for (char c: encryptMess){
                   size_t pos = alphabet.find(c);
                   if(pos != string::npos){
                       output += key.at(pos);
                   } else {
                       output += c;
                   }
               }
                cout << output<< endl;
            }
                break;
            
            case 2: {
                string messDecrypt {};
                string output{};
                
                cout << "What message would you like to decrypt?" << endl;
                getline(cin, messDecrypt);
                
               for (char c: messDecrypt){
                   size_t pos = key.find(c);
                   if(pos != string::npos){
                       output += alphabet.at(pos);
                   } else {
                       output += c;
                   }
               }
                cout << output<< endl;
            }
                break;
            
            case 3:{
                cout << "Congratz on discretly messaging." << endl;
                keepCipher = false;
                
            }
                break;
            
            default: {
            cout << "Enter one of the options next time." << endl; 
            }
                break;
        }
        
    }while (keepCipher);
    
    return 0;
}