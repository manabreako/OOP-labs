/**
 * @file labs1.c++
 * @brief Лабораторная работа №1. Работа со статическим массивом.
 *
 * Программа создаёт массив из 10 целых чисел,
 * заполняет его случайными значениями, выводит массив,
 * меняет местами два элемента и умножает все элементы на 2.
 *
 * @author Куртнебиев Р. Р.
 * @date 21.09.2026
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

/**
 * @brief Заполняет массив случайными числами.
 *
 * Каждому элементу массива присваивается случайное число
 * от 0 до 99.
 *
 * @param arr Массив из 10 целых чисел.
 */

void fillArray(int (&arr)[10])
{
    for (auto& x : arr)
    {
        x = rand() % 100;
    }
}

/**
 * @brief Выводит элементы массива на экран.
 *
 * @param arr Массив из 10 целых чисел.
 */

void printArray(const int (&arr)[10])
{
    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
}

/**
 * @brief Меняет местами два элемента массива.
 *
 * @param arr Массив из 10 целых чисел.
 * @param index1 Индекс первого элемента.
 * @param index2 Индекс второго элемента.
 */

void swapElements(int (&arr)[10], int& index1, int& index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

/**
 * @brief Умножает каждый элемент массива на 2.
 *
 * @param arr Массив из 10 целых чисел.
 */

void multiplyByTwo(int (&arr)[10])
{
    for (int& x : arr)
    {
        x *= 2;
    }
}

/**
 * @brief Главная функция программы.
 *
 * Создаёт массив из 10 целых чисел, заполняет его случайными
 * значениями, выводит массив, меняет местами первые два элемента,
 * а затем умножает все элементы на 2.
 *
 * @return 0 Если программа завершилась успешно.
 */

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand(time(0));
    int arr[10];
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
