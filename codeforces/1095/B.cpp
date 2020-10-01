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
		int sum = 0;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin >> v[i];
			sum += v[i];
		}
		sort(v.begin(), v.end());
		cout << min(v[n - 1] - v[1], v[n - 2] - v[0]) << endl;
	}
}