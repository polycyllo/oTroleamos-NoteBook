#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int 
#define endl '\n'
#define arr array
#define pb push_back
using namespace std;
int const mod= 1e9+7;
int const N = 1e6;
//vector<int> lpf(N+1,0);
int lpf[N+1] ;
vector<int> pfs;
signed main(){
    fastIO;
    for(int i=2;i<=N;i++){
        if(!lpf[i]){
            pfs.pb(i);
            lpf[i] = i;
        }
        for(int j = 0;j<pfs.size() && pfs[j]<=lpf[i]&&i*pfs[j]<=N;j++)
            lpf[i*pfs[j]] = pfs[j];
    }
    int n;
    cin >> n;
    //cout << "hola" << endl;
    /*for(int i=0;i<100;i++){
        cout << lpf[i] << endl;
    }*/
    while(n--){
        map<int,int> mp;
        int x;
        cin >> x;
        while(x>1){
            mp[lpf[x]]++;
            x/=lpf[x];
           //cout << x << endl;
        }
        int ans = 1;
        for(auto it:mp)
            ans*=(it.second+1);
        cout << ans << endl;
    }
}