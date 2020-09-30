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
		vector<int> a(n), b(n), c(n);
		for(int i=0;i<n;i++) {
			cin >> a[i];
		}
		for(int i=0;i<n;i++) {
			cin >> b[i];
		}
		for(int i=0;i<n;i++) {
			cin >> c[i];
		}
		vector<int> ans(n);
		for(int i=0;i<3;i++) {
			if(i == 0) ans[0] = a[0];
			else if(i == 1) ans[0] = b[0];
			else ans[0] = c[0];
			for(int i=1;i<n;i++) {
				if(a[i] != ans[i - 1]) ans[i] = a[i];
				else if(b[i] != ans[i - 1]) ans[i] = b[i];
				else ans[i] = c[i];
			}
			if(ans[0] != ans[n - 1]) break;
		}
		for(int i=0;i<n;i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}