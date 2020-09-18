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
		for(int i=n;i<n+10;i++) {
			int sum = 0;
			string s = to_string(i);
			for(int j=0;j<s.size();j++) {
				sum += s[j] - '0';
			}
			if(sum % 4 == 0) {
				cout << i << endl;
				break;
			}
		}
	}
}