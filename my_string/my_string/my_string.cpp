#include "my_string.h"
#include <iostream>
using namespace std;

my_string::my_string(){ //Default constructor
    this->ptr = nullptr;
    this->sz = 0;
    this->cap = 0;
}

my_string::my_string(int n){ //Constructor that creates empty string with allocated size n
    this->sz = 0;
    this->cap = n;
    this->ptr = new char[n];
}

my_string::my_string(char* str){ //Main constructor, creates string with cstring argument
    this->sz = 0;
    char* temp = str;
    
    while(*str != '\0'){ //While not the terminating character
        this->sz++;
        str++;
    }
    
    this->ptr = new char[this->sz];
    
    for(int i = 0; i < sz; i++){
        this->ptr[i] = temp[i];
    }
    
    this->cap = this->sz;
}

my_string::my_string(const my_string& rhs){ //Copy constructor: Deep copy
    this->sz = rhs.sz;
    this->ptr = new char[rhs.sz]; //Allocate appropriate memory
    
    for(int i = 0; i < this->sz; i++){
        ptr[i] = rhs.ptr[i]; //Copy each element
    }
    
    this->cap = this->sz;
}

my_string& my_string::operator=(const my_string& rhs)
{
    if(this != &rhs){ //Avoid self assignment
        delete [] this->ptr; //Erase old ptr
        this->sz = rhs.sz; //Reset the size to argument size
        this->ptr = new char[rhs.sz]; //Allocate appropriate memory
        
        for(int i = 0; i < this->sz; i++){
            ptr[i] = rhs.ptr[i]; //Copy Each element
        }
        
        this->cap = this->sz;
    }
    return *this;
}

my_string::~my_string(){ //Destructor
    
    delete [] ptr;
    ptr = nullptr;
}

void my_string::resize(){ //Doubles capacity if needed
    
    if(this->cap == 0)
        this->cap = 1;
    
    char* temp = new char[(this->cap) * 2]; //Create new ptr with twice the capacity of the previous
    
    for(int i = 0; i < this->sz; i++){
        temp[i] = this->ptr[i]; //Copy each element over
    }
    
    delete [] this->ptr; //Delete the old ptr
    this->ptr = temp; //Point to the same address of temp, memory already allocated
    this->cap = (this->cap) * 2; //Set capacity equal to double its previous
}

int my_string::size(){ //returns size
    return this->sz;
}

int my_string::capacity(){ //returns capacity
    return this->cap;
}

bool my_string::empty(){ //returns whether or not it is empty
    if(sz == 0)
        return true;
    
    else
        return false;
}

char& my_string::operator[](int i){ //returns element at i
    return *(this->ptr+i);
}

char& my_string::at(int i){ //returns error if inappropriate index
    if((this->size()) - 1 < i || i < 0)
        throw std::out_of_range ("Input is out of range");
    
    return *(this->ptr+i);
}

my_string& my_string::operator+=(my_string q){
    int totalSize = this->sz + q.sz;
    
    while(this->cap < totalSize){ //Resize if necessary
        this->resize();
    }
    
    for(int i = 0; i < q.sz; i++){ //Copies new values to ptr now that it has enough capacity
        this->ptr[sz+i] = q.at(i);
    }
    
    this->sz = totalSize;
    return *this;
}

my_string& my_string::operator+=(char c){
    int totalSize = this->sz + 1;
    
    if(this->cap < totalSize) //Resize if necessary
        this->resize();
    
    this->ptr[sz] = c; //Now that capacity has been updated
    this->sz = totalSize;
    return *this;
}

my_string& my_string::insert(int i, const my_string& s)
{
    if(this->size() < i || i < 0)
        throw out_of_range ("Input is out of range");
    
    int totalSize = this->sz + s.sz;
    char beg[i]; //Character array of ptr before the index at which we will insert the string
    char end[this->sz - i]; //Character array of ptr after the index
    char* temp = new char[totalSize]; //Cstring of appropriate size
    
    for(int j = 0; j < i; j++){ //Fills up beg with first part of ptr
        beg[j] = this->ptr[j];
    }
    
    for(int j = 0; j < (this->sz)-i; j++){
        end[j] = this->ptr[i+j]; //Fills end with last part of ptr
    }
    
    for(int j = 0; j < totalSize; j++){//Copies values to temp
        
        if(j >= 0 && j < i)
            temp[j] = beg[j];
    
        if(j >= i && j < (i + s.sz))
            temp[j] = s.ptr[j-i];
        
        if(j >= (i + s.sz) && j < totalSize)
            temp[j] = end[j - (i + s.sz)];
    }
    
    delete [] this->ptr;
    this->ptr = temp;
    this->cap = totalSize;
    this->sz = totalSize;
    return *this;
}

ostream& operator<<(std::ostream& os, my_string& rhs){ //Overload operator <<
    
    for(int i = 0; i < rhs.size(); i++){
        os << rhs[i];
    }
    
    return os;
}

istream& operator>>(std::istream& is, my_string& rhs){ //Overload operator >>
    char c[128];
    cin.get(c,128);
    rhs+=c;
    return is;
}
