#include <iostream>

using namespace std;

class kruskal
{
    private:
        graph* gra;
        priorityqueue* pq;
        int edges;
        Node* tree;
    public:
        kruskal(priorityqueue *pr_q, graph* gr);
        void findTreeValue();
};

