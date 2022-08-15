#include <iostream>
#include <string>
using namespace std;

class simple
{
    private:
        int p = 0, q = 1;
    public:
        simple() = default;
        simple(double x) = delete;
        simple(int x, int y): p(x), p(y){}
        simple(int x): simple(x, 1){}
        simple(const simple& x): simple(x.p, x.q){}
        simple(simple&& x): simple(x.p, x.q){ x.p = x.q = 0; }
};

class rational: public simple
{
    public:
        using simple::simple;
}