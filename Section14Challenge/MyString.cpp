#include <iostream>
#include <cstring>
#include "MyString.h"

using namespace std;

MyString::MyString() :str{nullptr}{
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *s) :str{nullptr}{
    if (s==nullptr){
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

MyString::MyString(const MyString &source) :str{nullptr}{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

MyString::MyString(MyString &&source) :str{source.str}{
    source.str = nullptr;
}

MyString::~MyString(){
    delete [] str;
}
// copy assignment
MyString &MyString::operator=(const MyString &rhs){
    if (this == &rhs) return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}
//move assingment 
MyString &MyString::operator=(MyString &&rhs){
    if (this == &rhs) return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

MyString MyString::operator-(){
    char *buff= new char[strlen(str)+1];
    strcpy(buff, str);
    for (size_t i{}; i < strlen(buff); i++){
        buff[i] = tolower(buff[i]);
    }
    MyString temp {buff};
    delete [] buff;
    return temp;
}

MyString MyString::operator+(const MyString &rhs) const{
    char *buff= new char[strlen(str) + strlen(rhs.str) + 1];
    strcpy(buff, str);
    strcat(buff, rhs.str);
    MyString temp {buff};
    delete [] buff;
    return temp;
}

bool MyString::operator==(const MyString &rhs) const{
    return (strcmp(str, rhs.str) == 0);
}

bool MyString::operator!=(const MyString &rhs) const{
    return !(strcmp(str, rhs.str) == 0);
}

bool MyString::operator<(const MyString &rhs) const{
    return (strcmp(str, rhs.str) < 0);
}

bool MyString::operator>(const MyString &rhs) const{
    return (strcmp(str, rhs.str) > 0);
}

MyString &MyString::operator+=(const MyString &rhs){
    *this = *this + rhs;
    return *this;
}

MyString MyString::operator*(int n) const{
    MyString temp;
    for (int i {1}; i <= n; i++){
        temp = temp + *this;
    }
    return temp;
}

MyString &MyString::operator*=(int n){
    *this = *this * n;
    return *this;
}

MyString &MyString::operator++(){
    for (size_t i{}; i < strlen(str); i++){
        str[i] = toupper(str[i]);
    }
    return *this;
}

MyString MyString::operator++(int){
    MyString temp(*this);
    operator++();
    return temp;
}


void MyString::display() const{
    cout << str << ' : ' << getLength() << endl;
}
    
int MyString::getLength() const{
    return strlen(str);
}
const char *MyString::getStr() const{
    return str;
}

// overloaded insertion operator
ostream &operator<<(ostream &os, const MyString &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
istream &operator>>(istream &in, MyString &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = MyString{buff};
    delete [] buff;
    return in;
}
