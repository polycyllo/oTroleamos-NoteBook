#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define mod (int)1e9+7
#define endl '\n'
#define arr array
#define pb push_back
using namespace std;
int const nxm = 1e5;
signed main(){
    fastIO;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;a--,b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    vector<int> p(n,-1);
    queue<int> qu;
    p[0]=-2;
    qu.push(0);
    while(qu.size()){
        int u = qu.front();
        qu.pop();
        for(int v:g[u]){
            if(p[v]<0){
                p[v] = u;
                qu.push(v);
            }
        }
    }
    vector<int> ans;
    if(p[n-1]<0){
        cout << "IMPOSSIBLE";
    }else{
        int v = n-1;
        while(v){
            ans.pb(v);
            v=p[v];
        }
        ans.pb(0);
        reverse(ans.begin(),ans.end());
        cout << ans.size() << endl;
        for(int i:ans){
            cout << i+1 << " ";
        }
    }
 
}