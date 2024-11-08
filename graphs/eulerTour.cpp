vi w(N), start(N),fin(N);
int t = 0;//N 2e5+5 sbt
void euler_tour(int r, int p, vector<vi> &v){
    start[r] = ++t;
    for(int i:v[r]){
        if(i==p)continue;
        euler_tour(i,r,v);
    }
    fin[r] = t;
}