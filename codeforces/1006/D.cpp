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
		string a, b;
		cin >> a >> b;
		int ans = 0;
		for(int i=0;i<n/2;i++) {
			if(b[i] == b[n - 1 - i]) {
				if(a[i] != a[n - 1 - i]) ans++;
			} else {
				if(a[i] == b[i]) {
					if(a[n - 1 - i] != b[n - 1 - i]) ans++;
				} else if(a[n - 1 - i] == b[n - 1 - i]) {
					if(a[i] != b[i]) ans++;
				} else if(a[n - 1 - i] == b[i]) {
					if(a[i] != b[n - 1 - i]) ans++;
				} else if(a[i] == b[n - 1 - i]) {
					if(a[n - 1 - i] != b[i]) ans++;
				} else ans += 2;
			}
		}
		if(n % 2 == 1 && a[n / 2] != b[n / 2]) ans++; 
		cout << ans << endl;
	}
}