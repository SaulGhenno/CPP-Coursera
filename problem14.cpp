#include <iostream>
#include <iterator>
#include <string>
#include <algorithm>
using namespace std;

//template<class InputIter, class T>
//InputIter find(InputIter b, InputIter e, const T& t);

//template<class RandAcc>
//void sort(RandAcc b, RandAcc e);

int main()
{
    string words[5] = {"my", "hop", "mop", "hope", "cope"};
    string* where;

    where = find(words, words + 5, "hop");
    cout << *++where << endl;
    sort(words, words + 5);
    where = find(words, words + 5, "hop");
    cout << *++where << endl;
}