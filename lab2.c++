#include <iostream>

using namespace std;

int process(int*& arr, int size)
{
    int negativeIndex = -1;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            negativeIndex = i;
            break;
        }
    }

    if (negativeIndex == -1)
    {
        return size;
    }

    int newSize = negativeIndex;

    int* newArr = new int[newSize]{};

    for (int i = 0; i < newSize; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;

    arr = newArr;

    return newSize;
}

int main()
{
    int N;

    cout << "Введите размер массива: ";
    cin >> N;

    int* arr = new int[N]{};

    cout << "Введите элементы массива:" << endl;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << "Исходный массив: ";

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    int newSize = process(arr, N);

    delete[] arr;

    arr = nullptr;

    return 0;
}