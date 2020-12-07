#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

using namespace std;

double MAX = 212;

double func(double x) {
	double tab[4] = { 1, 2, 3, 1 };
	double sum = 0;
	for (int i = 1; i < 4; i++) {
		sum = sum + (tab[i] * pow(x, i));
	}
	sum = sum + tab[0];
	return sum;
}

double random_double(double a, double b) {
	double random = ((double)rand()) / (double)RAND_MAX;
	double diff = b - a;
	double r = random * diff;
	return a + r;
}

double integrMC(double a, double b, double P) {
	double tmp, tmp2, tmp3;
	int below=0;
	double area;
	for (int i = 0; i < P; i++) {
		tmp = random_double(a, b);
		tmp2 = random_double(0, MAX);
		tmp3 = func(tmp);
		if (tmp2 <= tmp3) {
			below++;
		}
	}
	area = ((b - a) * MAX);
	return ((below/P)*area);
}


int main()
{
	srand(time(NULL));
	cout<<integrMC(0,5,1000000);

}