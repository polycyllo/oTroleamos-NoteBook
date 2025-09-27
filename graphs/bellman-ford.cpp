const int N = 1e4+10;
vi adj[N],adjw[N];
int n;
vi bellman_ford(int s){
    vi dist(n,INF);
    dis[s] = 0;
    for(int i = 0;i<n-1;i++){
        for(int u = 0,v,w; u<n;u++){
            for(int j = 0;j<adj[u].size();j++){
                v = adj[u][j],w=adjw[u][j];
                if(dist[v]>w+dist[u]){
                    dist[v] = w+dist[u];
                }
            }
        }
    }
    return dist;
}