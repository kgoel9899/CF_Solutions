#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		int g;
		for(int i=0;i<n;i++) {
			cin >> v[i];
			if(i == 0) g = v[0];
			else g = __gcd(g, v[i]);
		}
		vector<int> sieve(mx);
		for(int i=0;i<mx;i++) {
			sieve[i] = i;
		}
		for(int i=2;i*i<=mx;i++) {
			if(sieve[i] == i) {
				for(int j=i*i;j<=mx;j+=i) {
					if(sieve[j] == j) sieve[j] = i;
				}
			}
		}
		set<int> s;
		int flag = 0;
		for(int i=0;i<n;i++) {
			int x = v[i];
			set<int> temp;
			while(x > 1) {
				temp.insert(sieve[x]);
				x /= sieve[x];
			}
			for(auto j : temp) {
				if(s.count(j) > 0) {
					flag = 1;
					break;
				}
				s.insert(j);
			}
		}
		if(flag == 0) cout << "pairwise coprime" << endl;
		else if(g == 1) cout << "setwise coprime" << endl;
		else cout << "not coprime" << endl;
	}
}