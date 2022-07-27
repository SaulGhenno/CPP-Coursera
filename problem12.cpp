#include <iostream>
#include <iterator>
#include <vector>
#include <cstddef>
using namespace std;

template <typename RandomAccess>

RandomAccess pickRandEl(RandomAccess first, RandomAccess last)
{
    ptrdiff_t temp = last-first;
    return first + rand() % temp;
}

int main()
{
    vector<int> w = {3,5,2,7,13,25,4,8,6,9,16,27};

    cout << *pickRandEl(w.begin(), w.end());
}