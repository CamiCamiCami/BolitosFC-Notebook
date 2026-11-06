struct ST {
    // 1. NEUTRO (Declarar SIEMPRE arriba del vector!)
    // - Suma: 0 | Min: 4e18 (o 1e9 en int) | Max: -4e18 | XOR: 0
    ll NEUTRO = 0;
    int n;
    vector<ll> t;

    // 2. OPERACION DE CONSULTA
    // Cambiar segun el problema: a + b, min(a, b), max(a, b), a ^ b
    ll op(ll a, ll b) { return a + b; }

    // 3. CONSTRUCTOR (Usa solo 2 * n de memoria)
    ST(int n) : n(n), t(2 * n, NEUTRO) {}

    // 4. ACTUALIZAR UN PUNTO (Posicion k de 0 a n - 1)
    // - Por defecto ASIGNA/REEMPLAZA el valor: t[k += n] = x
    // - Si el problema pide SUMAR al valor que ya estaba: cambiar '=' por '+='
    void upd(int k, ll x) {
        for (t[k += n] = x; k /= 2;) t[k] = op(t[2 * k], t[2 * k + 1]);
    }

    // 5. CONSULTAR RANGO INCLUSIVO [l, r] (Indices de 0 a n - 1)
    ll query(int l, int r) {
        ll L = NEUTRO, R = NEUTRO;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if (l & 1) L = op(L, t[l++]);
            if (!(r & 1)) R = op(t[r--], R);
        }
        return op(L, R);
    }
};