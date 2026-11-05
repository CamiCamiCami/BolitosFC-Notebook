#define ll long long
using namespace std;

/* Binary search de Gaspi */
bool func(ll x);

ll solve(ll min_val, ll max_val) {
    ll L = min_val;
    ll R = max_val;
    ll ans = -1;
    while (L <= R) {
        ll mid = L + (R - L) / 2;
        if (func(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }
    return ans;
}
