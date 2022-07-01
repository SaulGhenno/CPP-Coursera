//   Convert this program to C++
//   change to C++ io
//   change to one line comments
//   change defines of constants to const
//   change array to vector<>
//   inline any short function

// #include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
// #define N 40
const int N = 40;

//assignation function definition
inline void assign(int n, vector<int>& data)
{
    for (int i = 0; i < n; i++)     data[i] = i;
}

//sum function definition
inline void sum(int& p, int n, vector<int>& data)
{
    for (int i = 0; i < n; ++i)     p = p + data[i];
}

int main(void)
{
    // code instructions of c
    // int i;
    // int accum = 0;
    int acum = 0;
    // int data[N];
    vector<int> data(N);
    assign(N, data);
    // sum(&accum, N, data);
    sum(acum, N, data);
    // printf("sum is %d\n", accum);
    cout << "sum is " << acum << endl;
}