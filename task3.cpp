#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

#include "graph.cpp"

using namespace std;

int main()
{
    int size = 5;
    int p1 = 3, p2 = 5, p3 = 1;
    float density = 0.5;
    graph a(size, density);
    // printing the original graph
    cout << "<<<<<<<Original graph>>>>>>>" << endl;
    a.print();
}