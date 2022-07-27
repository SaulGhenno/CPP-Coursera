#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

template<typename ForwardIterator>  

void square(ForwardIterator first, ForwardIterator last)
{
    for(;first != last; first++)
        *first = (*first) * (*first);
}

int main()
{
    vector<int> w;
    w.push_back(3);
    w.push_back(4);
    w.push_back(7);


    square(w.begin(),w.end());
    for(auto i: w)
        cout << i << "\t";
    cout << endl;
}