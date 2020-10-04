#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
bool compare(string a, string b) {
	return a.size() < b.size();
}
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int k;
		cin >> k;
		vector<vector<int>> v(k), check;
		map<int, vector<pair<int, int>>> m;
		for(int i=0;i<k;i++) {
			int n;
			cin >> n;
			int sum = 0;
			vector<int> temp(n);
			check.push_back(temp);
			for(int j=0;j<n;j++) {
				int num;
				cin >> num;
				v[i].push_back(num);
				sum += num;
			}
			set<int> s;
			for(int j=0;j<n;j++) {
				check[i][j] = sum - v[i][j];
				if(s.count(check[i][j]) == 0) m[check[i][j]].push_back({i + 1, j + 1});
				s.insert(check[i][j]);
			}
		}
		int flag = 0;
		for(auto i : m) {
			if(i.second.size() >= 2) {
				cout << "YES" << endl;
				vector<pair<int, int>> v = i.second;
				cout << v[0].first << " " << v[0].second << endl;
				cout << v[1].first << " " << v[1].second << endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0) cout << "NO" << endl;
	}
}