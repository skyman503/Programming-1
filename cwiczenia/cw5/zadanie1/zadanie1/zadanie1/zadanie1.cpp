#include <iostream>
#include <math.h>

using namespace std;

int stopien = 2;
int x;
double tablica[3];

double wartosc_w_punkcie(double arr[], int stopien, int arg) {
    int suma = 0;
    for (int i = 0; i < stopien; i++) {
        suma = suma + (arr[(i+1)] * pow(arg, (i+1)));
    }
    suma = suma + arr[0];
    return suma;
}



int main()
{
    for (int i = 0; i < (stopien+1); i++) {
        cout << "a" << i << ": ";
        cin >> tablica[i];
    }
    cout << "\nPodaj arugment x: ";
    cin >> x;

    cout <<"\n" << wartosc_w_punkcie(tablica, stopien, x) << "\n";

}
