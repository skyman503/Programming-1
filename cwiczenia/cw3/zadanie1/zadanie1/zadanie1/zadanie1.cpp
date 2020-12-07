#include <iostream>
#include <bitset>

using namespace std;

void row_generator(int x) {
	cout << " " << bitset<8>(x).to_string();
	if ((x) < 100) {
		cout << "  ";
	}
	else {
		cout << " ";
	}
	cout << (x) << " " << (char)(x) << " |";
}

int main()
{
	int lower, upper, n_rows, temp;
	bool flg = true;
	do {
		cout << "Podaj zakres dolny: ";
		cin >> lower;
		cout << "\nPodaj zakres gorny: ";
		cin >> upper;

		if ( !(((lower < 32) || (upper > 127)) || (lower > upper)) ) {
			flg = false;
		}
		else {
			system("cls");
			cout << "\nBledne wartosci. Podaj je na nowo\n\n";
		}
	} while (flg);

	cout << "\n\n";

	n_rows = min((upper - lower), 32);

	for (int i = 0; i < n_rows; i++) {
		row_generator(lower + i);
		if ((lower + i + 32) < upper) {
			cout << "\t\t";
			row_generator(lower + i + 32);
			if ((lower + i + 64) < upper) {
				cout << "\t\t";
				row_generator(lower + i + 64);
			}
		}
		cout << endl;
	}
}
