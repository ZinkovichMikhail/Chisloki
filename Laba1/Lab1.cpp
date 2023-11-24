#include <iostream>
#include <iomanip>

using namespace std;

// Âûâîäèì ìàòðèöó
void print_matrix(double** matrix_full, int n) {
    cout.precision(3);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(14) << matrix_full[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

// Çàïîëíåíèå ìàòðèöû
void fill_matrix(double** matrix_full, double* matrix_answers, int n, double L1, double L2, double L3) {
    matrix_full[0][0] = (2 * L1) + (4 * L2);
    matrix_full[0][1] = 2 * (L1 - L2);
    matrix_full[0][2] = 2 * (L1 - L2);
    matrix_full[1][0] = 2 * (L1 - L2);
    matrix_full[1][1] = (2 * L1) + L2 + (3 * L3);
    matrix_full[1][2] = (2 * L1) + L2 - (3 * L3);
    matrix_full[2][0] = 2 * (L1 - L2);
    matrix_full[2][1] = (2 * L1) + L2 - (3 * L3);
    matrix_full[2][2] = (2 * L1) + L2 + (3 * L3);

    matrix_answers[0] = (-4 * L1) - (2 * L2);
    matrix_answers[1] = (-4 * L1) + L2 + (9 * L3);
    matrix_answers[2] = (-4 * L1) + L2 - (9 * L3);
}

// Ñîçäàíèå è çàïîëíåíèå ìàòðèöû L, D è LT
void create_and_fill_matrices(double** matrix_full, double** matrix_L, double** matrix_D, double** matrix_a_slash, double** matrix_LT, double* matrix_answers, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) break;
            if (i == 0) {
                matrix_D[j][j] = matrix_full[j][j];
            }
            else {
                if (i == j) {
                    double sum_d = 0;
                    for (int k = 0; k <= i - 1; k++) {
                        sum_d += matrix_a_slash[j][k] * matrix_L[j][k];
                    }
                    matrix_D[j][j] = matrix_full[j][j] - sum_d;
                    sum_d = 0;
                }
            }
            if (j == 0) {
                matrix_a_slash[i][j] = matrix_full[i][j];
            }
            else {
                if (j != n) {
                    double sum_a = 0;
                    for (int k = 0; k < i - 1; k++) {
                        sum_a += matrix_a_slash[i][k] * matrix_L[j][k];
                    }
                    matrix_a_slash[i][j] = matrix_full[i][j] - sum_a;
                    sum_a = 0;
                }
            }
            matrix_L[i][j] = matrix_a_slash[i][j] / matrix_D[j][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                matrix_LT[i][j] = 1;
            }
            if (j < i) {
                matrix_LT[j][i] = matrix_L[i][j];
            }

        }
    }
    for (int i = 0; i < n; i++) {
        matrix_L[i][i] = 1;
        matrix_LT[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j) {
                matrix_L[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j < i) {
                matrix_LT[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j != i) {
                matrix_D[i][j] = 0;
            }
        }
    }
}

// Âûâîä îòâåòîâ
void print_answers(double** matrix_L, double** matrix_D, double** matrix_LT, double* matrix_answers, int n) {
    double* answers_L = new double[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (i == 0) {
                answers_L[i] = matrix_answers[i] / matrix_L[i][j];
            }
            else {
                double sum = 0;
                for (int k = 0; k < j; k++) {
                    sum += answers_L[k] * matrix_L[i][k];
                }
                answers_L[i] = (matrix_answers[i] - sum) / matrix_L[i][j];
            }

        }
    }
    double* answers_D = new double[n];
    for (int i = 0; i < n; i++) {
        answers_D[i] = answers_L[i] / matrix_D[i][i];
    }
    double* answers_LT = new double[n];
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 == n) {
            answers_LT[i] = answers_D[i] / matrix_LT[i][i];
        }
        else {
            double sum = 0;
            for (int j = n - 1; j > i; j--) {
                sum += matrix_LT[i][j] * answers_LT[j];
            }
            answers_LT[i] = (answers_D[i] - sum) / matrix_LT[i][i];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "X" << i + 1 << " = " << answers_LT[i] << " ";
    }
    delete[] answers_D;
    delete[] answers_L;
    delete[] answers_LT;
}

// Îñâîáîæäåíèå ïàìÿòè
void delete_memory(double** matrix_full, double** matrix_L, double** matrix_D, double** matrix_a_slash, double** matrix_LT, double* matrix_answers, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix_full[i];
    }
    delete[] matrix_full;
    for (int i = 0; i < n; i++) {
        delete[] matrix_L[i];
    }
    delete[] matrix_L;
    for (int i = 0; i < n; i++) {
        delete[] matrix_D[i];
    }
    delete[] matrix_D;
    for (int i = 0; i < n; i++) {
        delete[] matrix_a_slash[i];
    }
    delete[] matrix_a_slash;
    delete[] matrix_answers;
    for (int i = 0; i < n; i++) {
        delete[] matrix_LT[i];
    }
    delete[] matrix_LT;
}
