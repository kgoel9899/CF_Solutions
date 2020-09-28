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
		int n, m;
		cin >> n >> m;
		int flag = 0;
		for(int i=0;i<n;i++) {
			int a, b, c, d;
			cin >> a >> b;
			cin >> c >> d;
			if(a == b && b == c && c == d) flag = 1;
			if(b == c) flag = 1;
		}
		if(m % 2 == 1) cout << "NO" << endl;
		else {
			if(flag == 1) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
	}
}