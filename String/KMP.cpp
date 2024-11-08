#include <bits/stdc++.h>
using namespace std;
int const N = 1000;
string s,p;
int b[N], n, m; // n = strlen(s), m = strlen(p);

void kmppre() {
	b[0] = -1;
	for (int i = 0, j = -1; i < m; b[++i] = ++j)
		while (j >= 0 and p[i] != p[j])
			j = b[j];
}

void kmp() {
	for (int i = 0, j = 0; i < n;) {
		while (j >= 0 and s[i] != p[j]) j=b[j];
		i++, j++;
		if (j == m) {
			// match position i-j
            cout << i-j << endl;
            
			j = b[j];
		}
	}

}
int main(){
    cin >> s >> p;
    n = s.size(),m = p.size();
    kmppre();

    for(int i = 0;i<=m;i++)cout << b[i] << " ";
    cout << endl;

    kmp();
}