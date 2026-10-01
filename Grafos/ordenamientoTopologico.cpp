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

vector<ll> ordenTopologico;
vector<bool> visitado;
vector<ll> marcas;
ll ordenados;
bool visitarTarjan(Digrafo g, ll nodo, ll marcaActual) {
    if (visitado[nodo]) return true;
    if (marcas[nodo] == marcaActual) return false;
    marcas[nodo] = marcaActual;
    bool hayCiclo = false;
    for (auto [vecino, salida] : g[nodo]) {
        if (!salida) continue;
        hayCiclo = hayCiclo && !visitarTarjan(g, vecino, marcaActual);
    }
    visitado[nodo] = true;
    ordenTopologico[nodo] = ordenados++;
    return !hayCiclo;
}

bool ordenamientoTarjan(Digrafo g) {
    ordenTopologico = vector<ll>(g.size());
    visitado = vector<bool>(g.size(), false);
    marcas = vector<ll>(g.size(), -1);
    ordenados = 0;
    bool esAciclico = true;
    for (ll nodo = 0; nodo < g.size() && esAciclico; nodo++) {
        if (visitado[nodo]) continue;
        esAciclico = visitarTarjan(g, nodo, nodo);
    }
    return esAciclico;
}
