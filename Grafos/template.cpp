#include <bits/stdc++.h>
#define ll long long
using namespace std;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using Grafo = vector<vector<ll>>;
using Digrafo = vector<vector<pair<ll, bool>>>;
using Arbol = vector<vector<ll>>;

void bfs(Grafo &g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    queue<ll> q;
    q.push(raiz);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        visitados[actual] = true;
        for (ll vecino : g[actual]) {
            if (visitados[vecino]) continue;
            q.push(vecino);
        }
    }
}

void dfs(Grafo &g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    stack<ll> p;
    p.push(raiz);
    while (!p.empty()) {
        ll actual = p.top();
        p.pop();
        visitados[actual] = true;
        for (ll vecino : g[actual]) {
            if (visitados[vecino]) continue;
            p.push(vecino);
        }
    }
}

void dfs_recursivo(Grafo &g, ll raiz, vector<bool> &visitado) {
    visitado[raiz] = true;
    for (ll vecino : g[raiz]) {
        if (visitado[vecino]) continue;
        dfs_recursivo(g, vecino, visitado);
    }
}