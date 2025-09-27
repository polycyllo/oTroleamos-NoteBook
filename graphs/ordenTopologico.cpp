vector<int> state; // 0=unvisited, 1=visiting, 2=finished
bool hasCycle = false;

void dfs(int v) {
    state[v] = 1;
    for (int u : adj[v]) {
        if (state[u] == 0) {
            dfs(u);
        } else if (state[u] == 1) {
            hasCycle = true; // back edge
        }
    }
    state[v] = 2;
    ans.push_back(v);
}