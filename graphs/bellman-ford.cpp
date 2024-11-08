#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = 1e10;
const int N =1e4; // Máximo número de nodos
vector<int> adj[N], adjw[N]; // Lista de adyacencia y pesos de las aristas
int dist[N]; // Distancias desde la fuente
int n, m; // Número de nodos y aristas
void bellmanFord(int source) {
   fill(dist, dist + N, INF); // Inicializar distancias con un valor grande
    dist[source] = 0; // Distancia desde la fuente a sí mismo es 0
    for (int i = 0; i < n - 1; ++i) {
        for (int u = 1; u <= n; ++u) {
            for (size_t j = 0; j < adj[u].size(); ++j) {
                int v = adj[u][j], w = adjw[u][j];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }  
}
signed main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(v);
        adjw[u].push_back(w);
    }
    bellmanFord(1);
}
