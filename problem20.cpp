#include <iostream>
#include <string>

using namespace std;

class student
{
    public:
        enum year{fresh, soph, junior, senior, grad};
        student(string nm, int id, double g, year x);
        void print() const;
    protected:
        int student_id;
        double gpa;
        year y;
        string name;
};

class grad_student : public student
{
    public:
        enum support {ta, ra, fellowship, other};
        grad_student(string nm, int id, double g, year x, support t, string d, string th);
        void print() const;
    protected:
        support s;
        string dept;
        string thesis;
};

student::student(string nm, int id, double g, year x) : student_id(id), gpa(g), y(x), name(nm) {}

grad_student::grad_student(string nm, int id, double g, year x, support t, string d, string th) : student(nm, id, g, x), s(t),dept(d),thesis(th) {}

void student::print() const
{
    cout << name << ", " << student_id << ", " << y << ", " << gpa << endl;
}

void grad_student::print() const
{
    student::print();
    cout << dept << ", " << s << endl << thesis << endl;
}

int main()
{
    student s("Mae Pohl",100,3.425,student::fresh);
    student *ps = &s;
    grad_student gs("Morris Pohl",200,3.2564,student::grad,grad_student::ta,"Pharmacy","Retail Pharmacies"), *pgs;
    ps = pgs = &gs;
    ps->print();
    cout << endl;
    pgs->print();
}