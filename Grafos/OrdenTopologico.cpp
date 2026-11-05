#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)
#define endl '\n'
using namespace std;

using Digrafo = vector<vector<pair<ll, bool>>>;
vector<ll> ordenTarjan;
vector<bool> visitadoTarjan;
vector<ll> marcasTarjan;
ll ordenadosTarjan;
bool visitarTarjan(Digrafo &g, ll nodo, ll marcaActual) {
    if (visitadoTarjan[nodo]) return true;
    if (marcasTarjan[nodo] == marcaActual) return false;
    marcasTarjan[nodo] = marcaActual;
    bool hayCiclo = false;
    for (auto [vecino, salida] : g[nodo]) {
        if (!salida) continue;
        hayCiclo = hayCiclo && !visitarTarjan(g, vecino, marcaActual);
    }
    visitadoTarjan[nodo] = true;
    ordenTarjan[nodo] = ordenadosTarjan++;
    return !hayCiclo;
}

bool ordenamientoTarjan(Digrafo &g) {
    ordenTarjan = vector<ll>(g.size());
    visitadoTarjan = vector<bool>(g.size(), false);
    marcasTarjan = vector<ll>(g.size(), -1);
    ordenadosTarjan = 0;
    bool esAciclico = true;
    for (ll nodo = 0; nodo < g.size() && esAciclico; nodo++) {
        if (visitadoTarjan[nodo]) continue;
        esAciclico = visitarTarjan(g, nodo, nodo);
    }
    return esAciclico;
}
