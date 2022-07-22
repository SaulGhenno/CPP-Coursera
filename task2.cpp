#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

class graph
{
    public:
        graph();
        graph(int s, float d); //constructor of the class graph with parameter size
        void print(); //function to print the graph
        void print_val(); //function to print the list of node values
        int V(); //returns the number of vertices in the graph
        int E(); //returns the number of edges in the graph
        bool adjacent(int x, int y); //tests whether there is an edge from node x to node y
        void neighbors(int x); //lists all nodes y such that there is an edge from x to y
        void add(int x, int y); //adds to G the edge from x to y, if it is not there
        void del(int x, int y); //removes the edge from x to y, if it is there
        int get_node_value(int x); //returns the value associated with the node x
        void set_node_value(int x, int a); //sets the value associated with the node x to a
        int get_edge_value(int x, int y); //returns the value associated to the edge (x,y)
        void set_edge_value(int x, int y, int v); //sets the value associated to the edge (x,y) to v
    private:
        float density;
        int** g;
        int** ga;
        int size;
        int vertex;
        int edges = 0;
        int *val;
};

graph::graph()
{
    vertex = 0;
    edges = 0;
}
// Constructor of the class graph with parameter size
graph::graph(int s, float d)
{
    size = s;
    density = d;
    srand(time(NULL));
    //creating graph
    g = new int*[size];
    for (int i = 0; i < size; ++i)
        g[i] = new int[size];

    random_device rd;
    mt19937 gen(rd());
    discrete_distribution<> distrib({1 - density, density});
    //initialize values
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if(i == j)
                g[i][j] = 0;
            else
                g[i][j] = distrib(gen) * (rand() % 10 + 1);
        }
    }

    //create a larger graph just for printing format
    ga = new int *[size + 1];
    for (int i = 0; i < size + 1; ++i)
        ga[i] = new int[size + 1];
    for(int i = 0; i < size + 1; ++i)
        for(int j = 0; j < size + 1; ++j)
            ga[i][j] = 0;

    //create node value array
    val = new int [size];
    for (int i = 0; i < size; ++i)
        val[i] = (rand() % 10 + 1);

}
// Function to print the graph
void graph::print()
{
    for(int i = 0; i < size+1; ++i)
    {
        ga[i][0] = i; //assigning the number horizontally
        for(int j = 0; j < size+1; ++j){
            ga[0][j] = j;//assignen number varically
            if(j != 0 && i != 0)
                ga[i][j] = g [i-1][j-1]; //asign values
            cout << setw(3) << ga[i][j];//printing graph
        }
        cout << endl;
    }
}
// Function to print the list of node values
void graph::print_val()
{
    for (int i = 0; i < size; ++i)
        cout << "val[" << i+1 << "]=" << val[i] << "   ";
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
    //loops to count the number of 1s that means a edge
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            if(g[i][j] > 0)
                edges++;
    return edges;
}
// Tests whether there is an edge from node x to node y
bool graph::adjacent(int x, int y)
{
    bool adj = false;
    //lock for not valid points
    if(x > size || y > size) 
        cout << "Point value not valid"<< endl;
    else
        if(g[x-1][y-1] > 0) //condition to know adjacent
            adj = true;
    return adj;
}
// Lists all nodes such that there is an edge from x to y
void graph::neighbors(int x)
{
    cout << "Point " << x << " has neighbors in: ";
    //Loop for printing neighbors
    for (int i = 0; i < size; ++i)
        if(g[x-1][i] > 1)
            cout << i+1 << " ";
    cout << endl;
}
// Adds to G the edge from x to y, if it is not there
void graph::add(int x, int y)
{
    if(g[x-1][y-1] == 1)
        cout << "There is an edge already" << endl;
    else
        g[x-1][y-1] = 1;
}
// Removes the edge from x to y, if it is there
void graph::del(int x, int y)
{
    if(g[x-1][y-1] == 0)
        cout << "There is not an edge between "<< x << " and " << y << endl;
    else
        g[x-1][y-1] = 0;
}
// Returns the value associated with the node x
int graph::get_node_value(int x)
{
    int v;
    v = val[x-1];
    return v;
}
// Sets the value associated with the node x to a
void graph::set_node_value(int x, int a)
{
    val[x-1] = a;   
}
// Returns the value associated to the edge (x,y)
int graph::get_edge_value(int x, int y)
{
    int eV = 0.0;
    eV = g[x-1][y-1];
    return eV;
}
// Sets the value associated to the edge (x,y) to v
void graph::set_edge_value(int x, int y, int v)
{   
    g[x-1][y-1] = v;
}


class Node
{
    public:
        int index;
        int val;
        Node* next;
        Node* prev;
};

class priorityQueue
{
    public:
        priorityQueue(graph a);
        /*void chgPrioirity(PQ, int priority);
        void minPrioirty(PQ);
        void contains(PQ, int queue_element);
        void insert(PQ, int queue_element);
        int top(PQ);
        int size(PQ);*/
    private:
        graph gr;
        Node* queue;
};

void push(Node** head_ref, int i, int v, int n)
{
    Node *new_node = new Node();
    new_node->index = i;
    new_node->val = v;
    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    if ((*head_ref) != nullptr)
        (*head_ref)->prev = new_node;
    
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    Node* last;
    cout << "\tList in forward direction" << endl;
    while (node != nullptr)
    {
        cout << " " << node->index << "->" << node->val << " ";
        last = node;
        node = node->next;
    }
    
}

