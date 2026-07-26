#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>
#define ll long long
#define dd long double
#define forr(i, h) for (ll i = 0; i < h; i++)
#define forrr(i, d, h) for (ll i = d; i < h; i++)
#define techo(x, k) ((x + k - 1) / k)
#define initArr(arr, largo, contenido) \
    for (int i = 0; i < largo; i++)    \
        arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

bool es_primo(int x) {
    for (int i = 2; i < x / 2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

ll criba(ll MAX, vector<bool>& primos, vector<ll>& minDivisor) {
    primos.clear();
    minDivisor.clear();
    forr(i, MAX + 1) {
        primos.push_back(true);
        minDivisor.push_back(i);
    }

    primos[0] = primos[1] = false;

    ll cantPrimos = MAX;
    for (int p = 2; p * p <= MAX; p++) {
        if (!primos[p])
            continue;
        for (int d = p * p; d <= MAX; d += p) {
            if (primos[d]) {
                primos[d] = false;
                cantPrimos--;
                minDivisor[d] = p;
            }
        }
    }
    return cantPrimos;
}
