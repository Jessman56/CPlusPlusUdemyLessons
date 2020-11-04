#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::ostream &in, MyString &rhs);
    
private:
    char *str;

public:
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();

    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);
    
    MyString operator-();                               //make lowercase
    MyString operator+(const MyString &rhs) const;      // concatenate
    bool operator==(const MyString &rhs) const;         // equals
    bool operator!=(const MyString &rhs) const;         //not equals
    bool operator<(const MyString &rhs) const;          //less than
    bool operator>(const MyString &rhs) const;          //greater than
    MyString &operator+=(const MyString &rhs);    // s1 += s2;  concat and assign
    MyString operator*(int n) const;                    // s1 = s2 * 3;  repeat s2 n times
    MyString &operator*=(int n);                        // s1 *= 3;   s1 = s1 * 3;    
    
    MyString &operator++();
    MyString operator++(int);
    
    void display() const;
    
    int getLength() const;
    const char *getStr() const;
    
};

#endif // MYSTRING_H
