#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)
#define ull unsigned long long

using namespace std;

const int MAXN = 100005;

const ull p1 = 131;

ull potencias1[MAXN];
ull hashes[MAXN + 1];

void inicializar_potencias()
{
    potencias1[0] = 1;
    for (int i = 1; i < MAXN; i++)
    {
        potencias1[i] = potencias1[i - 1] * p1;
    }
}

void prefixSum_hashes(const char *s, int *largo)
{
    int n = *largo;
    for (int i = 0; i < n; i++)
    {
        hashes[i + 1] = hashes[i] * p1 + s[i];
    }
}

ull obtener_hash(ll l, ll r)
{
    ull len = r - l + 1;
    ull hash = hashes[r + 1] - hashes[l] * potencias1[len];
    return hash;
}

char s[100005];
char a[2005];
int main()
{
    inicializar_potencias();
    scanf("%s", s);
    int largo_s = strlen(s);
    prefixSum_hashes(s, &largo_s);

    int n;
    scanf("%d", &n);

    while (n--)
    {
        scanf("%s", a);
        int largo = strlen(a);

        ull hash_a = 0;
        for (int i = 0; i < largo; i++)
        {
            hash_a = hash_a * p1 + a[i];
        }

        bool flag = false;
        for (int i = 0; i <= largo_s - largo; i++) // 100000
        {
            ull len = largo;
            ull hash = hashes[i + largo] - hashes[i] * potencias1[len];
            if (hash_a == hash)
            {
                printf("Y \n");
                flag = true;
                break;
            }
        }
        if (!flag)
            printf("N \n");
    }
}