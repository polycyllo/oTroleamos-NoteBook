#include <bits/stdc++.h>
#define int ll
#define s second
#define f first
#define ing long long int
typedef long long ll;
using namespace std;
//algoritmo de Floyd–Warshall
//complejidad O(n*n*n)
typedef pair<int,int> ii;
const int INF = 1e18;
signed main(){
    int n,m,q;
    cin >> n >> m >> q;
    int v[n+10][n+10] = {0},dist[n+10][n+10] = {0};
    for(int i = 0,a,b,c;i<m;i++){
        cin >> a >> b >> c;
        if(v[a][b] && c<v[a][b]){
            v[a][b]=c;
            v[b][a]=c;
        }else if(!v[a][b]){
            v[a][b]=c;
            v[b][a]=c;
        } 
    }
    //llean la matriz con lo que debe estar 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (v[i][j]) dist[i][j] = v[i][j];
            else dist[i][j] = INF;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }   
    }
    for(int i = 0,a,b; i<q;i++){
        cin >> a >> b;
        cout << (dist[a][b]>=1e18?-1:dist[a][b]) << endl;
    }
    
}