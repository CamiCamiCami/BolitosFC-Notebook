#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MOD ((ll)1e6 + 7)
#define sum(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define res(a, b) (((a % MOD) - (b % MOD) + MOD) % MOD)
#define mul(a, b) (((a % MOD) * (b % MOD)) % MOD)

ll exponenciacionBinaria(ll x, ll e) {
    ll acumulador = 1;
    ll potBinaria = x;
    while (e != 0) {
        if (e & 1) {
            acumulador = mul(acumulador, potBinaria);
        }
        e = e >> 1;
        potBinaria = mul(potBinaria, potBinaria);
    }
    return acumulador;
}

ll inversoModular(ll x) { return exponenciacionBinaria(x, MOD - 2); } // MOD DEBE ser primo