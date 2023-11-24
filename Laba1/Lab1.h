#pragma once
void print_matrix(double** matrix_full, int n);
void fill_matrix(double** matrix_full, double* matrix_answers, int n, double L1, double L2, double L3);
void create_and_fill_matrices(double** matrix_full, double** matrix_L, double** matrix_D, double** matrix_a_slash, double** matrix_LT, double* matrix_answers, int n);
void print_answers(double** matrix_L, double** matrix_D, double** matrix_LT, double* matrix_answers, int n);
void delete_memory(double** matrix_full, double** matrix_L, double** matrix_D, double** matrix_a_slash, double** matrix_LT, double* matrix_answers, int n);
