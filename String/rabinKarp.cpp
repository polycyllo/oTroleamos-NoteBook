#include <bits/stdc++.h> 
#define int long long int
using namespace std;
const int p = 31; 
const int m = 1e9 + 9;
int S,T;//s patron, t texto 
//Rabin Karp O(n+m)
vector<int> rabin_karp(string const& s, string const& t) {
    S = s.size(), T = t.size();
    vector<int> p_pow(max(S, T)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<int> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 



    //for(int i:h)cout << i << " ";
    //cout << endl;

    int h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> ocurrencias;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            ocurrencias.push_back(i);
    }
    return ocurrencias;
}
signed main(){

    string s = "hola";
    string t= "holaaqueetal";
    auto v = rabin_karp(s,t);
    for(int i:v)cout << i << " ";
    cout << endl;
}