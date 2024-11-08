#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 10e5+2;
int n, st[4*N], v[N];
void build(int p, int l, int r){
    if(l == r) st[p] = v[l];
    else{
        build(2*p,l,(l+r)/2);
        build(2*p+1,(l+r)/2+1,r);
        st[p] = st[2*p]*st[2*p+1];
    }
}
int query(int a, int b, int p, int l, int r){
    if(a>b) return 1;
    if(l == a && r == b) return st[p];
    int mid = (l+r) / 2;
    return (query(a,min(mid,b),2*p,l,mid))
            *(query(max(a,mid+1),b,2*p+1,mid+1,r));
}
void update(int pos, int val, int p, int l, int r){
    if(l == r) st[p] = val;
    else{
        int mid = (l+r)/2;
    if(pos<=mid){
        update(pos, val, 2*p, l, mid);
    }else{
        update(pos, val, 2*p+1,mid+1,r);
    }
    st[p] = st[2*p] * st[2*p+1];
    }
}
int main(){
     return 0;
}