#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool is_sorted_descending(vector<int> &L)
{
    for(int i = 0; i < L.size(); i++)
    {
        if((i+1) == L.size())
        {
            return true;
        }
        else if(L.at(i) < L.at(i+1))
        {
            return false;
        }
    }
    return true;
}

int BinarySearchDescending(vector <int> L, int k, int low, int high, int& counter)
{
    
    bool flag = is_sorted_descending(L);
    if(counter++, flag == false)
    {
        cerr << "It ain't sorted boi" << endl;
        exit(0);
    }
    int mid = (high + low)/2;
    
    if(counter++, L.at(mid) == k)
        return mid;
    
    if(counter++, L.at(low) < k)
        return -1;
    
    else if(counter++, k < L.at(high))
        return -1;
    
    if(counter++, L.at(mid) > k)
        return BinarySearchDescending(L, k, mid + 1, high, counter);
        
    else
        return BinarySearchDescending(L, k, low, mid - 1, counter);
    
}


int BinarySearchAscending(vector <int> L, int k, int low, int high, int& counter)
{
    bool flag = is_sorted(L.begin(), L.end());
    if(counter++, flag == false)
    {
        cerr << "It ain't sorted boi" << endl;
        exit(0);
    }
    int mid = (high + low)/2;
    
    if(counter++, L.at(mid) == k)
        return mid;
    
    if(counter++, L.at(low) > k)
        return -1;
    
    else if(counter++, k > L.at(high))
        return -1;
    
    if(counter++, L.at(mid) > k)
        return BinarySearchAscending(L, k, low, mid - 1, counter);
    
    else
        return BinarySearchAscending(L, k, mid + 1, high, counter);
    
}

int main(int argc, const char * argv[])
{
    vector<int> d = {2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    vector<int> a = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int counter = 0;
    //int num1 = BinarySearchDescending(d, 2048, 0, 11, counter);
    int num1 = BinarySearchAscending(a, 2048, 0, 11, counter);
    cout << num1 << endl;
    cout << counter << endl;
}
