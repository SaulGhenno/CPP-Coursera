#include <iostream>

using namespace std;
const int N = 40;

inline int sum(int& p, int n, int d[])
{
    for (int i = 0; i < n; ++i)
    {
        p = p + d[i];
    }
}

int main(void)
{
    int acum;
    //int data[N];
    vector<int> data(N);
    for (int i = 0; i < N; ++i)
    {
        data[i] = i;
    }
    sum(acum, N, d);
    cout << "sum is " << acum << endl;
}