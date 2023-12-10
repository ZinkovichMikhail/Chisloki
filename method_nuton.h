#pragma once
double f1(double x1, double x2);
double f2(double x1, double x2);
void Gauss(double** matrix, double* dx, int n);
void nev(double* F, double* x);
double derivative_for_x(double* x, double (*func)(double, double), double M);
double derivative_for_x(double* x, double (*func)(double, double, double), double M);
double derivative_for_y(double* x, double (*func)(double, double), double M);
double derivative_for_y(double* x, double (*func)(double, double, double), double M);
double derivative_for_z(double* x, double (*func)(double, double, double), double M);
void Jacobian(double** J, double* x, double M);
void copy(double** J, double** matrix, double* F);
void sum(double* x, double* dx);
void nuton(double** J, double* F, double* x, double* xk, double M);
