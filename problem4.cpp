// Object Oriented in C++
#include <iostream>

using namespace std;

class point
{
    public:
        point(double x = 0.0,double y = 0.0):x(x),y(y){} //constructor
        double getx(){return x;}
        double gety(){return y;}
        void setx(double v){x = v;}
        void sety(double w){y = w;}
    
    private:
        double x, y;
};

point operator+ (point& p1, point& p2)
{
    point sum = {p1.getx() + p2.getx(), p1.gety() + p2.gety()};
    return sum;
}

ostream& operator<< (ostream& out, point p)
{
    out << "( " << p.getx() << ", " << p.gety() << " )";
    return out;
}

int main()
{
    point a = {3.5,2.5}, b = {2.5, 4.5},c;
    cout << "a = " << a << " b = " << b << endl;
    cout << "sum = " << a + b << endl; 
}