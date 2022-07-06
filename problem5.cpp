//Simple linked list (NOT FINISHED)
#include <iostream>

using namespace std;

struct  slistelem
{
    char data;
    slistelem* next;
};

class slist
{
    public:
        slist():h(0){}
        
        void prepend(const char& c);
        ~slist();
        char* getData(){return data;}
    
    private:
        slistelem* h;
        char* data;
};

void slist::prepend(const char& c)
{
    slistelem* temp = new slistelem;
    //allocation fails bad_alloc exception thrown
    temp -> next = h;
    temp -> data = c;
    h = temp; //update h
}

slist::~slist()
{
    cout << "destructor called" << endl;
    slistelem *n = this->h, *current = NULL;
    while(n)
    {
        current = n;
        n = n->next;
        delete(current);
    }
    h = NULL;
}

int main()
{
    slist list;
    list.prepend('a');
    cout << "Hola"<<list.getData()<<endl;
    
}