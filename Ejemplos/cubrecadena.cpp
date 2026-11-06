#include <bits/stdc++.h>
#define ll long long
#define forr(i, h) for (int i = 0; i < h; i++)

using namespace std;

class Trie
{
public:
    Trie *h[26];
    bool hoja;

    Trie()
    {
        hoja = false;
        for (int i = 0; i < 26; i++)
        {
            h[i] = nullptr;
        }
    }

    void insert(string word)
    {
        Trie *actual = this;

        for (char c : word)
        {
            int index = c - 'A';
            if (actual->h[index] == nullptr)
            {
                actual->h[index] = new Trie();
            }
            actual = actual->h[index];
        }
        actual->hoja = true;
    }
};

// int cubrecadena(string s, )

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int l = s.length();
    int n;
    cin >> n;

    vector<string> bloques;
    string bloque;
    Trie *trie = new Trie();

    forr(i, n)
    {
        cin >> bloque;
        bloques.push_back(bloque);
        trie->insert(bloque);
    }

    int dp[l + 1];
    dp[l] = 0;
    for (int i = l - 1; i >= 0; i--)
    {
        dp[i] = dp[i + 1];
        Trie *actual = trie;
        for (int j = i; j < l; j++)
        {
            int indice = s[j] - 'A';
            if (actual->h[indice] == nullptr)
            {
                break;
            }
            actual = actual->h[indice];
            if (actual->hoja)
            {
                int largo = j - i + 1;
                int opcion_actual = largo + dp[i + largo];
                if (opcion_actual > dp[i])
                {
                    dp[i] = opcion_actual;
                }
            }
        }
    }
}