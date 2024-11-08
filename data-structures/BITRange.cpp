struct BITRange {
	BIT a,b;//pos desde 1
    void build(int tam){
        a.build(tam+10);
        b.build(tam+10);
    }
	int sum(int x) {
		return a.sum(x)*x+b.sum(x);
	}
	void update(int l, int r, int v) {
		a.add(l,v), a.add(r+1,-v);
		b.add(l,-v*(l-1)), b.add(r+1,v*r);
	}
};