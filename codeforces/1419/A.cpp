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
		string s;
		cin >> s;
		vector<int> ra, br;
		for(int i=1;i<=n;i++) {
			if(i % 2 == 1 && (s[i - 1] - '0') % 2 == 0) ra.push_back(i);
			if(i % 2 == 0 && (s[i - 1] - '0') % 2 == 1) br.push_back(i); 
		}
		for(int i=1;i<=n;i++) {
			if(i % 2 == 1 && (s[i - 1] - '0') % 2 == 1) ra.push_back(i);
			if(i % 2 == 0 && (s[i - 1] - '0') % 2 == 0) br.push_back(i); 
		}
		if(ra.size() == br.size()) {
			if((s[br[(int)br.size() - 1] - 1] - '0') % 2 == 0) cout << 2 << endl;
			else cout << 1 << endl;
		} else {
			if((s[ra[(int)ra.size() - 1] - 1] - '0') % 2 == 1) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
}