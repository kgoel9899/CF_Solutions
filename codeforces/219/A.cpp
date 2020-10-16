#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
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
		int k;
		cin >> k;
		string s;
		cin >> s;
		int n = s.size();
		if(n % k != 0) cout << -1 << endl;
		else {
			map<char, int> m;
			for(int i=0;i<n;i++) {
				m[s[i]]++;
			}
			int flag = 0;
			for(auto i : m) {
				if(i.second % k != 0) {
					flag = 1;
					break;
				}
			}
			if(flag == 1) cout << -1 << endl;
			else {
				string ans = "";
				for(auto i : m) {
					for(int j=0;j<i.second/k;j++) {
						ans += i.first;
					}
				}
				for(int i=0;i<k;i++) {
					cout << ans;
				}
				cout << endl;
			}
		}
	}
}