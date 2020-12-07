#include <iostream>
#include <vector>

using namespace std;

vector<int> l_pierwsze, pary;

bool czy_pierwsza(int x) {
    for (int i = 2; i < (x / 2); i++) {
        if (x % i == 0){
            return false;
        }
    }
    return true;
}


void wybierz_pierwsze(int n) {
    l_pierwsze.push_back(2);

    for (int i = 3; i <= n; (i = i + 2)) {
        if (czy_pierwsza(i)) {
            l_pierwsze.push_back(i);
        }
    }

}

void wybierz_pary(int x) {
    pary.clear();
    for (int i = 0; i < l_pierwsze.size(); i++) {
        if (count(pary.begin(), pary.end(), l_pierwsze.at(i)) == 0) {
            for (int j = 0; j < l_pierwsze.size(); j++) {
                if (x == (l_pierwsze.at(i) + l_pierwsze.at(j))) {
                    pary.push_back(l_pierwsze.at(i));
                    pary.push_back(l_pierwsze.at(j));
                }
            }
        }
    }
}

int main()
{
    long long int n;
    

    cout << "Podaj gorna granice sprawdzanego przedzialu: ";
    cin >> n;

    wybierz_pierwsze(n);
    cout << "\n";

    for (int i = 4; i <= n; (i = i + 2)) {
        wybierz_pary(i);
        cout << i << ": ";
        for (int j = 0; j<pary.size(); j++) {
            if (j % 2 == 0) {
                cout << " [ " << pary.at(j) << " + ";
            }else{
                cout << pary.at(j) << " ],";
            }
        }
        cout << "\n";
    }

}
