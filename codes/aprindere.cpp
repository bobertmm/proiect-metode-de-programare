#include <fstream>
#include <vector>

using namespace std;
ifstream cin("aprindere.in");
ofstream cout("aprindere.out");

const int NMAX = 1e3;

struct intrerupator_t{
    int timp_actionare;
    int nr_camere_actionate;
    vector<int> camere;
};

int n, m, timp_total;
bool lumina[NMAX + 1];
intrerupator_t intrerupator[NMAX + 1];

void citire(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> lumina[i];
    for (int i = 1; i <= m; ++i){
        int c;
        cin >> c;
        c++;    // de ce ai folosi indexare de la 0 ?
        cin >> intrerupator[c].timp_actionare >> intrerupator[c].nr_camere_actionate;
        for (int j = 1; j <= intrerupator[c].nr_camere_actionate; ++j){
            int aux;
            cin >> aux;
            aux++; // serios de ce ai folosi vreodata indexare de la 0 ???!?!?!??!
            intrerupator[c].camere.push_back(aux);
        }
    }
}

void actionare_intrerupator(int i){
    for (auto x : intrerupator[i].camere){
        lumina[x] = ! lumina[x];
    }
    timp_total += intrerupator[i].timp_actionare;
}

void parcurgere(){
    for (int i = 1; i <= n; ++i){
        if (! lumina[i]){
            actionare_intrerupator(i);
        }
    }
}

void afisare(){
    cout << timp_total;
}

int main(){
    citire();
    parcurgere();
    afisare();
    return 0;
}