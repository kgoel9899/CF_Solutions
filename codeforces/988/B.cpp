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
		int n;
		cin >> n;
		vector<string> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), compare);
		string curr = v[0];
		int flag = 0;
		for(int i=1;i<n;i++) {
			if(v[i].size() == curr.size()) {
				if(v[i] != curr) {
					flag = 1;
					// cout << "here" << endl;
					break;
				}
			} else {
				int a = v[i].size(), temp = 0;
				for(int j=0;j<=a-(int)curr.size();j++) {
					// cout << curr << "  " << v[i].substr(i, (int)curr.size()) << endl;
					if(v[i].substr(j, (int)curr.size()) == curr) {
						// if(curr == "ba") {
						// 	cout << v[i].substr(i, (int)curr.size()) << endl;
						// }
						temp = 1;
						break;
					}
				}
				if(temp == 0) {
					// cout << curr << " " << v[i] << endl;
					flag = 1;
					break;
				}
			}
			curr = v[i];
		}
		if(flag == 0) {
			cout << "YES" << endl;
			for(auto i : v) {
				cout << i << endl;
			}
		} else cout << "NO" << endl;
	}
}