int timer = 1; //al final timer es 2*n;build(1,1,timer);
//depth[a]+depth[b]-2*depth[lca(a,b)] = dist
int ini[N], euler[N], st[4*N];
int mnTin(int x,int y){
    if (x == -1)return y;
    if( y == -1)return x;
    return (ini[x]<ini[y]?x:y);
}
void build(int p,int l, int r){
    if(l==r)st[p] = euler[l];
    else{
        build(p*2,l,(l+r)/2);
        build(p*2+1,(l+r)/2+1,r);
        st[p] = mnTin(st[p*2],st[2*p+1]);
    }
}
 
int query(int a,int b,int p, int l, int r){
    if(l>b || r<a)return -1;
    if(l>=a and r<= b)return st[p];
    int mid = (l+r)/2;
    return mnTin(query(a,b,2*p,l,mid),query(a,b,2*p+1,mid+1,r));
}
void dfs(int r, int p,vector<vi> &v){
    ini[r] = timer;
    euler[timer++] = r;
    for(int i:v[r]){
        if(i==p)continue;
        dfs(i,r,v);
        euler[timer++] = r;
    }
}
int lca(int a,int b){
    if(ini[a]>ini[b])swap(a,b);
    return query(ini[a],ini[b],1,1,timer);
}