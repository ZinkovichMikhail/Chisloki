#include "Lab1.h";
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n = 3;
    double L1, L2, L3;
    //������ ���� �1 �2 �35
    cout << "Write L1, L2 and L3" << endl;
    cin >> L1 >> L2 >> L3;

    double** matrix_full = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix_full[i] = new double[n];
    }
    double* matrix_answers = new double[n];

    double** matrix_L = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix_L[i] = new double[n];
    }
    double** matrix_D = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix_D[i] = new double[n];
    }
    double** matrix_a_slash = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix_a_slash[i] = new double[n];
    }

    double** matrix_LT = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix_LT[i] = new double[n];
    }

    // ���������� ������� ���������� � ������
    fill_matrix(matrix_full, matrix_answers, n, L1, L2, L3);
    print_matrix(matrix_full, n);

    // ������� � ��������� �������
    create_and_fill_matrices(matrix_full, matrix_L, matrix_D, matrix_a_slash, matrix_LT, matrix_answers, n);

    // ������� ��� �������
    cout << "Matrix L: " << endl;
    print_matrix(matrix_L, n);
    cout << endl << "Matrix D: " << endl;
    print_matrix(matrix_D, n);
    cout << endl << "Matrix LT: " << endl;
    print_matrix(matrix_LT, n);

    // ������� ������
    print_answers(matrix_L, matrix_D, matrix_LT, matrix_answers, n);

    // ����������� ������
    delete_memory(matrix_full, matrix_L, matrix_D, matrix_a_slash, matrix_LT, matrix_answers, n);

    return 0;
}
