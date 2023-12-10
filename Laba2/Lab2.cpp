#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// const variables
int NIT = 30;
int n = 2;
double e1 = 10e-9;
double e2 = 10e-9;

// start functions
// var 6
double f1(double x1, double x2) {
	return pow(x1, 3) + pow(x2, 3) - 6 * x1 + 3;
}

double f2(double x1, double x2) {
	return pow(x1, 3) - pow(x2, 3) - 6 * x2 + 2;
}

//double f3(double x1, double x2, double x3) {
//	return x3 + pow(x3, 2) + 2 * x1 * x2 - 0.3;
//}

// Gauss for nev
void Gauss(double** matrix, double* dx, int n) {
	double tmp;
	for (int i = 0; i < n; i++)
	{
		double max = fabs(matrix[i][i]);
		int save = i;
		for (int j = i + 1; j < n; j++) {
			if (fabs(matrix[j][i]) > max) {
				max = fabs(matrix[i][j]);
				save = j;
			}
		}
		swap(matrix[i], matrix[save]);
		tmp = matrix[i][i];
		for (int j = n; j >= i; j--)
			matrix[i][j] /= tmp;
		for (int j = i + 1; j < n; j++)
		{
			tmp = matrix[j][i];
			for (int k = n; k >= i; k--)
				matrix[j][k] -= tmp * matrix[i][k];
		}
	}
	dx[n - 1] = matrix[n - 1][n];
	for (int i = n - 2; i >= 0; i--) {
		dx[i] = matrix[i][n];
		for (int j = i + 1; j < n; j++) {
			dx[i] -= matrix[i][j] * dx[j];
		}
	}
}

// for n = 2
void nev(double* F, double* x) {
	F[0] = f1(x[0], x[1]);
	F[1] = f2(x[0], x[1]);
}

// for n = 3
//void nev(double* F, double* x) {
//	F[0] = f1(x[0], x[1], x[2]);
//	F[1] = f2(x[0], x[1], x[2]);
//	F[2] = f3(x[0], x[1], x[2]);
//}


// find derivatives
// M = îòíîñèòåëüíîå ïðèðàùåíèå
double derivative_for_x(double* x, double (*func)(double, double), double M) {
	double temp;
	if (x[0] == 0) {
		temp = 10e-5;
	}
	else {
		temp = M * x[0];
	}
	return (func(x[0] + temp, x[1]) - func(x[0], x[1])) / temp;
}

double derivative_for_x(double* x, double (*func)(double, double, double), double M) {
	double temp;
	if (x[0] == 0) {
		temp = 10e-5;
	}
	else {
		temp = M * x[0];
	}
	return (func(x[0] + temp, x[1], x[2]) - func(x[0], x[1], x[2])) / temp;
}

double derivative_for_y(double* x, double (*func)(double, double), double M) {
	double temp;
	if (x[1] == 0) {
		temp = 10e-5;
	}
	else {
		temp = M * x[1];
	}
	return (func(x[0], x[1] + temp) - func(x[0], x[1])) / temp;
}

double derivative_for_y(double* x, double (*func)(double, double, double), double M) {
	double temp;
	if (x[1] == 0) {
		temp = 10e-5;
	}
	else {
		temp = M * x[1];
	}
	return (func(x[0], x[1] + temp, x[2]) - func(x[0], x[1], x[2])) / temp;
}

double derivative_for_z(double* x, double (*func)(double, double, double), double M) {
	double temp;
	if (x[2] == 0) {
		temp = 10e-5;
	}
	else {
		temp = M * x[2];
	}
	return (func(x[0], x[1], x[2] + temp) - func(x[0], x[1], x[2])) / temp;
}

// find Jacobian
void Jacobian(double** J, double* x, double M) {
	if (n == 2) {
		J[0][0] = derivative_for_x(x, f1, M);
		J[0][1] = derivative_for_y(x, f1, M);
		J[1][0] = derivative_for_x(x, f2, M);
		J[1][1] = derivative_for_y(x, f2, M);
	}
	//else { // for n = 3
	//	J[0][0] = derivative_for_x(x, f1, M);
	//	J[0][1] = derivative_for_y(x, f1, M);
	//	J[0][2] = derivative_for_z(x, f1, M);
	//	J[1][0] = derivative_for_x(x, f2, M);
	//	J[1][1] = derivative_for_y(x, f2, M);
	//	J[1][2] = derivative_for_z(x, f2, M);
	//	J[2][0] = derivative_for_x(x, f3, M);
	//	J[2][1] = derivative_for_y(x, f3, M);
	//	J[2][2] = derivative_for_z(x, f3, M);
	//}
}

void copy(double** J, double** matrix, double* F) {
	matrix[0][0] = J[0][0];	matrix[0][1] = J[0][1];	/*matrix[0][2] = J[0][2];*/ matrix[0][2] = -F[0];
	matrix[1][0] = J[1][0];	matrix[1][1] = J[1][1];	/*matrix[1][2] = J[1][2];*/ matrix[1][2] = -F[1];
	/*matrix[2][0] = J[2][0]; matrix[2][1] = J[2][1]; matrix[2][2] = J[2][2]; matrix[2][3] = -F[2];*/
}

void sum(double* x, double* dx) {
	for (int i = 0; i < n; i++) {
		x[i] = x[i] + dx[i];
	}
}

void nuton(double** J, double* F, double* x, double* xk, double M) {
	int k = 1;
	double** matrix = new double* [n];
	for (int i = 0; i < n; i++) {
		matrix[i] = new double[n + 1];
	}
	double* dx = new double[n];
	double max1 = 0;
	double max2 = 0;
	double d1 = 0;
	double d2 = 0;
	double* x_save = new double[n];
	for (int i = 0; i < n; i++) {
		x_save[i] = x[i];
	}
	while (true) {
		cout << setw(7) << "k = " << k << setw(7) << "d1 = " << d1 << setw(7) << " d2 = " << d2 << endl;
		nev(F, x);
		Jacobian(J, x, M);
		copy(J, matrix, F);
		Gauss(matrix, dx, n);
		for (int i = 0; i < n; i++) {
			xk[i] = x[i];
		}
		cout << "Nevyazka: ";
		for (int i = 0; i < n; i++) {
			cout << F[i] << "  ";
		}
		cout << endl;
		cout << setw(10) << "xk = ( ";
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				cout << xk[i] << " )";
			}
			else cout << xk[i] << "; ";
		}
		cout << endl;
		sum(x, dx);
		cout << setw(10) << "   x(k + 1) = ( ";
		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				cout << x[i] << " )";
			}
			else cout << x[i] << "; ";
		}
		cout << endl;
		if (k >= NIT) {
			cout << "IER = 2" << endl;
			break;
		}
		k++;
		max1 = fabs(F[0]);
		for (int i = 0; i < n; i++) {
			if (max1 < fabs(F[i])) {
				max1 = fabs(F[i]);
			}
		}
		d1 = max1;
		for (int i = 0; i < n; i++) {
			if (fabs(x[i]) < 1) {
				max2 = fabs(x[i] - xk[i]);
			}
			else max2 = fabs((x[i] - xk[i]) / xk[i]);
		}
		d2 = max2;
		if (d1 <= e1 && d2 <= e2)
			break;

		cout << endl;
	}
	for (int i = 0; i < n; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
	delete[] dx;
	for (int i = 0; i < n; i++) {
		xk[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		x[i] = x_save[i];
	}
}
