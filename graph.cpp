#include "graph.h"

using namespace std;

// Constructor of the class graph with parameter size
graph::graph(int s, float d)
{
    size = s;
    density = d;
    srand(time(NULL));
    // creating graph
    g = new int *[size];
    for (int i = 0; i < size; ++i)
        g[i] = new int[size];

    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<> distrib({1 - density, density});
    // initialize values
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = distrib(gen) * (rand() % 10 + 1);
        }
    }

    // create a larger graph just for printing format
    ga = new int *[size + 1];
    for (int i = 0; i < size + 1; ++i)
        ga[i] = new int[size + 1];
    for (int i = 0; i < size + 1; ++i)
        for (int j = 0; j < size + 1; ++j)
            ga[i][j] = 0;

    // create node value array
    val = new int[size];
    for (int i = 0; i < size; ++i)
        val[i] = (rand() % 10 + 1);
}
// Function to print the graph
void graph::print()
{
    for (int i = 0; i < size + 1; ++i)
    {
        ga[i][0] = i; // assigning the number horizontally
        for (int j = 0; j < size + 1; ++j)
        {
            ga[0][j] = j; // assignen number varically
            if (j != 0 && i != 0)
                ga[i][j] = g[i - 1][j - 1]; // asign values
            cout << setw(3) << ga[i][j];    // printing graph
        }
        cout << endl;
    }
}
// Function to print the list of node values
void graph::print_val()
{
    for (int i = 0; i < size; ++i)
        cout << "val[" << i + 1 << "]=" << val[i] << "   ";
    cout << endl;
}
// Returns the number of vertices in the graph
int graph::V()
{
    vertex = size;
    return vertex;
}
// Returns the number of edges in the graph
int graph::E()
{
    // loops to count the number of 1s that means a edge
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if (g[i][j] > 0)
                edges++;
    return edges;
}
// Tests whether there is an edge from node x to node y
bool graph::adjacent(int x, int y)
{
    bool adj = false;
    // lock for not valid points
    if (x > size || y > size)
        cout << "Point value not valid" << endl;
    else if (g[x - 1][y - 1] > 0) // condition to know adjacent
        adj = true;
    return adj;
}
// Lists all nodes such that there is an edge from x to y
void graph::neighbors(int x)
{
    cout << "Point " << x << " has neighbors in: ";
    // Loop for printing neighbors
    for (int i = 0; i < size; ++i)
        if (g[x - 1][i] > 1)
            cout << i + 1 << " ";
    cout << endl;
}
// Adds to G the edge from x to y, if it is not there
void graph::add(int x, int y)
{
    if (g[x - 1][y - 1] == 1)
        cout << "There is an edge already" << endl;
    else
        g[x - 1][y - 1] = 1;
}
// Removes the edge from x to y, if it is there
void graph::del(int x, int y)
{
    if (g[x - 1][y - 1] == 0)
        cout << "There is not an edge between " << x << " and " << y << endl;
    else
        g[x - 1][y - 1] = 0;
}
// Returns the value associated with the node x
int graph::get_node_value(int x)
{
    int v;
    v = val[x - 1];
    return v;
}
// Sets the value associated with the node x to a
void graph::set_node_value(int x, int a)
{
    val[x - 1] = a;
}
// Returns the value associated to the edge (x,y)
int graph::get_edge_value(int x, int y)
{
    int eV = 0.0;
    eV = g[x - 1][y - 1];
    return eV;
}
// Sets the value associated to the edge (x,y) to v
void graph::set_edge_value(int x, int y, int v)
{
    g[x - 1][y - 1] = v;
}
