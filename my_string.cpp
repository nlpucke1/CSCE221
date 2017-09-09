#include "my_string.h"
#include <iostream>
using namespace std;

my_string::my_string()
{
    ptr = nullptr;
    sz = 0;
    cap = 0;
    
}

my_string::my_string(int n)
{
    sz = n;
    //cap = n;
    ptr = new char[n];
    
}

my_string::my_string(char* str)
{
    ptr = new char(*str); //idk
}

my_string::my_string(const my_string& rhs)
{
    //copy constructor
}

my_string& my_string::operator=(const my_string& rhs)
{
    //copy assignment
    return *this;
}

my_string::~my_string()
{
    delete [] ptr;
    ptr = nullptr;
}


int my_string::size()
{
    return sz;
}

int my_string::capacity()
{
    return cap;
}

bool my_string::empty()
{
    return false;
}

my_string& my_string::operator[](int i)
{
    
    return *this;
}

char my_string::at(int i)
{
    return this->ptr[i];
}

my_string& my_string::operator+=(my_string q)
{
    //Stuff
    return *this;
}
my_string& my_string::operator+=(char c)
{
    //Stuff
    return *this;
}

my_string& my_string::insert(int i, my_string& s)
{
    //Stuff
    return *this;
}

ostream& operator<<(std::ostream& os, const my_string& rhs)
{
    
}

ostream& operator>>(std::istream& is, const my_string& rhs)
{
    
}


















