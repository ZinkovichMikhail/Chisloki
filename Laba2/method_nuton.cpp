#include "method_nuton.h"
#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main() {
	int n = 2;
	// initial approximation
	double x1 = -3;
	double x2 = -1.5;
	/*double x3 = 0;*/
	double* x0 = new double[n] {x1, x2};

	double** J = new double* [n];
	for (int i = 0; i < n; i++) {
		J[i] = new double[n];
	}

	double* F = new double[n];
	double* xk = new double[n] {0, 0};

	// main part
	cout << "For M = 0.01 : " << endl;
	nuton(J, F, x0, xk, 0.01);

	cout << endl << endl;
	cout << "For M = 0.05 : " << endl;
	nuton(J, F, x0, xk, 0.05);

	cout << endl << endl;
	cout << "For M = 0.1 : " << endl;
	nuton(J, F, x0, xk, 0.1);

	// clearing memory
	for (int i = 0; i < n; i++) {
		delete[] J[i];
	}
	delete[] J;
	delete[] x0;
	delete[] F;
	delete[] xk;
}

