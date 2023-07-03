#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>

using namespace std;

void printVector(vector<int> vec)
{
    for (auto a = vec.begin(); a != vec.end(); ++a)
    {
        cout << *a << " ";
    }
    cout << endl;
}

void merge(vector<int> vec, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - l;
    vector<int> L(n1),R(n2);
    
    for (int i = 0; i < n1; ++i)
        L[i] = vec[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = vec[m + 1 + i];

    printVector(L);
    printVector(R);

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vec[k] = L[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        vec[k] = L[j];
        k++;
        j++;
    }
}

void mergeSort(vector<int> vec, int l, int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(vec, l, m);
        mergeSort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}



int main()
{
    int left, right, mid;
    vector<int> num;
    srand(clock());
     
    for (int i = 0; i < 10; i++)
    {
        int n = (rand() % 10) + 1;
        num.push_back(n);
    }
     
    printVector(num);
    cout << endl;
    cout << "Sorted array:\n";
    mergeSort(num, 0, num.size() - 1);
    
    printVector(num);
    return 0;
}