#include <iostream>
#include <iterator>
#include <string>
using namespace std;

template <typename Bidirectional>

bool isPalindrome(Bidirectional first, Bidirectional last)
{
    while(true)
    {
        last--;
        if(first == last)
            break;
        if(*first != *last)
            return false;
        first++;
        if(first == last)
            break;
    }
    return true;
}

int main()
{
    string p = "color";


    bool a = isPalindrome(p.begin(),p.end());
    if(a)
        cout << p << " is a palindrome" << endl;
    else
        cout << p << " is not a palindrome" << endl;
}