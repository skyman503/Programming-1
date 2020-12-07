#include <iostream>
#include <vector>

using namespace std;

vector<long long int> tablica;

void zapelnij_tablice(long long int n) {
    for (long long int i = 1; i <= n; i++) {
        for (long long int j = 1; j <= n; j++) {
            tablica.push_back((i * j));
        }
    }
}

int ile_cyfr(int x) {
    int ile = 1;
    while (x >= 10) {
        x = x / 10;
        ile++;
    }
    return ile;
}

int main()
{
    long long int n, maks;
    int cyfry, roznica;
    long long int l_cyfr = 1;

    cout << "Podaj rozmiar tablicy: ";
    cin >> n;
    if (n <= 0) {
        cout << "Uruchom program ponownie podajac wartosc wieksza niz 0!";
        return 0;
    }
    zapelnij_tablice(n);
    maks = tablica.at(((n * n) - 1));
    l_cyfr = ile_cyfr(maks);

    //pierwsz linijka
    cout << " ";
    roznica = l_cyfr - 1;
    for (int i = 0; i < roznica; i++) {
        cout << " ";
    }
    if (l_cyfr == 1) {
        cout << " ";
    }

    cout << "|";
    for (int i = 1; i <= n; i++) {
        cyfry = ile_cyfr(i);
        roznica = l_cyfr - cyfry;
        for (int j = 0; j <= roznica; j++) {
            cout << " ";
        }
        cout << i;
    }
    cout << "\n";

    //krawedz
    cout << "-";
    roznica = l_cyfr - 1;
    for (int i = 0; i < roznica; i++) {
        cout << "-";
    }
    if (l_cyfr == 1) {
        cout << "-";
    }
    cout << "+";
    for (int i = 0; i < ((l_cyfr + 1) * n); i++) {
        cout << "-";
    }

    cout << "\n";

    //zawartosc
    for (int i = 1; i <= n; i++) {

        //przed |
        cout << i;
        cyfry = ile_cyfr(i);
        roznica = l_cyfr - cyfry;
        for (int j = 0; j < roznica; j++) {
            cout << " ";
        }
        if (l_cyfr == 1) {
            cout << " ";
        }
        cout << "|";

        //po |
        for (int j = ((i * n) - n); j < (i * n); j++) {
            cout << " ";

            cyfry = ile_cyfr(tablica.at(j));
            roznica = l_cyfr - cyfry;

            for (int k = 0; k < roznica; k++) {
                cout << " ";
            }
            cout << tablica.at(j);
        }
        cout << "\n";
    }
}
