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
#define ull unsigned long long
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

ull gdbEuclideano(ull n1, ull n2) {
    if (n1 == n2 || n1 == 0 || n2 == 0) return max(n1, n2);
    if (n2 < n1) swap(n1, n2);
    return gdbEuclideano(n1, (n2 % n1));
}

ull mcmEuclideano(ull n1, ull n2) { return (n1 / gdbEuclideano(n1, n2)) * n2; }