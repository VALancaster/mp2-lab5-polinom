#include "polinom.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string input1, input2;

	cout << "Input format: 1x2y0z0+2x1y0z0+3x0y2z2 \n";
	cout << "Enter the first polynomial: \n";
	cin >> input1;
	cout << "Enter the second polynomial: \n";
	cin >> input2;

	Polinom p1(input1);
	Polinom p2(input2);

	cout << "Polynomial 1: " << p1.toString() << endl;
	cout << "Polynomial 2: " << p2.toString() << endl;

	Polinom sum = p1 + p2;
	Polinom diff = p1 - p2;
	Polinom scaled = p1 * 2.0;
	Polinom deriv = p1.derivativeX();
	
	cout << "Sum: " << sum.toString() << endl;
	cout << "Difference: " << diff.toString() << endl;
	cout << "Multiplying the first polynomial by 2: " << scaled.toString() << endl;
	cout << "Derivative of the first polynomial in x: " << deriv.toString() << endl;

	return 0;
}
