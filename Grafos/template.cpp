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

void bfs(Grafo& g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    queue<ll> q;
    q.push(raiz);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        visitados[actual] = true;
        for (ll vecino : g[actual]) {
            if (visitados[vecino])
                continue;
            q.push(vecino);
        }
    }
}

// TODO: testear
void dfs(Grafo& g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    stack<ll> p;
    p.push(raiz);
    while (!p.empty()) {
        ll actual = p.top();
        p.pop();
        visitados[actual] = true;
        for (ll vecino : g[actual]) {
            if (visitados[vecino])
                continue;
            p.push(vecino);
        }
    }
}

void dfs_recursivo(Grafo& g, ll raiz, vector<bool>& visitado) {
    visitado[raiz] = true;
    for (ll vecino : g[raiz]) {
        if (visitado[vecino])
            continue;
        dfs_recursivo(g, vecino, visitado);
    }
}