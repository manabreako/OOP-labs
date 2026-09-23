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

        // Статическая переменная-заглушка
        static int errorValue = 0;

        return errorValue;
    }

    return arr.data[index];
}

void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        cout << arr.data[i] << " ";
    }

    cout << endl;
}

int main()
{
    SafeArray myArr = createArray(5);

    for (int i = 0; i < myArr.size; i++)
    {
        myArr.data[i] = (i + 1) * 10;
    }

    cout << "Исходный массив: ";
    printSafe(myArr);

    getElement(myArr, 2) = 999;

    cout << "После изменения элемента: ";
    printSafe(myArr);

    getElement(myArr, 10) = 500;

    cout << "После попытки обратиться за границу: ";
    printSafe(myArr);

    return 0;
}