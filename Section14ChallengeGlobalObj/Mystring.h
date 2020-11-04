#ifndef MYSTRING_H
#define MYSTRING_H

class Mystring
{
    
    friend Mystring operator-(const Mystring &obj);                               //make lowercase
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);      // concatenate
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);         // equals
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);         //not equals
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);          //less than
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);          //greater than
    friend Mystring &operator+=( Mystring &lhs, const Mystring &rhs);    // s1 += s2;  concat and assign
    friend Mystring operator*(const Mystring &lhs, int n);                    // s1 = s2 * 3;  repeat s2 n times
    friend Mystring &operator*=(Mystring &lhs, int n);                        // s1 *= 3;   s1 = s1 * 3;    
    friend Mystring &operator++(Mystring &obj);
    friend Mystring operator++(Mystring &obj, int);
    
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::ostream &in, Mystring &rhs);
    
private:
    char *str;

public:
    Mystring();
    Mystring(const char *s);
    Mystring(const Mystring &source);
    Mystring(Mystring &&source);
    ~Mystring();

    Mystring &operator=(const Mystring &rhs);
    Mystring &operator=(Mystring &&rhs);
    
    void display() const;
    
    int getLength() const;
    const char *getStr() const;
    
};

#endif // MYSTRING_H
