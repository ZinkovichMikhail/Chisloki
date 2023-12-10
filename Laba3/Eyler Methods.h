#pragma once
double func(double* u, double t, int n);
double** createMatrix(int x);
void deleteMatrix(double** X, int x);
void copyMatrix(double** matrix, double** copyMatrix, int x);
double f1(double* uk1, double* uk, double t, double Tau);
double f2(double* uk1, double* uk, double t, double Tau);
bool Gauss(double* An, double** X, int x);
typedef double(*pf)(double*, double*, double, double);
double Differential(pf f, double* uk1, double* uk, double t, double Tau, int n);
double* neutone(double* yk_plus, double* yk, double tk, double Tau, int n);
void eilerImplicit(double* u, int n);
void eilerExplicit(double* u, int n);
