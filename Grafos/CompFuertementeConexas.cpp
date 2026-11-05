#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)
#define endl '\n'
using namespace std;
using Digrafo = vector<vector<pair<ll, bool>>>;

vector<ll> componente;
vector<bool> visitado;
stack<ll> semiOrden;
#define CENTINELA -1
void visitarKosaraju(Digrafo &g, ll nodo) {
    if (visitado[nodo]) return;
    visitado[nodo] = true;
    for (auto [vecino, salida] : g[nodo]) {
        if (!salida) continue;
        visitarKosaraju(g, vecino);
    }
    semiOrden.push(nodo);
}

void asignarKosaraju(Digrafo &g, ll nodo, ll comp) {
    if (componente[nodo] != CENTINELA) return;
    componente[nodo] = comp;
    for (auto [vecino, salida] : g[nodo]) {
        if (salida) continue;
        asignarKosaraju(g, vecino, comp);
    }
}

// Determina componentes fuertemente conexas de un dígrafo (aristas [vecino,
// salida?])
void algoritmoKosaraju(Digrafo &g) {
    componente = vector<ll>(g.size(), CENTINELA);
    visitado = vector<bool>(g.size(), false);
    forr(nodo, g.size()) { visitarKosaraju(g, nodo); }
    ll nroComponentes = 0;
    while (!semiOrden.empty()) {
        ll nodo = semiOrden.top();
        asignarKosaraju(g, nodo, nroComponentes);
        nroComponentes = max(nroComponentes, componente[nodo] + 1);
        semiOrden.pop();
    }
}
