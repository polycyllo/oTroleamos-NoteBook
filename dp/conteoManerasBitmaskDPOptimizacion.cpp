//Contar maneras de seleccionar 
//por por fila y columna Optimización
//dp con bitmask O(n*2^n) pero mejor constante
void solve(){
    ....
    int m = 1<<n;
    vi dp(m,0);
    dp[0] = 1;
    for(int mask = 0;mask<m;mask++){
        int i = __builtin_popcount(mask);
        if(i>=n)continue;
        int freebits = (~mask)&(m-1);//solo recorer directamente posiciones validas (1's)
        for(int b = freebits;b;b&=(b-1)){
            int aislar = b&(-b);
            int j = __builtin_ctz(aislar);
            if(v[i][j]==1){
                int nxt = mask|aislar;
                dp[nxt]+=dp[mask];
                dp[nxt]%=mod;
            }
        }
    }
    cout << dp[m-1] << endl;
}