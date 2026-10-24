struct Dinitz{
    const int INF = 1e9+7;
    Dinitz(){}
    Dinitz(int n,int s,int t){init(n,s,t);}

    void init(int n,int s,int t){
        S = s, T = t;
        nodes = n;
        G.clear(),G.resize(n);
        Q.resize(n);
    }
    struct flowEdge{
        int to, rev,f,cap;
    };
    vector<vector<flowEdge>> G;
    void addEdge(int st,int en,int cap){
        flowEdge A = {en,(int)G[en].size(),0,cap};
        flowEdge B = {st,(int)G[st].size(),0,0};
        G[st].pb(A);
        G[en].pb(B);
    }
    int nodes, S,T;
    vi work,lvl;
    vi Q;
    bool bfs(){
        int qt = 0;
        Q[qt++] = S;
        lvl.assign(nodes,-1);
        lvl[S] = 0;
        for(int qh = 0;qh<qt;qh++){
            int v = Q[qh];
            for(flowEdge &e:G[v]){
                int u = e.to;
                if(e.cap<=e.f || lvl[u]!=-1)continue;
                lvl[u] = lvl[v]+1;
                Q[qt++] = u;
            }
        }
        return lvl[T]!=-1;
    }
    int dfs(int v,int f){
        if(v==T||f==0)return f;
        for(int &i=work[v];i<G[v].size();i++){
            flowEdge &e = G[v][i];
            int u = e.to;
            if(e.cap<=e.f || lvl[u]!=lvl[v]+1)continue;
            int df = dfs(u,min(f,e.cap-e.f));
            if(df){
                e.f+=df;
                G[u][e.rev].f-=df;
                return df;
            }
        }
        return 0;
    }
    int maxFlow(){
        int flow = 0;
        while(bfs()){
            work.assign(nodes,0);
            while(1){
                int df = dfs(S,INF);
                if(df==0)break;
                flow+=df;
            }
        }
        return flow;
    }
};
//esto va en el void para poder mostrar los pares bloquedos
//crear un vector<ii> calles
//Corte minimo de un grafo no dirigido
//imprime las aristas con 0 de total
for(auto [a,b] : calles){
    bool llegaA = (v.lvl[a] != -1);
    bool llegaB = (v.lvl[b] != -1);
    //si es dirigido entonces
    //if(llegaA&&!llegaB)
    if(llegaA != llegaB){
        cout << a << ' ' << b << '\n';
    }
}
//imprime cobertura minima en un grafo bipartito
//1 es izq y 2 derecha
for(int i = 1;i<=n;i++){
    if(flujo.lvl[i]==-1){
        cout << "1 " << i << endl;
    }
}
for(int j = 1;j<=m;j++){
    if(flujo.lvl[n+j]!=-1){
        cout << "2 " << j << endl;
    }
}

//imprime parjeas en grafos bipartitos
for(int i = 1; i <= n; i++){
    for(const auto &e : flujo.G[i]){
        if(e.to >= n+1 && e.to <= n+m && e.f == 1){
            cout << i << ' ' << e.to-n << '\n';
        }
    }
}
//imprime cuando se manda de a a b solo en bipartitos
vvi ans(n+1,vi(n+1,0));
for(int i = 1;i<=n;i++){
    for(auto &e:v.G[i]){
        if(e.to>=n+1 && e.to<=2*n){
            int j = e.to-n;
            ans[i][j]+=e.f;
        }
    }
}
//Muestra cuando manda capacidad usa a y b de un grafo normal
vector<ii> originales;
// Al agregar cada arista original:
int pos = flujo.G[a].size();
flujo.addEdge(a, b, capacidad);
originales.pb({a, pos});
// FLUJO POR ARISTA ORIGINAL: red general o bipartita.
for(auto [a, pos] : originales){
    const auto &e = flujo.G[a][pos];
    cout << a << ' ' << e.to << ' ' << e.f << '\n';
}