#include <iostream>

using namespace std;

int main()
{
    double a = 0, b = 0, x = 0;

    cout << "Podaj wspolczynnik a: ";
    cin >> a;
    cout << "Podaj wspolczynnik b: ";
    cin >> b;
    cout << "\n";

    if (a != 0) {
        if (b == 0) {
            cout << "Rozwiazanie x0 wynosi: 0\n";
            return 0;
        }
        else {
            x = ((-1 * b) / a);
            cout << "Rozwiazanie x0 wynosi: " << x << "\n";
            return 0;
        }
    }
    else {
        if (b == 0) {
            cout << "Rownanie Tozsamosciowe \n";
            return 0;
        }
        else {
            cout << "Rownanie sprzeczne \n";
            return 0;
        }
    }
}
