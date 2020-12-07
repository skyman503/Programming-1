#include <iostream>

using namespace std;

int N=10, K=50;
int tablica[1000][1000], nastepny_stan[1000][1000];
string rozkaz;

void pokaz_tablice(int x) {
    cout << "\n\t\t\n\t\tKrok: " << x << "\n";

    //cout << "\t\t=============\n\t\t" << "      " << x << "\n\t\t=============\n";
    for (int i = 1; i <= N; i++) {
        cout << "\t\t";
        for (int j = 1; j <= N; j++) {    
            if (tablica[i][j] == 1) {
                cout << char(254u) << " ";
            }
            else {
                cout << char(255u) << " ";
            }
        }
        cout << endl;
    }
}

bool czy_zywa(int x, int y) {
    if (tablica[x][y] == 1) {
        return true;
    }
    return false;
}

int suma_sasiadow(int i, int j) {
    int suma = 0;
    if (czy_zywa((i + 1),j)) {
        suma++;
    }
    if (czy_zywa((i + 1),(j + 1))) {
        suma++;
    }
    if (czy_zywa(i, (j + 1))) {
        suma++;
    }
    if (czy_zywa((i - 1), (j + 1))) {
        suma++;
    }
    if (czy_zywa((i - 1), j)) {
        suma++;
    }
    if (czy_zywa((i - 1), (j - 1))) {
        suma++;
    }
    if (czy_zywa(i, (j - 1))) {
        suma++;
    }
    if (czy_zywa((i + 1), (j - 1))) {
        suma++;
    }
    //cout << "Suma z " << i << " " << j << " " <<suma<< endl;
    return suma;
}

void generuj_nastepny_stan() {
    int tmp;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if(tablica[i][j] == 0){ 
                if (suma_sasiadow(i, j) == 3) {
                    nastepny_stan[i][j] = 1;
                }
            }
            else {
                tmp = suma_sasiadow(i, j);
                if ((tmp == 2) || (tmp == 3)) {
                    nastepny_stan[i][j] = 1;
                }
                else {
                    nastepny_stan[i][j] = 0;
                }
            }
        }
    }
}

void podmiana_tablic() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
           // cout << nastepny_stan[i][j] << " ";
            tablica[i][j] = nastepny_stan[i][j];
        }
        //cout << endl;
    }
}


int main()
{
    for (int i = 0; i <= (N + 1); i++) {
        for (int j = 0; j <= (N + 1); j++) {
            tablica[i][j] = 0;
            nastepny_stan[i][j] = 0;
        }
    }

    int tmp;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> tmp;
            tablica[i][j] = tmp;
        }
    }

    system("cls");
    while (rozkaz != "START") {
        cin >> rozkaz;
        system("cls");
    }

    pokaz_tablice(0);
    for (int i = 1; i <= K; i++) {
        generuj_nastepny_stan();
        podmiana_tablic();
        pokaz_tablice(i);
    }
}
