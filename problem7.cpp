//use an input iterator 
#include <iostream>
#include <fstream>
#include <numeric>
#include <iterator>

using namespace std;

int main()
{
    int data[4] = {1,2,3,4};

    cout << "Sum of data is " << accumulate(data, data + 4, 5) << endl;

    return 0;
}