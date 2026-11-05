#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)
using namespace std;

/* Maxima distancia desde un vertice */

using Grafo = vector<vector<ll>>;
vector<ll> caminoDistancia;
ll maximaDistanciaDesde(Grafo &g, ll desde) {
    caminoDistancia = vector<ll>();
    vector<bool> encolado(g.size(), false);
    vector<ll> padres(g.size(), -1);
    queue<ll> q;
    ll lejano;
    q.push(desde);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        lejano = actual;
        for (ll vecino : g[actual]) {
            if (encolado[vecino]) continue;
            q.push(vecino);
            encolado[actual] = true;
        }
    }

    ll actual = lejano;
    while (actual != -1) {
        caminoDistancia.push_back(actual);
        actual = padres[actual];
    }
    reverse(caminoDistancia.begin(), caminoDistancia.end());
    return caminoDistancia.size();
}

/* Calculo de Diametro */

using Arbol = vector<vector<ll>>;
vector<ll> calcularDiametro(Arbol &g, ll nodo) {
    maximaDistanciaDesde(g, nodo);
    ll extremo = caminoDistancia.back();
    maximaDistanciaDesde(g, extremo);
    return caminoDistancia;
}

/* Centro del arbol (medio del diametro) (minimiza distancia maxima)*/

ll calcularCentro(vector<ll> diametro) { return diametro[diametro.size() / 2]; }