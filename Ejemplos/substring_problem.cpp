#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)


using namespace std;

const int MAXN = 100005;

const ll p1 = 131, p2 = 137;
const ll m1 = 1e9 + 7, m2 = 1e9 + 9;

vector<ll> potencias1(MAXN), potencias2(MAXN);
vector<ll> hashes1(MAXN + 1, 0), hashes2(MAXN + 1, 0);

void inicializar_potencias()
{
    potencias1[0] = 1;
    potencias2[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        potencias1[i] = (potencias1[i - 1] * p1) % m1;
        potencias2[i] = (potencias2[i - 1] * p2) % m2;
    }
}

void prefixSum_hashes(const string &s)
{
    ll n = s.length();
    for (int i = 0; i < n; i++)
    {
        hashes1[i + 1] = (hashes1[i] * p1 + s[i]) % m1;
        hashes2[i + 1] = (hashes2[i] * p2 + s[i]) % m2;
    }
}

pair<ll, ll> obtener_hash(ll l, ll r)
{
    ll len = r - l + 1;
    ll hash1 = (hashes1[r + 1] - (hashes1[l] * potencias1[len]) % m1) % m1;
    hash1 = (hash1 + m1) % m1;
    ll hash2 = (hashes2[r + 1] - (hashes2[l] * potencias2[len]) % m2) % m2;
    hash2 = (hash2 + m2) % m2;
    return make_pair(hash1, hash2);
}

int main()
{

    inicializar_potencias();
    string s;
    cin >> s;
    int largo_s = s.length();
    prefixSum_hashes(s);

    int n;
    cin >> n;
    string a;
    while (n--)
    {
        cin >> a;
        int largo = a.length();

        ll h1_a = 0, h2_a = 0;
        for (int i = 0; i < largo; i++)
        {
            h1_a = (h1_a * p1 + a[i]) % m1;
            h2_a = (h2_a * p2 + a[i]) % m2;
        }
        pair<ll, ll> hash_a = make_pair(h1_a, h2_a);

        bool flag = false;
        for (int i = 0; i <= largo_s - largo; i++)
        {
            if (hash_a == obtener_hash(i, i + largo - 1))
            {
                cout << "Y" << "\n";
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "N" << "\n";
    }
}