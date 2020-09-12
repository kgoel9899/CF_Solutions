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
	string s, t;
	cin >> s >> t;
	int m = s.size(), n = t.size();
	string temp = "";
	int ans = INT_MAX;
	for(int i=0;i<m;i++) {
		if(i >= n) {
			// cout << temp << endl;
			int ct = 0;
			for(int j=0;j<n;j++) {
				if(t[j] != temp[j]) ct++;
			}
			ans = min(ans, ct);
			temp.erase(temp.begin());
		}
		temp += s[i];
	}
	int ct = 0;
	for(int j=0;j<n;j++) {
		if(t[j] != temp[j]) ct++;
	}
	ans = min(ans, ct);
	cout << ans << endl;
}
