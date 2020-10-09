#include<bits/stdc++.h>
using namespace std;
#define mx 1000010
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
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		map<int, int> m;
		vector<int> ans;
		int tot = 0, curr = 0, flag = 0;
		set<int> s;
		for(int i=0;i<n;i++) {
			curr++;
			if(s.count(v[i]) > 0) {
				flag = 1;
				break;
			}
			s.insert(v[i]);
			if(v[i] > 0) m[v[i]]++;
			else m[abs(v[i])]--;
			if(m[abs(v[i])] < 0) {
				flag = 1;
				break;
			}
			if(m[abs(v[i])] == 0) m.erase(abs(v[i]));
			if(m.size() == 0) {
				tot++;
				ans.push_back(curr);
				s.clear();
				curr = 0;
			}
		}
		if(m.size() != 0) flag = 1;
		if(flag == 1) cout << -1 << endl;
		else {
			cout << tot << endl;
			for(int i=0;i<tot;i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
}