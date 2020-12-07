#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Rendeer {
    string name;
    string color;
    int distance;

    Rendeer(string _name, string _color, int _distance) {
        name = _name;
        color = _color;
        distance = _distance;
    }

    void update(string _name,string _color,int _distance) {
        name = _name;
        color = _color;
        distance = _distance;
    }

    void show() {
        cout << name << endl << color << endl << distance << endl;
    }

    void save(fstream& file) {
        file << name << endl;
        file << color << endl;
        file << distance << endl;
        file << endl;
    }
};

struct Team {
    Rendeer* team[12];
    int cnt = 0;
    
    void add(Rendeer* rendeer) {
        
        team[cnt] = rendeer;
        cnt++;
    }

    void print() {
        for (int i = 0; i < cnt; i++) {
            team[i]->show();
            cout << endl;
        }
    }

    void clear() {
        cnt = 0;
    }

    void zapiszDoPliku(string name) {
        fstream file(name, ios::out);
        file << cnt << endl;
        for (int i = 0; i < cnt; i++) {
            team[i]->save(file);
        }
        file.close();
    }

    void nadpiszZPliku(string name) {
        fstream file(name, ios::in);
        short tmp = 0;
        clear();
        string tmps;
        string tmp_name;
        string tmp_color;
        int  tmp_distance;
        int amount = 0;
        int goal = 0;
        int xd = 0;
        bool flg = true;
        while ((getline(file, tmps)) && flg) {
            if (amount == 0) {
                goal = stoi(tmps);
                cnt = goal;
                amount++;
            }else if (goal <= 0) {
                flg = false;
                break;
                //file.close();
            }else if ((cnt < 12) && (goal > 0) && (amount>0)) {
                switch (tmp)
                {
                case 0:
                    cout << tmps << " " << tmp << " 0" << endl;
                    tmp_name = tmps;
                    tmp = 1;
                    break;
                case 1:
                    cout << tmps << " " << tmp << " 1" << endl;
                    tmp_color = tmps;
                    tmp = 2;
                    break;
                case 2:
                    cout << tmps << " " << tmp << " 2" << endl;
                    tmp_distance = stoi(tmps);
                    tmp = 5;
                    break;
                case 5:
                    cout << "Xd";
                    tmp = 0;
                    Rendeer tmp_ren(tmp_name, tmp_color, tmp_distance);
                    Rendeer* tmp_p = &tmp_ren;
                    team[amount - 1]->update(tmp_name, tmp_color, tmp_distance);
                    amount++;
                    goal--;
                }
            }     
        }
        tmp = 0;
        Rendeer tmp_ren(tmp_name, tmp_color, tmp_distance);
        Rendeer* tmp_p = &tmp_ren;
        team[amount - 1]->update(tmp_name, tmp_color, tmp_distance);
        amount++;
        goal--;
    }
};


int main()
{
    Rendeer aa("elo", "zulty", 123);
    Rendeer ab("siema", "czarny", 421);
    Rendeer ac("test", "czerwony", 1234);
    Team team;
    Rendeer* pt1 = &aa;
    Rendeer* pt2 = &ab;
    Rendeer* pt3 = &ac;
    team.add(pt1);
    team.add(pt2);
    team.add(pt3);

    //team.print();
    //team.zapiszDoPliku("renifery.txt");
    team.nadpiszZPliku("wejscie.txt");
    cout << "=-------------------\n";
    team.print();

}
