
#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

const double eps = 0.00001;

using namespace std;

double function(double x) {
	return 1/(pow(log(x),2)+1);
}

double fun_cube_simpson(double x, double y) {
	return sin(x+y);
}
void trapec(double a, double b) {
	int n = 2;
	double h = 0;
	double integral = 0, integral_h_2, sum;
	int temp = 0;
	do {
		h = (b - a) / n;
		integral_h_2 = integral;
		integral = function(a) + function(b);
		sum = 0.0;
		for (int i = 1; i < n; i++) {
			sum += 2 * function(a + i * h);
		}
		integral += sum;
		integral *= h / 2;
		n *= 2;
		cout << "Step #" << temp + 1 << " n = " << n << " h = " << h << " sum = " << integral << endl << endl;
		temp++;
	} while (fabs(integral_h_2 - integral) >= 3 * eps);
	cout << " Integral by Trapec = " << integral << endl;
	cout << " n for Trapec = " << n << endl;
	cout << " Step h = " << h << endl << endl;
}

void simpson(double a, double b) {

	int m = 1, n = 2 * m;
	double h;
	double integral = 0, integral_h_2, sum;
	int temp = 0;
	do {

		h = (b - a) / n;
		integral_h_2 = integral;
		integral = function(a) + function(b);
		sum = 0;
		for (int i = 1; i < n; i++) {
			if (i % 2 != 0)
				sum += 4 * function(a + i * h);

			else
				sum += 2 * function(a + i * h);
		}
		integral += sum;
		integral *= h / 3;

		n *= 2;
		cout << "Step #" << temp + 1 << " n = " << n << " h = " << h << " sum = " << integral << endl << endl;
		temp++;
	} while (fabs(integral_h_2 - integral) >= 15 * eps);
	cout << " Integral by Simpson = " << integral << endl;
	cout << " n for Simpson = " << n << endl;
	cout << " Step h = " << h << endl << endl;
}

void cube_simpson(double a, double b, double c, double d) {
	int m = 2, n = 2 * m;
	double hx = (b - a) / (2 * n), hy = (d - c) / n;
	double integral = 0, sum = 0;

	double xi = a;
	double yi = c;

	double* Xi = new double[2 * n + 1];
	Xi[0] = xi;

	for (int i = 1; i <= 2 * n; i++)
		Xi[i] = Xi[i - 1] + hx;;

	double* Yi = new double[2 * m + 1];
	Yi[0] = yi;

	for (int j = 1; j <= 2 * m; j++)
		Yi[j] = Yi[j - 1] + hy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += fun_cube_simpson(Xi[2 * i], Yi[2 * j]);
			sum += 4 * fun_cube_simpson(Xi[2 * i + 1], Yi[2 * j]);
			sum += fun_cube_simpson(Xi[2 * i + 2], Yi[2 * j]);
			sum += 4 * fun_cube_simpson(Xi[2 * i], Yi[2 * j + 1]);
			sum += 16 * fun_cube_simpson(Xi[2 * i + 1], Yi[2 * j + 1]);
			sum += 4 * fun_cube_simpson(Xi[2 * i + 2], Yi[2 * j + 1]);
			sum += fun_cube_simpson(Xi[2 * i], Yi[2 * j + 2]);
			sum += 4 * fun_cube_simpson(Xi[2 * i + 1], Yi[2 * j + 2]);
			sum += fun_cube_simpson(Xi[2 * i + 2], Yi[2 * j + 2]);
		}
	}
	integral += sum;
	integral *= (hx * hy / 9);
	cout << " Integral by Cube Simpson = " << integral << endl;
	cout << " hx = " << hx << ", hy = " << hy << endl;
}

