/**
 * @file main.cpp
 * @brief Работа с безопасным динамическим массивом.
 *
 * Программа реализует структуру SafeArray для хранения динамического
 * массива целых чисел и его размера.
 *
 * Реализованы функции для создания массива, безопасного получения
 * элемента, вывода содержимого и изменения размера массива.
 *
 * @author Куртнебиев Р.Р.
 * @date 23.09.2026
 */

#include <iostream>
#include <windows.h>
using namespace std;

/**
 * @struct SafeArray
 * @brief Структура для хранения динамического массива.
 *
 * Содержит указатель на динамический массив целых чисел
 * и его текущий размер.
 */

struct SafeArray
{
    int* data;
    int size;
};

/**
 * @brief Создаёт динамический массив заданного размера.
 *
 * Выделяет память под массив целых чисел и заполняет
 * все его элементы нулевыми значениями.
 *
 * @param size Размер создаваемого массива.
 * @return SafeArray Структура с созданным массивом и его размером.
 *
 * @warning Параметр size должен быть неотрицательным.
 */

SafeArray createArray(int size)
{
    SafeArray arr;

    arr.data = new int[size]{};
    arr.size = size;

    return arr;
}

/**
 * @brief Безопасно получает элемент массива по индексу.
 *
 * Проверяет, находится ли указанный индекс в допустимых границах
 * массива. Если индекс корректный, возвращается ссылка на элемент.
 * При выходе за границы выводится сообщение об ошибке.
 *
 * @param arr Ссылка на структуру SafeArray.
 * @param index Индекс элемента, который необходимо получить.
 * @return Ссылка на элемент массива.
 *         При некорректном индексе возвращается ссылка на статическую
 *         переменную errorValue.
 *
 * @note Возвращаемая ссылка позволяет не только прочитать,
 *       но и изменить значение элемента массива.
 *
 * @warning При некорректном индексе изменение возвращаемого значения
 *          не изменяет исходный массив.
 */

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

/**
 * @brief Выводит содержимое массива на экран.
 *
 * Последовательно выводит все элементы массива через пробел.
 *
 * @param arr Константная ссылка на структуру SafeArray.
 *
 * @note Функция не изменяет содержимое массива.
 */

void printSafe(const SafeArray& arr)
{
    for (int i = 0; i < arr.size; i++)
    {
        cout << arr.data[i] << " ";
    }

    cout << endl;
}

/**
 * @brief Изменяет размер динамического массива.
 *
 * Создаёт новый массив указанного размера и копирует в него
 * существующие элементы старого массива.
 *
 * Если новый размер меньше текущего, лишние элементы выводятся
 * перед удалением.
 *
 * @param arr Ссылка на структуру SafeArray, размер которой изменяется.
 * @param newSize Новый размер массива.
 *
 * @details При уменьшении массива копируются только элементы,
 * которые помещаются в новый размер. При увеличении массива
 * все существующие элементы сохраняются, а новые элементы
 * инициализируются нулями.
 *
 * @warning Параметр newSize должен быть неотрицательным.
 */

void reSizeArray(SafeArray& arr, int newSize)
{
    if (newSize < arr.size)
    {
        cout << "Удалённые элементы: ";

        for (int i = newSize; i < arr.size; i++)
        {
            cout << arr.data[i] << " ";
        }

        cout << endl;
    }

    int* newData = new int[newSize]{};

    int copySize;

    if (newSize < arr.size)
    {
        copySize = newSize;
    }
    else
    {
        copySize = arr.size;
    }

    for (int i = 0; i < copySize; i++)
    {
        newData[i] = arr.data[i];
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = newSize;
}

/**
 * @brief Точка входа в программу.
 *
 * Создаёт безопасный динамический массив, заполняет его,
 * изменяет отдельный элемент, проверяет выход за границы,
 * уменьшает и увеличивает размер массива.
 *
 * @return 0 При успешном завершении программы.
 *
 * @details В конце работы программы динамическая память освобождается,
 * указатель на массив обнуляется, а размер устанавливается в 0.
 */

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
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

    cout << endl;
    cout << "Уменьшаем массив с 5 до 3 элементов:" << endl;

    reSizeArray(myArr, 3);

    cout << "Массив после уменьшения: ";
    printSafe(myArr);

    cout << endl;
    cout << "Увеличиваем массив с 3 до 6 элементов:" << endl;

    reSizeArray(myArr, 6);

    cout << "Массив после увеличения: ";
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;
    myArr.size = 0;

    cout << endl;
    cout << "Память освобождена, указатель обнулён." << endl;

    return 0;
}