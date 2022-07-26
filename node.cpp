#include "node.h"

using namespace std;

void append(Node** head_ref, int i, int j, int v)
{
    Node* new_node = new Node();
    Node* last = *head_ref;

    new_node->i = i;
    new_node->j = j;
    new_node->val = v;
    new_node->next = nullptr;

    if (*head_ref == nullptr)
    {
        new_node->prev = nullptr;
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr)
        last = last->next;

    
    last->next = new_node;
    new_node->prev = last;
    return;
    
}

void printList(Node* node)
{
    Node* last;

    while (node != nullptr)
    {
        cout << "|" << node->i << "|" << node->j << "|=" << node->val << "|" << endl;
        last = node;
        node = node->next;
    }
}

void deleteNode(Node** head_ref, int i, int j)
{
    
    Node* current = *head_ref;
    Node* previous = nullptr;
    
    if(current->prev == nullptr && current->i == i && current->j == j){
        *head_ref = current->next;
        free(current);
        return;
    }
    
    while((current->i != i) || (current->j != j))
        current = current->next;
    
    previous = current->prev;
    
    if(current->next == nullptr)
        previous->next = nullptr;
    else
    { 
        previous->next = current->next;
        current->next->prev = previous;
    }

    free(current);
    current = nullptr;
}