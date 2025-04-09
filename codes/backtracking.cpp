#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 1e5;
const int INF = 1e9;

int n, k;
int h[NMAX + 1];
int solutie = INF;

void citire(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> h[i];
    }
}

int cost_saritura(int i, int j){
    return abs(h[i] - h[j]);
}

void backtracking(int i, int cost_pana_acum){
    if (i == n){
        if (cost_pana_acum < solutie)
            solutie = cost_pana_acum;
        return;
    }
    for (int j = i + 1; j <= min(i + k, n); ++j){
        backtracking(j, cost_pana_acum + cost_saritura(i, j));
    }
}

void afisare(){
    cout << solutie;
}

int main()
{
    citire();
    backtracking(1, 0);
    afisare();
    return 0;
}
