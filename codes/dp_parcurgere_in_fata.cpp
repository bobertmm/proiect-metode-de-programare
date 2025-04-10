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

void init_dp(){
    for (int i = 2; i <= n; ++i){
        dp[i] = INF;
    }
}

void calculare_dp(){
    for (int i = 1; i < n; ++i){
        for (int j = i + 1; j <= min(i + k, n); ++j){
            int cost_curent = cost(i, j) + dp[i];
            if (cost_curent < dp[j]){
                dp[j] = cost_curent;
            }
        }
    }
}

void afisare(){
    cout << dp[n];
}

int main()
{
    citire();
    init_dp();
    calculare_dp();
    afisare();
    return 0;
}
