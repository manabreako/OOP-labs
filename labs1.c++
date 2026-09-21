#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

void fillArray(int (&arr)[5])
{
    for (auto& x : arr)
    {
        x = rand() % 100;
    }
}

void printArray(const int (&arr)[5])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

void swapElements(int (&arr)[5], int& index1, int& index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void multiplyByTwo(int (&arr)[5])
{
    for (int& x : arr)
    {
        x *= 2;
    }
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(0));
    int arr[5];
    fillArray(arr);
    cout << "Исходный массив: ";
    printArray(arr);
    int index1 = 0;
    int index2 = 1;
    swapElements(arr, index1, index2);
    cout << "После обмена элементов: ";
    printArray(arr);
    multiplyByTwo(arr);
    cout << "После умножения на 2: ";
    printArray(arr);
    return 0;
}
