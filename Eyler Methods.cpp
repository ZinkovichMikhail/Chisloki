#include "Eyler Methods.h"
#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

const double Eps = 0.001;
const int itr_max = 100;


int main()
{
	int n = 2;
	double* u = new double[n];

	cout << "Start value of U[0] = 0.0 U[1] = -0.412 " << endl;
	u[0] = 0.0;
	u[1] = -0.412;

	int method;
	cout << "1 - Explicit, 2 - Implicit" << endl;
	cin >> method;
	switch (method)
	{
	case 1:
	{
		cout << endl << "Explicit Method" << endl;
		eilerExplicit(u, n);
		break;
	}

	case 2:
	{
		cout << endl << "Implicit Method" << endl;
		eilerImplicit(u, n);
		break;
	}
	}
}