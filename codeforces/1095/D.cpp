#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define ll long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int main() {
	fast;
	int t = 1;
	// cin >> t;	
	while(t--) {
		int n;
		cin >> n;
		map<int, pair<int, int>> m;
		for(int i=0;i<n;i++) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			m[i] = make_pair(a, b);
		}
		vector<int> ans(n, -1);
		ans[0] = 0;
		for(int i=0;i<n;i++) {
			int curr = ans[i];
			pair<int, int> inter = m[curr];
			ans[(i + 1) % n] = inter.first;
			ans[(i + 2) % n] = inter.second;
			pair<int, int> temp = m[inter.first];
			int a = temp.first, b = temp.second;
			if(inter.second == a || inter.second == b) continue;
			// temp = m[inter.second];
			// a = temp.first, b = temp.second;
			swap(ans[(i + 1) % n], ans[(i + 2) % n]);
		}
		for(int i=0;i<n;i++) {
			cout << ans[i] + 1 << " ";
		}
		cout << endl;
	}
}