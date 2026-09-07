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

vector<vector<ll>> ancestros;  // La raíz es su propio ancestro
vector<ll> profundidad;

void calculaPrimerAncestro(Arbol& g, ll raiz) {
    stack<ll> p;
    p.push(raiz);
    ancestros[raiz].push_back(raiz);
    profundidad[raiz] = 0;
    while (!p.empty()) {
        auto act = p.top();
        p.pop();
        for (ll vecino : g[act]) {
            if (profundidad[vecino] == -1) {
                profundidad[vecino] = profundidad[act] + 1;
                ancestros[vecino].push_back(act);
                p.push(vecino);
            }
        }
    }
}

void calculaKesimoAncestro(Arbol& g, ll k) {
    forr(i, g.size()) {
        ll ancestro = ancestros[ancestros[i][k - 1]][k - 1];  // Cuidado si se cambia el ancestro de la raíz
        ancestros[i].push_back(ancestro);
    }
}

void calcularBinaryLifting(Arbol& g, ll raiz) {
    ancestros = vector<vector<ll>>(g.size());
    profundidad = vector<ll>(g.size(), -1);
    calculaPrimerAncestro(g, raiz);
    for (ll cont = 2, k = 1; cont < g.size(); cont *= 2, k++) {
        calculaKesimoAncestro(g, k);
    }
}

ll enecimoAncestro(Arbol& g, ll nodo, unsigned ll n) {
    for (unsigned ll salto = 0; n != 0; n >>= 1, salto++) {
        if ((n & 1) != 0) {
            nodo = ancestros[nodo][salto];
        }
    }
    return nodo;
}