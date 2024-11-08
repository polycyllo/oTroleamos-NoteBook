#include <bits/stdc++.h>
#define int ll
#define s second
#define f first
typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
const int N = 200010;
//dijkstra
//complejidad O(n + m log m)
vector<int> dis(N, 1e12);//almacena las distancias
vector<int> dijkstra(vector<vector<pair<int,int>>> &g,int r){
    int n = g.size();
    vector<int> par(n,-1);
    vector<bool> vis(n);
    priority_queue<pair<int,int>> cola;
    cola.push({0,r});
    dis[r] = 0;
    while(!cola.empty()){
        int node = cola.top().second;
        cola.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(ii ed: g[node]){
            if(dis[ed.f] > dis[node] + ed.s){
                par[ed.f] = node;
                dis[ed.f] = dis[node] + ed.s;
                cola.push({-dis[ed.f], ed.f});
            }
        }
    }
    return par;

}
signed main(){
    //v->vertices
    //a->aristas
    //o->origen
    //d->destino
    int v,a,o,d,c;cin >> v >> a;
    vector<vector<pair<int,int>>> g(v);
    for(int i = 0; i < a;i++){
        cin >> o >> d >> c;
        o--;d--;
        g[o].push_back({d,c});
        //g[d].push_back({o,c});
    }
    vector<int> par = dijkstra(g,0);
    //for(int &i:par) cout << i << endl;//mostrar padres
    if(dis[v - 1] == 1e12)
        cout<<-1<<'\n';
    else
    {
        vector<int> path;
        int nodo = v - 1;//camino que queremos retornar
        while(nodo != -1)
        {
            path.push_back(nodo + 1);
            nodo = par[nodo];
        }
        reverse(path.begin(),path.end());
        for(int x : path)
            cout<<x<<' ';
        cout<<'\n';
    }

    for(int i = 0;i<v;i++){
        cout << dis[i] << endl;
    }
    return 0;
}