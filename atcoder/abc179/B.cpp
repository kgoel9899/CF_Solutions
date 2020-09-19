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
		vector<int> a(n), b(n);
		for(int i=0;i<n;i++) {
			cin >> a[i] >> b[i];
		}
		int flag = 0;
		for(int i=0;i<n-2;i++) {
			flag = 0;
			for(int j=i;j<i+3;j++) {
				if(a[j] != b[j]) {
					flag = 1;
					break;
				}
			}
			if(flag == 0) {
				cout << "Yes" << endl;
				flag = 2;
				break;
			}
		}
		if(flag != 2) cout << "No" << endl;
	}
}