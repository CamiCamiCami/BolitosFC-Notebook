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

/* Calcular Altura */

void __calcularAlturas(Arbol& g, ll raiz, vector<ll>& altura, vector<bool>& visitado) {
    visitado[raiz] = true;
    ll maxAltura = 0;
    for (ll vecino : g[raiz]) {
        if (visitado[vecino])
            continue;
        __calcularAlturas(g, vecino, altura, visitado);
        maxAltura = max(maxAltura, altura[vecino] + 1);
    }
    altura[raiz] = maxAltura;
}

void calcularAlturas(Arbol& g, ll raiz, vector<ll>& altura) {
    vector<bool> visitados(g.size(), false);
    __calcularAlturas(g, raiz, altura, visitados);
}

/* Maxima distancia desde un vertice */

ll maximaDistanciaDesde(Grafo& g, ll desde, vector<ll>& camino) {
    vector<ll> distancia(g.size(), 10E9);
    vector<ll> padres(g.size(), -1);
    queue<ll> q;
    ll maximaDistancia = -1, lejano;
    distancia[desde] = 0;
    q.push(desde);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        if (maximaDistancia < distancia[actual]) {
            maximaDistancia = distancia[actual];
            lejano = actual;
        }
        for (ll vecino : g[actual]) {
            if (distancia[vecino] > distancia[actual] + 1) {
                padres[vecino] = actual;
                distancia[vecino] = distancia[actual] + 1;
                q.push(vecino);
            }
        }
    }
    ll recorriendo = lejano;
    while (recorriendo != -1) {
        camino.push_back(recorriendo);
        recorriendo = padres[recorriendo];
    }
    reverse(camino.begin(), camino.end());
    return maximaDistancia;
}

/* Calculo de Diametro */

vector<ll> calcularDiametro(Arbol& g, ll nodo) {
    vector<ll> camino;
    maximaDistanciaDesde(g, nodo, camino);
    ll extremo = camino.back();
    camino.clear();
    maximaDistanciaDesde(g, extremo, camino);
    return camino;
}

/* Convertir el arbol en un digrafo con arista dirigidas desde la raiz */

void enraizar(Arbol& g, ll raiz) {
    vector<bool> visitados(g.size(), false);
    queue<ll> q;
    q.push(raiz);
    while (!q.empty()) {
        ll actual = q.front();
        q.pop();
        visitados[actual] = true;
        vector<ll> hijos;
        for (ll vecino : g[actual]) {
            if (visitados[vecino])
                continue;
            hijos.push_back(vecino);
            q.push(vecino);
        }
        g[actual] = hijos;
    }
}

/* Centro del árbol (medio del diámetro) (minimiza distancia maxima)*/

ll calcularCentro(vector<ll> diametro) {
    return diametro[diametro.size() / 2];
}

/* Separa componentes conexas */

vector<Grafo> componentesConexas(Grafo& g) {
    vector<bool> visitados(g.size(), false);
    vector<Grafo> grafos;
    queue<ll> q;
    forr(nodo, g.size()) {
        if (visitados[nodo])
            continue;
        q.push(nodo);
        map<ll, ll> nuevosNombres;
        Grafo nuevo;
        ll aristas = 0;
        while (!q.empty()) {
            ll actual = q.front();
            q.pop();
            if (visitados[actual])
                continue;
            visitados[actual] = true;
            nuevosNombres[actual] = aristas;
            nuevo.push_back(vector<ll>());
            aristas++;
            for (ll vecino : g[actual]) {
                if (visitados[vecino]) {
                    ll nombreVecino = nuevosNombres[vecino], nombreActual = nuevosNombres[actual];
                    nuevo[nombreActual].push_back(nombreVecino);
                    nuevo[nombreVecino].push_back(nombreActual);
                }
                q.push(vecino);
            }
        }
        grafos.push_back(nuevo);
    }
    return grafos;
}

/* IO Grafo */

Grafo leerGrafo(ll vertices, ll aristas) {
    Grafo g(vertices);
    ll n1, n2;
    forr(i, aristas) {
        cin >> n1 >> n2;
        n1--;
        n2--;
        g[n1].push_back(n2);
        g[n2].push_back(n1);
    }
    return g;
}