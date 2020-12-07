#include <iostream>
#include <iomanip>

using namespace std;

double func(double x) {
	double tab[4] = { 1, 2, 3, 1 };
	double sum = 0;
	for (int i = 1; i < 4; i++) {
		sum = sum + (tab[i] * pow(x, i));
	}
	sum = sum + tab[0];
	return sum;
}



double integrT(double a, double b, double N) {
	double stemp = (b - a) / N;
	double tmp, tmp2;
	double area;
	double sum = 0;
	for (double point = a; point < b; (point = point + stemp)) {
		tmp = func(point);
		tmp2 = func(point + stemp);
		area = (((tmp + tmp2) / 2) * stemp);
		sum = sum + area;
	}
	return sum;
	
}

int main()
{
	cout << setprecision(8) <<integrT(0, 5, 1000000);
}
