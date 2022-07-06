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
        list(const int* arr, int n);
        list(const list& lst);//copy constructor
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

list::list(const int* arr, int n)
{
    if(arr == NULL)
    {
        head = nullptr;
        cursor = nullptr;
    }
    else
    {
        list_element* h = new list_element();
        list_element* previous;
        head = h;
        h->d = arr[0];
        previous = h;
        for (int i = 1; i < n; ++i)
        {
            h = new list_element();
            h->d = arr[i];
            previous->next = h;
            previous = h;
        }
    }
}

list::list(const list& lst)
{
    if(lst.head == 0)
    {
        head = nullptr;
        cursor = nullptr;
    }
    else
    {
        cursor = lst.head;
        list_element* h = new list_element();
        list_element* previous;
        head = h;
        h->d = lst.head->d;
        previous = h;
        cursor = cursor->next;
        while (cursor != nullptr)
        {
            h = new list_element();
            h->d = cursor->d;
            previous->next = h;
            cursor = cursor->next;
            previous = h;
        }
        cursor = head;
    }
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
    list d(data, 6);
    list e(data, 10);
    list c(b);
    cout << "list c " << endl;
    c.print();
    cout << "list d " << endl;
    d.print();
    cout << "list e " << endl;
    e.print();
}