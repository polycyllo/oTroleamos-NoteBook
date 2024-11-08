#include <bits/stdc++.h>
#define int long long int
#define endl '\n'
#define pb push_back
using namespace std;
const int INF = 1e9;

struct pt {
    int x, y;
};
 
int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1;
    if (v > 0) return +1; 
    return 0;
}
 
bool cw(pt a, pt b, pt c, bool bb) {
    int o = orientation(a, b, c);
    return o < 0 || (bb && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }
 
void convex_hull(vector<pt>& a, bool bb) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (bb) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }
 
    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], bb))
            st.pop_back();
        st.push_back(a[i]);
    }
 
    a = st;
}


double polygonArea(const vector<pt>& p) {
    double area = 0;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += p[i].x * p[j].y;
        area -= p[j].x * p[i].y;
    }
    area = fabs(area) / 2.0;
    return area;
}

bool isIn(const vector<pt>& v, pt p) {
    int n = v.size();
    if (n < 3) return false;
    double angleSum = 0;

    for (int i = 0; i < n; i++) {
        pt a = v[i];
        pt b = v[(i + 1) % n];
        double angle = atan2(b.y - p.y, b.x - p.x) - atan2(a.y - p.y, a.x - p.x);
        if (angle >= M_PI) angle -= 2 * M_PI;
        if (angle <= -M_PI) angle += 2 * M_PI;
        angleSum += angle;
    }

    return fabs(fabs(angleSum) - 2 * M_PI) < 1e-9;
}



signed main(){
    int n;
    int p = 0;
    vector<vector<pt>> v(20);
    while(cin >> n and n){
        for(int i = 0,a,b;i<n;i++){
            cin >> a >> b;
            //if(i==0)continue;
            v[p].pb({a,b});
        }
        convex_hull(v[p],false);
        p++;
    }
    int x,y;
    double ans = 0;
    bool vis[p] = {false};
    while(cin >> x >> y){
        for(int i = 0;i<p;i++){
            //if(vis[i])continue;
            pt p = {x,y};
            vector<pt> pp = v[i];
            if(vis[i])continue;
            if(isIn(pp,p)){
                vis[i]=1;
                ans+=polygonArea(v[i]);    
            }
            
        }
    }

    cout << fixed <<setprecision(2)<<ans  << endl;

}