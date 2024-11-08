#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long 
#define endl '\n'
#define arr array
#define nd second
#define st first
using namespace std;
const int mod = 1e9+7,INF=1e9;
const int N = 2e5+100;

/**********************************************************************************
* KRUSKAL'S ALGORITHM (MINIMAL SPANNING TREE - INCREASING EDGE SIZE)              *
* Time complexity: O(ElogE)                                                       *
* Usage: cost, sz[find(node)]                                                     *
* Notation: cost: sum of all edges which belong to such MST                       *
*           sz:   vector of subsets sizes, i.e. size of the subset a node is in   *
**********************************************************************************/
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
signed main(){
    fast;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
         int a,b,tam;
         cin >> a >> b >> tam;
         edges.push_back({tam,{a,b}});
    }
   
    
    sort(edges.begin(), edges.end());
    for (auto e : edges)
        if (find(e.nd.st) != find(e.nd.nd))
            unite(e.nd.st, e.nd.nd), cost += e.st;
    int ans = 0;
    for(int i = 1; i<=n;i++)ans+=(par[i]==-1?1:0);
    if(ans>1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << cost << endl;
}