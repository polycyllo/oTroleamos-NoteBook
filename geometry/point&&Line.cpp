#include <bits/stdc++.h>
using namespace std;
#define conDec(numero,i) fixed << setprecision(i) << numero
const double EPS = 1e-9;
struct point{
    double x, y;
    point(double x,double y): x(x),y(y){}
    point operator+(point b){return {x+b.x,y+b.y};}
    point operator -(point b){return {x-b.x,y-b.y};}
    point operator*(double d) {return {x*d, y*d};}
    point operator/(double d) {return {x/d, y/d};}
    point translate(point v,point p){return p+v;}
    point scale(point c, double factor, point p) {return c+(p-c)*factor;}
};

double dot(point a,point b){
    return a.x*b.x + a.y*b.y;
}
double abs(point a){
    return sqrt(dot(a,a));
}
double proj(point a,point b){
    return dot(a,b)/abs(b);
}
double angle(point a, point b) {
    double ans = acos(dot(a, b) / abs(a) / abs(b));//rad
    //ans *= 180.0/M_PI;
    return ans;
}




double dist(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool operator==(point a, point b) {return a.x == b.x && a.y == b.y;}
bool operator!=(point a,point b) {return !(a==b);}


double roundToThreeDecimals(double value) {
    return round(value * 1000.0) / 1000.0;
}

double cross(point a, point b){
    return a.x*b.y-a.y*b.x;
}
struct line{
    point v; double c;
    // From direction vector v and offset c
    line(point v, double c) : v(v), c(c) {}
    // From equation ax+by=c
    line(double a, double b, double c) : v({b,-a}), c(c) {}
    // From points P and Q
    line(point p, point q) : v(q-p), c(cross(v,p)) {}

    bool contains(const point& r){
        // Comprueba si el producto cruzado de v y (r - cualquier punto en la línea) es cero
        return fabs(cross(v, r) - c) < EPS;
    }
};
point inter(line l1, line l2) {
    double d = cross(l1.v, l2.v);
    //if (d == 0) return false;
    point res = ((l2.v*l1.c - l1.v*l2.c) / d);
    return ((l2.v*l1.c - l1.v*l2.c) / d);
} 
int main(){      
    point a(3,4),b(3,0);
    cout << angle(a,b) << endl;
}