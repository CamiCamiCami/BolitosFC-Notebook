#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull dcmEuclideano(ull n1, ull n2) {
    if (n1 == n2 || n1 == 0 || n2 == 0) return max(n1, n2);
    if (n2 < n1) swap(n1, n2);
    return dcmEuclideano(n1, (n2 % n1));
}

ull mcmEuclideano(ull n1, ull n2) { return (n1 / dcmEuclideano(n1, n2)) * n2; }