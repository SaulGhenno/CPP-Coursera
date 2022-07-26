#include "priorityqueue.h"


using namespace std;

priorityqueue::priorityqueue(graph* _graph)
{
    gr = _graph;
    queue = nullptr;

    int vertex = gr->V();
    for (int i = 0; i < vertex; ++i){
        for(int j = 0; j < vertex; ++j){
            int a = gr->get_edge_value(i + 1, j + 1);
                if(a != 0)
                    append(&queue, i+1, j+1, a);
            
        }
    }

}

Node* priorityqueue::getHead()
{
    return queue;
}

void priorityqueue::printQueue()
{
    cout << "Created list"<<endl;
    printList(queue);
}