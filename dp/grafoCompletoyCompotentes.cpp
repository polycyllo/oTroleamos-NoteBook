//Contar componentes que sean completos
//O(n*2^n + 3^n)
void solve(){
    int n,m;cin >> n >> m;
    vi adj(n);
    for(int i = 0,a,b;i<m;i++){
        cin >> a >> b;
        a--,b--;
        adj[a]|=(1<<b);
        adj[b]|=(1<<a);
    }
    vi dp(1<<n,inf);
    //comprobar conjuntos donde el los bits(representación de nodos) sea un grafo completo-todos contra todos
    for(int mask = 0;mask<(1<<n);mask++){
        bool complete = true;
        for(int u = 0;u<n;u++){
            if(mask&(1<<u)){
                if(((adj[u]|(1<<u))&mask)!=mask){
                    complete = false;
                    break;
                }
            }
        }
        if(complete)dp[mask] = 1;
    }
    for(int mask = 0;mask<(1<<n);mask++){
        //reducir submask a mascaras mas pequeñas que sean de mask original
        for(int submask = mask;submask;submask = (submask-1)&mask){
            int subset = mask^submask;
            if(dp[subset]!=inf and dp[submask]!=inf){
                dp[mask] = min(dp[mask],dp[submask]+dp[subset]);
            }
        }
    }
    cout << dp[(1<<n)-1];
}