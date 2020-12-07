#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

vector<string> p_pierwsze = { "Czesc Czlowieku!\nCo tam slychac?" };
vector<string> p_smutne = { "Powiesz cos wiecej?", "Co sie stalo?" };
vector<string> p_wesole = { "Milo mi to slyszec, to co porabiasz?","Jakies nowosci u ciebie?" , "U mnie to samo, a ogolnie co tam jeszcze ciekawego?" };
vector<string> p_neutralne = { "To jakie masz plany?", "Jak tam wygladaja twoje plany"};

vector<string> o_podstwowe = { "Calkiem w porzadku","Jakos leci","Bywalo lepiej" };
vector<string> o_smutne = { "Nie wazne, do jutra mi przejdzie", "Strasznie mi sie nudzi", "Nie radze sobie na studiach" };
vector<string> o_wesole = { "Dostalem 5 na koniec semestru z P1!", "Chyba znalazelm nowe hobby", "Sporo nauki ale jakos daje rade" };
vector<string> o_neutralne = { "Zamierzam wyjsc na rower", "Chyba musze isc cos ugotowac", "Nie mam ochoty teraaz rozmawiac" };

int los;

/*
	pytania rodzaje:
	1-pierwsze
	2-smutne
	3-wesole
	4-neutrlne

	odpowiedzi rodzaje:
	1-wesole
	2-neutraal
	3-smutne
*/

void pytaj(int o_r) {
	// wyswietlanie pytania
	if (o_r == 0) {
		cout << p_pierwsze.at(0);
	}
	else if (o_r == 1) {
		los = rand() % 3;
		cout << p_wesole.at(los);
	}
	else if (o_r == 2) {
		los = rand() % 2;
		cout << p_neutralne.at(los);
	}
	else if(o_r == 3){
		los = rand() % 2;
		cout << p_smutne.at(los);
	}

	cout << "\n\nWypisz cyfre aby wybrac odpoweidz:\n";

	//wyswietlanie odpoweidzi
	if (o_r == 0) {
		for (int i = 0; i < o_podstwowe.size(); i++) {
			cout << i + 1 << "- " << o_podstwowe.at(i) << "\n";
		}
	}
	else if (o_r == 1) {
		for (int i = 0; i < o_wesole.size(); i++) {
			cout << i + 1 << "- " << o_wesole.at(i) << "\n";
		}
	}
	else if (o_r == 2) {
		for (int i = 0; i < o_neutralne.size(); i++) {
			cout << i + 1 << "- " << o_neutralne.at(i) << "\n";
		}
	}
	else if (o_r==3) {
		for (int i = 0; i < o_smutne.size(); i++) {
			cout << i + 1 << "- " << o_smutne.at(i) << "\n";
		}
	}
}


int main()
{
	srand(time(NULL));

	int o_p=0, odp;
	bool rozmowa_trwa = true;
	

	while (rozmowa_trwa) {
		system("cls");
		cout << 7;
		cout << "Wpisz 9 aby zakonczyc rozmowe\n\n\n";
		pytaj(o_p);

		cout << "\n\nTwoja decyzja: ";
		cin >> o_p;

		if (o_p == 9) {
			return 0;
		}
	}

}
