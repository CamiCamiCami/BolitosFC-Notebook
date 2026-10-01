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
#define initArr(arr, largo, contenido)                                         \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Arbol = vector<vector<ll>>;

ll f(ll n); // COMPLETAR

ll busquedaBinaria(ll desde, ll hasta) {
    for (ll a = desde, b = hasta, medio = (a + b) / 2; a != b;
         medio = (a + b) / 2) {
        ll eval = f(medio);
        if (eval == 0) return medio;
        if (eval > 1) {
            b = medio;
        } else {
            a = medio + 1;
        }
    }
    return 0;
}

/* Binary search de Gaspi (nunca la entendí)*/
bool func(ll x);

ll solve(ll min_val, ll max_val) {
    ll L = min_val;
    ll R = max_val;
    ll ans = -1;
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (func(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    return ans;
}
