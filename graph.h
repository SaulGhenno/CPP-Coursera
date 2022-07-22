#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

class graph
{
    public:
        graph() : vertex(0), edges(0), g(nullptr), density(0.0), size(0){}
        graph(int s, float d);                    // constructor of the class graph with parameter size
        void print();                             // function to print the graph
        void print_val();                         // function to print the list of node values
        int V();                                  // returns the number of vertices in the graph
        int E();                                  // returns the number of edges in the graph
        bool adjacent(int x, int y);              // tests whether there is an edge from node x to node y
        void neighbors(int x);                    // lists all nodes y such that there is an edge from x to y
        void add(int x, int y);                   // adds to G the edge from x to y, if it is not there
        void del(int x, int y);                   // removes the edge from x to y, if it is there
        int get_node_value(int x);                // returns the value associated with the node x
        void set_node_value(int x, int a);        // sets the value associated with the node x to a
        int get_edge_value(int x, int y);         // returns the value associated to the edge (x,y)
        void set_edge_value(int x, int y, int v); // sets the value associated to the edge (x,y) to v
    private:
        float density;
        int **g;
        int **ga;
        int size;
        int vertex;
        int edges = 0;
        int *val;
};