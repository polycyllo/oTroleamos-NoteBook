int n;
const int MAX_N = 1e5; // N <= 100,000
const int LOG = ceil(log2(MAX_N)); 
int sparse[MAX_N][LOG];
int v[MAX_N];

void build() {
    for (int i = 0; i < n; i++)
        sparse[i][0] = v[i];

    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int a, int b) {
    int pot = 32 - __builtin_clz(b - a + 1) - 1;
    return min(sparse[a][pot], sparse[b - (1 << pot) + 1][pot]);
}

