//Tarjan O(n+m)
//Para SCC
vi s;
vi dfs_num(N,0),dfs_low(N,0);
int ct = 1, scc = 0;;
void tarjan(int r, vvi &v,vi &vis){
    dfs_num[r] = dfs_low[r] = ct++;
    vis[r] = 1;
    s.pb(r);
    for(int i:v[r]){
        if(dfs_num[i]==0){
            tarjan(i,v,vis);
            dfs_low[r] = min(dfs_low[i],dfs_low[r]);
        }
        
        if(vis[i])dfs_low[r] = min(dfs_num[i],dfs_low[r]);
        
    }
    if(dfs_num[r]==dfs_low[r]){
        scc++;
        while(1){
            int i = s.back();
            s.pop_back();
            vis[i] = 0;
            if(i==r)break;
        }
        
    }
}