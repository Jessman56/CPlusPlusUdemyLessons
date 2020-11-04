#include <iostream>
#include <cstring>
#include "Mystring.h"

using namespace std;

Mystring::Mystring() :str{nullptr}{
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char *s) :str{nullptr}{
    if (s==nullptr){
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring &source) :str{nullptr}{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) :str{source.str}{
    source.str = nullptr;
}

Mystring::~Mystring(){
    delete [] str;
}
// copy assignment
Mystring &Mystring::operator=(const Mystring &rhs){
    if (this == &rhs) return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}
//move assingment 
Mystring &Mystring::operator=(Mystring &&rhs){
    if (this == &rhs) return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring operator-(const Mystring &obj){
    char *buff= new char[strlen(obj.str)+1];
    strcpy(buff, obj.str);
    for (size_t i{}; i < strlen(buff); i++){
        buff[i] = tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs){
    char *buff= new char[strlen(lhs.str) + strlen(rhs.str) + 1];
    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs){
    return (strcmp(lhs.str, rhs.str) == 0);
}

bool operator!=(const Mystring &lhs, const Mystring &rhs){
    return !(strcmp(lhs.str, rhs.str) == 0);
}

bool operator<(const Mystring &lhs, const Mystring &rhs){
    return (strcmp(lhs.str, rhs.str) < 0);
}

bool operator>(const Mystring &lhs, const Mystring &rhs){
    return (strcmp(lhs.str, rhs.str) > 0);
}

Mystring &operator+=(Mystring &lhs, const Mystring &rhs){
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator*(const Mystring &lhs, int n){
    Mystring temp;
    for (int i {1}; i <= n; i++){
        temp = temp + lhs;
    }
    return temp;
}

Mystring &operator*=(Mystring &lhs, int n){
    lhs = lhs * n;
    return lhs;
}

Mystring &operator++(Mystring &obj){
    for (size_t i{}; i < strlen(obj.str); i++){
        obj.str[i] = toupper(obj.str[i]);
    }
    return obj;
}

Mystring operator++(Mystring &obj, int){
    Mystring temp(obj);
    ++obj;
    return temp;
}


void Mystring::display() const{
    cout << str << ' : ' << getLength() << endl;
}
    
int Mystring::getLength() const{
    return strlen(str);
}
const char *Mystring::getStr() const{
    return str;
}

// overloaded insertion operator
ostream &operator<<(ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
istream &operator>>(istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

