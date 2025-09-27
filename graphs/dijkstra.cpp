//dijkstra
//complejidad O(n + m log m)
vector<int> dis(N, 1e12);//almacena las distancias
vector<int> dijkstra(vector<vector<pair<int,int>>> &g,int r){
    int n = g.size();
    vector<int> par(n,-1);
    vector<bool> vis(n);
    priority_queue<pair<int,int>> cola;
    cola.push({0,r});
    dis[r] = 0;
    while(!cola.empty()){
        int node = cola.top().second;
        cola.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(ii ed: g[node]){
            if(dis[ed.f] > dis[node] + ed.s){
                par[ed.f] = node;
                dis[ed.f] = dis[node] + ed.s;
                cola.push({-dis[ed.f], ed.f});
            }
        }
    }
    return par;
}