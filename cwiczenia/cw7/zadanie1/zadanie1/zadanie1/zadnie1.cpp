#include <iostream>

using namespace std;

void poKropce() {
	cout << "kropka" << endl;
}
void poKresce() {
	cout << "kreska" << endl;
}
void poLiterze() {
	cout << "litera" << endl;
}
void poSlowie() {
	cout << "spacja" << endl;
}


void Morse(const string* napis, void (*poKropceArg)(), void (*poKresceArg)(), void (*poLiterzeArg)(), void (*poSlowieArg)()) {
	string mors;
	string zdanie = *napis;
	bool prev = false;
	for(auto l: zdanie) {
		if ((l == 'a') || (l == 'A')) {
			mors += "._/";
		}
		else if ((l == 'b') || (l == 'B')) {
			mors += "_.../";
		}
		else if ((l == 'c') || (l == 'C')) {
			mors += "_._./";
		}
		else if ((l == 'd') || (l == 'D')) {
			mors += "_../";
		}
		else if ((l == 'e') || (l == 'E')) {
			mors += "./";
		}
		else if ((l == 'f') || (l == 'F')) {
			mors += ".._./";
		}
		else if ((l == 'g') || (l == 'G')) {
			mors += "__./";
		}
		else if ((l == 'h') || (l == 'H')) {
			mors += "..../";
		}
		else if ((l == 'i') || (l == 'I')) {
			mors += "../";
		}
		else if ((l == 'j') || (l == 'J')) {
			mors += ".___/";
		}
		else if ((l == 'k') || (l == 'K')) {
			mors += "_._/";
		}
		else if ((l == 'l') || (l == 'L')) {
			mors += "._../";
		}
		else if ((l == 'm') || (l == 'M')) {
			mors += "__/";
		}
		else if ((l == 'n') || (l == 'N')) {
			mors += "_./";
		}
		else if ((l == 'o') || (l == 'O')) {
			mors += "___/";
		}
		else if ((l == 'p') || (l == 'P')) {
			mors += ".__./";
		}
		else if ((l == 'q') || (l == 'Q')) {
			mors += "__._./";
		}
		else if ((l == 'r') || (l == 'R')) {
			mors += "._./";
		}
		else if ((l == 's') || (l == 'S')) {
			mors += ".../";
		}
		else if ((l == 't') || (l == 'T')) {
			mors += "_/";
		}
		else if ((l == 'u') || (l == 'U')) {
			mors += ".._/";
		}
		else if ((l == 'v') || (l == 'V')) {
			mors += "..._/";
		}
		else if ((l == 'w') || (l == 'W')) {
			mors += ".__/";
		}
		else if ((l == 'x') || (l == 'X')) {
			mors += "_.._/";
		}
		else if ((l == 'y') || (l == 'Y')) {
			mors += "_.__/";
		}
		else if ((l == 'z') || (l == 'Z')) {
			mors += "__../";
		}
		else if (l == ' ') {
			mors += "/";
		}
	}
	cout << mors << endl;
	for (int i = 0; i < mors.size();i++) {
		if (mors[i] == '.') {
			poKropceArg();
			prev = false;
		}
		else if (mors[i] == '_') {
			poKresceArg();
			prev = false;
		}
		else if (mors.substr(i,2) == "//") {
			poSlowie();
			prev = true;
		}
		else if ((mors[i] == '/') && (!prev)) {
			poLiterze();
		}
	}
}




int main() {
	string napis = "Ida Swieta";
	const string napis2 = "kropka kreska";
	Morse(&napis, &poKropce, &poKresce, &poLiterze, &poSlowie);
}