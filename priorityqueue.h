#include <iostream>

using namespace std;

class priorityqueue
{
    private:
        graph* gr;
        Node* queue;
    public:
        priorityqueue(graph* _graph);
        Node* getHead();
        void printQueue();
};


