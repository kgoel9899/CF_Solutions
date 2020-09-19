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
		ll n;
		cin >> n;
		ll ans = 1;
		n--;
		ll curr = 0, sum = 0;
		while(true) {
			curr++;
			ll fi = (ll)pow(2, 2 * curr + 1);
			fi--;
			sum += (ll)pow(2, curr - 1);
			fi -= sum;
			if(fi <= n) {
				ans++;
				n -= fi;
			} else break;
		}
		cout << ans << endl;
	}
}