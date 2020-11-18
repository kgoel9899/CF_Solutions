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
		int n, k;
		cin >> n >> k;
		vector<int> ans;
		for(int i=31;i>=0;i--) {
			if(((n >> i) & 1) == 1) ans.push_back(1 << i);
		}
		if(k < ans.size() || k > n) cout << "NO" << endl;
		else {
			int reqd = k - ans.size();
			int ind = 0;
			while(reqd && ind <= (int)ans.size() - 1) {
				if(ans[ind] == 1) {
					ind++;
					continue;
				}
				ans[ind] /= 2;
				ans.push_back(ans[ind]);
				reqd--;
			}
			if(reqd == 0) {
				cout << "YES" << endl;
				for(int i=0;i<ans.size();i++) {
					cout << ans[i] << " ";
				}
				cout << endl;
			} else cout << "NO" << endl;
		}
	}
}