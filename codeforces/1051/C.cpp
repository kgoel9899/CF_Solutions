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
		vector<int> v(n);
		map<int, int> ct, ind;
		for(int i=0;i<n;i++) {
			cin >> v[i];
			ct[v[i]]++;
			ind[v[i]] = i;
		}
		int cnt = 0, mx = 0, val = 0;
		set<int> temp;
		for(auto i : ct) {
			if(i.second > mx) {
				mx = i.second;
				val = ind[i.first];
			}
			mx = max(mx, i.second);
			if(i.second == 1) {
				temp.insert(ind[i.first]);
				cnt++;
			}
		}
		if(cnt % 2 == 1) {
			if(mx <= 2) cout << "NO" << endl;
			else {
				cout << "YES" << endl;
				set<int> a, b;
				int x = 0;
				for(auto i : temp) {
					if(x % 2 == 0) a.insert(i);
					else b.insert(i);
					x++;
				}
				b.insert(val);
				for(int i=0;i<n;i++) {
					if(a.count(i) > 0) cout << 'A';
					else if(b.count(i) > 0) cout << 'B';
					else cout << 'A';
				}
				cout << endl;
			}
		} else {
			set<int> a, b;
			cout << "YES" << endl;
			int x = 0;
			for(auto i : temp) {
				if(x % 2 == 0) a.insert(i);
				else b.insert(i);
				x++;
			}
			for(int i=0;i<n;i++) {
				if(a.count(i) > 0) cout << 'A';
				else if(b.count(i) > 0) cout << 'B';
				else cout << 'A';
			}
			cout << endl;
		}
	}
}