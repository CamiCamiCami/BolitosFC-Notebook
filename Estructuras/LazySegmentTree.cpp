#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct LazyST {
    // 1. NEUTROS (Declarar SIEMPRE arriba de los vectores!)
    // - Para SUMA en rango: NEUTRO = 0, LZ_NEUTRO = 0
    // - Para MIN en rango:  NEUTRO = 4e18 (o 1e9 en int), LZ_NEUTRO = 0
    // - Para MAX en rango:  NEUTRO = -4e18, LZ_NEUTRO = 0
    // - Si el update es ASIGNAR (Set) en vez de sumar: LZ_NEUTRO = -1 (o un valor que no exista en el input)
    ll NEUTRO = 0, LZ_NEUTRO = 0;
    int n;
    vector<ll> t, lz;

    // 2. OPERACION DE CONSULTA
    // Cambiar segun lo que pida la query: a + b, min(a, b), max(a, b)
    ll op(ll a, ll b) { return a + b; }

    // 3. CONSTRUCTOR (Tamanno 4 * n)
    // OJO: Si vas a hacer min/max pero cargas los datos iniciales sumando con upd(i, i, x),
    // pone t(4 * n, 0) en vez de t(4 * n, NEUTRO) para que las hojas empiecen en 0 y no en 4e18.
    LazyST(int n) : n(n), t(4 * n, NEUTRO), lz(4 * n, LZ_NEUTRO) {}

    // 4. PROPAGACION (El "post-it")
    void push(int v, int tl, int tr) {
        if (lz[v] == LZ_NEUTRO) return;

        // A) Como afecta el cambio al nodo actual:
        // - Si op es SUMA y update es SUMAR:   t[v] += lz[v] * (tr - tl + 1);
        // - Si op es MIN/MAX y update es SUMAR: t[v] += lz[v];
        // - Si op es SUMA y update es ASIGNAR: t[v] = lz[v] * (tr - tl + 1);
        // - Si op es MIN/MAX y update es ASIGNAR: t[v] = lz[v];
        t[v] += lz[v] * (tr - tl + 1);

        // B) Como se pasa el post-it a los hijos (si no es hoja):
        // - Si el update es SUMAR: usar '+='
        // - Si el update es ASIGNAR (Set): cambiar '+=' por '=' (sobreescribir)
        if (tl != tr) lz[2 * v] += lz[v], lz[2 * v + 1] += lz[v];

        lz[v] = LZ_NEUTRO; // Limpiamos el post-it actual
    }

    // Funciones internas: 'v' es 1-indexado (raiz = 1, hijos = 2*v y 2*v+1)
    // 'tl' y 'tr' son los limites del nodo actual (0 a n-1)
    void upd(int v, int tl, int tr, int l, int r, ll val) {
        push(v, tl, tr);
        if (tl > r || tr < l) return;
        if (tl >= l && tr <= r) {
            // C) Aplicar nuevo post-it:
            // - Si el update es SUMAR:   lz[v] += val;
            // - Si el update es ASIGNAR: lz[v] = val;
            lz[v] += val;
            push(v, tl, tr);
            return;
        }
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, l, r, val);
        upd(2 * v + 1, tm + 1, tr, l, r, val);
        t[v] = op(t[2 * v], t[2 * v + 1]);
    }

    ll query(int v, int tl, int tr, int l, int r) {
        push(v, tl, tr);
        if (tl > r || tr < l) return NEUTRO;
        if (tl >= l && tr <= r) return t[v];
        int tm = (tl + tr) / 2;
        return op(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }

    // 5. FUNCIONES PARA USAR EN EL MAIN (Indices l y r van de 0 a n - 1, inclusivos)
    void upd(int l, int r, ll val) { upd(1, 0, n - 1, l, r, val); }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};