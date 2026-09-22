#include <iostream>

using namespace std;

int main()
{
    int N;

    cout << "Введите размер массива: ";
    cin >> N;

    int* arr = new int[N]{};

    return 0;

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
}