priorityQueue::priorityQueue(graph a)
{
    gr = a;
    //queue = new Node[gr.V()];
    gr.print();
    int num = 0;
    num =  gr.get_edge_value(3, 1);
    cout << num;
    /*for (int i = 0; i < gr.V(); ++i)
    {
        cout << gr.get_edge_value(i,0) << " ";
        
    }*/
    
}
/*
class shortestPath
{
    public:
        shortestPath(graph l);
        int* path(int u, int w); //find shortest path between u-w and returns the sequence of vertices representing shorest path
        int path_size(int u, int w); //return the path cost associated with the shortest path

        void findLowest(int &c_point, int& g_point, int& l_next, int& p_val, int& p_point);
    private:
        graph g;
        int* list;
};

shortestPath::shortestPath(graph l)
{
    g = l;
    list = new int[g.V()];
    
}

int* shortestPath::path(int u, int w)
{
    int dir_val = 999;
    int path_val = 0;
    int curr_point = u;
    int goal_point = w;
    int prev_point = 0;
    int low_next = 999;

    if (g.adjacent(u,w)){
        dir_val = g.get_edge_value(u, w);
    }

    findLowest(curr_point, goal_point, low_next, path_val, prev_point);

    /*
    //Debug printing
    cout << "Direct value: " << dir_val << endl;
    //////////////
    for (int i = 1; i < g.V()+1; i++)
    {
        //Debug printing
        cout << "val of : "<<curr_point<< " " <<i<< " : "<<g.get_edge_value(curr_point, i) << endl;
        ////////////////
        if (g.get_edge_value(curr_point, i) < low_val && g.get_edge_value(curr_point, i) != 0)
        {
            low_val = g.get_edge_value(curr_point, i);
            low_next = i;
        }
    }
    if(low_next == 999)
        cout << "No edges in this vertix" << endl;

    curr_point = low_next;  
    path_val += low_val;
    ////////////////
    cout << "Lowest edge value: " << low_val << endl;
    cout << "Lowest next edge: " << low_next << endl;
    cout << "Path value: " << path_val << endl;
    */
//}
/*
void shortestPath::findLowest(int &c_point, int& g_point, int& l_next, int& p_val, int& p_point)
{
    if (g_point == c_point)
        return;
    
    int l_val = 999;
    int s_l_val = 0;

    cout << "///////////////////////" << endl;
    cout << "Previous point: " << p_point << endl;
    cout << "Current point: " << c_point << endl;
    cout << "///////////////////////" << endl;
    //////////////

    for (int i = 1; i < g.V() + 1; i++)
    {
        // Debug printing
        cout << "val of : " << c_point << " " << i << " : " << g.get_edge_value(c_point, i) << endl;
        ////////////////
        if (g.get_edge_value(c_point, i) < l_val && g.get_edge_value(c_point, i) != 0)
        {
            l_val = g.get_edge_value(c_point, i);
            l_val = s_l_val;
            l_next = i;
        }
        /*if (g.get_edge_value(c_point, i) > s                                                                             l_val && l_val != s_l_val)
        {
            s_l_val = g.get_edge_value(c_point, i);
        }*/
/*        cout << l_val << " " << s_l_val << endl;
    }
    
    if (l_val == 999)
    {
        cout << "No edges in this vertix" << endl;
        return;
    }
    cout << "///////////////////////" << endl;
    cout << "Next point: " << l_next << endl;
    cout << "Lowest edge value: " << l_val << endl;
    cout << "Second lowest edge value: " << s_l_val << endl;

    if (p_point == l_next)
    {
        cout << "Same as previous" << endl;
        return;
    }
    

    p_point = c_point;
    c_point = l_next;
    
    p_val += l_val;

    cout << "///////////////////////" << endl;
    
    
    cout << "Path value: " << p_val << endl;
    cout << endl;

    
    
    ////////////////
    

    if (g_point != l_next)
        findLowest(c_point, g_point, l_next, p_val, p_point);
    
    
} 
*/
int main()
{
    
    int size = 5;
    int p1 = 3, p2 = 5, p3 = 1;
    float density = 0.5;
    graph a(size, density);
    //printing the original graph
    cout << "<<<<<<<Original graph>>>>>>>" << endl;
    //a.print();
    /*//Test vertex function
    cout << "The number of vertices are: " << a.V() << endl;
    //Test edges function
    cout << "The number of edges is: " << a.E() << endl;
    //Test adjacent function from p1 and p2
    if(a.adjacent(p1,p2) == 1)
        cout << "There is an edge between points " << p1 << " and " << p2 << endl;
    else
        cout << "There is NOT an edge between points " << p1 << " and " << p2 << endl;
    //Test neighbors for a point 
    a.neighbors(p2);
    //Test for add edges
    a.add(p3,2);
    a.add(p3,p3);
    cout << "<<<<<<<First modify graph>>>>>>>" << endl;
    a.print();
    //Test for delete edges
    a.del(p3,p1);
    a.del(p3,p3);
    cout << "<<<<<<<Second modify graph>>>>>>>" << endl;
    a.print();
    //Test get value of the node
    cout << "The value of the node is " << a.get_node_value(1) << endl;
    a.print_val();
    //Test set value of the node
    a.set_node_value(p1, 20);
    a.print_val();*/
    //Test get edge value
    cout << "The value of the edge is " << a.get_edge_value(p1,p3) << endl;
    //Test set edge value
    //a.set_edge_value(p1,p3,0.7);
    //cout << "The value of the edge is " << a.get_edge_value(p1,p3) << endl;
    //shortestPath first(a);
    //first.path(p1,p3);
    priorityQueue queue(a);
}