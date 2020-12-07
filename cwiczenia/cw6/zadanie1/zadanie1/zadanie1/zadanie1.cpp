#include <iostream>

using namespace std;

double get_min_max(double* tab, int x, int y, double* mini, double* maxi) {
    double tmini, tmaxi, temp;
    tmini = *tab;
    tmaxi = *tab;
    for (int i = 0; i < x * y; i++) {
        temp = *(tab + i);
        if (temp > tmaxi){
            tmaxi = temp;
        }
        else if (temp < tmini) {
            tmini = temp;
        }
    }
    *mini = tmini;
    *maxi = tmaxi;
    return 1;
}

int main()
{
    double mini;
    double maxi;
    double* pmini = &mini;
    double* pmaxi = &maxi;
    double tablica[3][5] = { {1,2,3,5,8},{-1,-2,7,-124,34},{-123,-124,-125,126,0} };
    get_min_max((double*)tablica, 3,5, pmini, pmaxi);
    cout << "minimum: " << mini << "\nmaksimum: " << maxi;
    
    
    cin.ignore();
}
