#include <iostream>

using namespace std;

const int NMAX = 1e5;

int n, v[NMAX + 1], aux[NMAX + 1];

void citire(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> v[i];
    }
}

void interclaseaza(int st, int mid, int dr){
    int i = st;
    int j = mid + 1;
    int poz = 1;

    // cat timp nu am terminat de interclasat intervalele
    // le interclasam
    while (i <= mid and j <= dr){
        if (v[i] < v[j]){
            aux[poz] = v[i];
            ++i;
            ++poz;
        } else {
            aux[poz] = v[j];
            ++j;
            ++poz;
        }
    }

    // am terminat de interclasat unul dintre intervale
    // dar nu stiu care
    // asa ca incercam sa le terminam de parcurs pe ambele
    while (i <= mid){
        aux[poz] = v[i];
        ++i;
        ++poz;
    }

    while (j <= dr){
        aux[poz] = v[j];
        ++j;
        ++poz;
    }

    // copiez vectorul auxiliar in cel final
    for (int i = 1; i < poz; ++i){
        v[st + i - 1] = aux[i];
        aux[i] = 0;
    }
}

void merge_sort(int st, int dr){

    if (st == dr)
        return;

    int mid = (st + dr) / 2;

    merge_sort(st, mid);
    merge_sort(mid + 1, dr);

    interclaseaza(st, mid, dr);
}

void afisare(){
    for (int i = 1; i <= n; ++i){
        cout << v[i] << ' ';
    }
}

int main()
{
    citire();
    merge_sort(1, n);
    afisare();
    return 0;
}
