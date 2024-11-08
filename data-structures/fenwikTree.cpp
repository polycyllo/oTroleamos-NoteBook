struct BIT{
    int n;//pos desde 1
    vi bit;
    void build(int tam){
        n = tam+10;
        bit.resize(n,0);
    }
    int sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
    
    void add(int pos, int val){
        pos++;
        int tam = n+1;
        while(pos <= tam){
            bit[pos] += val;
            pos += pos & (-pos);
        }
    }

};