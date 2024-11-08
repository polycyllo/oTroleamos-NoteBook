const int tam = 1000 + 10;

struct Point {
    int x, y;

    Point(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}

    Point operator - (const Point & p) const {
        return Point(x - p.x, y - p.y);
    }

    bool operator < (const Point & other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }

    int cross(const Point & p) const {
        return x * p.y - y * p.x;
    }

    int cross(const Point & p, const Point & q) const {
        return (p - *this).cross(q - *this);
    }

    int half() const {
        return int(y < 0 || (y == 0 && x < 0));
    }
};



vector<vector<int>> find_faces(vector<Point> vertices, vector<vector<int>> adj) {
    int n = vertices.size();
    vector<vector<char>> used(n);
    for (int i = 0; i < n; i++) {
        used[i].resize(adj[i].size(), 0);
        auto compare = [&](int l, int r) {
            Point pl = vertices[l] - vertices[i];
            Point pr = vertices[r] - vertices[i];
            if (pl.half() != pr.half())
                return pl.half() < pr.half();
            return pl.cross(pr) > 0;
        };
        sort(adj[i].begin(), adj[i].end(), compare);
    }

    vector<vector<int>> faces;
    for (int i = 0; i < n; i++) {
        for (int edge_id = 0; edge_id < adj[i].size(); edge_id++) {
            if (used[i][edge_id]) {
                continue;
            }
            vector<int> face;
            int v = i;
            int e = edge_id;
            while (!used[v][e]) {
                used[v][e] = true;
                face.push_back(v);
                int u = adj[v][e];
                int e1 = -1;
                for (int j = 0; j < adj[u].size(); j++) {
                    if (adj[u][j] == v) {
                        e1 = (j + 1) % adj[u].size();
                        break;
                    }
                }
                if (e1 == -1) break; 
                v = u;
                e = e1;
            }
            if (!face.empty()) {
                faces.push_back(face);
            }
        }
    }
    vector<pair<double, vector<int>>> face_areas;
    for (auto &face : faces) {
        vector<Point> polygon;
        for (int idx : face) {
            polygon.push_back(vertices[idx]);
        }
        double area = polygonArea(polygon);
        face_areas.push_back({area, face});
    }

    
    sort(face_areas.begin(), face_areas.end());
    face_areas.pop_back(); 

  
    vector<vector<int>> result;
    for (const auto &entry : face_areas) {
        result.push_back(entry.second);
    }

    return result;
}
double polygonArea(const vector<Point>& p) {
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
void solve() {
    int n;
    cin >> n;
    vector<Point> vertices;
    vector<vector<int>> adj(n);
    map<Point, int> mp;
    map<int,Point> mp2;
    int nodo = 0;
    for (int i = 0, a, b, c, d; i < n; i++) {
        cin >> a >> b >> c >> d;
        Point a1(a, b), a2(c, d);
        int p1, p2;

        if (mp.find(a1) != mp.end()) {
            p1 = mp[a1];
        } else {
            p1 = nodo;
            mp[a1] = p1;
            mp2[p1] = a1;
            nodo++;
            vertices.pb(a1);
        }

        if (mp.find(a2) != mp.end()) {
            p2 = mp[a2];
        } else {
            p2 = nodo;
            mp2[p2] = a2;
            mp[a2] = p2;
            nodo++;
            vertices.pb(a2);
        }
        adj[p1].pb(p2);
        adj[p2].pb(p1);
    }

    vector<vi> faces = find_faces(vertices, adj);

    double ans = 0;
    for(auto v:faces){
        vector<Point> pol;
        for(auto i:v){
            pol.pb(mp2[i]);
        }
        double aux = polygonArea(pol);
        ans+=(aux*aux);
    }
    cout << fixed << setprecision(6) << ans << endl;
}