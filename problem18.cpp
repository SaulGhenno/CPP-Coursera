#include <algorithm>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class ForwIter>

void print(ForwIter first, ForwIter last, const char* title)
{
    cout << title << endl;
    while( first != last )
        cout << *first++ << '\t';
    cout << endl;
}

int main()
{
    int data[3] = {9, 10, 11};

    print(data, data + 3, "Original values");
    transform(data, data + 3, data, binder2nd(multiplies<int>(), 2));
    print(data, data+3, "New values");
}