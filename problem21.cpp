#include <iostream>

using namespace std;

template<class T, int n>
class my_container
{
    private:
        T* a;
    public:
        my_container() { a = new T[n]; }
        explicit my_container(T *b) : my_container()
        {
            for (int i = 0; i < n; ++i)
                a[i] = b[i];
        }
        my_container(my_container &&b)noexcept
        {
            a = b.a;
            b.a = nullptr;
        }
        my_container &operator=(my_container &&b) noexcept
        {
            a = b.a;
            b.a = nullptr;
            return *this;
        }
        void fill(T x)
        {
            for (int i = 0; i < n; ++i)
                a[i] = x;
        }
        void print()
        {
            if(a == nullptr){cout << "empty" << endl; return;}
            for(int i = 0; i < n; ++i)
                cout << a[i] << ", ";
            cout << endl;
        }
        void swap(my_container &b)
        {
            my_container temp = move(b);
            b = move(*this);
            *this = move(temp);
        }
        ~my_container() { delete[] a; }
};



int main()
{
    double data[10] {1,2,3,4,5,6,7,8,9,10};
    my_container<double, 5> x;
    my_container<double, 5> y(data);
    x.fill(2.0);
    x.print();
    y.print();
    cout << endl;
    y.swap(x);
    x.print();
    y.print();
}