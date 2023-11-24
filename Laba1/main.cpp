//#include "Lab1.h";
#include "Lab1d.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    //int n = 3;
    //double L1, L2, L3;
    ////Вводим наши Л1 Л2 Л35
    //cout << "Write L1, L2 and L3" << endl;
    //cin >> L1 >> L2 >> L3;

    //double** matrix_full = new double* [n];
    //for (int i = 0; i < n; i++) {
    //    matrix_full[i] = new double[n];
    //}
    //double* matrix_answers = new double[n];

    //double** matrix_L = new double* [n];
    //for (int i = 0; i < n; i++) {
    //    matrix_L[i] = new double[n];
    //}
    //double** matrix_D = new double* [n];
    //for (int i = 0; i < n; i++) {
    //    matrix_D[i] = new double[n];
    //}
    //double** matrix_a_slash = new double* [n];
    //for (int i = 0; i < n; i++) {
    //    matrix_a_slash[i] = new double[n];
    //}

    //double** matrix_LT = new double* [n];
    //for (int i = 0; i < n; i++) {
    //    matrix_LT[i] = new double[n];
    //}

    //// Используем функции заполнения и вывода
    //fill_matrix(matrix_full, matrix_answers, n, L1, L2, L3);
    //print_matrix(matrix_full, n);

    //// Создаем и заполняем матрицы
    //create_and_fill_matrices(matrix_full, matrix_L, matrix_D, matrix_a_slash, matrix_LT, matrix_answers, n);

    //// Выводим три матрицы
    //cout << "Matrix L: " << endl;
    //print_matrix(matrix_L, n);
    //cout << endl << "Matrix D: " << endl;
    //print_matrix(matrix_D, n);
    //cout << endl << "Matrix LT: " << endl;
    //print_matrix(matrix_LT, n);

    //// Выводим ответы
    //print_answers(matrix_L, matrix_D, matrix_LT, matrix_answers, n);

    //// Освобождаем память
    //delete_memory(matrix_full, matrix_L, matrix_D, matrix_a_slash, matrix_LT, matrix_answers, n);

    //return 0;
   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "Write 'n' count of strings and columns" << endl << "n = ";
    int n;
    cin >> n;
    cout << endl;
    double** matrix_full = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix_full[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        cout << "Write " << i + 1 << " string" << endl;
        for (int j = 0; j < n; j++) {
            cin >> matrix_full[i][j];
        }
        cout << endl;
    }
    double** matrix_full_copy = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix_full_copy[i] = new double[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix_full_copy[i][j] = matrix_full[i][j];
        }
    }
    cout << "Write column of answers" << endl;
    double* matrix_answers = new double[n];
    for (int i = 0; i < n; i++) {
        cin >> matrix_answers[i];
    }
    double* matrix_answers_copy = new double[n];
    for (int i = 0; i < n; i++) {
        matrix_answers_copy[i] = matrix_answers[i];
    }
    print_matrix(matrix_full, matrix_answers, n);

    double* answers = find_x(matrix_full, matrix_answers, n);
    if (answers == 0) return 0;
    for (int i = 0; i < n; i++) {
        cout << "X" << i + 1 << " = " << answers[i] << " ";
    }
    cout << endl;
    cout << "Vector nevyaz: ";
    double* vectorNevya = vectorNevyaz(matrix_full_copy, matrix_answers_copy, answers, n);
    for (int i = 0; i < n; i++) {
        cout << vectorNevya[i] << " ";
    }
    double norma = vectorNevya[0];
    for (int i = 0; i < n; i++) {
        if (vectorNevya[i] > norma) {
            norma = vectorNevya[i];
        }
    }
    cout << endl << "Norma: " << norma << endl;

    double* new_answers = find_x(matrix_full_copy, answers, n);
    cout << endl << "New X:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "X" << i + 1 << " = " << new_answers[i] << " ";
    }
    cout << endl << "Fault: " << fault(answers, new_answers, n);

    // Очистка памяти
    delete[] answers;
    delete[] matrix_answers;
    delete[] matrix_answers_copy;
    for (int i = 0; i < n; i++) {
        delete[] matrix_full[i];
    }
    delete[] matrix_full;
    for (int i = 0; i < n; i++) {
        delete[] matrix_full_copy[i];
    }
    delete[] matrix_full_copy;

    return 0;
}
