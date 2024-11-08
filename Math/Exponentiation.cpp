#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int 
#define endl '\n'
#define arr array
#define pb push_back
using namespace std;
int const mod= 1e9+7;
int pt(int a,int b,int m){
    int r = 1;
    while(b){
        if(b&1)
            r=r*a%m;
        a=a*a%m;
        b/=2;
    }
    return r;
}
signed main(){
    fastIO;
    int n;
    cin >> n;
    while(n--){
        int a,b;cin >> a >> b;
        cout << pt(a,b,mod) << endl;
    }
}