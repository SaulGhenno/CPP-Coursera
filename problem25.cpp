#include <iostream>
#include <string>
#include <regex>
using namespace std;

int main()
{
    string fnames[] = {"data.txt", "graph.h", "01.PNG", "graph_data.txt"};
    regex txt_regex("[a-z]+\\.txt");

    for(int i = 0; i < 4; ++i)
        cout << fnames[i] << ": " << regex_match(fnames[i], txt_regex) << '\n';
}