#include "Lab_5.h"
#define _USE_MATH_DEFINES

#include<iostream>
#include<cmath>

using namespace std;

int main() {
	double a = 1.0;
	double b = 2.835;

	trapec(a, b);
	cout << "--------------------------------------------------------------------" << endl;
	simpson(a, b);
	cout << "--------------------------------------------------------------------" << endl;
	a = 0;
	b = M_PI/2;
	double c = 0;
	double d = M_PI/4;
	cube_simpson(a, b, c, d);
}
