#include <iostream>

using namespace std;

const int NMAX = 1e5;
const int INF = 1e9;

int n, k;
int h[NMAX + 1];
int dp[NMAX + 1];

void citire(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> h[i];
    }
}

int cost(int a, int b){
    return abs(h[a] - h[b]);
}

void calculare_dp(){
    for (int i = 2; i <= n; ++i){
        int mini = INF;
        for (int j = i - 1; j >= max(i - k, 1); --j){
             int cost_curent = cost(i, j) + dp[j];
             if (cost_curent < mini)
                    mini = cost_curent;
        }
        dp[i] = mini;
    }
}

void afisare(){
    cout << dp[n];
}

int main()
{
    citire();
    calculare_dp();
    afisare();
    return 0;
}
