//Kosaraju SCC
//Utilizar 2 grafos el original(tipo0) y tranpsuesto(tipo1)
void dfs(int r,vvi &v,vector<bool> &vis,vi &s,int tp,int scc){
    vis[r] = 1;
    for(int i:v[r]){
        if(!vis[i]){
            dfs(i,v,vis,s,tp,scc);
        }
    }    
    if(tp==0)s.pb(r);
}