#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}

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

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

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
