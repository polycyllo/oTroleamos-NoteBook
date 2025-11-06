//Kuhn emparejamiento maximo
//O(N*M) 
//un fore(i,n)vis.assigned(n,false)kuhn(i...vis);
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