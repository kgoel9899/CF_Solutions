#include<bits/stdc++.h>
using namespace std;
#define mx 1000005
#define MOD 1000000007
#define int long long
#define ld long double
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
int32_t main() {
	fast;
	int t = 1;
	// cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a = 0, b = 0, c = 0, d = 0;
		while(n--) {
			string s;
			cin >> s;
			if(s == "AC") a++;
			else if(s == "WA") b++;
			else if(s == "TLE") c++;
			else d++;
		}
		cout << "AC x " << a << endl;
		cout << "WA x " << b << endl;
		cout << "TLE x " << c << endl;
		cout << "RE x " << d << endl;
	}
}