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
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> v(n);
		map<int, int> m;
		for(int i=0;i<n;i++) {
			cin >> v[i];
			m[v[i]]++;
		}
		priority_queue<int> pq;
		for(auto i : m) {
			pq.push(i.second);
		}
		ll ans = 0;
		if(pq.size() == 0) cout << 0 << endl;
		else {
			int curr = pq.top();
			ans += curr;
			pq.pop();
			curr--;
			curr = max(0, curr);
			while(!pq.empty()) {
				int f = pq.top();
				// cout << f << " ";
				pq.pop();
				if(curr > f) {
					ans += f;
					curr = max(0, f - 1);
				} else {
					ans += curr;
					curr--;
					curr = max(0, curr);
				}
			}
			cout << ans << endl;
		}
	}
}