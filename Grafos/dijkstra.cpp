#include <queue>
#include <utility>
#include <vector>
#define ll long long
using namespace std;

vector<ll> distanciasDijkstra;
using GrafoPesado = vector<vector<pair<ll, ll>>>;
using ElementoDijkstra = pair<ll, ll>;
// TODO: testear
void Dijkstra(GrafoPesado g, ll inicial) {
    distanciasDijkstra = vector<ll>(g.size(), 10e10);
    distanciasDijkstra[inicial] = 0;
    priority_queue<ElementoDijkstra, vector<ElementoDijkstra>, greater<ElementoDijkstra>> queue;
    queue.push({0, inicial});
    while (!queue.empty()) {
        auto [distanciaActual, actual] = queue.top();
        queue.pop();
        if (distanciasDijkstra[actual] < distanciaActual) continue;
        for (auto [vecino, largoArista] : g[actual]) {
            if (distanciasDijkstra[vecino] > largoArista + distanciaActual) {
                distanciasDijkstra[vecino] = largoArista + distanciaActual;
                queue.push({distanciasDijkstra[vecino], vecino});
            }
        }
    }
}
