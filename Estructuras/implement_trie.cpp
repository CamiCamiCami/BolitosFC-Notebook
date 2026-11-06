#include <bits/stdc++.h>

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
            int index = c - 'a';
            if (actual->h[index] == nullptr)
            {
                actual->h[index] = new Trie();
            }
            actual = actual->h[index];
        }
        actual->hoja = true;
    }

    bool search(string word)
    {
        Trie *actual = this;

        for (char c : word)
        {
            int index = c - 'a';
            if (actual->h[index] == nullptr)
            {
                return false;
            }
            actual = actual->h[index];
        }
        return actual->hoja;
    }

    bool startsWith(string prefix)
    {
        Trie *actual = this;

        for (char c : prefix)
        {
            int index = c - 'a';
            if (actual->h[index] == nullptr)
            {
                return false;
            }
            actual = actual->h[index];
        }
        return true;
    }
};