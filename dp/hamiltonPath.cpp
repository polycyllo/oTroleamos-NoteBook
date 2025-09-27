
//hamilton count
//O(2^n*n*m)
void solve(){
    for(int s = 2;s<nm;s++){
        if((s&(1<<(n-1)) and (s!=((1<<n)-1))))continue;
        for(int d = 0;d<n;d++){
            if(s&(1<<d)){
                for(int i:v[d]){
                    if(s&(1<<i)){
                        dp[s][d]+=dp[s^(1<<d)][i];
                        dp[s][d]%=mod;
                    }
                }
            }
        }
    }
}