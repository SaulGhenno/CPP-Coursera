//   Convert this program to C++
//   change to C++ io
//   change to one line comments
//   change defines of constants to const
//   change array to vector<>
//   inline any short function


#include <iostream>
#include <vector>
using namespace std;
const int N = 40;

inline void assign(int n, vector<int>& data)
{
    for (int i = 0; i < n; i++)     data[i] = i;
}

inline void sum(int& p, int n, vector<int>& data)
{
    for (int i = 0; i < n; ++i)     p = p + data[i];
}

int main(void)
{
    int acum = 0;
    vector<int> data(N);
    assign(N, data);
    sum(acum, N, data);
    cout << "sum is " << acum << endl;
}