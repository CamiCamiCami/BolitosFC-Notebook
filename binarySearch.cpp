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

ll f(ll n);  // COMPLETAR

ll busquedaBinaria(ll desde, ll hasta) {
    for (ll a = desde, b = hasta, medio = (a + b) / 2; a != b; medio = (a + b) / 2) {
        int eval = f(medio);
        if (eval == 0)
            return medio;
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

long long solve(long long min_val, long long max_val) {
    long long L = min_val;
    long long R = max_val;
    long long ans = -1;  // Guarda la mejor respuesta encontrada hasta ahora
    while (L <= R) {
        // L + (R - L) / 2 previene overflow que pasaría si usas (L + R) / 2
        long long mid = L + (R - L) / 2;

        if (func(mid)) {
            ans = mid;    // mid es válido, lo guardamos como posible respuesta
            R = mid - 1;  // Como queremos el menor valor, buscamos más a la izquierda
        } else {
            L = mid + 1;  // mid no es válido (dio false), buscamos a la derecha
        }
    }

    return ans;  // Al final del ciclo, 'ans' tiene el primer 'true'
}
