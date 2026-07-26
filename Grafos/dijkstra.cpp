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

// TODO: testear
int Dijkstra(GrafoPesado g, ll inicial, ll objetivo, ll nodos)
{
    vector<ll> pesos(nodos, -1);
    vector<bool> visitados(nodos, false);
    pesos[inicial] = 0;
    priority_queue<pair<ll, ll>> queue;
    queue.push({inicial, 0});
    while (!queue.empty())
    {
        ll actual = queue.top().first;
        ll pesoActual = queue.top().second;
        queue.pop();
        visitados[actual] = true;
        if (pesos[actual] != pesoActual)
            continue;
        for (auto [vecino, peso] : g[actual])
        {
            if (peso == -1)
                continue;
            if (pesos[vecino] == -1 || pesos[vecino] > peso + pesos[actual])
            {
                pesos[vecino] = peso + pesos[actual];
                queue.push({vecino, pesos[vecino]});
            }
        }
    }
    return pesos[objetivo];
}