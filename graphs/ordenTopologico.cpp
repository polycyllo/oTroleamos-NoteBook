#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define mod (int)1e9+7
#define endl '\n'
#define arr array
#define pb push_back
using namespace std;
const int INF = 1e9;
vector<int> ans;
vector<bool> visited, inStack; 
vector<vector<int>> g;
int n, m;
bool cycle; 

void dfs(int v) {
    visited[v] = true;
    inStack[v] = true; 
    for (int u : g[v]) {
        if (!visited[u])
            dfs(u);
        else if (inStack[u])
            cycle = true;
    }
    inStack[v] = false; 
    ans.push_back(v+1);
}

void topological_sort() {
    visited.assign(n, false);
    inStack.assign(n, false);
    ans.clear();
    cycle = false;
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());

    if (cycle) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
}

signed main(){
    cin >> n >> m;
    g.resize(n);
    for(int i = 0, a, b; i < m; i++){
        cin >> a >> b, a--, b--;
        g[a].push_back(b);
    }
    topological_sort();
    if (!cycle) {
        for(int i : ans){
            cout << i << " ";
        }
    }
    return 0;
}
