//Tarjan O(n+m)
//Puntos y puentes de articulación
int timer = 0;
vector<bool> vis;
vi dfs_num, dfs_low;
void tarjan(int r,vvi &v, int p = -1){
    vis[r] = 1;
    dfs_num[r] = dfs_low[r] = timer++;
    int children = 0;
    for(int i:v[r]){
        if(i == p)continue;
        if(vis[i]){
            dfs_low[r] = min(dfs_low[r],dfs_num[i]);
        }else{
            tarjan(i,v,r);
            dfs_low[r] = min(dfs_low[r],dfs_low[i]);
            if(dfs_low[i]>=dfs_num[r] and p!=-1){
                //r punto de articulación 
            }
            if(dfs_low[i]>dfs_num[r] and p!=-1){
                // (r,i) puente
            }
            children++;
        }
    }
    if(p == -1 && children > 1){
        //punto de articulación
    }
}