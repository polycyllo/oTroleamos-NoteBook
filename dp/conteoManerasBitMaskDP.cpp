//Contar maneras de seleccionar por por fila y columna
//dp con bitmask O(n*2^n)
void solve(){
    .....
    int m = 1<<n;
    vi dp(m,0);
    dp[0] = 1;
    for(int mask = 0;mask<m;mask++){
        int i = __builtin_popcount(mask);
        if(i>=n)continue;
        for(int j = 0;j<n;j++){
            if(mask&(1<<j))continue;
            if(v[i][j]==0)continue;
            int nxt = mask|(1<<j);
            dp[nxt]+=dp[mask];
            dp[nxt]%=mod;
        }
    }
    cout << dp[m-1] << endl;
}