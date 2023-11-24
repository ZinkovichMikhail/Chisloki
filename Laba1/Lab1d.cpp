#include <iostream>
#include <iomanip>

using namespace std;

// Ôóíêöèÿ äëÿ ïå÷àòè ìàòðèöû è ñòîëáöà îòâåòîâ
void print_matrix(double** matrix_full, double* matrix_answers, int n) {
    cout << endl << "Matrix: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(10) << matrix_full[i][j];
        }
        cout << setw(10) << matrix_answers[i];
        cout << endl;
    }
    cout << endl;
}

// Ôóíêöèÿ äëÿ âû÷èñëåíèÿ âåêòîðà íåâÿçîê
double* vectorNevyaz(double** matrix_full, double* matrix_answers, double* answers, int n) {
    double* tempSum = new double[n] {};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tempSum[i] += matrix_full[i][j] * answers[j];
        }
    }
    for (int i = 0; i < n; i++) {
        tempSum[i] = tempSum[i] - matrix_answers[i];
    }
    return tempSum;
}

// Ôóíêöèÿ äëÿ ðåøåíèÿ ñèñòåìû ëèíåéíûõ óðàâíåíèé ìåòîäîì Ãàóññà
double* find_x(double** matrix_full, double* matrix_answers, int n) {
    for (int i = 0; i < n; i++) {
        double max_number = abs(matrix_full[i][i]);
        int max_column = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(matrix_full[j][i]) > max_number) {
                max_number = abs(matrix_full[j][i]);
                max_column = j;
            }
        }
        if (max_number == 0) {
            cout << "Bad type of matrix all main elements == 0";
            return 0;
        }
        swap(matrix_full[i], matrix_full[max_column]);
        swap(matrix_answers[i], matrix_answers[max_column]);
        print_matrix(matrix_full, matrix_answers, n);
        double divider = matrix_full[i][i];
        for (int k = i; k < n; k++) {
            matrix_full[i][k] /= divider;
        }
        matrix_answers[i] /= divider;
        double* save_string = new double[n + 1];
        for (int j = i; j < n; j++) {
            save_string[j] = matrix_full[i][j];
        }
        save_string[n] = matrix_answers[i];
        for (int j = i + 1; j < n; j++) {
            matrix_answers[j] -= save_string[n] * matrix_full[j][i];
            for (int k = n - 1; k >= i; k--) {
                matrix_full[j][k] -= save_string[k] * matrix_full[j][i];
            }
        }
        delete[] save_string;
    }
    print_matrix(matrix_full, matrix_answers, n);

    double* answers = new double[n];
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 == n) {
            answers[i] = matrix_answers[i] / matrix_full[i][i];
        }
        else {
            double sum = 0;
            for (int j = n - 1; j > i; j--) {
                sum += matrix_full[i][j] * answers[j];
            }
            answers[i] = (matrix_answers[i] - sum) / matrix_full[i][i];
        }
    }
    return answers;
}

// Ôóíêöèÿ äëÿ âû÷èñëåíèÿ îòíîñèòåëüíîé îøèáêè
double fault(double* answers, double* new_answers, int n) {
    double* result = new double[n];
    for (int i = 0; i < n; i++) {
        result[i] = new_answers[i] - answers[i];
    }
    double max_up = result[0];
    for (int i = 1; i < n; i++) {
        if (max_up < result[i]) {
            max_up = result[i];
        }
    }
    double max_down = answers[0];
    for (int i = 1; i < n; i++) {
        if (max_down < answers[i]) {
            max_down = answers[i];
        }
    }
    return max_up / max_down;
}
