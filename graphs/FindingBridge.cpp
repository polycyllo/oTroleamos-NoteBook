#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;
const int N = 1e5+5, INF = 1e18;
vector<vi> g(N);
int ans,timer = 1,n;
vi vis,low;
vector<vi> v;
//Buscar puentes en un grafo en O(n+m)
void dfs(int i,int p = -1){
    //int c = 1;
    vis[i] = low[i] = timer++;
    for(int j:v[i]){
        if(j!=p){
            if(vis[j]) low[i] = min(low[i],vis[j]);
            else{
                int count = dfs(j,i);
                if(vis[i]<low[j]){
                    //proceso con el puente
                }else low[i] = min(low[i],low[j]);
                //c+=count;
            }
        }
    }
    //return c;
}
