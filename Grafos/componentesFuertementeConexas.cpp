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
#define endl '\n'
#define initArr(arr, largo, contenido)                                         \
    for (int i = 0; i < largo; i++) arr[i] = contenido;
using namespace std;
using Par = pair<ll, ll>;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

vector<ll> componente;
vector<bool> visitado;
stack<ll> semiOrden;
#define CENTINELA -1
void visitar(Digrafo &g, ll nodo) {
    if (visitado[nodo]) return;
    visitado[nodo] = true;
    for (auto [vecino, salida] : g[nodo]) {
        if (!salida) continue;
        visitar(g, vecino);
    }
    semiOrden.push(nodo);
}

void asignar(Digrafo &g, ll nodo, ll comp) {
    if (componente[nodo] != CENTINELA) return;
    componente[nodo] = comp;
    for (auto [vecino, salida] : g[nodo]) {
        if (salida) continue;
        asignar(g, vecino, comp);
    }
}

// Determina componentes fuertemente conexas de un dígrafo (aristas [vecino,
// salida?])
void algoritmoKosaraju(Digrafo &g) {
    componente = vector<ll>(g.size(), CENTINELA);
    visitado = vector<bool>(g.size(), false);
    forr(nodo, g.size()) { visitar(g, nodo); }
    ll nroComponentes = 0;
    while (!semiOrden.empty()) {
        ll nodo = semiOrden.top();
        asignar(g, nodo, nroComponentes);
        nroComponentes = max(nroComponentes, componente[nodo] + 1);
        semiOrden.pop();
    }
}
