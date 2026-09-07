#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
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

vector<vector<ll>> ancestros;
vector<ll> profundidad;
void calcularBinaryLifting(Arbol& g, ll raiz);  // Ver binaryLifting.cpp
ll enecimoAncestro(Arbol& g, ll nodo, unsigned ll n);

void calcularLCA(Arbol& g, ll raiz) {
    calcularBinaryLifting(g, raiz);
}

ll lowestCommonAncestor(Arbol& g, ll a, ll b) {
    if (profundidad[a] < profundidad[b])
        swap(a, b);

    a = enecimoAncestro(g, a, profundidad[a] - profundidad[b]);

    while (a != b) {
        ll L = 0;
        ll R = ancestros[b].size() - 1;
        ll ans = 0;
        while (L <= R) {
            ll mid = L + (R - L) / 2;
            if (ancestros[a][mid] != ancestros[b][mid]) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        a = ancestros[a][ans];
        b = ancestros[b][ans];
    }
    return a;
}