#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define st first
#define nd second
using namespace std;
const int N = 1000;
vector<int> par(N,-1),sz(N,1);
vector <pair<int, pair<int, int>>> edges;
int cost = 0;
int v,a;
//par: vector of parents                                                *
//sz:  vector of subsets sizes, i.e. size of the subset a node is in
int find(int a) { return par[a] == -1 ? a : par[a] = find(par[a]); }

void unite(int a, int b) {
  if ((a = find(a)) == (b = find(b))) return;
  if (sz[a] < sz[b]) swap(a, b);
  par[b] = a; sz[a] += sz[b];
}


int main () {
    
    return 0;
}