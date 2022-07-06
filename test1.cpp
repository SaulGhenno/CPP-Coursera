#include <iostream>
#include <iterator>
#include <list>

using namespace std;

ostream &operator<<(ostream &out, list<int> l)
{
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it)
        cout << "   " << *it;
    cout << '\n';
    return out;
}

int main()
{
    list<int> a, b;

    for (int i = 0; i < 10; ++i)
    {
        a.push_back(i * 2);
        b.push_front(i * 3);
    }

    cout << "List 1 (a) is : ";
    cout << a;

    cout << "List 2 (b) is : ";
    cout << b;

    cout << "List 1.back() : " << a.back() << endl;
    cout << "List 2.front() : " << b.front() << endl;
    
    a.pop_front();
    cout << "List 1 (a) after pop_front() is : ";
    cout << a;

    b.pop_back();
    cout << "List 2 (b) after pop_back() is : ";
    cout << b;

    a.reverse();
    cout << "List 1.reverse() (a) : ";
    cout << a;

    b.sort();
    cout << "List 2.sort() (b) : ";
    cout << b;
}