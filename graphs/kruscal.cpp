/**
* KRUSKAL'S ALGORITHM (MINIMAL SPANNING TREE - INCREASING EDGE SIZE)              *
* Time complexity: O(ElogE)                                                       *
* Usage: cost, sz[find(node)]                                                     *
* Notation: cost: sum of all edges which belong to such MST                       *
*           sz:   vector of subsets sizes, i.e. size of the subset a node is in   *
*******************************/
#define nd second
#define st first
vector<int> par(N,-1),sz(N,1);

int n,m;
int cost = 0;
vector <pair<int, pair<int, int>>> edges; //mp(dist, mp(node1, node2))
int find(int a) { return par[a] == -1 ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b)))return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
} 
void solve(){
    sort(edges.begin(), edges.end());
    for (auto e : edges)
        if (find(e.nd.st) != find(e.nd.nd))
            unite(e.nd.st, e.nd.nd), cost += e.st;
}