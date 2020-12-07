#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double a = 0, b = 0, c = 0;
    double wyznacznik = 0;
    double x1 = 0, x2 = 0;

    cout << "Podaj wspolczynnik a: ";
    cin >> a;
    cout << "Podaj wspolczynnik b: ";
    cin >> b;
    cout << "Podaj wspolczynnik c: ";
    cin >> c;
    cout << "\n";

    if (a == 0) {
        if (b != 0) {
            if (c == 0) {
                cout << "Rozwiaznie x0 wynosi: 0\n";
                return 0;
            }
            else {
                x1 = ((-1 * c) / b);
                cout << "Rozwiaznie x0 wynosi: " << x1 << "\n";
                return 0;
            }
        }
        else {
            if (c == 0) {
                cout << "Rownanie Tozsamosciowe \n";
                return 0;
            }
            else {
                cout << "Rownanie sprzeczne \n";
                return 0;
            }
        }
    }
    else {
        wyznacznik = ((b * b) - (4 * a * c));
        if (wyznacznik < 0) {
            cout << "Rownanie nie posiada rozwian w zbiorze liczb rzeczywistych \n";
            return 0;
        }
        else if (wyznacznik == 0) {
            x1 = ((-1 * b) / 2 * a);
            cout << "Funckja posiada 1 rozwiazanie rowne x0: " << x1 << "\n";
            return 0;
        }
        else {
            x1 = (((-1 * b) - sqrt(wyznacznik)) / (2 * a));
            x2 = (((-1 * b) + sqrt(wyznacznik)) / (2 * a));

            cout << "Funkcja posiada 2 rozwiazania rowne x1: " << x1 << ", x2: " << x2 << "\n";
            return 0;
        }
        

    }

}
