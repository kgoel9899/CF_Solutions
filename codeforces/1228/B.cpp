#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int modexpo(int a, int b, int c){
	if(b == 0) return 1;
	if(b % 2 == 0) return modexpo((a * a) % c, b / 2, c);
	else return ((a % c) * (modexpo((a * a) % c, b / 2, c))) % c;
}
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int h, w;
		cin >> h >> w;
		vector<int> r(h), c(w);
		for(int i=0;i<h;i++) {
			cin >> r[i];
		}
		for(int i=0;i<w;i++) {
			cin >> c[i];
		}
		vector<vector<int>> v(h, vector<int>(w));
		for(int i=0;i<h;i++) {
			for(int j=0;j<r[i];j++) {
				v[i][j] = 1;
			}
			if(r[i] < w) v[i][r[i]] = -1;
		}
		for(int i=0;i<w;i++) {
			for(int j=0;j<c[i];j++) {
				if(v[j][i] == -1) {
					cout << 0 << endl;
					return 0;
				}
				v[j][i] = 1;
			}
			if(c[i] < h) {
				if(v[c[i]][i] == 1) {
					cout << 0 << endl;
					return 0;
				}
				v[c[i]][i] = -1;
			}
		}
		int ct = 0;
		for(int i=0;i<h;i++) {
			for(int j=0;j<w;j++) {
				if(v[i][j] == 0) ct++;
			}
		}
		cout << modexpo(2, ct, MOD) << endl;
	}
}