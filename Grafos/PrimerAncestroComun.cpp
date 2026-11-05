#include <utility>
#include <vector>
#define ll long long
#define forr(i, h) for (ll i = 0; i < h; i++)
using namespace std;

using Arbol = vector<vector<ll>>;
vector<vector<ll>> ancestrosLCA;
vector<ll> profundidadLCA;

// Utiliza Binary Lifting. Ver binaryLifting.cpp
void calcularBinaryLifting(Arbol &g, ll raiz); //
ll enecimoAncestro(Arbol &g, ll nodo, unsigned ll n);

void calcularLCA(Arbol &g, ll raiz) { calcularBinaryLifting(g, raiz); }

ll lowestCommonAncestor(Arbol &g, ll a, ll b) {
    if (profundidadLCA[a] < profundidadLCA[b]) swap(a, b);

    a = enecimoAncestro(g, a, profundidadLCA[a] - profundidadLCA[b]);

    while (a != b) {
        ll L = 0;
        ll R = ancestrosLCA[b].size() - 1;
        ll ans = 0;
        while (L <= R) {
            ll mid = L + (R - L) / 2;
            if (ancestrosLCA[a][mid] != ancestrosLCA[b][mid]) {
                ans = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        a = ancestrosLCA[a][ans];
        b = ancestrosLCA[b][ans];
    }
    return a;
}