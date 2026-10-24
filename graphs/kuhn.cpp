//Kuhn emparejamiento maximo
//O(N*M) mt tiene mananio derecho
//un fore(i,n)vis.assigned(n,false)if(kuhn(i...vis));
bool kuhn(int r,vvi &v,vi &mt,vector<bool> &vis){
    if(vis[r])return false;
    vis[r] = true;
    for(int i:v[r]){
        if((mt[i]==-1) || kuhn(mt[i],v,mt,vis)){
            mt[i] = r;
            return true;
        }
    }
    return false;
}
//para mostrar los pares que se hacen
vector<bool> tienePareja(n,false);
for(int col = 0;col<n;col++){
    if(mt[col]!=-1){
        tienePareja[mt[col]]=1;
    }
}
//filas es izq
//col es der
vector<bool> filas(n,false),columnas(n,false);
auto dfs =[&](auto &&self,int fila)->void{
    if(filas[fila])return;
    filas[fila]=true;
    for(int col:v[fila]){
        columnas[col] = 1;
        if(mt[col]!=-1){
            self(self,mt[col]);
        }
    }
};
for(int i = 0;i<n;i++){
    if(!tienePareja[i]){
        dfs(dfs,i);
    }
}
//este es un ejemplo para escoger una fila o col
for(int i = 0;i<n;i++){
    if(!filas[i])cout << "1 " << i+1 << endl;
    if(columnas[i])cout << "2 " << i+1 << endl;
}