#include <iostream>
#include <queue>
#include <ctime>
using namespace std;

void showpq(priority_queue<int, vector<int>, greater<int> > gq)
{
    priority_queue<int, vector<int>, greater<int> > g = gq;
    while (!g.empty()) {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

// Driver Code
int main()
{
    srand(time(NULL));

    priority_queue<int, vector<int>, greater<int>> *gquiz = new priority_queue<int, vector<int>, greater<int>>[5];

    
    for (int i = 0; i < 5; ++i)
    {
        int a = (rand() % 5);
        cout << a << " ";
        if(a != 0)
            gquiz[0].push(a);
    }

    cout << "\nThe priority queue gquiz is : ";
    showpq(gquiz[0]);

    return 0;
}