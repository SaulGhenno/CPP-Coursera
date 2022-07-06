#include <iostream>

using namespace std;

class list_element
{
    public:
        list_element(int n = 0,list_element* ptr = nullptr): d(n), next(ptr){}
        int d;
        list_element* next;
};

class list
{
    public:
        list():head(nullptr),cursor(nullptr){}
        void prepend(int n); //insert at front value n
        int get_element(){return cursor->d;}
        void advance(){cursor = cursor->next;}
        void print();
        ~list();
    private:
        list_element* head;
        list_element* cursor;
};

void list::prepend(int n)
{
    if(head == nullptr)
        cursor = head = new list_element(n, head);
    else
        head = new list_element(n, head);
}

void list::print()
{
    list_element* h = head;
    while (h != 0)
    {
        cout << h -> d << ", ";
        h = h -> next;
    }
    cout << "###" << endl;
}

list::~list()
{
    for( cursor = head ; cursor != 0;)
    {
        cursor = head->next;
        delete head;
        head = cursor;
    }
}

int main()
{
    list a,b;

    a.prepend(9);
    a.prepend(8);
    cout << "list a " << endl;
    a.print();

    for (int i = 0;i < 40;++i)
        b.prepend(i*i);
    cout << "list b " << endl;
    b.print();

    int data[10] = {3,4,6,7,-3,5};
    //list d(data, 6);
    //list e(data, 10);
    list c(b);
    c.print();
    //d.print();
    //e.print();
}