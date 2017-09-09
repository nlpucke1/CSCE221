#include <iostream>
#ifndef my_string_hpp
#define my_string_hpp

class my_string
{

private:
    char* ptr;
    int sz;
    int cap;
    
public:
    my_string();
    ~my_string();
    my_string(int);
    my_string(char*); //Main constructor //Needs to be constructor with CString and create string
    my_string(const my_string&);
    my_string& operator=(const my_string&);
    
    int size();
    int capacity();
    bool empty();
    my_string& operator[](int); //returns the character at index i of s, without performing arrays bounds checking
    char at(int);
    my_string& operator+=(my_string); //appends the string q to s
    my_string& operator+=(char); //appends the character c to s
    my_string& insert(int, my_string& ); //insert(i, s) inserts the string s before the position i in s and returns a reference to the resulting string. This function is optional for extra credit.
    
};

std::ostream& operator<<(std::ostream& os, const my_string&);
std::ostream& operator>>(std::istream& is, const my_string&); //reads input to s. It should stop when a white space is detected.
#endif
