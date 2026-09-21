#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void fillArray(int (&arr)[10])
{
    for (auto& x : arr)
    {
        x = rand() % 100;
    }
}

void printArray(const int (&arr)[10])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

void swapElements(int (&arr)[10], int& index1, int& index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
