//binary lifting
int lg = 1; 
void dfs(int r,int p, vi &parent,vi &depth,vvi &g,vvi &up){
    parent[r] = (p == 0)?0:p;
    up[r][0]=parent[r];
    depth[r] = (p == 0)?0:(1+depth[p]);
    
    if(p==0)bit[r].reset();
    else bit[r]= bit[p];
    bit[r].set(r-1);

    for(int i:g[r]){
        if(i!=p)dfs(i,r,parent,depth,g,up);
    }

}
int lca(int a,int b,vi &depth, vi &parent,vvi &up){
    if(depth[a]<depth[b])swap(a,b);
    int k = depth[a]-depth[b];
    for(int j = 0;j<LOG;j++)if(k&(1<<j)) a = up[a][j];
    if(a==b)return a;
    for(int j = LOG;j>=0;j--){
        if(up[a][j]!=up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return parent[a];
}
    //lg = ceil(log2(n));
    while((1 << lg) <= n) ++lg;
    vvi up(n,vector<int>(lg+1));
    for(int i = 0;i<n;i++){
        up[i][0] = parent[i];
    }
    up[0][0] = 0;
    for(int j = 1;j<=lg;j++){
        for(int vv = 0;vv<n;vv++){
            int mid = up[vv][j-1];
            up[vv][j] = (mid == -1 ? -1 : up[mid][j-1]);
        }
    }