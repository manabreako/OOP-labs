#include <iostream>

using namespace std;

struct SafeArray
{
    int* data;
    int size;
};

SafeArray createArray(int size)
{
    SafeArray arr;

    arr.data = new int[size]{};
    arr.size = size;

    return arr;
}

int& getElement(SafeArray& arr, int index)
{

    if (index < 0 || index >= arr.size)
    {
        cout << "Ошибка: индекс выходит за границы массива!" << endl;

        static int errorValue = 0;

        return errorValue;
    }

    return arr.data[index];
}