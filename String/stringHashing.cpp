#include <bits/stdc++.h>
#define fore(i,b,n) for(int i = b; i < n; i++)
#define endl "\n"
#define MOD                   1000000007
#define INF                   2e18
#define fast_cin()            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int B = 257;//259

using namespace std;
struct hashing{
    string s;
    int n, b,mod;
    vector<int> hash, base;
    hashing(){}
    void init(string &s1, int b1, int mod1){
        s = s1; n = s.size(); b = b1; mod = mod1;
        hash.resize(n); base.resize(n);
        build();        
    }
    void build(){
        base[0] = 1;
        for(int i = 1; i < n; i++)
            base[i] = 1ll*base[i-1]*b % mod;
        int h = 0;
        for(int i = 0; i < n; i++){
            h = (1ll*h*b + s[i]) % mod;
            hash[i] = h;
        }
    }
    int stringH(){return hash[n-1];}
    int substringH(int l, int r){return (l==0)?hash[r]:
    (hash[r] - (1ll*hash[l-1]*base[r-l+1]) % mod + mod) % mod;}
};
int main(){
    string s = "ab";
    hashing h1;
    h1.init(s,257,MOD);
    cout << h1.stringH() << endl;
    return 0;
}