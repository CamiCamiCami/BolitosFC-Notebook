#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)
using namespace std;

vector<ll> predecesoresUF;  // INICIALIZAR
vector<ll> profundidadesUF; // INICIALIZAR

ll initUnionFind(ll elementos) {
    predecesoresUF = vector<ll>(elementos);
    profundidadesUF = vector<ll>(elementos, 0);
    forr(i, elementos) profundidadesUF[i] = i;
}

ll buscarRepresentante(ll i) {
    if (predecesoresUF[i] == i) return i;
    return predecesoresUF[i] = buscarRepresentante(predecesoresUF[i]);
}

void unirConjuntos(ll e1, ll e2) {
    e1 = buscarRepresentante(e1);
    e2 = buscarRepresentante(e2);
    if (e1 == e2) return;
    if (profundidadesUF[e1] < profundidadesUF[e2]) {
        predecesoresUF[e1] = e2;
    } else if (profundidadesUF[e1] > profundidadesUF[e2]) {
        predecesoresUF[e2] = e1;
    } else {
        predecesoresUF[e1] = e2;
        profundidadesUF[e1]++;
    }
}