/**
 * @file main.cpp
 * @brief Работа с динамической двумерной матрицей.
 *
 * Программа создаёт динамическую матрицу целых чисел,
 * заполняет её данными пользователя и выводит на экран.
 *
 * Для работы с матрицей используются отдельные функции
 * для выделения памяти, заполнения, вывода и освобождения памяти.
 *
 * Функция printMatrix() поддерживает необязательные параметры
 * для отображения рамки и задания заголовка матрицы.
 *
 * @author Куртнебиев Р.Р.
 * @date 23.09.2026
 */
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

/**
 * @brief Выделяет память для двумерной динамической матрицы.
 *
 * Создаёт массив указателей на строки, после чего для каждой строки
 * выделяет память под заданное количество элементов.
 *
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 * @return Указатель на созданную двумерную матрицу.
 *
 * @warning Параметры rows и cols должны быть неотрицательными.
 */

int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}

/**
 * @brief Заполняет матрицу значениями с клавиатуры.
 *
 * Последовательно считывает значения для каждого элемента
 * двумерной матрицы.
 *
 * @param matrix Указатель на двумерную матрицу.
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 *
 * @note Значения вводятся построчно слева направо.
 */

void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Выводит матрицу на экран.
 *
 * Выводит заголовок и элементы матрицы.
 * При необходимости вокруг матрицы отображается рамка.
 *
 * @param matrix Указатель на двумерную матрицу.
 * @param rows Количество строк матрицы.
 * @param cols Количество столбцов матрицы.
 * @param showBorders Флаг отображения рамки.
 *        По умолчанию true.
 * @param title Заголовок матрицы.
 *        По умолчанию "Matrix".
 *
 * @details Если параметр showBorders равен true,
 * вокруг матрицы выводится рамка.
 * Если false, матрица выводится без рамки.
 */

void printMatrix(int** matrix, int rows, int cols,
                 bool showBorders = true, string title = "Matrix")
{
    cout << endl;
    cout << title << endl;

    if (showBorders)
    {
        cout << "------------------------" << endl;
    }

    for (int i = 0; i < rows; i++)
    {
        if (showBorders)
            cout << "| ";

        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        if (showBorders)
            cout << "|";

        cout << endl;
    }

    if (showBorders)
    {
        cout << "------------------------" << endl;
    }
}

/**
 * @brief Освобождает память, выделенную под матрицу.
 *
 * Сначала освобождает память каждой строки матрицы,
 * после чего освобождает массив указателей на строки.
 *
 * @param matrix Указатель на двумерную матрицу.
 * @param rows Количество строк матрицы.
 *
 * @note Функция должна вызываться после завершения работы
 *       с динамической матрицей.
 */

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

/**
 * @brief Точка входа в программу.
 *
 * Запрашивает у пользователя количество строк и столбцов,
 * создаёт динамическую матрицу, заполняет её значениями
 * и демонстрирует различные варианты её вывода.
 *
 * @return 0 При успешном завершении программы.
 *
 * @details Матрица выводится три раза:
 * с параметрами по умолчанию, с пользовательским заголовком
 * и без рамки. После завершения работы выделенная память
 * освобождается с помощью функции freeMatrix().
 */

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int rows;
    int cols;

    cout << "Введите количество строк: ";
    cin >> rows;

    cout << "Введите количество столбцов: ";
    cin >> cols;

    int** matrix = allocateMatrix(rows, cols);

    cout << "Введите элементы матрицы:" << endl;
    fillMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols);

    printMatrix(matrix, rows, cols, true, "Оценки студентов");

    printMatrix(matrix, rows, cols, false, "Матрица без рамки");

    freeMatrix(matrix, rows);

    return 0;
}
