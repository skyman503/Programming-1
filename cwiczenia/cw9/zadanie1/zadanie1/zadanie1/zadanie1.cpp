#include <iostream>

using namespace std;

struct napis{
    char napisTabela[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
    int napisDlugosc = 0;

    void ustaw(string s) {
        int i = 0;
        for (auto l : s) {
            napisTabela[i] = l;
            i++;
        }
        napisDlugosc = i;
    }

    int dlugosc() {
        return napisDlugosc;
    }

    void wyswietl() {
        for (int i = 0; i < napisDlugosc; i++) {
            cout << napisTabela[i];
        }
    }

    char litera(int i) {
        if ((i >= 0) && (i < 20)) {
            return napisTabela[i];
        }
        else {
            cout << endl << "BLAD" << endl;
        }
    }

    void dodaj(char c) {
        if (napisDlugosc < 20) {
            napisTabela[napisDlugosc] = c;
            napisDlugosc++;
        }
        else {
            cout << endl << "BLAD" << endl;
        }
    }

    void konkakentuj(napis& n) {
        int tmp = n.napisDlugosc + napisDlugosc;
        if (tmp <= 20) {
            int j = 0;
            for (int i = napisDlugosc; i < tmp; i++) {
                napisTabela[i] = n.napisTabela[j];
                j++;
            }
            napisDlugosc = tmp;
        }else{
            cout << endl << "BLAD" << endl;
        }
    }

    int porownaj(napis &n){
        int mini;
        if (napisDlugosc > n.napisDlugosc) {
            mini = n.napisDlugosc;
        }
        else {
            mini = napisDlugosc;
        }
        int i = 0;
        while (i<mini) {
            if (int(napisTabela[i]) < int(n.napisTabela[i])) {
                return -1;
            }
            else if (int(napisTabela[i]) > int(n.napisTabela[i])) {
                return 1;
            }
            i++;
        }
        if (napisDlugosc == n.napisDlugosc) {
            return 0;
        }
        else if (i >= napisDlugosc) {
            return -1;
        }else if(i >= n.napisDlugosc){
            return 1;
        }
        return 0;
    }

    void usun(int start, int dlugosc) {
        if ((start + dlugosc) < 20) {
            char tmpTabela[20];
            int j = 0;
            for (int i = 0; i < napisDlugosc; i++) {
                if ((i<start) || (i>=(start+dlugosc))) {
                    tmpTabela[j] = napisTabela[i];
                    j++;
                }
            }
            int i = 0;
            while (i < j) {
                napisTabela[i] = tmpTabela[i];
                i++;
            }
            while (i < 20) {
                napisTabela[i] = 0;
                i++;
            }
        }
        else {
            cout << endl << "BLAD" << endl;
        }
    }
};

int main()
{
    napis test1;
    napis test2;

    //ustaw
    test1.ustaw("abcdefghijk");
    test2.ustaw("ghijklmnop");

    //wyswietl
    test1.wyswietl();
    cout << endl;
    test2.wyswietl();

    //dlugosc
    cout << endl << test1.dlugosc() << "   " << test2.dlugosc() << endl;

    //litera
    cout << test1.litera(0) << "   " << test1.litera(7) << endl;

    //dodaj
    test1.dodaj('z');
    test1.wyswietl();
    cout << endl;

    //konkatentuj
    napis test3;
    test3.ustaw("xyz");
    test1.konkakentuj(test3);
    test1.wyswietl();
    cout << endl;

    //porownaj
    napis test4;
    test4.ustaw("xyz");
    cout << "test1 z test2: " << test1.porownaj(test2) << "   test3 z test2: " << test3.porownaj(test2) << "   test3 z test3: " << test3.porownaj(test3) << endl;

    //usun
    test3.usun(0, 3);
    cout << "Usuwamy z test3 od 0 dlugosc 3: ";
    test3.wyswietl();
    cout << endl;

    test1.usun(3, 5);
    cout << "Usuwamy z test1 od 3 dlugosc 5: ";
    test1.wyswietl();
    cout << endl;

    test2.usun(5, 18); //BLAD
    cout << "Usuwamy z test1 od 3 dlugosc 5: ";
    test2.wyswietl();
    cout << endl;
}