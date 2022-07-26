#include "kruskal.h"

using namespace std;

kruskal::kruskal(priorityqueue *pr_q, graph* gr)
{
    gra = gr;
    pq = pr_q;
    edges = gra->E();
}

void kruskal::findTreeValue()
{
    int val = 0;
    int low_val = 0;

    Node* head = pq->getHead();
    Node* last;

    Node* lowest = new Node;
    tree = nullptr;
    
    ////////////    
    cout << "The number of edges is: " << edges << endl;
    ///////////
    low_val = head->val;

    printList(head);

    while (head != nullptr)
    {
        //cout << head->i << "|" << head->j << "=" << head->val << endl;
        
        if (low_val >= head->val)
        {
            low_val = head->val;
            lowest->i = head->i;
            lowest->j = head->j;
            lowest->val = head->val;
        }

        last = head;
        head = head->next;
    }
    
    head = pq->getHead();

    cout << "Lowest node: ";
    cout << lowest->i << "|" << lowest->j << "|=" << lowest->val << endl;

    
    deleteNode(&head, lowest->i, lowest->j);
    printList(head);
    append(&tree,lowest->i,lowest->j,lowest->val);
    cout << "Tree list" << endl;
    printList(tree);
    cout << "///////////////////////"<<endl;
    /////////////
    ///////////
    low_val = head->val;

    printList(head);

    while (head != nullptr)
    {
        // cout << head->i << "|" << head->j << "=" << head->val << endl;

        if (low_val >= head->val)
        {
            low_val = head->val;
            lowest->i = head->i;
            lowest->j = head->j;
            lowest->val = head->val;
        }

        last = head;
        head = head->next;
    }

    head = pq->getHead();

    cout << "Lowest node: ";
    cout << lowest->i << "|" << lowest->j << "|=" << lowest->val << endl;

    deleteNode(&head, lowest->i, lowest->j);
    printList(head);
    append(&tree, lowest->i, lowest->j, lowest->val);
    cout << "Tree list" << endl;
    printList(tree);
    /////////////

    //cout << "Three value with Kruskal's algorithm: " << val;
}