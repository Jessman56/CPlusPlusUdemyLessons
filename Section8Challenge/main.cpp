#include <iostream>

using namespace std;

int main(){
    const int dollarVal {100};
    const int quarterVal {25};
    const int dimeVal {10};
    const int nickelVal {5};
    const int pennyVal {1};
    
    int centAmount {}, balance{};
    int dollarAmount {}, quarterAmount {}, dimeAmount {},
    pennyAmount {}, nickelAmount {};

    cout << "Enter an amount in cents: ";
    cin >> centAmount;
    
    dollarAmount = centAmount / dollarVal;
    balance = centAmount % dollarVal;
    
    quarterAmount = balance / quarterVal;
    balance %= quarterVal;
    
    dimeAmount = balance / dimeVal;
    balance %= dimeVal;
    
    nickelAmount = balance / nickelVal;
    balance %= nickelVal;
    
    pennyAmount = balance;
    
    cout << dollarAmount << endl;
    cout << quarterAmount << endl;
    cout << dimeAmount << endl;
    cout << nickelAmount << endl;
    cout << pennyAmount << endl;
    return 0;
}