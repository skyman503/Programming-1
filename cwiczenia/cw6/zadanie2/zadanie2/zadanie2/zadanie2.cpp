#include <iostream>

using namespace std;

void transpozycja(double* tab, int n) {
    double tmp;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tmp = *(tab + i * n + j);
            *(tab + i * n + j) = *(tab + j * n + i);
            *(tab + j * n + i) = tmp;
        }
    }
}


int main()
{
    int m = 4;
    double arr[4][4] = { {1,2,3,4},{5,6,7,8},{9,1,1,2},{3,1,5,6}};
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    transpozycja((double*)arr, m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}
