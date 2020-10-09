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
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n), temp;
		map<int, int> m;
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		for(int i=0;i<n;i++) {
			cin >> b[i];
		}
		int br = 0;
		for(int i=0;i<n;i++) {
			if(a[i] != b[i]) {
				if(b[i] < a[i]) br = 1;
				m[b[i] - a[i]]++;
				temp.push_back(i);
			}
		}
		if(m.size() >= 2 || br == 1) cout << "NO" << endl;
		else {
			int flag = 0;
			for(int i=1;i<temp.size();i++) {
				if(temp[i] != temp[i - 1] + 1) {
					flag = 1;
					break;
				}
			}
			if(flag == 1) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
}